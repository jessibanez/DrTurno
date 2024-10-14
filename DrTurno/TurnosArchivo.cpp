#include "TurnosArchivo.h"
#include <iostream>
#include <cstdio>

bool TurnosArchivo::guardar(Turnos turno){
    bool result;
    FILE *p = fopen("turnos.dat", "ab");
    if (p == nullptr){
        return false;
    }
    result = fwrite(&turno, sizeof(Turnos), 1, p);
    fclose(p);
    return result;
}

 int TurnosArchivo::contarRegistros(){
 FILE *pFile;
   int tam;

   pFile = fopen("turnos.dat", "rb");

   if(pFile == nullptr){
      return 0;
   }

   fseek(pFile, 0, SEEK_END);
   tam = ftell(pFile) / sizeof (Turnos);
   fclose(pFile);

   return tam;

 }

int TurnosArchivo::buscarPorIdMesProfesional(int id, int mes, int matricula){
  Turnos reg;
    int pos = 0;
    FILE * pFile = fopen("turnos.dat", "rb");
    if(pFile == nullptr){
        return -1;
    }

    while(fread(&reg, sizeof(Turnos), 1, pFile)){
        if(reg.getIdTurno()== id&&
           reg.getFecha().getMes()==mes&&
           reg.getMatricula()==matricula){
            fclose(pFile);
            return pos;
        }
        pos++;

    }
        fclose(pFile);
    return -1;
}

Turnos TurnosArchivo::leer(int Reg){
 Turnos aux;
    FILE *p;
    p= fopen("turnos.dat", "rb");

    if (p == nullptr){
        return aux;
    }

    fseek(p, Reg*sizeof(Turnos), SEEK_SET);
    fread(&aux, sizeof(Turnos), 1, p);
    fclose(p);
    return aux;

}

void TurnosArchivo::leerTodos(Turnos turnos[], int cant){
FILE *pFile= fopen("turnos.dat", "rb");

   if(pFile == nullptr){
      return;
   }

   fread(turnos, sizeof(Turnos), cant, pFile);

   fclose(pFile);

}

bool TurnosArchivo::guardar(Turnos turno, int nroRegistro){
   bool result;
   FILE *p = fopen("turnos.dat", "rb+");

   if(p == nullptr){
      return false;
   }

   fseek(p, sizeof(Turnos) * nroRegistro, SEEK_SET);
   result = fwrite(&turno, sizeof (Turnos), 1, p);
   fclose(p);

   return result;
}
///agregado 24_7
int TurnosArchivo::buscarPorIdMesProfesionalP(int id, int mes, int matricula, int dniPaciente) {
    Turnos reg;
    int pos = 0;
    FILE * pFile = fopen("turnos.dat", "rb");
    if(pFile == nullptr){
        return -1;
    }

    while(fread(&reg, sizeof(Turnos), 1, pFile)){
        if(reg.getIdTurno() == id &&
           reg.getFecha().getMes() == mes &&
           reg.getMatricula() == matricula &&
           reg.getDniPaciente() == dniPaciente){ // Comparar el DNI del paciente
            fclose(pFile);
            return pos;
        }
        pos++;
    }
    fclose(pFile);
    return -1;
}
