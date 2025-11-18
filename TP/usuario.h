#pragma once
class usuario
{
private:
    int _id;
    char _nombreUsuario[20];
    char _password[20];
    char _rol [10];
public:
    usuario(int id, const char *nombre, const char *password, int rol);

    void setID(int id);
    void setNombre(const char *nombre);
    void setPassword(const char *password);
    void setRol(int rol);

    const char * getRol();
    const char *getPassword();
    const char *getNombre();
    int getID();


};



