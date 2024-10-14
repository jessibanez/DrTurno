#include <iostream>
#include <cstring>
#include<string>
#include <ctime>

#include "Turnos.h"
#include "TurnosArchivo.h"
#include "Fecha.h"
#include "ProfesionalArchivo.h"
#include "profesional.h"

using namespace std;
///3er intento
///4to intento, cambié "const string& Hora", saqué &
Turnos::Turnos()
: _matricula(0), _fecha(1,1,1), _hora("0"), _reservado(false), _idTurno(0), _dniPaciente(0){}

Turnos::Turnos(int profesionalID, Fecha fecha, std::string hora, bool reservado, int idTurno, int dniPaciente)
        : _fecha(1,1,1)
{
setMatricula(profesionalID);
setFecha(fecha);
setHora(hora);
setReservado(reservado);
setIdTurno(idTurno);
setDniPaciente(dniPaciente);
        }

int Turnos::getMatricula() const {
    return _matricula;
}
void Turnos::setMatricula(int profesionalID) {
     _matricula = profesionalID;
}

Fecha Turnos::getFecha()const{
   return _fecha;
}

void Turnos::setFecha(Fecha fecha){
   _fecha = fecha;
}

const char* Turnos::getHora() const {
    return _hora;
}

void Turnos::setHora(std::string hora) {
     strcpy(_hora, hora.c_str());
}

bool Turnos::getReservado() const {
    return _reservado;
}
void Turnos::setReservado(bool reservado) {
    _reservado = reservado;
}

int Turnos::getIdTurno() const {
    return _idTurno;
}
void Turnos::setIdTurno(int ID) {
    _idTurno = ID;
}

int Turnos::getDniPaciente() const {
    return _dniPaciente;
}
void Turnos::setDniPaciente(int dniPaciente) {
    _dniPaciente = dniPaciente;
}

void Turnos::cargar() {
    cout << "Matricula: ";
    cin >> _matricula;
    cout << "DNI Paciente: ";
    cin >> _dniPaciente;
    cout<<"Fecha: ";
       int dia, mes, anio;
    cout<<"Dia: ";
    cin>>dia;
    cout<<"Mes: ";
    cin>>mes;
    cout<<"Anio (4 digitos): ";
    cin>>anio;
    _fecha.setDia(dia);
    _fecha.setMes(mes);
    _fecha.setAnio(anio);
    cout << "Hora (hh:mm): ";
    cin.ignore();
    cin.getline(_hora,10);
    cout << "Reservado (1: Si, 0: No): ";
    cin >> _reservado;
}

void Turnos::mostrarTurno() const {
    cout << "ID Turno: "<<_idTurno<<endl;
    cout <<"Fecha: "<<_fecha.toString()<<endl;
    cout << "Hora: " << _hora <<endl;
    cout<<"-------------------------------------"<<endl;
}
void Turnos::mostrarTurnoReservado() const {
   Profesional profesional;
   ProfesionalArchivo profesionalArchivo;
   profesional= profesionalArchivo.leerPorMatricula(getMatricula());
    string nombre, apellido;
    if (profesional.getMatricula()==getMatricula())
    {
        nombre= profesional.getNombre();
        apellido=profesional.getApellido();
    }


    cout << "Turno reservado:" <<endl;
    cout << "ID del Turno: " << getIdTurno() <<endl;
    cout << "Profesional: "<<nombre<<" "<<apellido<<endl;
    cout << "Matricula del Profesional: " << getMatricula() <<endl;
    cout << "Fecha: " << getFecha().toString() <<endl;
    cout << "Hora: " << getHora() <<endl;
    cout << "DNI del Paciente: " << getDniPaciente() <<endl;
}

