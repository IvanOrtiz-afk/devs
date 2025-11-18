#include "usuario.h"
#include <cstring>

usuario::usuario(int id, const char *nombre, const char *password, int rol)
{
    _id = id;

    strncpy(_nombreUsuario, nombre, sizeof(_nombreUsuario) - 1);
    _nombreUsuario[sizeof(_nombreUsuario) - 1] = '\0';

    strncpy(_password, password, sizeof(_password) - 1);
    _password[sizeof(_password) - 1] = '\0';

    setRol(rol);
}

void usuario::setID(int id) {
    _id = id;
}

void usuario::setNombre(const char *nombre)
{
    strncpy(_nombreUsuario, nombre, sizeof(_nombreUsuario) - 1);
    _nombreUsuario[sizeof(_nombreUsuario) - 1] = '\0';
}

void usuario::setPassword(const char *password)
{
    strncpy(_password, password, sizeof(_password) - 1);
    _password[sizeof(_password) - 1] = '\0';
}

void usuario::setRol(int rol)
{
    if (rol == 1)
        strncpy(_rol, "admin", sizeof(_rol) - 1);
    else if (rol == 2)
        strncpy(_rol, "encargado", sizeof(_rol) - 1);
    else
        strncpy(_rol, "comensal", sizeof(_rol) - 1);

    _rol[sizeof(_rol) - 1] = '\0';
}

const char* usuario::getRol() {
    return _rol;
}

const char* usuario::getPassword() {
    return _password;
}

const char* usuario::getNombre() {
    return _nombreUsuario;
}

int usuario::getID() {
    return _id;
}
