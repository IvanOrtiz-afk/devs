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
}

Factura::Factura()
    :Comprobante () {}

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

std::string Factura::FCtoString()
{
    std::string strComprobante = Comprobante::toString();

    return strComprobante;
    /// return std::to_string(_numeroFactura) + "/" + std::to_string(_IDcomensal) + "/" + std::string (_nombrecomensal) + "/" + _fecha.toString() + "/" + _idmenu.toString() + "/" + std::to_string(_importe) + "/" + std::string (_medioDePago);
}


