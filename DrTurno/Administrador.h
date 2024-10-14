#ifndef ADMINISTRADOR_H_INCLUDED
#define ADMINISTRADOR_H_INCLUDED
#include <string>

class Administrador{
    private:
    char _contrasenia[20];
    int _id;

    public:
    Administrador();
    Administrador(int id, std::string contrasenia);

    const char* getContrasenia() const;
    void setContrasenia(std::string contrasenia);

    int getID() const;
    void setID(int id);
};

#endif // ADMINISTRADOR_H_INCLUDED
