#include <iostream>
#include <string>
#include <cstring>
#include "Facturas.h"
#include "Comensales.h"
#include "Establecimientos.h"
#include "Fecha.h"
#include "Archivos.h"

Factura::Factura() {}
Factura::Factura(int numeroFactura, Comensal IDcomensal, Fecha fecha, Menues idmenu, float importe, const char *medioDePago)
{
    _numeroFactura=numeroFactura;
    _IDcomensal=IDcomensal;
    _fecha= fecha;
    _idmenu=idmenu;
    _importe=importe;
    strncpy(_medioDePago, medioDePago, sizeof(_medioDePago) - 1);
    _medioDePago[sizeof(_medioDePago) - 1] = '\0';
}

int Factura::getNumeroFactura()
{
    return _numeroFactura;
}

Comensal Factura::getIDcomensal()
{
    return _IDcomensal;
}

Fecha Factura::getFecha()
{
    return _fecha;
}

Menues Factura::getIDmenu()
{
    return _idmenu;
}

float Factura::getImporte()
{
    return _importe;
}

const char* Factura::getMedioDePago()
{
    return _medioDePago;
}


void Factura::setNumeroFactura(int numeroFactura)
{
    _numeroFactura=numeroFactura;
}

void Factura::setIDcomensal (Comensal IDcomensal)
{

    _IDcomensal=IDcomensal;
}

void Factura::setFecha(Fecha fecha)
{
    _fecha=fecha;
}

void Factura::setIDmenu (Menues idmenu)
{
    _idmenu=idmenu;
}

void Factura::setImporte(float importe)
{
    _importe=importe;
}

void Factura::setMedioDePago(const char* medioDePago)
{

    strncpy(_medioDePago, medioDePago, sizeof(_medioDePago) - 1);
    _medioDePago[sizeof(_medioDePago) - 1] = '\0';
}

/*std::string Factura::toString(Comensal datoComensal, Fecha datofecha, Menues datoMenu)
{
    return std::to_string(_numeroFactura) + "/" + datoComensal.toString(datofecha) + "/" + datofecha.toString() + "/" + datoMenu.toString(datotipo, datofecha) + "/" + std::to_string(_importe) + "/" +std::string(_medioDePago);
}
*/ // ver xq no compila

