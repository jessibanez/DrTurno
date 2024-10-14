#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED

#include <string>
#include "Fecha.h"

class Usuario{
protected:
    char _nombre[50];
    char _apellido[50];
    char _email[50];
    Fecha _fechaNacimiento;
    int _dni;
    int _telefono;
    bool _estado;
    ///Domicilio
    char _calle[30];
    char _localidad[30];
    char _partido[30];
    char _provincia[30];
    char _pais[30];
    int _numero;
    int _codigoPostal;


public:
    Usuario();
    Usuario(std::string nombre, std::string apellido, std::string email, Fecha fechaNacimiento, int dni, int telefono, bool estado);
    const char* getNombre() const;
    void setNombre(std::string nombre);

    const char* getApellido() const;
    void setApellido(std::string apellido);

    const char* getEmail()const;
    void setEmail(std::string email);

    Fecha getFechaNacimiento() const;
    void setFechaNacimiento (Fecha fechaNacimiento);

    int getDni() const;
    void setDni(int dni);

    int getTelefono() const;
    void setTelefono(int telefono);

    bool getEstado() const;
    void setEstado(bool estado);

    ///Domicilio
    const char* getCalle() const;
    void setCalle(std::string calle);

    const char* getLocalidad() const;
    void setLocalidad(std::string localidad);

    const char* getPartido() const;
    void setPartido(std::string partido);

    const char* getProvincia() const;
    void setProvincia(std::string provincia);

    const char* getPais() const;
    void setPais(std::string pais);

    int getNumero() const;
    void setNumero(int numero);

    int getCodigoPostal() const;
    void setCodigoPostal(int codigoPostal);

    ///Funciones
    void cargarPaciente();
    void cargarProfesional();
    void mostrarPaciente();
    void mostrarProfesional();
};

#endif // USUARIO_H_INCLUDED
