#ifndef GLOBALES_H_INCLUDED
#define GLOBALES_H_INCLUDED
#include <cstring>
#include "Paciente.h"
#include "PacienteArchivo.h"
#include "Administrador.h"

 void inicioDeSesion(PacienteArchivo& archivo, Administrador Administradores[], int adminTam);
 std::pair<int, std::string> selectorDeEspecialidad();
 string seleccionarDiasDeLaSemana();
 string diaEnLetras(int dia);
 string mesEnLetras(int mes);
#endif // GLOBALES_H_INCLUDED
