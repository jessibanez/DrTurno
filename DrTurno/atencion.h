#ifndef ATENCION_H_INCLUDED
#define ATENCION_H_INCLUDED
#include <string>
using namespace std;

class Atencion {
private:
    int _numDias;
    int _numHorarioInicio;
    int _horarioFin;
    string* _dias;
    string* _horarios;

    void liberarMemoria();

public:
    Atencion();
    ~Atencion();

    int getNumDias()const;
    int getNumHorarioInicio()const;
    int getHorarioFin()const;
    string getDias()const;
    string* getHorarios()const;

    void setNumDias(int numDias);
    void setNumHorarioInicio(int numHorarioInicio);
    void setHorarioFin(int horarioFin);
    void setDias(string* dias);
    void setHorarios(string* horarios);


    void seleccionarDias();
    void seleccionarHorarios();
    void mostrarDisponibilidad();
};


#endif // ATENCION_H_INCLUDED
