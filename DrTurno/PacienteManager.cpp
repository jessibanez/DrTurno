#include <iostream>
#include <cstring>
#include <cstdlib>
#include <limits> ///Libreria para generar pausas entre un paciente y otro al momento de mostrarlos listados.
#include <utility> // Para std::pair
#include <ctime>

#include "Globales.h"
#include "PacienteManager.h"
#include "Paciente.h"
#include "PacienteArchivo.h"
#include "ProfesionalArchivo.h"
#include "profesional.h"
#include "Turnos.h"
#include "TurnosArchivo.h"

#include "Agenda.h"
#include "AgendaArchivo.h"

#include <vector>
using namespace std;

Paciente PacienteManager::cargarNuevo(){
Paciente nuevoPaciente;
PacienteArchivo archivo;
cout << "------------CARGA NUEVO PACIENTE------------" << endl;
cout<<endl;
cout << "Verificaremos que el paciente no se encuentre previamente en el sistema." << endl;
cout << "Ingrese el DNI del mismo: " << endl;
int dni;
cin>>dni;
    if(archivo.buscar(dni)==-1){
    nuevoPaciente.cargar();
    bool guardado = archivo.guardar(nuevoPaciente);

    if (guardado) {
        cout << "Paciente guardado exitosamente." << endl;
    } else {
        cout << "Error al guardar el paciente." << endl;
    }

    return nuevoPaciente;
}
else{
    cout << "Error, el DNI ingresado ya se encuentra en el sistema." << endl;
}
system("pause");
}

void PacienteManager::mostrar(const Paciente& paciente) const{
   system("cls");
    cout << "----------DATOS PERSONALES----------" << endl;
    cout << "->Nombre: " << paciente.getNombre() << endl;
    cout << "->Apellido: " << paciente.getApellido() << endl;
    cout << "->DNI: " << paciente.getDni() << endl;
    cout << "->Correo electronico: " << paciente.getEmail() << endl;
    cout << "->Fecha de nacimiento: " << paciente.getFechaNacimiento().toString() << endl;
    cout << "->Telefono: " << paciente.getTelefono() << endl;
    cout <<endl;
    cout << "--------DETALLES DEL DOMICILIO--------" << endl;
    cout << "Calle: " << paciente.getCalle() << endl;
    cout << "Numero: " << paciente.getNumero() << endl;
    cout << "Localidad: " << paciente.getLocalidad() << endl;
    cout << "Partido: " << paciente.getPartido() << endl;
    cout << "Provincia: " << paciente.getProvincia() << endl;
    cout << "Pais: " << paciente.getPais() << endl;
    cout << "Codigo Postal: " << paciente.getCodigoPostal() << endl;


}

void PacienteManager:: cargarDatosNuevos(Paciente& paciente){
 char nombre[50], apellido[50], email[50];
    int telefono;
    Fecha fechaNacimiento;

    cout <<"----INGRESARA DE NUEVO SUS DATOS----"<<endl;
    cout <<"Complete: "<<endl;
    cout << endl;

    cout << "-> Ingrese su nombre: ";
    cin.ignore();
    cin.getline(nombre,50);

    cout << "-> Ingrese su apellido: ";
    cin.getline(apellido,50);

    cout << "-> Correo electronico:";
    cin.getline(email,50);

    cout<<"-> Fecha de nacimiento: "<<endl;
    int dia, mes, anio;
    cout<<"Dia: ";
    cin>>dia;
    cout<<"Mes: ";
    cin>>mes;
    cout<<"Anio (4 digitos): ";
    cin>>anio;

    cout<<"->Telefono (sin espacios, ni guiones): ";
    cin>>telefono;
    cout << endl;

    char calle[30], localidad[30], partido[30], prov[30], pais[30];
    int num, codPostal;

    cout << "--------INGRESE SU DOMICILIO--------" << endl;

    cout << "-> Calle: ";
    cin.ignore();
    cin.getline(calle, 30);

    cout << "-> Numero: ";
    cin >> num;
    cin.ignore();

    cout << "-> Localidad: ";
    cin.getline(localidad, 30);

    cout << "-> Partido: ";
    cin.getline(partido, 30);

    cout << "-> Provincia: ";
    cin.getline(prov, 30);

    cout << "-> Pais: ";
    cin.getline(pais, 30);

    cout << "-> Codigo Postal: ";
    cin >> codPostal;
    cin.ignore();

    paciente.setNombre(nombre);
    paciente.setApellido(apellido);
    paciente.setEmail(email);
    paciente.getFechaNacimiento().setDia(dia);
    paciente.getFechaNacimiento().setAnio(anio);
    paciente.getFechaNacimiento().setMes(mes);
    paciente.setTelefono(telefono);
    paciente.setCalle(calle);
    paciente.setNumero(num);
    paciente.setLocalidad(localidad);
    paciente.setPartido(partido);
    paciente.setProvincia(prov);
    paciente.setPais(pais);
    paciente.setCodigoPostal(codPostal);
    paciente.setEstado(true);
    cout <<endl;
    cout <<endl;
    cout << "-> Finalizo la carga" <<endl;
}

