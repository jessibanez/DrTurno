#include <iostream>
#include <ctime>
#include <sstream>
#include <iomanip>
#include <cstring>

#include "Agenda.h"
#include "AgendaArchivo.h"
#include "Turnos.h"
#include "Fecha.h"
#include "Globales.h"

using namespace std;

void Agenda::mostrarAgenda(int profesionalID, int dia, int mes, int anio)
{
    TurnosArchivo archivoLectura;
    Turnos* turnosParaMostrar;
    int cant=turnoArchivo.contarRegistros();
    turnosParaMostrar =new Turnos[cant];

    // Leer todas las agendas del archivo
    archivoLectura.leerTodos(turnosParaMostrar, cant);

    bool coincidenciasEncontradas = false;
    string nombre, apellido;
    Profesional profesional;
    profesional= profesionalArchivo.leerPorMatricula(profesionalID);
    if (profesional.getMatricula()==profesionalID)
    {
        nombre= profesional.getNombre();
        apellido=profesional.getApellido();
    }
    string mesDeTurno = mesEnLetras(mes);
    cout<<"AGENDA DEL PROFESIONAL: "<<nombre<< " "<<apellido<<endl;
    cout<<"Para el mes de: "<< mesDeTurno<<endl;

    // Obtener el mes actual
    time_t t = time(nullptr);
    tm* currentTime = localtime(&t);
    int mesActual = currentTime->tm_mon + 1;

    for (int i=0; i<cant; i++)
    {
        if (turnosParaMostrar[i].getMatricula() == profesionalID&&
                turnosParaMostrar[i].getFecha().getMes()==mes&&
                turnosParaMostrar[i].getFecha().getAnio()==anio&&
                turnosParaMostrar[i].getReservado()==false)
        {
            if (mes > mesActual || (mes == mesActual && turnosParaMostrar[i].getFecha().getDia() >= dia))
            {
                turnosParaMostrar[i].mostrarTurno();
                coincidenciasEncontradas = true;
            }
        }
    }
    if (!coincidenciasEncontradas)
    {
        cout << "No existen coincidencias, generando agenda..." << endl;
        generarAgendaMensual(profesionalID, mes, anio);

        cout << "Leo el archivo por 2da vez" << endl;
        // Volver a leer todas las agendas
        cant = archivoLectura.contarRegistros();
        delete[] turnosParaMostrar;
        turnosParaMostrar = new Turnos[cant];
        archivoLectura.leerTodos(turnosParaMostrar, cant);

        for (int i=0; i<cant; i++)
        {
            if (turnosParaMostrar[i].getMatricula() == profesionalID&&
                    turnosParaMostrar[i].getFecha().getMes()==mes&&
                    turnosParaMostrar[i].getFecha().getAnio()==anio&&
                    turnosParaMostrar[i].getReservado()==false)
            {
                if (mes > mesActual || (mes == mesActual && turnosParaMostrar[i].getFecha().getDia() >= dia))
                {
                    turnosParaMostrar[i].mostrarTurno();

                }
            }
        }
    }

    delete[] turnosParaMostrar;
    system("pause");
}

void Agenda::cargarHorarios(int profesionalID)
{
    _horarios.clear();

    int cantidad = horariosArchivo.contarRegistros();
    if (cantidad <= 0)
    {
        std::cerr << "Error: No hay registros de horarios disponibles." << std::endl;
        return;
    }

    Horarios* horarios = new (std::nothrow) Horarios[cantidad];
    if (horarios == nullptr)
    {
        std::cerr << "Error: No se pudo reservar memoria para los horarios." << std::endl;
        return;
    }

    horariosArchivo.leerTodos(horarios, cantidad);

    for (int i = 0; i < cantidad; i++)
    {
        if (horarios[i].getID() == profesionalID)
        {
            _horarios.push_back(horarios[i]);
        }
    }

    delete[] horarios;
}