void Turnos::mostrarTurnoReservadoFuturo(int dniPaciente) {
    TurnosArchivo archivoLectura;
    Turnos* turnosParaMostrar;
    int cant = archivoLectura.contarRegistros();
    turnosParaMostrar = new Turnos[cant];

    // Leer todas las agendas del archivo
    archivoLectura.leerTodos(turnosParaMostrar, cant);

    ///Tomo la fecha del sistema.
    time_t t = time(nullptr);
                tm* now = localtime(&t);
                int anioActual = now->tm_year + 1900;
                int diaActual = now->tm_mday;
                int mesActual = now->tm_mon +1;

    bool turnoEncontrado = false;

  for (int i = 0; i < cant; i++) {
        if (turnosParaMostrar[i].getDniPaciente() == dniPaciente) {
            int anioTurno = turnosParaMostrar[i].getFecha().getAnio();
            int mesTurno = turnosParaMostrar[i].getFecha().getMes();
            int diaTurno = turnosParaMostrar[i].getFecha().getDia();

            // Comparar fechas
            if (anioTurno > anioActual ||
                (anioTurno == anioActual && mesTurno > mesActual) ||
                (anioTurno == anioActual && mesTurno == mesActual && diaTurno >= diaActual)) {
                cout << "--------------------------" << endl;
                turnosParaMostrar[i].mostrarTurnoReservado();
                cout << "--------------------------" << endl;
                turnoEncontrado = true;
            }
        }
    }

    if (!turnoEncontrado) {
        cout << "No se ha encontrado un turno reservado para el paciente con DNI " << dniPaciente << std::endl;
    }

    delete[] turnosParaMostrar;
    system("pause");
}

void Turnos::mostrarTurnoReservadoPasado(int dniPaciente) {
    TurnosArchivo archivoLectura;
    Turnos* turnosParaMostrar;
    int cant = archivoLectura.contarRegistros();
    turnosParaMostrar = new Turnos[cant];

    // Leer todas las agendas del archivo
    archivoLectura.leerTodos(turnosParaMostrar, cant);

    // Tomar la fecha del sistema
    time_t t = time(nullptr);
    tm* now = localtime(&t);
    int anioActual = now->tm_year + 1900;
    int mesActual = now->tm_mon + 1; // tm_mon es 0-based
    int diaActual = now->tm_mday;

    bool turnoEncontrado = false;

    for (int i = 0; i < cant; i++) {
        if (turnosParaMostrar[i].getDniPaciente() == dniPaciente) {
            int anioTurno = turnosParaMostrar[i].getFecha().getAnio();
            int mesTurno = turnosParaMostrar[i].getFecha().getMes();
            int diaTurno = turnosParaMostrar[i].getFecha().getDia();

            // Comparar fechas
            if (anioTurno < anioActual ||
                (anioTurno == anioActual && mesTurno < mesActual) ||
                (anioTurno == anioActual && mesTurno == mesActual && diaTurno < diaActual)) {
                cout << "--------------------------" << endl;
                turnosParaMostrar[i].mostrarTurnoReservado();
                cout << "--------------------------" << endl;
                turnoEncontrado = true;
            }
        }
    }

    if (!turnoEncontrado) {
        cout << "No se ha encontrado un turno reservado anterior a la fecha actual para el paciente con DNI " << dniPaciente << std::endl;
    }

    delete[] turnosParaMostrar;
    system("pause");
}

void Turnos::cancelarTurnoPaciente(int dniPaciente, int idTurno) {
    TurnosArchivo archivoLectura;
    Turnos* turnosParaCancelar;
    int cant = archivoLectura.contarRegistros();
    turnosParaCancelar = new Turnos[cant];

    // Leer todas las agendas del archivo
    archivoLectura.leerTodos(turnosParaCancelar, cant);

    bool turnoEncontrado = false;

    for (int i = 0; i < cant; i++) {
        if (turnosParaCancelar[i].getDniPaciente() == dniPaciente &&
            turnosParaCancelar[i].getIdTurno() == idTurno &&
            turnosParaCancelar[i].getReservado()==true) {
            turnosParaCancelar[i].setReservado(false);
            turnosParaCancelar[i].setDniPaciente(0);

            int pos = archivoLectura.buscarPorIdMesProfesional(turnosParaCancelar[i].getIdTurno(), turnosParaCancelar[i].getFecha().getMes(), turnosParaCancelar[i].getMatricula());
            if (pos != -1) {
                archivoLectura.guardar(turnosParaCancelar[i], pos);
                turnoEncontrado = true;
                std::cout << "El turno ha sido cancelado con exito." << std::endl;
            }
            break;
        }
    }

    if (!turnoEncontrado) {
        std::cout << "No se ha encontrado un turno reservado para el paciente con DNI " << dniPaciente << " y ID de turno " << idTurno << std::endl;
    }

    delete[] turnosParaCancelar;
    system("pause");
}

