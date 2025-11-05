#pragma once
#include "Fecha.h"
#include "Menues.h"
#include "Comensales.h"

class Factura {

private:
    int _numeroFactura;
    Comensal _IDcomensal;
    Fecha _fecha;
    Menues _idmenu;
    float _importe;
    char _medioDePago [10];

public:
    Factura();
    Factura(int numeroFactura, Comensal IDcomensal, Fecha fecha, Menues idmenu, float importe, const char *medioDePago);

    void setNumeroFactura (int numeroFactura);
    void setIDcomensal (Comensal IDcomensal);
    void setFecha (Fecha fecha);
    void setIDmenu (Menues idmenu);
    void setImporte (float importe);
    void setMedioDePago (const char *medioDePago);
    std::string toString(Comensal datoComensal, Fecha datofecha, Menues datoMenu);

    int getNumeroFactura();
    Comensal getIDcomensal ();
    Fecha getFecha ();
    Menues getIDmenu ();
    float getImporte ();
    const char* getMedioDePago ();
};
