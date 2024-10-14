#include <iostream>
#include <cstring>
#include <cctype>  // Para usar tolower
#include <windows.h>
#include <cstdlib>

#include "Paciente.h"
#include "PacienteManager.h"
#include "Globales.h"
#include "PacienteArchivo.h"
#include "Administrador.h"

using namespace std;


// Función para convertir la cadena a minúsculas
void toLowerCase(char* str) {
    for (int i = 0; str[i]; i++) {
        str[i] = std::tolower(str[i]);
    }
}
//Función para centrar textos en pantalla
void gotoxy(int, int);

void Bienvenidos(PacienteArchivo& archivo, Administrador Administradores[], int adminTam);

int main()
{
    PacienteArchivo aux;
    ///extern lo convierte en un array "global"
    extern Administrador Administradores[3];

        Bienvenidos(aux, Administradores, 3);

    return 0;
}

void Bienvenidos(PacienteArchivo& archivo, Administrador Administradores[], int adminTam){
///Paciente aux;

char opc[3];
char opc2[3]="si";
gotoxy(40,4);printf("----------------------------------------");
gotoxy(40,5);printf("|                                      |");
gotoxy(40,6);printf("|-------BIENVENIDO/A A DR. TURNO-------|");
gotoxy(40,7);printf("|                                      |");
gotoxy(40,8);printf("|        ESTA USTED REGISTRADO?        |");
gotoxy(40,9);printf("|                SI/NO                 |");
gotoxy(40,10);printf("----------------------------------------");

cin>>opc;

toLowerCase(opc);

if(strcmp (opc, opc2)==0){
system("cls");
inicioDeSesion(archivo, Administradores,adminTam);

   }
   else{
PacienteManager Nuevo;
cout<<"Crearemos su usuario ahora"<<endl;
    system("pause");
    system("cls");

    Nuevo.cargarNuevo();

   }
}

//Función para centrar textos en pantalla
void gotoxy(int x, int y){
HANDLE manipulador;
COORD coordenadas;
manipulador= GetStdHandle(STD_OUTPUT_HANDLE);
coordenadas.X= x;
coordenadas.Y= y;
SetConsoleCursorPosition(manipulador, coordenadas);
}

/*
#include <iostream>
#include <vector>
#include "Turnos.h"
#include "TurnosArchivo.h"
#include "Fecha.h"

int main() {
    TurnosArchivo turnoArchivo;

    // Crear algunos turnos de ejemplo
    vector<Turnos> turnosParaGuardar;
    turnosParaGuardar.push_back(Turnos(1, Fecha(15, 7, 2024), "10:00", false, 1, 0));
    turnosParaGuardar.push_back(Turnos(1, Fecha(16, 7, 2024), "11:00", false, 2, 0));
    int matricula=1;

    // Guardar turnos en el archivo
    if (turnoArchivo.guardar(turnosParaGuardar)) {
        std::cout << "Turnos guardados correctamente." << std::endl;
    } else {
        std::cerr << "Error al guardar los turnos." << std::endl;
    }
cout<<"Paso a leer"<<endl;
cout<<endl;
cout<<endl;
cout<<"---------------------------"<<endl;

turnosParaGuardar=turnoArchivo.buscarProfesional(matricula);

    // Leer todos los turnos del archivo
    vector<Turnos> turnosLeidos;
    turnoArchivo.leerTodos(turnosLeidos);
cout<<"Salgo de leerTodos"<<endl;
    // Verificar si se han leído turnos
    if (turnosLeidos.empty()) {
        std::cerr << "No se han leído turnos del archivo." << std::endl;
        return 1;
    }

    // Mostrar los turnos leídos
    for (const Turnos& turno : turnosLeidos) {
        std::cout << "ID: " << turno.getIdTurno() << " - Fecha: " << turno.getFecha().toString()
                  << " - Hora: " << turno.getHora() << " - Profesional ID: " << turno.getProfesionalID() << std::endl;
    }

    return 0;
}
*/
