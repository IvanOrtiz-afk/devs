#include <iostream>
#include <string>
#include <cstring>
#include "Facturas.h"
#include "Comensales.h"
#include "Establecimientos.h"
#include "Fecha.h"
#include "Archivos.h"

Factura::Factura(int numeroFactura, Comensal comensal, Fecha fecha, Menues idmenu, float importe, const char *medioDePago)
{
    _numeroFactura=numeroFactura;
    _IDcomensal=comensal.getIDcomensal(); ///_IDcomensal INT = INT
    strncpy(_nombrecomensal, comensal.getNombre(), sizeof(_nombrecomensal) - 1);
    _nombrecomensal[sizeof(_nombrecomensal) - 1] = '\0';
    _fecha = fecha;
    _idmenu=idmenu;
    _importe=importe;
    strncpy(_medioDePago, medioDePago, sizeof(_medioDePago) - 1);
    _medioDePago[sizeof(_medioDePago) - 1] = '\0';
};

Factura::Factura(){};

const char *Factura::getnombrecomensal()
{
    return _nombrecomensal;
};

void Factura::setNombrecomensal (Comensal comensal)
{
    strncpy(_nombrecomensal, comensal.getNombre(), sizeof(_nombrecomensal) - 1);
    _nombrecomensal[sizeof(_nombrecomensal) - 1] = '\0';
};

int Factura::getNumeroFactura()
{
    return _numeroFactura;
};

int Factura::getIDcomensal()
{
    return _IDcomensal;
};

Fecha Factura::getFecha()
{
    return _fecha;
};

Menues Factura::getIDmenu()
{
    return _idmenu;
};

float Factura::getImporte()
{
    return _importe;
};

const char* Factura::getMedioDePago()
{
    return _medioDePago;
};

void Factura::setNumeroFactura(int numeroFactura)
{
    _numeroFactura=numeroFactura;
};

void Factura::setIDcomensal (Comensal comensal)
{
    _IDcomensal=comensal.getIDcomensal();
};

void Factura::setFecha(Fecha fecha)
{
    _fecha=fecha;
};

void Factura::setIDmenu (Menues idmenu)
{
    _idmenu=idmenu;
};

void Factura::setImporte(float importe)
{
    _importe=importe;
};

void Factura::setMedioDePago(const char* medioDePago)
{
    strncpy(_medioDePago, medioDePago, sizeof(_medioDePago) - 1);
    _medioDePago[sizeof(_medioDePago) - 1] = '\0';
};

std::string Factura::toString()
{
    return std::to_string(_numeroFactura) + "/" + std::to_string(_IDcomensal) + "/" + std::string (_nombrecomensal) + "/" + _fecha.toString() + "/" + _idmenu.toString() + "/" + std::to_string(_importe) + "/" + std::string (_medioDePago);
};
// ver xq no compila

