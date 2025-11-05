#include <iostream>
#include "Comensales.h"
#include "Fecha.h"
#include "Establecimientos.h"

const char* Comensal::getNombre()
{
    return _nombre;
}

int Comensal::getIDcomensal()
{
    return _IDcomensal;
}
const char* Comensal::getDireccion ()
{
    return _direccion;
}

Fecha Comensal::getFechaNacimiento ()
{
    return _fechaNacimiento;
}
Establecimientos Comensal::getIDestablecimiento()
{
    return _IDestablecimiento;
}


void Comensal::setNombre (const char* nombre)
{
    _nombre = nombre;
}
void Comensal::setIDcomensal (int IDcomensal)
{
    _IDcomensal = IDcomensal;
}

void Comensal::setDireccion (const char* direccion)
{
    _direccion = direccion;
}
void Comensal::setFechaNacimiento (Fecha fechaNacimiento)
{
    _fechaNacimiento = fechaNacimiento;
}
void Comensal::setIDEstablecimiento (Establecimientos IDestablecimiento)
{
    _IDestablecimiento= IDestablecimiento;
}


