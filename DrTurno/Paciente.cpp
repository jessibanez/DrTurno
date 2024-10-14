#include <cstring>
#include <iostream>
#include <regex>///BIBLIOTECA PARA QUE FUNCIONE LA VERIFICACIÓN DE LA CONTRASEÑA.

using namespace std;

#include "Paciente.h"

Paciente::Paciente() : Usuario() {
    strcpy(_contrasenia, "");
}

const char* Paciente::getContrasenia()const{
   return _contrasenia;
}

void Paciente::setContrasenia(const std::string& contrasenia){
   if(contrasenia.size() <= 20){
      strcpy(_contrasenia, contrasenia.c_str());
   }
   else{
      strcpy(_contrasenia, "SIN DATOS");
   }
}

bool Paciente::validarContrasenia(const std::string& contrasenia) {
        // La contraseña debe tener al menos 5 caracteres y al menos un número
        std::regex pattern("(?=.*[0-9]).{5,}");

        if (!std::regex_match(contrasenia, pattern)) {
            std::cout << "La contrasenia ingresada NO cumple con las caracteristicas solicitadas." << std::endl;
            return false;
        }
        return true;
    }


void Paciente::cargar() {
cargarPaciente();
    char pass[20];

    cin.ignore();
    std::cout << "-> Ingrese una contrasenia (minimo 5 caracteres, al menos un numero): ";
    cin.getline(pass, 19);


    while (!validarContrasenia(pass)) {
            std::cout << "Reingrese la contrasenia: ";
            cin.getline(pass, 19);
    }
        std::cout << "La contraseña cumple con lo solicitado"<<endl;

        char confirmacion[20];
        std::cout << "-> Confirme la contrasenia: ";
        cin.getline(confirmacion, 19);

    while(strcmp(pass,confirmacion)!=0) {
            std::cout << "Las contrasenias no coinciden. Por favor, intente de nuevo" << std::endl;
            std::cout << "-> Confirme la contrasenia: ";
           cin.getline(confirmacion, 19);

        }
            std::cout << " SU CONTRASENIA SE GUARDO CON EXITO ";
            setContrasenia(pass);

}


