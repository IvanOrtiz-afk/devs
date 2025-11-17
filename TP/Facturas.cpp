#include <iostream>
#include <string>
#include <cstring>
#include "Facturas.h"
#include "Comprobante.h"
#include "Comensales.h"
#include "Fecha.h"
#include "Archivos.h"
#include "Menues.h"



Factura::Factura(int numeroFactura, Comensal comensal, Fecha fecha, Menues idmenu, float importe, const char *medioDePago)
    :Comprobante(numeroFactura, comensal, fecha, idmenu, importe, medioDePago)
{


}

Factura::Factura()
    :Comprobante () {}





std::string Factura::toString()
{
    std::string strComprobante = Comprobante::toString();


    return strComprobante;
       /// return std::to_string(_numeroFactura) + "/" + std::to_string(_IDcomensal) + "/" + std::string (_nombrecomensal) + "/" + _fecha.toString() + "/" + _idmenu.toString() + "/" + std::to_string(_importe) + "/" + std::string (_medioDePago);
}


