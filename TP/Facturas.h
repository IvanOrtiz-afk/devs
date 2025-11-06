#pragma once
#include <string>
#include "Fecha.h"
#include "Menues.h"
#include "Comensales.h"

class Factura {

private:
    int _numeroFactura;
    Menues _idmenu;
    char _medioDePago [20];

protected:
    int _IDcomensal;
    char _nombrecomensal[15];
    Fecha _fecha;
    float _importe;

public:
    Factura(int numeroFactura, Comensal comensal, Fecha fecha, Menues idmenu, float importe, const char *medioDePago);
    Factura();

    void setNombrecomensal (Comensal comensal);
    void setNumeroFactura (int numeroFactura);
    void setIDcomensal (Comensal comensal);
    void setFecha (Fecha fecha);
    void setIDmenu (Menues idmenu);
    void setImporte (float importe);
    void setMedioDePago (const char *medioDePago);
    std::string toString();

    const char *getnombrecomensal();
    int getNumeroFactura();
    int getIDcomensal ();
    Fecha getFecha ();
    Menues getIDmenu ();
    float getImporte ();
    const char* getMedioDePago ();
};
