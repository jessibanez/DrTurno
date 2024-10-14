#ifndef PACIENTEARCHIVO_H_INCLUDED
#define PACIENTEARCHIVO_H_INCLUDED
#include <string>
#include <cstdio>
using namespace std;
#include "Paciente.h"

class PacienteArchivo{
    public:
        bool guardar(Paciente paciente);
        bool guardar(Paciente paciente, int nroRegistro);
        int contarRegistros();
        int buscar(int dni);
        Paciente leerUno(int nroRegistro);
        Paciente leerPorDNI(int dni);
        void leerTodos(Paciente pacientes[], int cantidad);
        int buscarContra(char contrasenia[]);
    private:

};


#endif // PACIENTEARCHIVO_H_INCLUDED
