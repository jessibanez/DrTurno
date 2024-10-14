#include <iostream>
#include <cstring>

#include "Horarios.h"

using namespace std;

Horarios::Horarios(){
_id=0;
_dia=0;
_horaInicio=0;
_horaFin=0;
}

int Horarios::getID()const{
 return _id;
}
void Horarios::setID(int id){
 _id=id;
}

int Horarios::getDia()const{
return _dia;
}
void Horarios::setDia(int dia){
_dia=dia;
}

int Horarios::getHoraInicio()const{
return _horaInicio;
}

void Horarios::setHoraInicio(int horaInicio){
_horaInicio=horaInicio;
}

int Horarios::getHoraFin()const{
return _horaFin;
}
void Horarios::setHoraFin(int horaFin){
_horaFin=horaFin;
}

void Horarios::cargar(){
cout<<" -> Matricula del profesional: ";
cin>>_id;
    do{
            cout<<" -> Dia de atencion (1.Lunes, 2.Martes, 3.Miercoles, 4.Jueves, 5.Viernes): ";
            cin>>_dia;
            if (_dia<1 || _dia>5){
            cout<<"DIA invalido"<<endl;
            cout<<"Reingrese"<<endl;
            }
    }while(_dia<1 || _dia>5);
cout<<" -> Horario de inicio (Formato 24Hs.): ";
cin>>_horaInicio;
cout<<" -> Hora de finalizacion (Formato 24Hs.): ";
cin>>_horaFin;
}

void Horarios::mostrarParaPaciente()const{
cout<<" -> Matricula del profesional: "<<_id<<endl;
cout<<" -> Dia de atencion: "<<_dia<<endl;
cout<<" -> Horario de inicio (Formato 24Hs.): "<<_horaInicio<<endl;
cout<<" -> Hora de finalizacion (Formato 24Hs.): "<<_horaFin<<endl;
cout<<" -----------------------------------------------------"<<endl;
}

void Horarios::mostrarParaProfesional()const{
cout<<" -> Dia de atencion: "<<_dia<<endl;
cout<<" -> Horario de inicio (Formato 24Hs.): "<<_horaInicio<<endl;
cout<<" -> Hora de finalizacion (Formato 24Hs.): "<<_horaFin<<endl;
cout<<" -----------------------------------------------------"<<endl;
}

/*void Horarios::mostrar(const Horarios& hora) const{
    cout << "----------ATENCION----------" << endl;
    cout << "->Dia: " << hora.getDia() << endl;
    cout << "->Hora de inicio: " << hora.getHoraInicio() << endl;
    cout << "->Hora de finalizacion: " << hora.getHoraFin() << endl;
    cout << "-----------------------------" << endl;
    cout <<endl;
}
*/
