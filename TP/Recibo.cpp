#include <iostream>
#include <string>
#include <cstring>
#include "Recibo.h"

Recibo::Recibo() : Comprobante() {}

Recibo::Recibo (int numeroRecibo, Comensal comensal, Fecha fecha, Menues idmenu, float importe, const char *medioDePago, int numeroCuentaAsociada, const char * detalle)
    : Comprobante (numeroRecibo, comensal, fecha, idmenu, importe, medioDePago)
{

    _numeroCuentaAsociada = numeroCuentaAsociada;
    strncpy(_detalle, detalle, sizeof(_detalle) - 1);
    _detalle[sizeof(_detalle) - 1] = '\0';
}


void Recibo::setNumeroCuentaAsociada (int numeroCuentaAsociada)
{
    _numeroCuentaAsociada = numeroCuentaAsociada;
}

int Recibo::getNumeroCuentaAsociada ()
{
    return _numeroCuentaAsociada;
}

void Recibo::setDetalle (const char * detalle)
{
    strncpy(_detalle, detalle, sizeof(_detalle) - 1);
    _detalle[sizeof(_detalle) - 1] = '\0';
}

const char * Recibo::getDetalle ()
{
    return _detalle;
}

std::string Recibo::toString()
{
    std::string strComprobante = Comprobante::toString();
    strComprobante += "/" + std::to_string(_numeroCuentaAsociada);
    strComprobante += "/" + std::string(_detalle);

    return strComprobante;
}
