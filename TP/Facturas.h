#pragma once
#include <string>
#include "Comprobante.h"
#include "Fecha.h"
#include "Menues.h"
#include "Comensales.h"



class Factura : public Comprobante
{

public:
    Factura(int numeroFactura, Comensal comensal, Fecha fecha, Menues idmenu, float importe, const char *medioDePago);
    Factura();


    std::string toString();

private:
   

};
