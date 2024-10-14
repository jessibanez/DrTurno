#ifndef AGENDAARCHIVO_H_INCLUDED
#define AGENDAARCHIVO_H_INCLUDED

#include "Agenda.h"
#include <vector>

class AgendaArchivo {
public:
    bool guardar(Agenda agenda);
    bool guardar(const Agenda& agenda, int nroRegistro);
    Agenda leerUno(int nroRegistro);
    int contarRegistros();
    int buscar(int profesionalID);
    void leerTodos(Agenda agendas[], int cantidad);
    vector<Agenda> leerTodo();
};

#endif // AGENDAARCHIVO_H_INCLUDED
