#ifndef PACIENTEMANAGER_H_INCLUDED
#define PACIENTEMANAGER_H_INCLUDED
#include "PacienteArchivo.h"

class PacienteManager{

    private:


    public:
        void menu(Paciente& paciente);
        Paciente cargarNuevo();
        void mostrar(const Paciente& paciente)const;///Se pasa por referencia para que no se pierdan datos
         void modificarDatos();
        void menuTurnos();
        void menuInformes(int dniPaciente);
        void menuHistorial();
        void listarTodosPorAlfabeto(bool ordernarABC);
        void ordenarAlfabeticamente(Paciente pacientes[], int cantidad);
        void listarTodosPorEdad();
        void cargarDatosNuevos(Paciente& paciente);
        void buscarEspecialista();
        void reservarTurno();
        void cancelarTurno();
        void reprogramarTurno();
        void mostrarMisTurnos(int dniPaciente);
};



#endif // PACIENTEMANAGER_H_INCLUDED
