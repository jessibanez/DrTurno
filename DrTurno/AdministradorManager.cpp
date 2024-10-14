#include <iostream>
#include <cstring>
#include <cstdlib>
#include <limits>
#include <ctime>
///--------------
#include "Administrador.h"
#include "AdministradorManager.h"
#include "PacienteManager.h"
#include "PacienteArchivo.h"
#include "Paciente.h"
#include "profesional.h"
#include "ProfesionalArchivo.h"
#include "atencion.h"
#include "Globales.h"
#include "Horarios.h"
#include "HorariosArchivo.h"
#include "Agenda.h"
#include "Turnos.h"
#include "TurnosArchivo.h"

using namespace std;

void AdministradorManager::cargarPaciente(){
PacienteManager nuevo;
nuevo.cargarNuevo();
}
void AdministradorManager::modificarPaciente(){
Paciente paraModificar;
PacienteManager manager;
PacienteArchivo archivo;
int dni, index;

    cout<<"MODIFICAR DATOS DE PACIENTES"<<endl;
    cout<<endl;
    cout << "Ingrese el DNI del paciente a modificar: ";
    cin >> dni;

    index = archivo.buscar(dni);
    if(index == -1) {
        cout << "No se encuentra el usuario" << endl;
        return;
    }

    /// Uso el objeto para leer el archivo
        paraModificar = archivo.leerUno(index);
        if(paraModificar.getEstado()==true){
        paraModificar.mostrarPaciente();
        }else {
        cout<<"El paciente ingresado se encuentra dado de baja";
        system("pause");
        system("cls");
         return;
        }
        cout <<endl;
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
        ///FIN de modificaciones

        /// Permito modificar
        manager.cargarDatosNuevos(paraModificar);
        /// Guardar los cambios en el archivo
        if(archivo.guardar(paraModificar, index)==1) {
            cout << "Se modifico con exito" << endl;
        } else {
            cout << "No se realizaron las modificaciones" << endl;
        }
system("pause");
}

void AdministradorManager::eliminarPaciente(){
int dni, index;
    Paciente paciente;
    PacienteArchivo pacienteArchivo;
    bool eliminar;

    cout << "Ingrese el DNI del USUARIO PACIENTE a eliminar: ";
    cin >> dni;

    index = pacienteArchivo.buscar(dni);

    if(index != -1)
    {
        paciente = pacienteArchivo.leerUno(index);

        paciente.mostrarPaciente();

        cout << "Esta segudo de que quiere eliminarlo? 1-Si 0-No: ";
        cin >> eliminar;

        if(eliminar==1){
            paciente.setEstado(false);

            if(pacienteArchivo.guardar(paciente, index)){
                cout << "El paciente a sido eliminado con exito" << endl;
            }
            else{
                cout << "No se pudo eliminar el paciente" << endl;
            }
        }
        else{
            cout << "El paciente no fue eliminado" << endl;

        }
    }
    else{
        cout << "No se encuentra al paciente con DNI " <<dni<< endl;
    }
system("pause");
}

void AdministradorManager::cargarProfesional(){
   cout << "-----Iniciando carga de profesional-----" << endl;
    Profesional nuevo;
    ProfesionalArchivo archivo;
    nuevo.cargar();
    cout << "-----Guardando profesional-----" << endl;
    if (archivo.guardar(nuevo)) {
        cout << "Profesional guardado exitosamente." << endl;
    } else {
        cout << "Error al guardar el profesional." << endl;
    }
system("pause");
}

