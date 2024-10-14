#include "Administrador.h"
#include <cstring>
#include <iostream>

using namespace std;

Administrador::Administrador() {
    _id = 0;
    strcpy(_contrasenia, "");
}

Administrador::Administrador(int id, std::string contrasenia) {
    _id = id;
    setContrasenia(contrasenia);
}

const char* Administrador::getContrasenia()const{
   return _contrasenia;
}

void Administrador::setContrasenia(std::string contrasenia){
   if(contrasenia.size() <= 20){
      strcpy(_contrasenia, contrasenia.c_str());
   }
   else{
      strcpy(_contrasenia, "SIN DATOS");
   }
}

int Administrador::getID() const{
    return _id;
}

void Administrador::setID(int id) {
    _id = id;
}

Administrador Administradores[3] = {
    Administrador(1, "Jessi2024"),
    Administrador(2, "Ro2024"),
    Administrador(3, "Nahuel2024")
};
