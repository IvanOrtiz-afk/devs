#pragma once
class usuario
{

public:
    usuario();
    usuario( const char *nombreUsuario, const char *password, int rol);

   /// void setID(int id);
    void setNombreUsuario(const char *nombre);
    void setPassword(const char *password);
    void setRol(int rol);

    int getRol();
    const char *getPassword();
    const char *getNombreUsuario();
   /// int getID();

private:
    ///int _id;
    char _nombreUsuario[20];
    char _password[20];
    int _rol;

};



