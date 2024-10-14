#include <iostream>
#include <cstring>

#include "profesional.h"
#include "Globales.h"

using namespace std;

Profesional::Profesional(){
 strcpy(_especialidad, "");
}

const char*  Profesional::getEspecialidad() const {
    return _especialidad;
}

void Profesional::setEspecialidad(std::string especialidad) {
    if(especialidad.size() <= 50){
      strcpy(_especialidad, especialidad.c_str());
   }
   else{
      strcpy(_especialidad, "SIN DATOS");
   }
}

int Profesional::getIDEspecialidad(){
    return _idEspecialidad;
}

void  Profesional::setIDEspecialidad(int idEspecialidad){
    _idEspecialidad = idEspecialidad;
}

int  Profesional::getMatricula()const{
    return _matricula;
}
void  Profesional::setMatricula(int matricula){
_matricula=matricula;
}

void Profesional::cargar() {
    ///Cargo profesional, función originada en Usuario.cpp
    cargarProfesional();
    do{
            cout << "-> Matricula: ";
            cin>>_matricula;
            if(_matricula<10000){
                cout<<"Error NUMERO DE MATRICULA invalido"<<endl;
                cout<<"Reingrese"<<endl;
            }
    }while(_matricula<10000);

    cout << "Seleccione la especialidad del profesional: "<<endl;
    auto especialidadSeleccionada = selectorDeEspecialidad();

    strcpy(_especialidad, especialidadSeleccionada.second.c_str());
    _idEspecialidad = especialidadSeleccionada.first;
}

void Profesional::mostrar()  {
    mostrarProfesional();
    std::cout << "Especialidad: " << _especialidad << std::endl;
    std::cout << "Matricula: " <<_matricula<< std::endl;
}
