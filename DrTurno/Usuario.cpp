#include "Usuario.h"
#include <cstring>
#include <iostream>
#include <algorithm>
#include <limits>
#include <string>
#include <stdexcept> // Para std::out_of_range
#include <ctime>


using namespace std;

bool contieneNumeros(const std::string& str) {
        for (char c : str) {
            if (isdigit(static_cast<unsigned char>(c))) {
                return true;
            }
        }
        return false;
    }

Usuario::Usuario()
:_fechaNacimiento(1,1,1), _dni(0), _telefono(0), _estado(false){
strcpy(_nombre, "");
strcpy(_apellido,"");
strcpy(_email,"");
}

Usuario::Usuario(std::string nombre, std::string apellido, std::string email, Fecha fechaNacimiento, int dni, int telefono, bool estado)
: _fechaNacimiento(1,1,1)
{
    setNombre(nombre);
    setApellido(apellido);
    setEmail(email);
    setFechaNacimiento (fechaNacimiento);
    setDni(dni);
    setTelefono(telefono);
    setEstado(estado);
}


const char* Usuario::getNombre()const{
   return _nombre;
}

void Usuario::setNombre(std::string nombre){
   if(nombre.size() <= 50|| contieneNumeros(nombre)){
      strcpy(_nombre, nombre.c_str());
   }
   else{
       cout<<"NOMBRE invalido"<<endl;
        cout<<"Se guardara -sin datos-"<<endl;
      strcpy(_nombre, "SIN DATOS");
   }
}

const char* Usuario::getApellido()const{
   return _apellido;
}

void Usuario::setApellido(std::string apellido){
   if(apellido.size() <= 50&& !contieneNumeros(apellido)){
      strcpy(_apellido, apellido.c_str());
   }
   else{
        cout<<"APELLIDO invalido"<<endl;
        cout<<"Se guardara -sin datos-"<<endl;
      strcpy(_apellido, "SIN DATOS");
   }
}

const char* Usuario::getEmail()const{
   return _email;
}

void Usuario::setEmail(std::string email){
   if(email.size() <= 50&& email.find('@') != std::string::npos){
      strcpy(_email, email.c_str());
   }
   else{
            cout<<"EMAIL inválido"<<endl;
            cout<<"Se SIN DATOS"<<endl;
      strcpy(_email, "SIN DATOS");
   }
}

Fecha Usuario::getFechaNacimiento()const{
   return _fechaNacimiento;
}

void Usuario::setFechaNacimiento(const Fecha fechaNacimiento){
   _fechaNacimiento = fechaNacimiento;
}

int Usuario::getDni() const{
    return _dni;
}

void Usuario::setDni(int dni) {
     if (dni > 4000000) {
            _dni = dni;
        } else {
            cout<<"DNI inválido"<<endl;
            cout<<"Se guardara 0"<<endl;
        }
}

int Usuario::getTelefono() const{
    return _telefono;
}

void Usuario::setTelefono(int telefono) {
   if (telefono > 2000000) {
            _telefono = telefono;
        } else {
            cout<<"TELEFONO inválido"<<endl;
            cout<<"Se guardara 0"<<endl;
        }

}

bool Usuario::getEstado()const{
    return _estado;
}

void Usuario::setEstado(bool estado){
    _estado= estado;
}
///Domicilio


const char* Usuario::getCalle() const{
    return _calle;
}

void Usuario::setCalle(std::string calle) {
    if (calle.size() <= 30&& !contieneNumeros(calle)) {
        strcpy(_calle, calle.c_str());
    } else {
        cout<<"CALLE invalido"<<endl;
        cout<<"Se guardara -sin datos-"<<endl;
        strcpy(_calle, "sin datos");
    }
}

const char* Usuario::getLocalidad() const{
    return _localidad;
}

void Usuario::setLocalidad(std::string localidad) {
    if (localidad.size() <= 30&& !contieneNumeros(localidad)) {
        strcpy(_localidad, localidad.c_str());
    } else {
        cout<<"LOCALIDAD invalido"<<endl;
        cout<<"Se guardara -sin datos-"<<endl;
        strcpy(_localidad, "sin datos");
    }
}

const char* Usuario::getPartido() const{
    return _partido;
}

void Usuario::setPartido(std::string partido) {
    if (partido.size() <= 30&& !contieneNumeros(partido)) {
        strcpy(_partido, partido.c_str());
    } else {
        cout<<"PARTIDO invalido"<<endl;
        cout<<"Se guardara -sin datos-"<<endl;
        strcpy(_partido, "sin datos");
    }
}

const char* Usuario::getProvincia() const{
    return _provincia;
}

void Usuario::setProvincia(std::string provincia) {
    if (provincia.size() <= 30&& !contieneNumeros(provincia)) {
        strcpy(_provincia, provincia.c_str());
    } else {
        cout<<"PROVINCIA invalido"<<endl;
        cout<<"Se guardara -sin datos-"<<endl;
        strcpy(_provincia, "sin datos");
    }
}

const char* Usuario::getPais() const{
    return _pais;
}

