#include <iostream>
#include <string>
#include <cstring>
#include "CC.h"


CuentaCorriente::CuentaCorriente(int numeroCuenta, Comensal comensal, Fecha fecha, Menues idmenu, float importe, const char *medioDePago, float saldoAnterior, bool tipoMovimiento)
    :Comprobante(numeroCuenta, comensal, fecha, idmenu, importe, medioDePago)
{

    _saldoAnterior = saldoAnterior;
    _tipoMovimiento = tipoMovimiento;

    ///calcula el saldo actual, teniendo en cuenta que si el importe es positivo es deuda, si es negativo es un pago
    _saldoActual = _saldoAnterior + getImporte();
}

CuentaCorriente::CuentaCorriente()
    :Comprobante () {}



void CuentaCorriente::setSaldoActual (float saldoActual)
{
    _saldoActual = saldoActual;
}

float CuentaCorriente::getSaldoActual ()
{
    return _saldoActual;
}

void CuentaCorriente::setSaldoAnterior (float saldoAnterior)
{
    _saldoAnterior = saldoAnterior;
}

float CuentaCorriente::getSaldoAnterior ()
{
    return _saldoAnterior;
}

void CuentaCorriente::setTipoMovimiento (bool tipoMovimiento)
{
    _tipoMovimiento = tipoMovimiento;
}

bool CuentaCorriente::getTipoMovimiento ()
{
    return _tipoMovimiento;
}


std::string CuentaCorriente::toString()
{
    std::string strComprobante = Comprobante::toString();
    strComprobante += "/" + std::to_string(_saldoActual);
    strComprobante += "/" + std::to_string(_saldoAnterior);

    if (_tipoMovimiento) {
        strComprobante += "CARGO";
    } else {
        strComprobante += "PAGO";
    }

    return strComprobante;
       /// averiguar si asi esta bien pasar a texto un booleano
}