void Agenda::generarAgendaMensual(int profesionalID, int mes, int anio)
{
    int dniPaciente = 0;

    cargarHorarios(profesionalID);

    int turnoID = 1;
    tm time_in = { 0, 0, 0, 1, mes - 1, anio - 1900 };
    time_t firstDay = mktime(&time_in);
    tm* day = localtime(&firstDay);

    for (int i = 0; i < 31; ++i)
    {
        day->tm_mday = i + 1;
        mktime(day);

        if (day->tm_mon != mes - 1) break;

        for (const auto& horario : _horarios)
        {
            if (horario.getDia() == day->tm_wday)
            {
                int horaInicio = horario.getHoraInicio();
                int horaFin = horario.getHoraFin();

                for (int hora = horaInicio; hora < horaFin; ++hora)
                {
                    for (int minuto = 0; minuto < 60; minuto += 30)
                    {
                        stringstream x;
                        x << setfill('0') << setw(2) << hora << ":" << setw(2) << minuto;
                        string horaString = x.str();
                        Fecha fecha(day->tm_mday, mes, anio);
                        Turnos turno;
                        turno.setMatricula(profesionalID);
                        turno.setFecha(fecha);
                        turno.setHora(horaString);
                        turno.setReservado(false);
                        turno.setIdTurno(turnoID++);
                        turno.setDniPaciente(dniPaciente);
                        turnoArchivo.guardar(turno);

                    }

                }

            }

        }
    }


    system ("pause");
}

void Agenda::reservarTurno(int profesionalID, int turnoID, int dni, int mes)
{
    TurnosArchivo archivoLectura;
    Turnos* turnosParaReservar;
    int cant=turnoArchivo.contarRegistros();
    turnosParaReservar =new Turnos[cant];

    // Leer todas las agendas del archivo
    archivoLectura.leerTodos(turnosParaReservar, cant);

    bool turnoEncontrado=false;

    for (int i=0; i<cant; i++)
    {
        if (turnosParaReservar[i].getIdTurno() == turnoID&&
                turnosParaReservar[i].getMatricula()==profesionalID&&
                turnosParaReservar[i].getFecha().getMes()==mes)
        {
            turnosParaReservar[i].setReservado(true);
            turnosParaReservar[i].setDniPaciente(dni);

            int pos=archivoLectura.buscarPorIdMesProfesional(turnoID, mes, profesionalID);
            if (pos!=-1)
            {
                archivoLectura.guardar(turnosParaReservar[i], pos);
                turnoEncontrado=true;
                cout<<"El turnos con ID "<<turnoID<<" ha sido reservado con exito"<<endl;
            }
            break;
        }

    }
    if(!turnoEncontrado)
    {
        cout<<"Error al reservar el turno, no ha sido encontrado"<<endl;
    }
    delete[] turnosParaReservar;

    system("pause");
}

///funcion para ver la atencion por mes

/// Verifico si un día es válido en un mes "x"
bool Agenda::diaEsValido(int dia, int mes)
{
    time_t t = time(nullptr);
    struct tm* now = localtime(&t);
    int anio = now->tm_year + 1900;

    if (mes == 2)
    {
        /// Si es año bisiesto
        if ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0))
        {
            return dia <= 29;
        }
        else
        {
            return dia <= 28;
        }
    }
    else if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
    {
        return dia <= 30;
    }
    else
    {
        return dia <= 31;
    }
}

///Día de la semana para una fecha "x"
int Agenda::obtenerDiaSemana(int dia, int mes)
{
    time_t t = time(nullptr);
    struct tm* now = localtime(&t);
    int anio = now->tm_year + 1900;

    tm time_in = { 0, 0, 0, dia, mes - 1, anio - 1900 };
    time_t time_temp = mktime(&time_in);

    const tm * time_out = localtime(&time_temp);
    int diaSemana = time_out->tm_wday; ///1:lunes, 2:marte, etc


    return diaSemana == 0 ? 7 : diaSemana; ///Si es domingo, devolver 7 para ignorar
}

