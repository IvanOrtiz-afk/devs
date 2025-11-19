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
    _IDestablecimiento=idestablecimiento.getidestablecimiento();
}

Comensal::Comensal() {}


void Comensal::setNombre (const char* nombre)
{
    strncpy(_nombre, nombre, sizeof(_nombre) - 1);
    _nombre[sizeof(_nombre) - 1] = '\0';
}


const char* Comensal::getNombre()
{
    return _nombre;
}


void Comensal::setIDcomensal (int IDcomensal)
{
    _IDcomensal = IDcomensal;
}


int Comensal::getIDcomensal()
{
    return _IDcomensal;
}


void Comensal::setDireccion (const char* direccion)
{
    strncpy(_direccion, direccion, sizeof(_direccion) - 1);
    _direccion[sizeof(_direccion) - 1] = '\0';
}


const char* Comensal::getDireccion ()
{
    return _direccion;
}


void Comensal::setFechaNacimiento (Fecha fechaNacimiento)
{
    _fechaNacimiento = fechaNacimiento;
}


Fecha Comensal::getFechaNacimiento ()
{
    return _fechaNacimiento;
}


void Comensal::setIDEstablecimiento (Establecimientos IDestablecimiento)
{
    _IDestablecimiento=IDestablecimiento.getidestablecimiento();
}


int Comensal::getIDestablecimiento()
{
    return _IDestablecimiento;
}


std::string Comensal::toString()
{
    return std::to_string(_IDcomensal) + "/" + std::string(_nombre) + "/" + std::string(_direccion) + "/" + _fechaNacimiento.toString() + "/" + std::to_string(_IDestablecimiento);
}

