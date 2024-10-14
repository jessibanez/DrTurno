#include "PacienteArchivo.h"
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>

bool PacienteArchivo::guardar(Paciente paciente){
    bool result;
    FILE *p;
    p = fopen("pacientes.dat", "ab");
    if (p == nullptr){
        return false;
    }
    result = fwrite(&paciente, sizeof(Paciente), 1, p);
    fclose(p);
    return result;
}

bool PacienteArchivo::guardar(Paciente paciente, int nroRegistro){
   bool result;
   FILE *p;

   p = fopen("pacientes.dat", "rb+");

   if(p == nullptr){

      return false;
   }

   fseek(p, sizeof(Paciente) * nroRegistro, SEEK_SET);

   result = fwrite(&paciente, sizeof (Paciente), 1, p);

   fclose(p);

   return result;
}

Paciente PacienteArchivo::leerUno(int nroRegistro){
    Paciente aux;
    FILE *p;
    p = fopen("pacientes.dat", "rb");
    if (p == nullptr){
        return aux;
    }

    fseek(p, nroRegistro*sizeof(Paciente), SEEK_SET);
    fread(&aux, sizeof(Paciente), 1, p);
    fclose(p);
    return aux;
}

int PacienteArchivo::contarRegistros(){
    FILE *pFile;
   int tam;

   pFile = fopen("pacientes.dat", "rb");

   if(pFile == nullptr){
      return 0;
   }

   fseek(pFile, 0, SEEK_END);

   tam = ftell(pFile) / sizeof (Paciente);

   fclose(pFile);

   return tam;
}

int PacienteArchivo::buscar(int dni){
    Paciente reg;
    int pos = 0;
    FILE * pFile;

    pFile = fopen("pacientes.dat", "rb");
    if(pFile == nullptr){
        return -1;
    }

    while(fread(&reg, sizeof(Paciente), 1, pFile)){
        if(reg.getDni() == dni){
            fclose(pFile);
            return pos;
        }
        pos++;
    }

    fclose(pFile);
    return -1;
}
int PacienteArchivo::buscarContra(char contrasenia[]){
    Paciente reg;
    int pos = 0;
    FILE * pFile;

    pFile = fopen("pacientes.dat", "rb");
    if(pFile == nullptr){
        return -1;
    }

    while(fread(&reg, sizeof(Paciente), 1, pFile)){
        if(strcmp(reg.getContrasenia(), contrasenia)){
            fclose(pFile);
            return pos;
        }
        pos++;
    }

    fclose(pFile);
    return -1;
}

Paciente PacienteArchivo::leerPorDNI(int dni) {
    Paciente paciente;
    FILE* pFile = fopen("pacientes.dat", "rb");
    if (pFile == nullptr) {
        paciente.setDni(-1);  // Indicar que no se encontró el paciente
        return paciente;
    }

    while (fread(&paciente, sizeof(Paciente), 1, pFile)) {
        if (paciente.getDni() == dni) {
            fclose(pFile);
            return paciente;
        }
    }

    fclose(pFile);
    paciente.setDni(-1);  // Indicar que no se encontró el paciente
    return paciente;
}

void PacienteArchivo::leerTodos(Paciente pacientes[], int cantidad){
   bool result;
   FILE *pFile;

   pFile = fopen("pacientes.dat", "rb");

   if(pFile == nullptr){
      return;
   }

   fread(pacientes, sizeof(Paciente), cantidad, pFile);

   fclose(pFile);
}

