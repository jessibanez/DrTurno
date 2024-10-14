#pragma once
#include <string>
#include <cstdio>
using namespace std;
#include "Profesional.h"

class ProfesionalArchivo {
public:
    bool guardar(Profesional profesional);
    bool guardar (Profesional profesional, int nroRegisttro);
    int contarRegistros();
    int buscar(int dni);
    int buscarPorID(int id);
    Profesional leer(int Registro);
    Profesional leerPorDni(int dni);
    Profesional leerPorMatricula(int matricula);
    void leerTodos(Profesional profesionales[], int cant);
    bool borrarDatos ();
    bool modificarProfesional(Profesional profesional);
    bool agregarProfesional(Profesional profesional);
private:

};


