#ifndef ADMINISTRADORMANAGER_H_INCLUDED
#define ADMINISTRADORMANAGER_H_INCLUDED
#include "Administrador.h"
#include "PacienteArchivo.h"
#include "ProfesionalArchivo.h"
#include "Horarios.h"

class AdministradorManager{
private:

public:
    ///MENU
    void menu();
    void menuProfesionales();
    void menuPacientes();
    void menuInformes();
    ///PACIENTES
    void cargarPaciente();
    void eliminarPaciente();
    void modificarPaciente();
    ///PROFESIONALES
    void cargarProfesional();
    void cargarHorariosProfesional();
    void modificarDatosPersonalesProfesional();
    void cargarDatosPersonalesNuevos(Profesional& profesional);
    void modificarDiasHorariosDeAtencion();
    void modificarAtencion(Horarios& horario);
    void mostrarPacientesABC();
    void mostrarProfesionalesABC();
    void listarTodos();
    void mostrar(const Profesional& profesional) const;
    void cancelarTurnosProfesionalPorDia(int profesionalID, int dia, int mes, int anio);
    void cancelarTurnosProfesionalPorPeriodo(int profesionalID, int diaInicio, int diaFin, int mes, int anio);
    ///INFORMES
    void verFechasDeAtencionProfesional(int profesionalID, int mes);
    void mostrarTurnosReservadosSemanaActual();
    void verTurnosSolicitadosDeProfesional();
    void verTurnosSolicitadosPorPaciente();
};


#endif // ADMINISTRADORMANAGER_H_INCLUDED
