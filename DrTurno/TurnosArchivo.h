#ifndef TURNOSARCHIVO_H_INCLUDED
#define TURNOSARCHIVO_H_INCLUDED
#include <string>
#include <cstdio>
#include <vector>

#include "Turnos.h"
using namespace std;

class TurnosArchivo {
public:
    bool guardar(Turnos reg);
    int contarRegistros();
    int buscarPorIdMesProfesional(int id, int mes, int matricula);
    Turnos leer(int Reg);
    void leerTodos(Turnos turnos[], int cant);
    bool guardar(Turnos turno, int nroRegistro);

    int buscarPorIdMesProfesionalP(int id, int mes, int matricula, int dniPaciente);

};

#endif // TURNOSARCHIVO_H_INCLUDED
