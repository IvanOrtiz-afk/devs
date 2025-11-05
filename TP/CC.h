#pragma once
#include "Factura.h"
#include "Fecha.h"
#include "Comensal.h"

class CuentaCorriente : public Factura{

private:
    int _IDcuenta;
    float _saldo;

public:
    CuentaCorriente();
    CuentaCorriente(int IDcuenta, Comensal IDcomensal, Fecha fecha, float saldo);
/*
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
}; */
