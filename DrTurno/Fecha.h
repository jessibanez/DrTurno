#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
#pragma once
#include <string>

class Fecha{
  private:
    int _dia, _mes, _anio;

  public:
    Fecha();
    Fecha(int _dia, int _mes, int _anio);
    int getDia()const;
    int getMes() const;
    int getAnio() const;
    void setDia(int _dia);
    void setMes(int _mes);
    void setAnio(int _anio);
    std::string toString() const;
};


#endif // FECHA_H_INCLUDED