void Usuario::setPais(std::string pais) {
    if (pais.size() <= 30&& !contieneNumeros(pais)) {
        strcpy(_pais, pais.c_str());
    } else {
        cout<<"PAIS invalido"<<endl;
        cout<<"Se guardara -sin datos-"<<endl;
        strcpy(_pais, "sin datos");
    }
}

int Usuario::getNumero() const{
    return _numero;
}

void Usuario::setNumero(int numero) {
    if( numero > 0){
            _numero=numero;
    }else {
    cout<<"Numero invalido"<<endl;
    cout<<"Se guardara -1-"<<endl;
    _numero=0;
    }
}

int Usuario::getCodigoPostal() const{
    return _codigoPostal;
}

void Usuario::setCodigoPostal(int codigoPostal) {
   if( codigoPostal > 0){
            _codigoPostal=codigoPostal;
    }else {
    cout<<"Numero invalido"<<endl;
    cout<<"Se guardara -1-"<<endl;
    _codigoPostal=0;
    }
}


///Funciones
void Usuario::cargarPaciente(){
    cout <<"--------BIENVENIDO/A--------"<<endl;
    cout <<"----Crearemos tu usuario----"<<endl;
    cout <<"Completa los siguientes datos: "<<endl;
    cout << endl;
string nombre;
 do{   cout << "-> Ingrese su nombre: ";
    cin>>nombre;
    if(nombre.size() >=50 || contieneNumeros(nombre)){
       cout<<"NOMBRE invalido"<<endl;
        cout<<"Reingrese"<<endl;
        }else{
    strcpy(_nombre, nombre.c_str());
        }
 }while(nombre.size() >=50 || contieneNumeros(nombre));

 string apellido;
do{
    cout << "-> Ingrese su apellido: ";
   cin>>apellido;
    if (apellido.size() >= 50|| contieneNumeros(apellido)) {
        cout<<"APELLIDO invalido"<<endl;
        cout<<"Reingrese"<<endl;
        }else{
    strcpy(_apellido, apellido.c_str());
        }
}while(apellido.size()>=50 || contieneNumeros(apellido));

 do {
        cout << "-> DNI: ";
        cin >> _dni;
        cin.ignore();
        if (_dni < 4000000) {
            cout << "DNI invalido. Debe estar entre 5,000,000 y 100,000,000." << endl;
        }
    } while (_dni < 4000000);

do {
        cout << "-> Correo electronico: ";
        cin.getline(_email, 50);
        if (strlen(_email) > 50 || strchr(_email, '@') == nullptr) {
            cout << "Correo electronico invalido. Debe contener un '@' y tener menos de 50 caracteres." << endl;
        }
    } while (strlen(_email) > 50 || strchr(_email, '@') == nullptr);

    cout<<"-> Fecha de nacimiento: "<<endl;
    int dia, mes, anio;
    do{
            cout<<"Dia: ";
            cin>>dia;
             _fechaNacimiento.setDia(dia);
            if (dia<0 || dia>31){
            cout<<"DIA invalido"<<endl;
            cout<<"Reingrese"<<endl;
            }
    }while(dia<0 || dia>31);

     do{
            cout<<"Mes: ";
            cin>>mes;
             _fechaNacimiento.setMes(mes);
            if (mes<0 || mes>12){
            cout<<"MES invalido"<<endl;
            cout<<"Reingrese"<<endl;
            }
    }while(mes<0 || mes>12);

    time_t t = time(nullptr);
                tm* now = localtime(&t);
                int anio2 = now->tm_year + 1900;
     do{
         cout<<"Anio (4 digitos): ";
         cin>>anio;

             _fechaNacimiento.setAnio(anio);
            if (anio < 1900|| anio>anio2){
            cout<<"ANIO invalido"<<endl;
            cout<<"Reingrese"<<endl;
            }
    }while(anio<1900 || anio>anio2);


    cout<<"->Telefono (sin espacios, ni guiones): ";
    cin>>_telefono;
    cout << endl;
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

string provincia;
 do{   cout << "-> Provincia: ";
    cin>>provincia;
    if(provincia.size() >=50 || contieneNumeros(provincia)){
       cout<<"PROVINCIA invalido"<<endl;
        cout<<"Reingrese"<<endl;
        }else{
    strcpy(_provincia, provincia.c_str());
        }
 }while(provincia.size() >=50 || contieneNumeros(provincia));

    string pais;
 do{   cout << "-> Pais: ";
    cin>>pais;
    if(pais.size() >=50 || contieneNumeros(pais)){
       cout<<"PAIS invalido"<<endl;
        cout<<"Reingrese"<<endl;
        }else{
    strcpy(_pais, pais.c_str());
        }
 }while(pais.size() >=50 || contieneNumeros(pais));
do{
    cout << "-> Codigo Postal: ";
    cin >> _codigoPostal;
   if (_codigoPostal<0){
    cout<<"CODIGO POSTAL invalido"<<endl;
        cout<<"Reingrese"<<endl;
   }
}while(_codigoPostal<0);
    _estado=true;
}

