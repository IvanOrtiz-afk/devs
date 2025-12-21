#include <iostream>
#include <string>
#include <cstring>
#include "Pagos.h"
#include "Comensales.h"
#include "CC.h"
#include "Facturas.h"
#include "Fecha.h"
#include "Archivos.h"

Pagos::Pagos(int numeracion, Comensal comensal, float importe, Fecha fecha)
{
    _numeracion= numeracion;
    strncpy(_nombre, comensal.getNombre(), sizeof(_nombre) - 1);
    _nombre[sizeof(_nombre) - 1] = '\0';
    _idcomensal=comensal.getIDcomensal();
    _importe=importe;
    _fecha=fecha;
}

Pagos::Pagos()
{

}

int Pagos::getNumeracion()
{
    return _numeracion;
}

void Pagos::setNumeracion(int numeracion)
{
    _numeracion = numeracion;
}


void Pagos::setfecha(Fecha fecha)
{
    _fecha=fecha;
}

void Pagos::setIDcomensal(Comensal comensal)
{
    _idcomensal=comensal.getIDcomensal();
}

void Pagos::setnombre(Comensal comensal)
{
    strncpy(_nombre, comensal.getNombre(), sizeof(_nombre) - 1);
    _nombre[sizeof(_nombre) - 1] = '\0';
}

void Pagos::setimporte(float importe)
{
    _importe=importe;
}

float Pagos::getimporte()
{
    return _importe;
}

int Pagos::getIDcomensal()
{
    return _idcomensal;
}

Fecha Pagos::getfecha()
{
    return _fecha;
}

const char *Pagos::getnombre()
{
    return _nombre;
}

std::string Pagos::toString()
{
    return std::to_string(_idcomensal) + "/" + std::string(_nombre) + "/" + std::to_string(_importe) + "/" + _fecha.toString();
}
