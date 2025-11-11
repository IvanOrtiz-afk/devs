#include <iostream>
#include <string>
#include <cstring>
#include "Comprobante.h"
#include "Comensales.h"
#include "Fecha.h"
#include "Archivos.h"
#include "Menues.h"

Comprobante::Comprobante(int numeracion, Comensal comensal, Fecha fecha, Menues idmenu, float importe, const char *medioDePago)
{
    _numeracion = numeracion;
    _IDcomensal=comensal.getIDcomensal(); ///_IDcomensal INT = INT
    strncpy(_nombrecomensal, comensal.getNombre(), sizeof(_nombrecomensal) - 1);
    _nombrecomensal[sizeof(_nombrecomensal) - 1] = '\0';
    _fecha = fecha;
    _idmenu=idmenu;
    _importe=importe;
    strncpy(_medioDePago, medioDePago, sizeof(_medioDePago) - 1);
    _medioDePago[sizeof(_medioDePago) - 1] = '\0';
}

Comprobante::Comprobante(){}


void Comprobante::setNumeracion(int numeracion)
{
    _numeracion=numeracion;
}

int Comprobante::getNumeracion()
{
    return _numeracion;
}

void Comprobante::setIDcomensal (Comensal comensal)
{
    _IDcomensal=comensal.getIDcomensal();
}

int Comprobante::getIDcomensal()
{
    return _IDcomensal;
}


void Comprobante::setNombrecomensal (Comensal comensal)
{
    strncpy(_nombrecomensal, comensal.getNombre(), sizeof(_nombrecomensal) - 1);
    _nombrecomensal[sizeof(_nombrecomensal) - 1] = '\0';
}

const char *Comprobante::getnombrecomensal()
{
    return _nombrecomensal;
}


void Comprobante::setFecha(Fecha fecha)
{
    _fecha = fecha;
}


Fecha Comprobante::getFecha()
{
    return _fecha;
}

void Comprobante::setIDmenu (Menues idmenu)
{
    _idmenu=idmenu;
}

Menues Comprobante::getIDmenu()
{
    return _idmenu;
}

void Comprobante::setImporte(float importe)
{
    _importe=importe;
}

float Comprobante::getImporte()
{
    return _importe;
}

void Comprobante::setMedioDePago(const char* medioDePago)
{
    strncpy(_medioDePago, medioDePago, sizeof(_medioDePago) - 1);
    _medioDePago[sizeof(_medioDePago) - 1] = '\0';
}

const char* Comprobante::getMedioDePago()
{
    return _medioDePago;
}



std::string Comprobante::toString()
{
    return std::to_string(_numeracion) + "/" + std::to_string(_IDcomensal) + "/" + std::string (_nombrecomensal) + "/" + _fecha.toString() + "/" + _idmenu.toString() + "/" + std::to_string(_importe) + "/" + std::string (_medioDePago);
}



