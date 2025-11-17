#pragma once
#include "Comprobante.h"


class CuentaCorriente : public Comprobante{

public:
    CuentaCorriente();
    CuentaCorriente(int numeroCuenta, Comensal comensal, Fecha fecha, Menues idmenu, float importe, const char *medioDePago, float saldoAnterior, bool tipoMovimiento);

    void setSaldoActual (float saldoActual);
    float getSaldoActual ();

    void setSaldoAnterior (float saldoAnterior);
    float getSaldoAnterior ();

    void setTipoMovimiento (bool tipoMovimiento);
    bool getTipoMovimiento ();

    std::string toString();

private:


    float _saldoActual;
    float _saldoAnterior;
    bool _tipoMovimiento; /// si es true es una deuda, si es false es un pago

};
