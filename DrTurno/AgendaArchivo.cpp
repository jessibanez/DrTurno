#include "AgendaArchivo.h"
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
/*
bool AgendaArchivo::guardar(Agenda agenda) {
    FILE* p = fopen("agendas.dat", "ab");
    if (p == nullptr) {
        return false;
    }

    // Guardar datos básicos de la agenda
    int idProfesional = agenda.getIdProfesional();
    fwrite(&idProfesional, sizeof(int), 1, p);

    // Guardar nombre y apellido como cadenas de longitud fija (por ejemplo, 100 caracteres)
    std::string nombreProfesional = agenda.getNombreProfesional();
    std::string apellidoProfesional = agenda.getApellidoProfesional();
    char nombre[100] = {0};
    strncpy(nombre, nombreProfesional.c_str(), sizeof(nombre) - 1);
    fwrite(nombre, sizeof(nombre), 1, p);
    char apellido[100] = {0};
    strncpy(apellido, apellidoProfesional.c_str(), sizeof(apellido) - 1);
    fwrite(apellido, sizeof(apellido), 1, p);

    // Guardar cantidad de turnos y cada turno
    int cantidadTurnos = agenda.getTurnos().size();
    fwrite(&cantidadTurnos, sizeof(int), 1, p);
    for (const auto& turno : agenda.getTurnos()) {
        fwrite(&turno, sizeof(Turnos), 1, p);
    }

    // Guardar cantidad de horarios y cada horario
    int cantidadHorarios = agenda.getHorarios().size();
    fwrite(&cantidadHorarios, sizeof(int), 1, p);
    for (const auto& horario : agenda.getHorarios()) {
        fwrite(&horario, sizeof(Horarios), 1, p);
    }

    fclose(p);

    return true;

}*/
///BUEN INTENTO

bool AgendaArchivo::guardar(Agenda agenda) {
    FILE* p = fopen("agendas.dat", "ab");
    if (p == nullptr) {
        return false;
    }

    // Guardar datos básicos de la agenda
    int idProfesional = agenda.getIdProfesional();
    string nombreProfesional = agenda.getNombreProfesional();
    string apellidoProfesional = agenda.getApellidoProfesional();

    fwrite(&idProfesional, sizeof(int), 1, p);
    cout << "Guardando ID Profesional: " << idProfesional << endl;

    // Guardar nombre y apellido como cadenas de longitud fija (por ejemplo, 100 caracteres)
    char nombre[50] = {0};
    strncpy(nombre, nombreProfesional.c_str(), sizeof(nombre) - 1);
    fwrite(nombre, sizeof(nombre), 1, p);
    cout << "Guardando Nombre Profesional: " << nombre << endl;

    char apellido[50] = {0};
    strncpy(apellido, apellidoProfesional.c_str(), sizeof(apellido) - 1);
    fwrite(apellido, sizeof(apellido), 1, p);
    cout << "Guardando Apellido Profesional: " << apellido << endl;

     // Guardar cantidad de horarios y cada horario
    int cantidadHorarios = agenda.getHorarios().size();
    fwrite(&cantidadHorarios, sizeof(int), 1, p);
    cout << "Guardando cantidad de horarios: " << cantidadHorarios << endl;
    for (const auto& horario : agenda.getHorarios()) {
        fwrite(&horario, sizeof(Horarios), 1, p);
    }

    // Guardar cantidad de turnos y cada turno
    int cantidadTurnos = agenda.getTurnos().size();
    fwrite(&cantidadTurnos, sizeof(int), 1, p);
    cout << "Guardando cantidad de turnos: " << cantidadTurnos <<endl;
    for (const auto& turno : agenda.getTurnos()) {
        fwrite(&turno, sizeof(Turnos), 1, p);
    }



    fclose(p);
    return true;
}


/*
bool AgendaArchivo::guardar(Agenda agenda) {
    FILE* p = fopen("agendas.dat", "ab");
    if (p == nullptr) {
        return false;
    }
    bool result = fwrite(&agenda, sizeof(Agenda), 1, p);
    fclose(p);
    return result;
}*/

