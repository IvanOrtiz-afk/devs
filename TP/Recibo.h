#pragma once
#include "Comprobante.h"

class Recibo : public Comprobante {

public:

    Recibo();
    Recibo (int numeroRecibo, Comensal comensal, Fecha fecha, Menues idmenu, float importe, const char *medioDePago, int numeroCuentaAsociada, const char * _detalle);

    void setNumeroCuentaAsociada (int numeroCuentaAsociada);
    int getNumeroCuentaAsociada ();

    void setDetalle (const char * detalle);
    const char * getDetalle ();

    std::string toString();

private:

    int _numeroCuentaAsociada;
    char _detalle[50];

};
