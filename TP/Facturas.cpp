#include <iostream>
#include <string>
#include <cstring>
#include "Facturas.h"
#include "Comprobante.h"
#include "Comensales.h"
#include "Fecha.h"
#include "Archivos.h"
#include "Menues.h"



Factura::Factura(int numeroFactura, Comensal comensal, Fecha fecha, Menues idmenu, float importe, const char *medioDePago, int cuit, const char *tipoFactura)
    :Comprobante(numeroFactura, comensal, fecha, idmenu, importe, medioDePago)
{

    _cuit = cuit;
    strncpy(_tipoFactura, tipoFactura, sizeof(_tipoFactura) - 1);
    _tipoFactura[sizeof(_tipoFactura) - 1] = '\0';
}

Factura::Factura()
    :Comprobante () {}

void Factura::setCuit(int cuit)
{
    _cuit = cuit;
}

int Factura::getCuit()
{
    return _cuit;
}

void Factura::setTipoFactura(const char * tipoFactura)
{
    strncpy(_tipoFactura, tipoFactura, sizeof(_tipoFactura) - 1);
    _tipoFactura[sizeof(_tipoFactura) - 1] = '\0';
}

const char * Factura::getTipoFactura()
{
    return _tipoFactura;
}



std::string Factura::toString()
{
    std::string strPadre = Comprobante::toString();
    strPadre += "/" + std::to_string(_cuit);
    strPadre += "/" + std::string(_tipoFactura);

    return strPadre;
       /// return std::to_string(_numeroFactura) + "/" + std::to_string(_IDcomensal) + "/" + std::string (_nombrecomensal) + "/" + _fecha.toString() + "/" + _idmenu.toString() + "/" + std::to_string(_importe) + "/" + std::string (_medioDePago);
}


