#ifndef PROFESIONAL_H_INCLUDED
#define PROFESIONAL_H_INCLUDED
#include <string>
#include "Usuario.h"

class Profesional: public Usuario {
private:
    char _especialidad[50];
    int _idEspecialidad;
    int _matricula;

public:
    Profesional();

    const char* getEspecialidad()const;
    void setEspecialidad(std::string especialidad);

    int getIDEspecialidad();
    void setIDEspecialidad(int idEspecialidad);

    int getMatricula()const;
    void setMatricula(int matricula);

    void cargar();
    void mostrar() ;
};


#endif // PROFESIONAL_H_INCLUDED
