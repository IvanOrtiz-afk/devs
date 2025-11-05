#include <iostream>
#include <string>
#include <cstring>
#include "Comensales.h"
#include "Fecha.h"
#include "Establecimientos.h"
#include "Archivos.h"

Comensal::Comensal(int idcomensal, const char *nombre, const char *direccion, Fecha fechanacimiento, Establecimientos idestablecimiento)
{
    _IDcomensal=idcomensal;
    strncpy(_nombre, nombre, sizeof(_nombre) - 1);
    _nombre[sizeof(_nombre) - 1] = '\0';
    strncpy(_direccion, direccion, sizeof(_direccion) - 1);
    _direccion[sizeof(_direccion) - 1] = '\0';
    _fechaNacimiento=fechanacimiento;
    _IDestablecimiento=idestablecimiento;
};
Comensal::Comensal(){};
const char* Comensal::getNombre()
{
    return _nombre;
};
int Comensal::getIDcomensal()
{
    return _IDcomensal;
};
const char* Comensal::getDireccion ()
{
    return _direccion;
};
Fecha Comensal::getFechaNacimiento ()
{
    return _fechaNacimiento;
};
Establecimientos Comensal::getIDestablecimiento()
{
    return _IDestablecimiento;
};
void Comensal::setNombre (const char* nombre)
{
    strncpy(_nombre, nombre, sizeof(_nombre) - 1);
    _nombre[sizeof(_nombre) - 1] = '\0';
};
void Comensal::setIDcomensal (int IDcomensal)
{
    _IDcomensal = IDcomensal;
};
void Comensal::setDireccion (const char* direccion)
{
    strncpy(_direccion, direccion, sizeof(_direccion) - 1);
    _direccion[sizeof(_direccion) - 1] = '\0';
};
void Comensal::setFechaNacimiento (Fecha fechaNacimiento)
{
    _fechaNacimiento = fechaNacimiento;
};
void Comensal::setIDEstablecimiento (Establecimientos IDestablecimiento)
{
    _IDestablecimiento= IDestablecimiento;
};
std::string Comensal::toString()
{
    return std::to_string(_IDcomensal) + "/" + std::string(_nombre) + "/" + std::string(_direccion) + "/" + _fechaNacimiento.toString() + "/" + _IDestablecimiento.toString();
};