void Usuario::cargarProfesional() {
    cout << "-----------BIENVENIDO/A-----------" << endl;
    cout << "--Ingresara un nuevo profesional--" << endl;
    cout << "--Completa los siguientes datos:--" << endl;

string nombre;
 do{   cout << "-> Ingrese su nombre: ";
    cin>>nombre;
    if(nombre.size() >=50 || contieneNumeros(nombre)){
       cout<<"NOMBRE invalido"<<endl;
        cout<<"Reingrese"<<endl;
        }else{
    strcpy(_nombre, nombre.c_str());
        }
 }while(nombre.size() >=50 || contieneNumeros(nombre));

 string apellido;
do{
    cout << "-> Ingrese su apellido: ";
   cin>>apellido;
    if (apellido.size() >= 50|| contieneNumeros(apellido)) {
        cout<<"APELLIDO invalido"<<endl;
        cout<<"Reingrese"<<endl;
        }else{
    strcpy(_apellido, apellido.c_str());
        }
}while(apellido.size()>=50 || contieneNumeros(apellido));

    // Validación del DNI
 do {
        cout << "-> DNI: ";
        cin >> _dni;
        cin.ignore();
        if (_dni < 4000000) {
            cout << "DNI invalido. Debe estar entre 5,000,000 y 100,000,000." << endl;
        }
    } while (_dni < 4000000);

   cin.ignore();

do {
        cout << "-> Correo electronico: ";
        cin.getline(_email, 50);
        if (strlen(_email) > 50 || strchr(_email, '@') == nullptr) {
            cout << "Correo electronico invalido. Debe contener un '@' y tener menos de 50 caracteres." << endl;
        }
    } while (strlen(_email) > 50 || strchr(_email, '@') == nullptr);

    // Validación de la fecha de nacimiento
    int dia, mes, anio;
    bool fechaValida = false;
    while (!fechaValida) {
        cout << "-> Fecha de nacimiento: " << endl;
        cout << "Dia (1-31): ";
        cin >> dia;
        cout << "Mes (1-12): ";
        cin >> mes;
        cout << "Anio: ";
        cin >> anio;

        if (dia >= 1 && dia <= 31 && mes >= 1 && mes <= 12 && anio > 1900 && anio < 2025) {
            fechaValida = true;
        } else {
            cout << "Error: Fecha no valida. Intente nuevamente." << endl;
            cin.clear();  // Limpiar estado de error de cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Descartar entrada no válida
        }
    }
    _fechaNacimiento.setDia(dia);
    _fechaNacimiento.setMes(mes);
    _fechaNacimiento.setAnio(anio);

    // Validación del teléfono
    bool telefonoValido = false;
    while (!telefonoValido) {
        cout << "-> Telefono (sin espacios, ni guiones, entre 10 y 14 digitos): ";
        string telefonoStr;
        cin >> telefonoStr;
        if (telefonoStr.length() >= 10 && telefonoStr.length() <= 14 && all_of(telefonoStr.begin(), telefonoStr.end(), ::isdigit)) {
            try {
                _telefono = stoll(telefonoStr); // Cambiado a stoll para números largos
                telefonoValido = true;
            } catch (const std::out_of_range& e) {
                cout << "Error: El telefono está fuera del rango permitido." << endl;
                cin.clear();  // Limpiar estado de error de cin
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Descartar entrada no válida
            }
        } else {
            cout << "Error: El telefono debe tener entre 10 y 14 digitos y contener solo números." << endl;
            cin.clear();  // Limpiar estado de error de cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Descartar entrada no válida
        }
    }

    _estado = true;
}


void Usuario::mostrarPaciente() {
    cout << "--------DETALLES DEL USUARIO--------" << endl;
    cout << "Nombre: " << _nombre << endl;
    cout << "Apellido: " << _apellido << endl;
    cout << "DNI: " << _dni << endl;
    cout << "Correo electronico: " << _email << endl;
    cout << "Fecha de nacimiento: " << _fechaNacimiento.toString()<<endl;
    cout << "Telefono: " << _telefono << endl;
    cout << "--------DETALLES DEL DOMICILIO--------" << endl;
    cout << "Calle: " << _calle << endl;
    cout << "Numero: " << _numero << endl;
    cout << "Localidad: " << _localidad << endl;
    cout << "Partido: " << _partido << endl;
    cout << "Provincia: " << _provincia << endl;
    cout << "Pais: " << _pais << endl;
    cout << "Codigo Postal: " << _codigoPostal << endl;
}

void Usuario::mostrarProfesional() {
    cout << "--------DETALLES DEL PROFESIONAL--------" << endl;
    cout << "Nombre: " << _nombre << endl;
    cout << "Apellido: " << _apellido << endl;
    cout << "DNI: " << _dni << endl;
    cout << "Correo electronico: " << _email << endl;
    cout << "Fecha de nacimiento: " << _fechaNacimiento.toString()<<endl;
    cout << "Telefono: " << _telefono << endl;
}