bool AgendaArchivo::guardar(const Agenda& agenda, int nroRegistro) {
    FILE* p = fopen("agendas.dat", "rb+");
    if (p == nullptr) {
        return false;
    }
    fseek(p, sizeof(Agenda) * nroRegistro, SEEK_SET);
    bool result = fwrite(&agenda, sizeof(Agenda), 1, p);
    fclose(p);
    return result;
}

Agenda AgendaArchivo::leerUno(int nroRegistro) {
    Agenda agenda;
    FILE* p = fopen("agendas.dat", "rb");
    if (p == nullptr) {
        return agenda;
    }
    fseek(p, nroRegistro * sizeof(Agenda), SEEK_SET);
    fread(&agenda, sizeof(Agenda), 1, p);
    fclose(p);
    return agenda;
}

int AgendaArchivo::contarRegistros() {
    FILE* pFile = fopen("agendas.dat", "rb");
    if (pFile == nullptr) {
        return 0;
    }
    fseek(pFile, 0, SEEK_END);
    int tam = ftell(pFile) / sizeof(Agenda);
    fclose(pFile);
    return tam;
}

int AgendaArchivo::buscar(int profesionalID) {
    Agenda agenda;
    int pos = 0;
    FILE* pFile = fopen("agendas.dat", "rb");
    if (pFile == nullptr) {
        return -1;
    }
    while (fread(&agenda, sizeof(Agenda), 1, pFile)) {
        if (agenda.getIdProfesional() == profesionalID) {
            fclose(pFile);
            return pos;
        }
        pos++;
    }
    fclose(pFile);
    return -1;
}

void AgendaArchivo::leerTodos(Agenda agenda[], int cantidad) {
    cout<<"Ingresando en el archivo de agendas"<<endl;
    FILE *pFile;
    pFile= fopen("agendas.dat", "rb");
    if (pFile == nullptr) {
        return;
    }
cout<<"El archivo se abrio" <<endl;

    for (int i = 0; i < cantidad; ++i) {
        int idProfesional;
        if (fread(&idProfesional, sizeof(int), 1, pFile) != 1) {
            cout<<"ERROR AL LEER"<<endl;
                break;}
        agenda[i].setIdProfesional(idProfesional);
cout<<"ID "<<endl;
        char nombre[100];
        if (fread(nombre, sizeof(nombre), 1, pFile) != 1) {
               cout<<"ERROR AL LEER"<<endl;
                break;}
        agenda[i].setNombreProfesional(string(nombre));
cout<<"Nombre "<<nombre<<endl;
        char apellido[100];
        if (fread(apellido, sizeof(apellido), 1, pFile) != 1) {
                cout<<"ERROR AL LEER"<<endl;    break;}
        agenda[i].setApellidoProfesional(string(apellido));
cout<<"Apellido "<<endl;
        int horariosSize;
        if (fread(&horariosSize, sizeof(int), 1, pFile) != 1) break;
        if (horariosSize < 0 || horariosSize > 1000) {
                cout<<"ERROR AL LEER"<<endl;    break;}
cout<<"----Cantidad de horarios: "<<horariosSize<<endl;
        vector<Horarios> horarios(horariosSize);
        for (int j = 0; j < horariosSize; ++j) {
            if (fread(&horarios[j], sizeof(Horarios), 1, pFile) != 1) {
                    cout<<"ERROR AL LEER"<<endl;    break;}
        }
        agenda[i].setHorarios(horarios);

        int turnosSize;
        if (fread(&turnosSize, sizeof(int), 1, pFile) != 1) {
                cout<<"ERROR AL LEER"<<endl;    break;}
        if (turnosSize < 0 || turnosSize > 1000) break;
cout<<"----Cantidad de turnos: "<<turnosSize<<endl;
        vector<Turnos> turnos(turnosSize);
        for (int j = 0; j < turnosSize; ++j) {
            if (fread(&turnos[j], sizeof(Turnos), 1, pFile) != 1) {
                    cout<<"ERROR AL LEER"<<endl;    break;}
        }
cout<<"----Cargo el vector" <<endl;
        agenda[i].setTurnos(turnos);
        agenda[i].mostrar();
    }

    fclose(pFile);
cout<<"Se cierra el archivo"<<endl;
}

