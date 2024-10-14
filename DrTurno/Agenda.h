#ifndef AGENDA_H_INCLUDED
#define AGENDA_H_INCLUDED
#include <vector>
#include <map>
#include "Horarios.h"
#include "HorariosArchivo.h"
#include "Profesional.h"
#include "ProfesionalArchivo.h"
#include "Turnos.h"
#include "TurnosArchivo.h"

class Agenda{
private:
    ///Modo de visualización.

    ProfesionalArchivo profesionalArchivo;
    HorariosArchivo horariosArchivo;
    TurnosArchivo turnoArchivo;

    vector<Horarios> _horarios;


public:

    vector<Horarios> getHorarios() const { return _horarios; }

    void setHorarios(const vector<Horarios>& horarios) { _horarios = horarios; }

    void mostrarAgenda(int matricula, int dia, int mes, int anio);
    bool diaEsValido(int dia, int mes);
    int obtenerDiaSemana(int dia, int mes);
    void cargarHorarios(int profesionalID);
    void generarAgendaMensual(int profesionalID, int mes, int anio);
    void reservarTurno(int profesionalID, int turnoID, int dni, int mes);
    ///agrgado 24_7

    ///void cancelarTurnosProfesionalPorDia(int profesionalID, int dia, int mes, int anio, int dniPaciente);
    ///void verFechasDeAtencionProfesional(int profesionalID, int mes);
};


#endif // AGENDA_H_INCLUDED
