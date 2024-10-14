#ifndef HORARIOSARCHIVO_H_INCLUDED
#define HORARIOSARCHIVO_H_INCLUDED
#include <string>
#include <cstdio>

#include "Horarios.h"

class HorariosArchivo{
    public:
        bool guardar(Horarios reg);
        bool guardar(Horarios reg, int nroRegistro);
        int contarRegistros();
        int buscar(int id);
        Horarios leerUno(int nroRegistro);
        Horarios leerPorID(int id);
        void leerTodos(Horarios horarios[], int cantidad);

    private:

};


#endif // HORARIOSARCHIVO_H_INCLUDED