///INTENTO NRO 12938239483
/*
vector<Agenda> AgendaArchivo::leerTodo() {
    vector<Agenda> agendas;
    FILE* p = fopen("agendas.dat", "rb");
    if (p == nullptr) {
        std::cerr << "Error: No se pudo abrir el archivo agendas.dat" << std::endl;
        return agendas;
    }
    cout << "Se abrio el archivo" <<endl;

    while (!feof(p)) {
        Agenda agenda;

        // Leer los datos básicos de Agenda
        int idProfesional;
        if (fread(&idProfesional, sizeof(idProfesional), 1, p) != 1) {
            break; // Salir si no se pueden leer los datos básicos
        }
        agenda.setIdProfesional(idProfesional);
        cout << "Cargo el ID" <<endl;

        // Leer el nombre y apellido como cadenas de caracteres de tamaño fijo
        char nombre[50];
        if (fread(nombre, sizeof(nombre), 1, p) != 1) {
            break; // Salir si no se pueden leer los datos
        }
        agenda.setNombreProfesional(string(nombre));
        cout << "Cargo el Nombre" << endl;

        char apellido[50];
        if (fread(apellido, sizeof(apellido), 1, p) != 1) {
            break; // Salir si no se pueden leer los datos
        }
        agenda.setApellidoProfesional(string(apellido));
        cout << "Cargo el Apellido" <<endl;

        // Leer el tamaño y contenido de los vectores
        size_t horariosSize;
        if (fread(&horariosSize, sizeof(horariosSize), 1, p) != 1) {
            break; // Salir si no se puede leer el tamaño
        }
        cout << "Tamaño de Horarios: " << horariosSize <<endl;

        // Limitar el tamaño de los horarios para evitar asignaciones excesivas
        if (horariosSize > 1000) {  // Asume que 1000 es un número razonable para el tamaño máximo
            cout << "Error: Tamaño de horarios inusualmente grande" <<endl;
            break;
        }

        vector<Horarios> horarios(horariosSize);
        for (size_t i = 0; i < horariosSize; ++i) {
            if (fread(&horarios[i], sizeof(Horarios), 1, p) != 1) {
                break; // Salir si no se pueden leer los datos
            }
        }
        agenda.setHorarios(horarios);
        cout << "Cargo el HORARIOS" <<endl;

        size_t turnosSize;
        if (fread(&turnosSize, sizeof(turnosSize), 1, p) != 1) {
            break; // Salir si no se puede leer el tamaño
        }
        cout << "Tamaño de Turnos: " << turnosSize <<endl;

        // Limitar el tamaño de los turnos para evitar asignaciones excesivas
        if (turnosSize > 1000) {  // Asume que 1000 es un número razonable para el tamaño máximo
            cout << "Error: Tamaño de turnos inusualmente grande" <<endl;
            break;
        }

        vector<Turnos> turnos(turnosSize);
        for (size_t i = 0; i < turnosSize; ++i) {
            if (fread(&turnos[i], sizeof(Turnos), 1, p) != 1) {
                break; // Salir si no se pueden leer los datos
            }
        }
        agenda.setTurnos(turnos);
        cout << "Cargo TURNOS" <<endl;

        agendas.push_back(agenda);
    }

    fclose(p);
    cout << "Se leyeron " << agendas.size() << " agendas del archivo." <<endl;
    return agendas;
}
*/

/*
void AgendaArchivo::leerTodos(Agenda agendas[], int cantidad) {
    /*bool result;
    FILE *pFile;

    pFile = fopen("agendas.dat", "rb");
    if (pFile == nullptr) {
        return;
    }
        fread(agendas, sizeof(Agenda), cantidad, pFile);

    fclose(pFile);
    */
    ///Segundo intento
   /*
    FILE* pFile;
    pFile = fopen("agendas.dat", "rb");
    if (pFile == nullptr) {
        cout << "No se pudo abrir el archivo agendas.dat para leer." <<endl;
        return;
    }

    size_t result = fread(agendas, sizeof(Agenda), cantidad, pFile);
    if (result != cantidad) {
        cout << "Error al leer las agendas del archivo." <<endl;
    }

    fclose(pFile);
}
*/
