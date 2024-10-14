#ifndef TURNOS_H
#define TURNOS_H
#include "Fecha.h"

#include <string>
///#include "Fecha.h" ///del 2do intento
///3er intento
using namespace std;
class Turnos {
private:
    int _matricula; ///Cambiar a Matricula ///Enlace a archivos profesional
    Fecha _fecha;
    char _hora[10];
    bool _reservado;
    int _idTurno;///Enlace a pacientes
    int _dniPaciente; ///Enlace a archivos de paciente

public:
    Turnos();
    Turnos(int matricula, Fecha fecha, std::string hora, bool reservado, int idTurno, int dniPaciente);

    int getMatricula() const;
    void setMatricula(int matricula);

    Fecha getFecha() const;
    void setFecha(Fecha fecha);

    ///Cambiar
    const char* getHora() const;
    void setHora(std:: string hora);

    bool getReservado() const;
    void setReservado(bool reservado);

    int getIdTurno() const;
    void setIdTurno(int ID);

    int getDniPaciente() const;
    void setDniPaciente(int dniPaciente);

    void cargar();
    void mostrarTurno() const;
    void mostrarTurnoReservado() const;
    void mostrarTurnoReservadoFuturo(int dniPaciente);
    void mostrarTurnoReservadoPasado(int dniPaciente);
    void cancelarTurnoPaciente(int dniPaciente, int idTurno);
};


#endif // TURNOS_H