void PacienteManager::modificarDatos(){
    int dni, index;
    char contra[20];
    Paciente paciente;
    PacienteArchivo archivo;
    cout << "---Por seguridad, solicitadremos algunos datos--"<<endl;
    cout<<endl;
    cout << "Ingrese su DNI: ";
    cin >> dni;

    index = archivo.buscar(dni);
    if(index == -1) {
        cout << "No se encuentra el usuario" << endl;
        return;
    }

    // Uso el objeto para leer el archivo
    paciente = archivo.leerUno(index);
    cout << "Ingrese su CONTRASENIA: ";
    cin >> contra;
    // Comparo la contraseña ingresada con la guardada
    if(strcmp(contra, paciente.getContrasenia()) == 0) {
        // Muestro los datos actuales del paciente(borrar)
        mostrar(paciente);
        cout << "Desea proceder con los cambios? (0 Si, 1 NO): ";
        int opc;
        cin>>opc;
        if(opc==1){
         cout << "Volvemos al menu"<<endl;
         system("pause");
         system("cls");
         return;
        }else {
         cout << "Continuamos con las modificaciones"<<endl;
        }
        system("cls");
        ////FIN de modificaciones

        // Permito modificar
        cargarDatosNuevos(paciente);

        // Guardar los cambios en el archivo
        if(archivo.guardar(paciente, index)==1) {
            cout << "Se modifico con exito" << endl;
        } else {
            cout << "No se realizaron las modificaciones" << endl;
        }
    } else {
        cout << "Contrasenia invalida" << endl;
    }
}

void PacienteManager::menuTurnos(){
    int opcion;
    Turnos turno;
    Agenda agenda;
    do {
        cout << "-----------MENU TURNOS----------" << endl;
        cout << "| 1. Busqueda de profesionales |" << endl;
        cout << "| 2. Reserva tu turno          |" << endl;
        cout << "| 3. Cancela tu turno          |" << endl;
        cout << "| 4. Informes                  |" << endl;
        cout << "|                              |" << endl;
        cout << "| 0. Salir                     |" << endl;
        cout<< "---------------------------------" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:{
                system("cls");
                buscarEspecialista();
                system("cls");
               } break;
            case 2:{
                ///FECHA ACTUAL DEL SISTEMA
                time_t t = time(nullptr);
                tm* now = localtime(&t);
                int anio = now->tm_year + 1900;
                int dia = now->tm_mday;
                int mesActual = now->tm_mon +1;
                   system("cls");
                cout << "MATRICULA DEL PROFESIONAL: ";
                int matricula;
                cin >> matricula;
                int mes;
                do{
                        cout << "MES DE ATENCION: ";

                cin >> mes;
                        if (mes< mesActual){
                    cout<<"ERROR. No puede seleccionar un mes anterior al que esta en curso"<<endl;
                    cout<<"Reingrese"<<endl;
                } else{
                system("cls");
                agenda.mostrarAgenda(matricula, dia, mes, anio);
                }
                }while(mes< mesActual);
                cout<<endl;
                cout<<"Desea reservar un turnos? (1-Si, 0-No)"<<endl;
                int opc;
                cin>>opc;
                cout<<endl;
                if(opc==1){
                cout << "-->Ingrese el numero de turno seleccionado: ";
                int nroTurno;
                cin >> nroTurno;
                cout << "-->Por SEGURIDAD, le solicitamos que ingrese su DNI: ";
                int dni;
                cin >> dni;
                agenda.reservarTurno(matricula, nroTurno, dni, mes);
                }else{
                 cout<<"Volvera al menu anterior"<<endl;
                   system("cls");
                    break;
                }
                system("cls");
                } break;
            case 3:{
                int dniPaciente,idTurno;
                cout << "Ingrese el DNI del paciente para cancelar el turno reservado: ";;
                cin >> dniPaciente;
                cout << "Ingrese el ID del turno a cancelar:  ";
                cin >> idTurno;
                system("cls");
                turno.cancelarTurnoPaciente(dniPaciente, idTurno);
                system("cls");
               } break;
            case 4:{
                int dniPaciente;
                cout << "Para solicitar acceso a los informes solcitaremos su DNI"<<endl;
                cout << "Ingrese su DNI: ";
                cin >> dniPaciente;
                system("cls");
                menuInformes(dniPaciente);
                system("cls");
                } break;
            case 0:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion invalida." << endl;
                break;
        }
    } while (opcion != 0);
}

