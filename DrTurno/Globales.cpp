#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <utility> // Para std::pair

#include "Globales.h"
#include "PacienteManager.h"
#include "AdministradorManager.h"

using namespace std;

void inicioDeSesion(PacienteArchivo& archivo,Administrador Administradores[], int adminTam ){

int id;
char contra[20];

cout<< "Ingrese su ID (nro DNI): ";
cin>>id;
cout<< endl;
///-----------------------------------------------
/// Verifico si es un Admin.
    for (int i = 0; i < adminTam; ++i) {
        if (Administradores[i].getID() == id) {
            cout << "Ingrese su contrasenia: ";
            cin >> contra;

            while (strcmp(contra, Administradores[i].getContrasenia()) != 0) {
                cout << "Contrasenia invalida" << std::endl;
                cout << "Reintente el ingreso: ";
                cin >> contra;
            }

            system("cls");
            cout << "Bienvenido/a Administrador " << Administradores[i].getID() << std::endl;
            AdministradorManager adminManager;
            adminManager.menu();
            return;
        }
    }


///-----------------------------------------------
/// Verifico si es un Paciente
    Paciente p = archivo.leerPorDNI(id);
    if (p.getDni() == -1 || p.getEstado()==false) {
        std::cout << "Usuario no encontrado" << std::endl;
        return;
    }

    std::cout << "Ingrese su contrasenia: ";
    std::cin >> contra;

    while (strcmp(contra, p.getContrasenia()) != 0) {
        std::cout << "Contrasenia invalida" << std::endl;
        std::cout << "Reintente el ingreso: ";
        std::cin >> contra;
    }

    std::system("cls");
    std::cout << "Bienvenido/a " << p.getNombre() << std::endl;
    PacienteManager pacienteManager;
    pacienteManager.menu(p);
}

std::pair<int, std::string> selectorDeEspecialidad(){
const char* especialidades[21] = {
 "Alergologia",
 "Analisis Clinicos",
 "Cardiologia",
 "Dermatologia",
 "Endocrinologia",
 "Fertilidad",
 "Gastroenterologia",
 "Geriatria",
 "Ginecologia",
 "Medicina General",
 "Neumonologia",
 "Nutricion",
 "Oftalmologia",
 "Oncologia Medica",
 "Pediatria",
 "Psicologia Clinica",
 "Psiquiatria",
 "Radiodiagnostico",
 "Reumatologia",
 "Traumatologia",
 "Urologia"
};
cout << "Seleccione una especialidad:" << endl;
    for (int i = 0; i < 21; ++i) {
        cout << i + 1 << ". " << especialidades[i] << endl;
    }
    int opcion;

cout << "Ingrese el numero de la especialidad: ";
    cin >> opcion;

    while (opcion < 1 || opcion > 21) {
        cout << "Opcion invalida. Intente nuevamente: ";
        cin >> opcion;
    }

return  std::make_pair(opcion, especialidades[opcion - 1]);
}

string seleccionarDiasDeLaSemana() {
    vector<string> diasDeLaSemana = {"Lunes", "Martes", "Miercoles", "Jueves", "Viernes"};
    vector<bool> seleccionados(5, false);///Vector de 5 elementos, todos inicializados en false.
    int opcion;
    string diasSeleccionados;

    cout << "->Seleccione los días de la semana (0 para finalizar):" << endl;
    for (int i = 0; i < diasDeLaSemana.size(); ++i) {
        cout << i + 1 << ". " << diasDeLaSemana[i] << endl;
    }

    while (true) {
        cout << "->Ingrese el numero del día (0 para finalizar): ";
        cin >> opcion;

        if (opcion == 0) {
            break;
        }

        if (opcion < 1 || opcion > diasDeLaSemana.size()) {
            cout << "Opción inválida. Intente nuevamente." << endl;
        } else {
            seleccionados[opcion - 1] = !seleccionados[opcion - 1];///Cambio el estado dentro del vector
            cout << (seleccionados[opcion - 1] ? "Seleccionado: " : "Deseleccionado: ") << diasDeLaSemana[opcion - 1] << endl; ///Muestro "Seleccionado o Deseleccionado por día de semana.
        }
    }
///Construyo una cadena con los días seleccionados
    for (int i = 0; i < seleccionados.size(); ++i) {
        if (seleccionados[i]) {///Si es true, agrega a la cadena.
            if (!diasSeleccionados.empty()) {
                diasSeleccionados += ", ";
            }
            diasSeleccionados += diasDeLaSemana[i];
        }
    }

    return diasSeleccionados;
}

string diaEnLetras(int dia){
switch (dia) {
            case 1:
               return "Lunes";
                break;
            case 2:
                return "Martes";
                break;
            case 3:
                return "Miercoles";
                break;
            case 4:
                return "Jueves";
                break;
            case 5:
                return "Viernes";
                break;
            default:
                cout << "Dia no encontrado" << endl;
                break;
        }


}

string mesEnLetras(int mes)
{
    const char* nombresMes[] = { "", "Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre" };
    return nombresMes[mes];
}
