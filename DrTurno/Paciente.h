#ifndef PACIENTE_H_INCLUDED
#define PACIENTE_H_INCLUDED
#pragma once
#include "Usuario.h"
///#include "Domicilio.h"

class Paciente: public Usuario{
    private:
   /// Domicilio _domicilio;
    char _contrasenia[20];

    public:
    Paciente();
    ///Domicilio getDomicilio()const;
    const char* getContrasenia()const;

   /// void setDomicilio(const Domicilio domicilio);
    void setContrasenia (const std::string& contrasenia);
    bool validarContrasenia(const std::string& contrasenia);
    void cargar();
};



#endif // PACIENTE_H_INCLUDED
