#ifndef HORARIOS_H_INCLUDED
#define HORARIOS_H_INCLUDED

class Horarios{
private:
    int _id;
    int _dia;
    int _horaInicio;
    int _horaFin;
public:
    Horarios();

    int getID()const;
    void setID(int id);

    int getDia()const;
    void setDia(int dia);

    int getHoraInicio()const;
    void setHoraInicio(int horaInicio);

    int getHoraFin()const;
    void setHoraFin(int horaFin);

    void cargar();
    void mostrarParaPaciente()const;
    void mostrarParaProfesional()const;
    void mostrar(const Horarios& hora) const;
};

#endif // HORARIOS_H_INCLUDED