void PacienteManager::menuInformes(int dniPaciente){
    int opcion;
    Turnos turno;
    do {
        cout << "-----------MENU TURNOS----------" << endl;
        cout << "| 1. Turnos Pasados            |" << endl;
        cout << "| 2. Turnos Futuros            |" << endl;
        cout << "|                              |" << endl;
        cout << "| 0. Salir                     |" << endl;
        cout<< "---------------------------------" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:{
                system("cls");
                turno.mostrarTurnoReservadoPasado(dniPaciente);
                system("cls");
               } break;
            case 2:{
                   system("cls");
                   turno.mostrarTurnoReservadoFuturo(dniPaciente);
                   system("cls");
                   } break;
            case 0:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion invalida." << endl;
                break;
        }
    } while (opcion != 0);
    }

void PacienteManager::ordenarAlfabeticamente(Paciente pacientes[], int cantidad){
   for (int i = 0; i < cantidad - 1; i++) {
        int abc = i;
        for (int j = i + 1; j < cantidad; j++) {
            if (strcmp(pacientes[j].getApellido(), pacientes[abc].getApellido()) < 0) {
                abc = j;
            }
        }
        if (i != abc) {
            Paciente aux = pacientes[i];
            pacientes[i] = pacientes[abc];
            pacientes[abc] = aux;
        }
    }
}

void PacienteManager::listarTodosPorAlfabeto(bool ordernarABC){
    PacienteArchivo archivo;
    int cantidad = archivo.contarRegistros();
    Paciente* pacientes= new Paciente[cantidad];
    archivo.leerTodos(pacientes, cantidad);

   //Ordenar por Alfabeto
 if (ordernarABC){
    ordenarAlfabeticamente(pacientes, cantidad);
}
   for (int i = 0; i < cantidad; i++) {
        if(pacientes[i].getEstado()==true){
        pacientes[i].mostrarPaciente();
        cout << "--------------------------" << endl << endl;
        }
    }

delete [] pacientes;

}

void PacienteManager::menu(Paciente& aux) {
    int opcion;
    do {


        cout << "------------MENU PRINPCIPAL-----------" << endl;
        cout << "| 1. Mostrar sus datos personales    |" << endl;
        cout << "| 2. Modificar sus datos personales  |" << endl;
        cout << "| 3. Turnos                          |" << endl;
        cout << "|                                    |" << endl;
        cout << "| 0. Salir                           |" << endl;
        cout<< "--------------------------------------" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                mostrar(aux);
                cout<<endl;
                cout<<endl;
                system ("pause");
                system ("cls");
                break;
            case 2:
                system ("cls");
                modificarDatos();
                system ("cls");
                break;
            case 3:
                system ("cls");
                menuTurnos();
                system ("cls");
                break;
            case 0:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion invalida." << endl;
                break;
        }
    } while (opcion != 0);
}

void PacienteManager::buscarEspecialista(){
ProfesionalArchivo archivo;
int cantidad = archivo.contarRegistros();
Profesional *profesionales = new Profesional[cantidad];
cout<<"Inicia la busqueda de su especialista ideal: "<<endl;

auto especialidadSeleccionada = selectorDeEspecialidad();
int opc = especialidadSeleccionada.first;
char especialidad[50];
strcpy(especialidad, especialidadSeleccionada.second.c_str());

system("cls");

cout<<"Los profesionales especializados en "<<especialidad<<" son: "<<endl;

archivo.leerTodos(profesionales, cantidad);
bool encontrado = false;

    for (int i = 0; i < cantidad; i++) {
        if (profesionales[i].getIDEspecialidad() == opc) {
            profesionales[i].mostrar();
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "No se encontraron profesionales con la especialidad seleccionada." << endl;
    }

    delete[] profesionales;
system("pause");
}
