#include "usuario.h"
#include <cstring>

usuario::usuario(){}
usuario::usuario( const char *nombreUsuario, const char *password, int rol)
{
   ///_id = id;

    strncpy(_nombreUsuario, nombreUsuario, sizeof(_nombreUsuario) - 1);
    _nombreUsuario[sizeof(_nombreUsuario) - 1] = '\0';

    strncpy(_password, password, sizeof(_password) - 1);
    _password[sizeof(_password) - 1] = '\0';
    
    _rol = rol;

  /*  if (rol == 1)
    {
        strncpy(_rol, "admin", sizeof(_rol) - 1);
        _rol[sizeof(_rol) - 1] = '\0';
    }
    else if (rol == 2)
    {
        strncpy(_rol, "encargado", sizeof(_rol) - 1);
        _rol[sizeof(_rol) - 1] = '\0';
    }
    else if (rol == 0)
    {
        strncpy(_rol, "comensal", sizeof(_rol) - 1);

        _rol[sizeof(_rol) - 1] = '\0';
    }
*/
}

/*void usuario::setID(int id)
{
    _id = id;
}
*/

void usuario::setNombreUsuario(const char *nombreUsuario)
{
    strncpy(_nombreUsuario, nombreUsuario, sizeof(_nombreUsuario) - 1);
    _nombreUsuario[sizeof(_nombreUsuario) - 1] = '\0';
}

void usuario::setPassword(const char *password)
{
    strncpy(_password, password, sizeof(_password) - 1);
    _password[sizeof(_password) - 1] = '\0';
}

void usuario::setRol(int rol)
{
    
      _rol = rol;
  /*  if (rol == 1)
    {
        strncpy(_rol, "admin", sizeof(_rol) - 1);
        _rol[sizeof(_rol) - 1] = '\0';
    }
    else if (rol == 2)
    {
        strncpy(_rol, "encargado", sizeof(_rol) - 1);
        _rol[sizeof(_rol) - 1] = '\0';
    }
    else if (rol == 0)
    {
        strncpy(_rol, "comensal", sizeof(_rol) - 1);

        _rol[sizeof(_rol) - 1] = '\0';
    } */
}

int usuario::getRol()
{
    return _rol;
}

const char* usuario::getPassword()
{
    return _password;
}

const char* usuario::getNombreUsuario()
{
    return _nombreUsuario;
}

/*int usuario::getID()
{
    return _id;
}
*/
