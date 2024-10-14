#include "ProfesionalArchivo.h"
#include <cstdio>


int ProfesionalArchivo::contarRegistros(){
    FILE *pFile;
   int tam;

   pFile = fopen("profesionales.dat", "rb");

   if(pFile == nullptr){
      return 0;
   }

   fseek(pFile, 0, SEEK_END);
   tam = ftell(pFile) / sizeof (Profesional);
   fclose(pFile);

   return tam;
}

bool ProfesionalArchivo::guardar(Profesional profesional){
    bool result;
    FILE *p = fopen("profesionales.dat", "ab");
    if (p == nullptr){
        return false;
    }
    result = fwrite(&profesional, sizeof(Profesional), 1, p);
    fclose(p);
    return result;
}

bool ProfesionalArchivo::guardar(Profesional profesional, int nroRegistro){
   bool result;
   FILE *p = fopen("profesionales.dat", "rb+");

   if(p == nullptr){
      return false;
   }

   fseek(p, sizeof(Profesional) * nroRegistro, SEEK_SET);
   result = fwrite(&profesional, sizeof (Profesional), 1, p);
   fclose(p);

   return result;
}

int ProfesionalArchivo::buscar(int dni){
    Profesional reg;
    int pos = 0;
    FILE * pFile = fopen("profesionales.dat", "rb");
    if(pFile == nullptr){
        return -1;
    }

    while(fread(&reg, sizeof(Profesional), 1, pFile)){
        if(reg.getDni() == dni){
            fclose(pFile);
            return pos;
        }
        pos++;
    }

    fclose(pFile);
    return -1;
}

int ProfesionalArchivo::buscarPorID(int id){
    Profesional reg;
    int pos = 0;
    FILE * pFile = fopen("profesionales.dat", "rb");
    if(pFile == nullptr){
        return -1;
    }

    while(fread(&reg, sizeof(Profesional), 1, pFile)){
        if(reg.getIDEspecialidad() == id){
            fclose(pFile);
            return pos;
        }
        pos++;
    }

    fclose(pFile);
    return -1;
}

Profesional ProfesionalArchivo::leer(int Registro){
    Profesional aux;
    FILE *p;
    p= fopen("profesionales.dat", "rb");

    if (p == nullptr){
        return aux;
    }

    fseek(p, Registro*sizeof(Profesional), SEEK_SET);
    fread(&aux, sizeof(Profesional), 1, p);
    fclose(p);
    return aux;
}

Profesional ProfesionalArchivo::leerPorDni(int dni) {
    Profesional profesional;
    FILE* pFile = fopen("profesionales.dat", "rb");
    if (pFile == nullptr) {
        profesional.setDni(-1);
        return profesional;
    }

    while (fread(&profesional, sizeof(Profesional), 1, pFile)) {
        if (profesional.getDni() == dni) {
            fclose(pFile);
            return profesional;
        }
    }

    fclose(pFile);
    profesional.setDni(-1);
    return profesional;
}

Profesional ProfesionalArchivo::leerPorMatricula(int matricula) {
    Profesional profesional;
    FILE* pFile = fopen("profesionales.dat", "rb");
    if (pFile == nullptr) {
        profesional.setMatricula(-1);
        return profesional;
    }

    while (fread(&profesional, sizeof(Profesional), 1, pFile)) {
        if (profesional.getMatricula() == matricula) {
            fclose(pFile);
            return profesional;
        }
    }

    fclose(pFile);
    profesional.setMatricula(-1);
    return profesional;
}

void ProfesionalArchivo::leerTodos(Profesional profesional[], int cant){
   FILE *pFile= fopen("profesionales.dat", "rb");

   if(pFile == nullptr){
      return;
   }

   fread(profesional, sizeof(Profesional), cant, pFile);

   fclose(pFile);
}

bool ProfesionalArchivo::modificarProfesional(Profesional profesional) {
    Profesional reg;
    FILE* pFile = fopen("profesionales.dat", "rb+");
    if (pFile == nullptr) {

        return false;
    }

    while (fread(&reg, sizeof(Profesional), 1, pFile)) {
        if (reg.getDni() == profesional.getDni()) {

            fseek(pFile, -sizeof(Profesional), SEEK_CUR);
            bool result = fwrite(&profesional, sizeof(Profesional), 1, pFile);
            fclose(pFile);
            return result == 1;
        }
    }
    fclose(pFile);
    return false;
}

bool ProfesionalArchivo::borrarDatos() {
    FILE* pFile = fopen("profesionales.dat", "wb");
    if (pFile != nullptr) {
        fclose(pFile);
        return true;
    }
    return false;
}

bool ProfesionalArchivo::agregarProfesional(Profesional profesional) {

    FILE* pFile = fopen("profesionales.dat", "rb+");

    if (pFile == nullptr) {
        pFile = fopen("profesionales.dat", "ab");
        if (pFile == nullptr) {
            return false;
        }
    } else {
        /// Si el archivo ya existe, buscamos
        Profesional reg;
        while (fread(&reg, sizeof(Profesional), 1, pFile)) {
            if (reg.getDni() == profesional.getDni()) {
                ///Si ya existe un profesional con el mismo dni, cerramos el archivo y retorna false
                fclose(pFile);
                return false;
            }
        }

        fseek(pFile, 0, SEEK_END);
    }

    /// Escribimos el nuevo profesional al final del archivo
    bool result = fwrite(&profesional, sizeof(Profesional), 1, pFile);
    fclose(pFile);

    return result;
}


