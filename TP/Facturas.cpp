#include <iostream>
#include <string>
#include <cstring>
#include "Comprobante.h"
#include "Facturas.h"
#include "Comensales.h"
#include "Fecha.h"
#include "Archivos.h"
#include "Menues.h"

Factura::Factura(int numeroFactura, Comensal comensal, Fecha fecha, Menues idmenu, float importe, bool medioDePago)
    :Comprobante(numeroFactura, comensal, fecha, idmenu, importe, medioDePago)
{
    const int LIMITE_CORRELATIVO = 99999;
    if (numeroFactura < 1)
    {
        numeroFactura = 1;
    }
    int sucursal = (numeroFactura - 1) / LIMITE_CORRELATIVO + 1;
    int correlativo = (numeroFactura - 1) % LIMITE_CORRELATIVO + 1;
    std::snprintf(_numero_factura, sizeof(_numero_factura), "%04d-%05d", sucursal, correlativo);

    _id_comensal=comensal.getIDcomensal();
    strncpy(_nombre_comensal, comensal.getNombre(), sizeof(_nombre_comensal) - 1);
    _nombre_comensal[sizeof(_nombre_comensal) - 1] = '\0';
}

Factura::Factura()
    :Comprobante () {}

void Factura::setnombrecomen(Comensal comensal)
{
    strncpy(_nombre_comensal, comensal.getNombre(), sizeof(_nombre_comensal) - 1);
    _nombre_comensal[sizeof(_nombre_comensal) - 1] = '\0';
}

const char *Factura::getnombrecomen()
{
    return _nombre_comensal;
}

void Factura::setnumfc(int numeroFactura)
{
    const int LIMITE_CORRELATIVO = 99999;
    if (numeroFactura < 1)
    {
        numeroFactura = 1;
    }
    int sucursal = (numeroFactura - 1) / LIMITE_CORRELATIVO + 1;
    int correlativo = (numeroFactura - 1) % LIMITE_CORRELATIVO + 1;
    std::snprintf(_numero_factura, sizeof(_numero_factura), "%04d-%05d", sucursal, correlativo);
}

const char* Factura::getnumfc()
{
    return _numero_factura;
}

void Factura::setidcomen(Comensal comensal)
{
    _id_comensal=comensal.getIDcomensal();
}

int Factura::getidcomen()
{
    return _id_comensal;
}

std::string Factura::FCtoString()
{
    std::string strComprobante = Comprobante::toString();

    return strComprobante;
    /// return std::to_string(_numeroFactura) + "/" + std::to_string(_IDcomensal) + "/" + std::string (_nombrecomensal) + "/" + _fecha.toString() + "/" + _idmenu.toString() + "/" + std::to_string(_importe) + "/" + std::string (_medioDePago);
}


