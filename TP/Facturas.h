#pragma once
#include <string>
#include "Comprobante.h"
#include "Fecha.h"
#include "Menues.h"
#include "Comensales.h"



class Factura : public Comprobante
{

public:
    Factura(int numeroFactura, Comensal comensal, Fecha fecha, Menues idmenu, float importe, const char *medioDePago, int cuit, const char *tipoFactura);
    Factura();

    void setCuit(int cuit);
    int getCuit();

    void setTipoFactura (const char * tipoFactura);
    const char * getTipoFactura();

    std::string toString();

private:
    int _cuit;
    char _tipoFactura[2];

};
