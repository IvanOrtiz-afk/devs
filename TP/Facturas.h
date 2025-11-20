#pragma once
#include <string>
#include "Comprobante.h"
#include "Fecha.h"
#include "Menues.h"
#include "Comensales.h"

class Factura : public Comprobante
{

public:
    Factura(int numeroFactura, Comensal comensal, Fecha fecha, Menues idmenu, float importe, bool medioDePago);
    Factura();
    void setnumfc(int numeroFactura);
    int getidcomen();
    void setidcomen(Comensal);
    void setnombrecomen(Comensal comensal);
    const char *getnombrecomen();
    const char* getnumfc();

    std::string FCtoString();

private:
    char _numero_factura[11];
    int _id_comensal;
    char _nombre_comensal[30];

};
