#ifndef DOMICILIO_H_INCLUDED
#define DOMICILIO_H_INCLUDED

#include <string>

class Domicilio{
private:
    char _calle[30];
    char _localidad[30];
    char _partido[30];
    char _provincia[30];
    char _pais[30];
    int _numero;
    int _codigoPostal;
public:
    Domicilio();
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

    void cargar();
    void mostrar();
};


#endif // DOMICILIO_H_INCLUDED
