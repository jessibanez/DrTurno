#include "atencion.h"
#include <iostream>
#include <sstream>///librería para función ostringstream
#include <string>

/*
Atencion::Atencion() {
    _numDias = 0;
    _numHorarioInicio = 0;
    _horarioFin = 0;
    _dias = nullptr;
    _horarios = nullptr;
}
*/

void Atencion::liberarMemoria() {
       if (_dias) {
        delete[] _dias;
        _dias = nullptr;
    }
    if (_horarios) {
        delete[] _horarios;
        _horarios = nullptr;
    }
}
///Constructor
Atencion::Atencion() : _numDias(0), _numHorarioInicio(0), _horarioFin(0), _dias(nullptr), _horarios(nullptr) {}

/// Destructor
Atencion::~Atencion() {
    liberarMemoria();
}


int Atencion::getNumDias()const {
    return _numDias;
}

int Atencion::getNumHorarioInicio() const{
    return _numHorarioInicio;
}

int Atencion::getHorarioFin() const {
    return _horarioFin;
}

 string Atencion::getDias() const {
        string diasStr;
        for (int i = 0; i < _numDias; ++i) {
            diasStr += _dias[i] + " ";
        }
        return diasStr;
    }

/*
std::string Atencion::getDias() const{
std::ostringstream diasStream;///ostringstream Crea una cadena de texto, para poder mostrarlo por pantalla, posteriormente.

    for (int i = 0; i < _numDias; ++i) {
        diasStream << _dias[i];
        if (i < _numDias - 1) {
            diasStream << ", ";
        }
    }

    return diasStream.str();
}

string* Atencion::getDias() const {
    return _dias;
}
*/
string* Atencion::getHorarios() const{
    return _horarios;
}


void Atencion::setNumDias(int numDias) {
    _numDias = numDias;
}

void Atencion::setNumHorarioInicio(int numHorarioInicio) {
    _numHorarioInicio = numHorarioInicio;
}

void Atencion::setHorarioFin(int horarioFin) {
    _horarioFin = horarioFin;
}


void Atencion::setDias(string* dias) {
     if (_dias) {
        delete[] _dias;
    }
    _dias = new string[_numDias];
    for (int i = 0; i < _numDias; ++i) {
        _dias[i] = dias[i];
    }
  /*delete[] _dias;
    _dias = dias; */
}


void Atencion::setHorarios(string* horarios) {
     if (_horarios) {
        delete[] _horarios;
    }
    _horarios = new string[_numHorarioInicio];
    for (int i = 0; i < _numHorarioInicio; ++i) {
        _horarios[i] = horarios[i];
    }
   /* delete[] _horarios;
    _horarios = horarios; */
}

// Métodos
void Atencion::seleccionarDias() {
    cout << "Ingrese el numero de dias de atencion: ";
    cin >> _numDias;

 if (_dias) { ///PRUEBA para liberar memoria, fallas en mostrar
    delete[] _dias;
 }
    _dias = new string[_numDias];

    cout << "Ingrese los dias de la semana de atencion:" << endl;
    for (int i = 0; i < _numDias; ++i) {
        cout << "Día " << i + 1 << ": ";
        cin >> _dias[i];
    }
}

void Atencion::seleccionarHorarios() {
    cout << "Ingrese la hora de inicio de atencion (en formato 24 horas): ";
    cin >> _numHorarioInicio;

    cout << "Ingrese la hora de fin de atencion (en formato 24 horas): ";
    cin >> _horarioFin;
}

void Atencion::mostrarDisponibilidad() {
  cout << "Dias de atencion: " << getDias() <<endl;
  cout << "Horario de inicio: " << getNumHorarioInicio() <<endl;
  cout << "Horario de finalizacion: " << getHorarioFin() <<endl;
}