void AdministradorManager::cargarDatosPersonalesNuevos(Profesional& profesional) {
    char nombre[50], apellido[50], email[50];
    std::string telefono;
    bool telefonoValido = false;

    cout << "--MODIFICARA LOS SIGUIENTES DATOS--" << endl;
    cout << "Complete: " << endl;
    cout << endl;

    cout << "-> Ingrese su nombre: ";
    cin.ignore();
    cin.getline(nombre, 50);

    cout << "-> Ingrese su apellido: ";
    cin.getline(apellido, 50);

    cout << "-> Correo electronico:";
    cin.getline(email, 50);

    while (!telefonoValido) {
        cout << "-> Telefono (sin espacios, ni guiones, entre 6 y 12 dígitos): ";
        cin >> telefono;
        telefonoValido = true;

        if (telefono.length() < 10 || telefono.length() > 14) {
            telefonoValido = false;
            cout << "Error: El telefono debe tener entre 10 y 14 digitos." << endl;
        }

        for (char c : telefono) {
            if (!isdigit(c)) {
                telefonoValido = false;
                cout << "Error: El telefono solo debe contener digitos." << endl;
                break;
            }
        }
    }

    profesional.setNombre(nombre);
    profesional.setApellido(apellido);
    profesional.setEmail(email);
    profesional.setTelefono(stoi(telefono));  // Convertimos la cadena a entero
    profesional.setEstado(true);

    cout << endl;
    cout << "-> Finalizo la carga" << endl;
}

void AdministradorManager::cargarHorariosProfesional(){
Horarios nuevo;
HorariosArchivo archivo;
cout<<"---------CARGA DE HORARIOS---------"<<endl;
nuevo.cargar();
archivo.guardar(nuevo);
}

void AdministradorManager::listarTodos() {
    ProfesionalArchivo archivo;
    HorariosArchivo archivo2;
    int cantidad = archivo.contarRegistros();
    Profesional *profesionales = new Profesional[cantidad];

    if(profesionales == nullptr) {
        cout << "No se pudo pedir memoria... " << endl;
        return;
    }

    archivo.leerTodos(profesionales, cantidad);

    for (int i = 0; i < cantidad; i++) {
        mostrar(profesionales[i]);

        int cantidadHorarios = archivo2.contarRegistros();
        bool encontrado = false;

        for (int j = 0; j < cantidadHorarios; j++) {
            Horarios horario = archivo2.leerUno(j);
            if (horario.getID() == profesionales[i].getMatricula()) {
                if (!encontrado) {
                    cout << "---------DATOS DE ATENCION---------" << endl;
                    encontrado = true;
                }
                int dia=horario.getDia();
                string nombreDia = diaEnLetras(dia);
                cout << "Dia: " << nombreDia << endl;
                cout << "Hora de inicio: " << horario.getHoraInicio() << endl;
                cout << "Hora de Fin: " << horario.getHoraFin() << endl;
            }
        }

        if (encontrado) {
            cout << "-----------------------------------" << endl;
        } else {
            cout << "No hay horarios registrados para este profesional." << endl;
        }

        // Pausar para permitir ver cada profesional
        cout << "Presione Enter para continuar..." << endl;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin.get();
    }

    delete[] profesionales;
}

void AdministradorManager::mostrar(const Profesional& profesional) const{
   system("cls");
    cout << "----------DATOS PERSONALES----------" << endl;
    cout << "->Nombre: " << profesional.getNombre() << endl;
    cout << "->Apellido: " << profesional.getApellido() << endl;
    cout << "->DNI: " << profesional.getDni() << endl;
    cout << "->Matricula: " << profesional.getMatricula() << endl;
    cout << "->Especialidad: " << profesional.getEspecialidad() << endl;
    cout << "->Correo electronico: " << profesional.getEmail() << endl;
    cout << "->Fecha de nacimiento: " << profesional.getFechaNacimiento().toString() << endl;
    cout << "->Telefono: " << profesional.getTelefono() << endl;
    cout <<endl;

}

