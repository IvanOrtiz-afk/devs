#pragma once
#include <string>
#include "Fecha.h"
#include "Menues.h"
#include "Comensales.h"

class Comprobante
{

public:
    Comprobante(int numeracion, Comensal comensal, Fecha fecha, Menues idmenu, float importe, const char *medioDePago);
    Comprobante();

    void setNumeracion (int numeracion);
    int getNumeracion();

    void setNombrecomensal (Comensal comensal);
    const char *getnombrecomensal();

    void setIDcomensal (Comensal comensal);
    int getIDcomensal ();

    void setFecha (Fecha fecha);
    Fecha getFecha ();

    void setIDmenu (Menues idmenu);
    Menues getIDmenu ();

    void setImporte (float importe);
    float getImporte ();

    void setMedioDePago (const char *medioDePago);
    const char* getMedioDePago ();

    std::string toString();

protected:
    int _numeracion;
    int _IDcomensal;
    char _nombrecomensal[15];
    Fecha _fecha;
    Menues _idmenu;
    float _importe;
    char _medioDePago[15];


private:


};
