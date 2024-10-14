#include <cstring>
#include <iostream>
#include "Domicilio.h"
using namespace std;

Domicilio::Domicilio() {
    strcpy(_calle, "");
    strcpy(_localidad, "");
    strcpy(_partido, "");
    strcpy(_provincia, "");
    strcpy(_pais, "");
    _numero = 0;
    _codigoPostal = 0;
}

const char* Domicilio::getCalle() const{
    return _calle;
}

void Domicilio::setCalle(std::string calle) {
    if (calle.size() <= 30) {
        strcpy(_calle, calle.c_str());
    } else {
        strcpy(_calle, "no exite");
    }
}

const char* Domicilio::getLocalidad() const{
    return _localidad;
}

void Domicilio::setLocalidad(std::string localidad) {
    if (localidad.size() <= 30) {
        strcpy(_localidad, localidad.c_str());
    } else {
        strcpy(_localidad, "no existe");
    }
}

const char* Domicilio::getPartido() const{
    return _partido;
}

void Domicilio::setPartido(std::string partido) {
    if (partido.size() <= 30) {
        strcpy(_partido, partido.c_str());
    } else {
        strcpy(_partido, "no existe");
    }
}

const char* Domicilio::getProvincia() const{
    return _provincia;
}

void Domicilio::setProvincia(std::string provincia) {
    if (provincia.size() <= 30) {
        strcpy(_provincia, provincia.c_str());
    } else {
        strcpy(_provincia, "no existe");
    }
}

const char* Domicilio::getPais() const{
    return _pais;
}

void Domicilio::setPais(std::string pais) {
    if (pais.size() <= 30) {
        strcpy(_pais, pais.c_str());
    } else {
        strcpy(_pais, "no existe");
    }
}

int Domicilio::getNumero() const{
    return _numero;
}

void Domicilio::setNumero(int numero) {
    _numero = numero;
}

int Domicilio::getCodigoPostal() const{
    return _codigoPostal;
}

void Domicilio::setCodigoPostal(int codigoPostal) {
    _codigoPostal = codigoPostal;
}

void Domicilio::cargar() {
    cout << "--------INGRESE SU DOMICILIO--------" << endl;

    cout << "-> Calle: ";
    cin.ignore();
    cin.getline(_calle, 30);

    cout << "-> Numero: ";
    cin >> _numero;
    cin.ignore();

    cout << "-> Localidad: ";
    cin.getline(_localidad, 30);

    cout << "-> Partido: ";
    cin.getline(_partido, 30);

    cout << "-> Provincia: ";
    cin.getline(_provincia, 30);

    cout << "-> Pais: ";
    cin.getline(_pais, 30);

    cout << "-> Codigo Postal: ";
    cin >> _codigoPostal;
    cin.ignore();

}

void Domicilio::mostrar() {
    cout << "--------DETALLES DEL DOMICILIO--------" << endl;
    cout << "Calle: " << _calle << endl;
    cout << "Numero: " << _numero << endl;
    cout << "Localidad: " << _localidad << endl;
    cout << "Partido: " << _partido << endl;
    cout << "Provincia: " << _provincia << endl;
    cout << "Pais: " << _pais << endl;
    cout << "Codigo Postal: " << _codigoPostal << endl;
}