void AdministradorManager::modificarDatosPersonalesProfesional(){
    int dni, index;
    Profesional profesional;
    ProfesionalArchivo archivo;
    cout << "---MODIFICAR DATOS DE PROFESIONAL--"<<endl;
    cout<<endl;
    cout << "Ingrese el DNI del profesional: ";
    cin >> dni;

    index = archivo.buscar(dni);
    if(index == -1) {
        cout << "No se encuentra el profesional" << endl;
        return;
    }

    // Uso el objeto para leer el archivo
    profesional = archivo.leer(index);
    profesional.mostrar();
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
        cargarDatosPersonalesNuevos(profesional);

        // Guardar los cambios en el archivo
        if(archivo.guardar(profesional, index)==1) {
            cout << "Se modifico con exito" << endl;
        } else {
            cout << "No se realizaron las modificaciones" << endl;
        }
}

void AdministradorManager::mostrarPacientesABC() {
    PacienteManager x;
    x.listarTodosPorAlfabeto(true);
}

void AdministradorManager::menu(){
int opcion;
    do {


        cout << "------------------MENU PRINPCIPAL----------------" << endl;
        cout << "| 1. MENU Profesionales                         |" << endl;
        cout << "| 2. MENU Pacientes                             |" << endl;
        cout << "| 3. MENU Informes                              |" << endl;
        cout << "| 0. Salir                                      |" << endl;
        cout<< "--------------------------------------------------" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                system ("cls");
                menuProfesionales();
                cout<<endl;
                cout<<endl;
                system ("pause");
                system ("cls");
                break;
            case 2:
                system ("cls");
                menuPacientes();
                system ("cls");
                break;
            case 3:
                system ("cls");
                menuInformes();
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

void AdministradorManager::menuProfesionales(){
int opcion;
    Agenda agenda;
    do {
        cout << "-----------------MENU PROFESIONALES--------------" << endl;
        cout << "| 1. Cargar Datos Personales                    |" << endl;
        cout << "| 2. Cargar Dias/Horarios                       |" << endl;
        cout << "| 3. Modificar Datos Personales                 |" << endl;
        cout << "| 4. Modificar Dias y Horarios de Atencion      |" << endl;
        cout << "| 5. Cancelar turno                             |" << endl;
        cout << "| 6. Cancelar turnos por periodo (licencias)    |" << endl;
        cout << "| 0. Salir                                      |" << endl;
        cout<< "--------------------------------------------------" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cargarProfesional();
                cout<<endl;
                system ("pause");
                system ("cls");
                break;
            case 2:
                system ("cls");
                cargarHorariosProfesional();
                system ("cls");
                break;
            case 3:
                system ("cls");
                modificarDatosPersonalesProfesional();
                system ("cls");
                break;
            case 4:
                system ("cls");
                modificarDiasHorariosDeAtencion();
                system ("cls");
                break;
            case 5:
                int profesionalID, dia, mes, anio;
            system ("cls");
            cout << "--CANCELARA UN DIA COMPLETO DE TURNOS---"<<endl;
            cout << "Ingrese el Matricula para cancelar los turnos: ";
            cin >> profesionalID;

            cout << "Ingrese el dia (1-31) para cancelar los turnos: ";
            cin >> dia;

            cout << "Ingrese el mes (1-12) para cancelar los turnos: ";
            cin >> mes;

            cout << "Ingrese el anio para cancelar los turnos: ";
            cin >> anio;
                system ("cls");
                cancelarTurnosProfesionalPorDia(profesionalID, dia, mes, anio);
                system ("cls");
                break;
            case 6:
                system ("cls");
                cout << "--CANCELARA UN PERIODO DE TIEMPO---"<<endl;
                cout << "Funcional para vacaciones, licencias, etc." << endl;
                cout <<endl;
                int diaInicio, diaFin;
                int mes2, anio2, profesionalID2;
                cout <<"->MATRICULA del profesional: ";
                cin>>profesionalID2;
                cout <<endl;
                cout <<"->DIA DE INICIO del receso: ";
                cin>>diaInicio;
                cout <<endl;
                cout <<"->DIA DE FIN del receso (inclusive): ";
                cin>>diaFin;
                cout <<endl;
                cout <<"->MES del receso: ";
                cin>>mes2;
                cout <<endl;
                cout <<"->ANIO del receso: ";
                cin>>anio2;
                system ("cls");
                cancelarTurnosProfesionalPorPeriodo(profesionalID2, diaInicio, diaFin, mes2, anio2);
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

void AdministradorManager::menuPacientes(){
int opcion;
    do {


        cout << "------------------MENU PACIENTES-----------------" << endl;
        cout << "| 1. Cargar Paciente                            |" << endl;
        cout << "| 2. Dar de BAJA un Paciente                    |" << endl;
        cout << "| 3. Modificar datos de Paciente                |" << endl;
        cout << "| 0. Salir                                      |" << endl;
        cout<< "--------------------------------------------------" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                system ("cls");
                cargarPaciente();
                cout<<endl;
                cout<<endl;
                system ("pause");
                system ("cls");
                break;
            case 2:
                system ("cls");
                eliminarPaciente();
                system ("cls");
                break;
            case 3:
                system ("cls");
                modificarPaciente();
                system ("cls");
                break;
            case 4:
                system ("cls");

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

void AdministradorManager::menuInformes(){
int opcion;
    Agenda agenda;
    do {


        cout << "-------------------MENU INFORMES-----------------" << endl;
        cout << "| 1. Listar Pacientes Alfabeticamente           |" << endl;
        cout << "| 2. Listar Profesionales Alfabeticamente       |" << endl;
        cout << "| 3. Listar turnos por mes y profesional        |" << endl;
        cout << "| 4. Listar turnos semanales                    |" << endl;
        cout << "| 5. Listar turnos solicitados de profesional   |" << endl;
        cout << "| 6. Listar turnos solicitados por paciente     |" << endl;
        cout << "| 0. Salir                                      |" << endl;
        cout<< "--------------------------------------------------" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                system ("cls");
                mostrarPacientesABC();
                cout<<endl;
                cout<<endl;
                system ("pause");
                system ("cls");
                break;
            case 2:
                system ("cls");
                listarTodos();
                system ("cls");
                break;
            case 3:
                system ("cls");
                int profesionalID, mes;

                cout << "Ingrese su Matricula para ver la atencion mensual:  ";
                cin >> profesionalID;

                cout << "Ingrese el mes (1-12):  ";
                cin >> mes;
                verFechasDeAtencionProfesional(profesionalID, mes);
                system ("cls");
                break;
            case 4:
                system ("cls");
                mostrarTurnosReservadosSemanaActual();
                system ("cls");
                break;
            case 5:
                system("cls");
                verTurnosSolicitadosDeProfesional();
                system("pause");
                system("cls");
                break;
                case 6:
                system("cls");
                verTurnosSolicitadosPorPaciente();
                system("pause");
                system("cls");
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

void AdministradorManager::modificarAtencion(Horarios& horario) {
    cout << "Cargue los NUEVOS datos de atencion" << endl;

    int dia, horaInicio, horaFin;
    cout << " -> Dia de atencion (1.Lunes, 2.Martes, 3.Miercoles, 4.Jueves, 5.Viernes): ";
    cin >> dia;
    cout << " -> Horario de inicio (Formato 24Hs.): ";
    cin >> horaInicio;
    cout << " -> Hora de finalizacion (Formato 24Hs.): ";
    cin >> horaFin;

    horario.setDia(dia);
    horario.setHoraInicio(horaInicio);
    horario.setHoraFin(horaFin);
}

void AdministradorManager::modificarDiasHorariosDeAtencion() {
    int matricula, index;
    Horarios horarioActual;
    HorariosArchivo archivo;
    cout << "---MODIFICAR DIAS Y HORARIOS DE ATENCION---" << endl;
    cout << endl;
    cout << "Ingrese la MATRICULA del profesional: ";
    cin >> matricula;

    index = archivo.buscar(matricula);
    if (index == -1) {
        cout << "No se encuentra el profesional" << endl;
        return;
    }

    horarioActual = archivo.leerUno(index);

    // Mostrar información actual
    cout << "Dia actual de atencion: " << diaEnLetras(horarioActual.getDia()) << endl;
    cout << "Horario de inicio actual: " << horarioActual.getHoraInicio() << endl;
    cout << "Horario de finalizacion actual: " << horarioActual.getHoraFin() << endl;

    cout << "Desea proceder con los cambios? (0 Si, 1 NO): ";
    int opc;
    cin >> opc;
    if (opc == 1) {
        cout << "Volvemos al menu" << endl;
        system("pause");
        system("cls");
        return;
    } else {
        cout << "Continuamos con las modificaciones" << endl;
    }
    system("cls");

    // Permito modificar
    modificarAtencion(horarioActual);

    // Guardar los cambios en el archivo
    if (archivo.guardar(horarioActual, index)) {
        cout << "Se modifico con exito" << endl;
    } else {
        cout << "No se realizaron las modificaciones" << endl;
    }
}

void AdministradorManager::cancelarTurnosProfesionalPorDia(int profesionalID, int dia, int mes, int anio) {
    TurnosArchivo archivoLectura;
    Turnos* turnosParaCancelar;
    int cant = archivoLectura.contarRegistros();
    turnosParaCancelar = new Turnos[cant];
    PacienteArchivo pacienteArchivo;

    archivoLectura.leerTodos(turnosParaCancelar, cant);

    bool coincidenciasEncontradas = false;
    std::vector<int> turnosACancelar;
cout<<"SOBRE LOS TURNOS QUE SE ENCUENTREN RESERVADOS"<<endl;
cout<<" SE LE PROPORCIONARA INFORMACION DE CONTACTO "<<endl;
cout<<"    PARA QUE DE EL AVISO CORRESPONDIENTE "<<endl;
cout<<"---------------------------------------------"<<endl;

    for (int i = 0; i < cant; i++) {
        if (turnosParaCancelar[i].getMatricula() == profesionalID &&
            turnosParaCancelar[i].getFecha().getDia() == dia &&
            turnosParaCancelar[i].getFecha().getMes() == mes &&
            turnosParaCancelar[i].getFecha().getAnio() == anio) {

        if(turnosParaCancelar[i].getReservado()){
           Paciente paciente = pacienteArchivo.leerPorDNI(turnosParaCancelar[i].getDniPaciente());
                cout << "Nombre: " << paciente.getNombre() << endl;
                cout << "Apellido: " << paciente.getApellido() << endl;
                cout << "Telefono: " << paciente.getTelefono() << endl;
                cout << "Email: " << paciente.getEmail() << endl;
        }
            turnosParaCancelar[i].mostrarTurnoReservado();
            cout <<"---------------------------------------"<<endl;

            turnosACancelar.push_back(turnosParaCancelar[i].getIdTurno());
            coincidenciasEncontradas = true;
        }
    }

    if (!coincidenciasEncontradas) {
        std::cout << "No se encontraron turnos para cancelar." << std::endl;
    } else {
        char confirm;
        std::cout << "¿Desea cancelar estos turnos? (s/n): ";
        std::cin >> confirm;
        if (confirm == 's' || confirm == 'S') {
            for (int id : turnosACancelar) {
                int pos = archivoLectura.buscarPorIdMesProfesional(id, mes, profesionalID);
                if (pos != -1) {
                    turnosParaCancelar[pos].setReservado(true);
                    turnosParaCancelar[pos].setDniPaciente(0);
                    archivoLectura.guardar(turnosParaCancelar[pos], pos);
                }
            }
            std::cout << "Turnos cancelados con éxito." << std::endl;
        } else {
            std::cout << "Cancelación de turnos abortada." << std::endl;
        }
    }

    delete[] turnosParaCancelar;
    system("pause");
}

void AdministradorManager::cancelarTurnosProfesionalPorPeriodo(int profesionalID, int diaInicio, int diaFin, int mes, int anio) {
    TurnosArchivo archivoLectura;
    Turnos* turnosParaCancelar;
    int cant = archivoLectura.contarRegistros();
    turnosParaCancelar = new Turnos[cant];
    Agenda agenda;
    PacienteArchivo pacienteArchivo;

    archivoLectura.leerTodos(turnosParaCancelar, cant);

    bool agendaExistente = false;

    // Verificar si ya existe la agenda para el profesional y el mes específicos
    for (int i = 0; i < cant; i++) {
        if (turnosParaCancelar[i].getMatricula() == profesionalID &&
            turnosParaCancelar[i].getFecha().getMes() == mes &&
            turnosParaCancelar[i].getFecha().getAnio() == anio) {
            agendaExistente = true;
            break;
        }
    }

    // Generar agenda para todo el mes si no existe
    if (!agendaExistente) {
        agenda.generarAgendaMensual(profesionalID, mes, anio);
        // Volver a leer todos los turnos después de generar la agenda
        cant = archivoLectura.contarRegistros();
        delete[] turnosParaCancelar;
        turnosParaCancelar = new Turnos[cant];
        archivoLectura.leerTodos(turnosParaCancelar, cant);
    }

    bool coincidenciasEncontradas = false;
    std::vector<int> turnosACancelar;

    for (int dia = diaInicio; dia <= diaFin; dia++) {
        for (int i = 0; i < cant; i++) {
            if (turnosParaCancelar[i].getMatricula() == profesionalID &&
                turnosParaCancelar[i].getFecha().getDia() == dia &&
                turnosParaCancelar[i].getFecha().getMes() == mes &&
                turnosParaCancelar[i].getFecha().getAnio() == anio) {

                if (turnosParaCancelar[i].getReservado()) {
                    Paciente paciente = pacienteArchivo.leerPorDNI(turnosParaCancelar[i].getDniPaciente());
                    cout << "DNI: " << paciente.getDni() << endl;
                    cout << "Nombre: " << paciente.getNombre() << endl;
                    cout << "Apellido: " << paciente.getApellido() << endl;
                    cout << "Telefono: " << paciente.getTelefono() << endl;
                    cout << "Email: " << paciente.getEmail() << endl;
                }

                turnosParaCancelar[i].mostrarTurnoReservado();
                turnosACancelar.push_back(i); // Guardar el índice
                coincidenciasEncontradas = true;
            }
        }
    }

    if (!coincidenciasEncontradas) {
        std::cout << "No se encontraron turnos para cancelar en el periodo especificado." << std::endl;
    } else {
        char confirm;
        std::cout << "¿Desea cancelar estos turnos? (s/n): ";
        std::cin >> confirm;
        if (confirm == 's' || confirm == 'S') {
            for (int index : turnosACancelar) {
                turnosParaCancelar[index].setReservado(true);  // Cambia el estado a reservado (true)
                turnosParaCancelar[index].setDniPaciente(0);   // Cambia el DNI a 0
                archivoLectura.guardar(turnosParaCancelar[index], index);
            }
            std::cout << "Turnos cancelados con éxito." << std::endl;
        } else {
            std::cout << "Cancelación de turnos abortada." << std::endl;
        }
    }

    delete[] turnosParaCancelar;
    system("pause");
}

void AdministradorManager::verFechasDeAtencionProfesional(int profesionalID, int mes) {
    TurnosArchivo archivoLectura;
    Turnos* turnosParaVer;
    int cant = archivoLectura.contarRegistros();
    turnosParaVer = new Turnos[cant];

    archivoLectura.leerTodos(turnosParaVer, cant);

    bool fechasEncontradas = false;

    std::cout << "Fechas de atencion del profesional con ID " << profesionalID << " para el mes " << mesEnLetras(mes) << ":" << std::endl;
    for (int i = 0; i < cant; i++) {
        if (turnosParaVer[i].getMatricula() == profesionalID &&
            turnosParaVer[i].getFecha().getMes() == mes &&
            turnosParaVer[i].getReservado()) {
            std::cout << "Fecha: " << turnosParaVer[i].getFecha().getDia() << "/"
                      << turnosParaVer[i].getFecha().getMes() << "/"
                      << turnosParaVer[i].getFecha().getAnio()
                      << ", Hora: " << turnosParaVer[i].getHora()
                      << ", DNI del Paciente: " << turnosParaVer[i].getDniPaciente() << std::endl;
            fechasEncontradas = true;
        }
    }

    if (!fechasEncontradas) {
        std::cout << "No hay fechas de atencion reservadas para este profesional en el mes especificado." << std::endl;
    }

    delete[] turnosParaVer;
    system("pause");
}

void AdministradorManager::mostrarTurnosReservadosSemanaActual() {
   TurnosArchivo archivoLectura;
    Turnos* turnosParaMostrar;
    int cant = archivoLectura.contarRegistros();
    turnosParaMostrar = new Turnos[cant];
    PacienteArchivo pacienteArchivo;

    archivoLectura.leerTodos(turnosParaMostrar, cant);

    // Obtener la fecha actual
    time_t t = time(nullptr);
    tm* now = localtime(&t);
    int anioActual = now->tm_year + 1900;
    int mesActual = now->tm_mon + 1;
    int diaActual = now->tm_mday;
    int diaSemanaActual = now->tm_wday;

    // Calcular el inicio y el fin de la semana actual (de lunes a viernes)
    int diaInicioSemana = diaActual - (diaSemanaActual == 0 ? 6 : diaSemanaActual - 1); // Lunes actual o anterior si es domingo
    int diaFinSemana = diaInicioSemana + 4; // Viernes de la misma semana

    // Ajustar los días y meses si se salen del mes actual
    tm inicioSemana = *now; ///tm es una ESTRUCTURA, inicioSemana se inicializa con la fecha y hora actual a traves de el puntero now
    inicioSemana.tm_mday = diaInicioSemana; ///Se establece el día del mes en inicioSemana
    mktime(&inicioSemana);///Convierte una estructura en objeto
    int mesInicioSemana = inicioSemana.tm_mon + 1;///Ajusta el mes a través de inicioSemana
    int diaInicioSemanaAjustado = inicioSemana.tm_mday;///Toma el dia ajustado por el mes de inicioSemana y lo almacena

    tm finSemana = *now;
    finSemana.tm_mday = diaFinSemana;///Establece el día del mes
    mktime(&finSemana);
    int mesFinSemana = finSemana.tm_mon + 1;///Toma el mes ajustado
    int diaFinSemanaAjustado = finSemana.tm_mday;///Toma el dia ajustado del mes

    // Mostrar el rango de días de la semana
    std::cout << "Se mostraran los turnos de la corriente semana, del día lunes " << diaInicioSemanaAjustado << " al viernes " << diaFinSemanaAjustado << " de " << mesActual << " de " << anioActual << std::endl;

    bool coincidenciasEncontradas = false;

    for (int i = 0; i < cant; i++) {
        Fecha fechaTurno = turnosParaMostrar[i].getFecha();
        if (turnosParaMostrar[i].getReservado() &&
            fechaTurno.getAnio() == anioActual &&
            fechaTurno.getMes() == mesActual &&
            fechaTurno.getDia() >= diaInicioSemanaAjustado &&
            fechaTurno.getDia() <= diaFinSemanaAjustado) {
       if(turnosParaMostrar[i].getReservado()){
           Paciente paciente = pacienteArchivo.leerPorDNI(turnosParaMostrar[i].getDniPaciente());
                cout << "--->Paciente: "<<paciente.getNombre()<<" "<<paciente.getApellido()<< endl;
                cout << "-Telefono: " << paciente.getTelefono() << endl;
                cout << "-Email: " << paciente.getEmail() << endl;
        }

            turnosParaMostrar[i].mostrarTurnoReservado();
                cout<<"-------------------------------------"<<endl;
            coincidenciasEncontradas = true;
        }
    }

    if (!coincidenciasEncontradas) {
        std::cout << "No se encontraron turnos reservados para la semana en curso." << std::endl;
    }

    delete[] turnosParaMostrar;
    system("pause");
}

void AdministradorManager::verTurnosSolicitadosDeProfesional() {
    int matriculaProfesional;
    cout << "Ingrese la matricula del profesional: ";
    cin >> matriculaProfesional;

    TurnosArchivo turnosArchivo;
    int cantidadTurnos = turnosArchivo.contarRegistros();
    Turnos* turnos = new Turnos[cantidadTurnos];
    turnosArchivo.leerTodos(turnos, cantidadTurnos); // leerTodos no devuelve valor

    bool hayTurnos = false;
    for (int i = 0; i < cantidadTurnos; i++) {
        if (turnos[i].getMatricula() == matriculaProfesional && turnos[i].getReservado()) {
                if (turnos[i].getDniPaciente()==0){
            cout<<"---------Vacaciones/Licencia---------"<<endl;
                }
            turnos[i].mostrarTurnoReservado();
            cout<<"-------------------------------------"<<endl;
            hayTurnos = true;
        }
    }

    if (!hayTurnos) {
        cout << "No se encontraron turnos para el profesional con matricula " << matriculaProfesional << "." << endl;
    }

    delete[] turnos;
}

void AdministradorManager::verTurnosSolicitadosPorPaciente() {
    int dni;
    cout << "Ingrese el DNI del paciente: ";
    cin >> dni;

    TurnosArchivo turnosArchivo;
    int cantidadTurnos = turnosArchivo.contarRegistros();
    Turnos* turnos = new Turnos[cantidadTurnos];
    turnosArchivo.leerTodos(turnos, cantidadTurnos); // leerTodos no devuelve valor

    Paciente paciente;
    PacienteArchivo pacienteArchivo;
    paciente=pacienteArchivo.leerPorDNI(dni);

    Profesional profesional;
    ProfesionalArchivo profesionalArchivo;


    bool hayTurnos = false;
    if(paciente.getDni()==dni){
    cout<<"---Datos del paciente ingresado---"<<endl;
    cout<<"->Nombre: "<<paciente.getNombre()<<" "<<paciente.getApellido()<<endl;
    cout<<"->Telefono: "<<paciente.getTelefono()<<endl;
    cout<<"->Email: "<<paciente.getEmail()<<endl;
    cout<<"->Domicilio: "<<paciente.getCalle()<< " Nro: "<<paciente.getNumero()<<", Localidad: "<<paciente.getLocalidad()<<", Provincia: "<<paciente.getProvincia()<<endl;
    cout<<"---------------------------------------------------------------------"<<endl;
    cout<<endl;
    cout<<endl;
    }

    for (int i = 0; i < cantidadTurnos; i++) {
        if (turnos[i].getDniPaciente() == dni) {
            profesional=profesionalArchivo.leerPorMatricula(turnos[i].getMatricula());
            cout<<"Profesional: "<<profesional.getNombre()<<" "<<profesional.getApellido()<<endl;
            cout<<"Especialidad: "<<profesional.getEspecialidad()<<endl;
            cout<<"Fecha: "<<turnos[i].getFecha().toString()<<endl;
            cout<<"Hora: "<<turnos[i].getHora()<<endl;
            cout<<"-------------------------------------"<<endl;
            hayTurnos = true;
        }
    }

    if (!hayTurnos) {
        cout << "No se encontraron turnos para el paciente con DNI " << dni << "." << endl;
    }

    delete[] turnos;
}

