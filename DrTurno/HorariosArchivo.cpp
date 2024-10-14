#include "HorariosArchivo.h"
#include <cstdio>

bool HorariosArchivo::guardar(Horarios reg){
    FILE *p = fopen("horarios.dat", "ab");
    if (p == nullptr){
        return false;
    }
        bool result = fwrite(&reg, sizeof(Horarios), 1, p);
    fclose(p);
    return result;
}

bool HorariosArchivo::guardar(Horarios reg, int nroRegistro){
   FILE *p = fopen("horarios.dat", "rb+");

   if(p == nullptr){

      return false;
   }

   fseek(p, sizeof(Horarios) * nroRegistro, SEEK_SET);

   bool result = fwrite(&reg, sizeof (Horarios), 1, p);

   fclose(p);

   return result;
}

Horarios HorariosArchivo::leerUno(int nroRegistro){
    Horarios reg;
    FILE *p = fopen("horarios.dat", "rb");
    if (p == nullptr) {
        return reg;
    }
    fseek(p, nroRegistro * sizeof(Horarios), SEEK_SET);
    fread(&reg, sizeof(Horarios), 1, p);
    fclose(p);
    return reg;
}

int HorariosArchivo::contarRegistros(){
    FILE *pFile = fopen("horarios.dat", "rb");
    if (pFile == nullptr) {
        return 0;
    }
    fseek(pFile, 0, SEEK_END);
    int tam = ftell(pFile) / sizeof(Horarios);
    fclose(pFile);
    return tam;
}

int HorariosArchivo::buscar(int id){
   Horarios reg;
    int pos = 0;
    FILE *pFile = fopen("horarios.dat", "rb");
    if (pFile == nullptr) {
        return -1;
    }
    while (fread(&reg, sizeof(Horarios), 1, pFile)) {
        if (reg.getID() == id) {
            fclose(pFile);
            return pos;
        }
        pos++;
    }
    fclose(pFile);
    return -1;
}

Horarios HorariosArchivo::leerPorID(int id) {
     Horarios horario;
    FILE* pFile = fopen("horarios.dat", "rb");
    if (pFile == nullptr) {
        horario.setID(-1);  // Indicar que no se encontró el id
        return horario;
    }
    while (fread(&horario, sizeof(Horarios), 1, pFile)) {
        if (horario.getID() == id) {
            fclose(pFile);
            return horario;
        }
    }
    fclose(pFile);
    horario.setID(-1);  // Indicar que no se encontró el id
    return horario;
}

void HorariosArchivo::leerTodos(Horarios horarios[], int cantidad){
   FILE *pFile = fopen("horarios.dat", "rb");
    if (pFile == nullptr) {
        return;
    }
    fread(horarios, sizeof(Horarios), cantidad, pFile);
    fclose(pFile);
}


