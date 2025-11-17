#include <iostream>
#include <string>
#include <cstring>
#include "CC.h"
#include "Comensales.h"


CuentaCorriente::CuentaCorriente()
{

}
CuentaCorriente::CuentaCorriente(int numeracion, Comensal comensal, float saldoactual, bool estadodeuda)
{
    _numeracion=numeracion;
    _idcomensal=comensal.getIDcomensal();
    _saldoActual=saldoactual;
    _estadodeuda=estadodeuda;
}

void CuentaCorriente::setSaldoActual (float saldoactual)
{
    _saldoActual=saldoactual;
}
float CuentaCorriente::getSaldoActual ()
{
    return _saldoActual;
}
void CuentaCorriente::setnumeracion (int numeracion)
{
    _numeracion=numeracion;
}
int CuentaCorriente::getnumeracion ()
{
    return _numeracion;
}
void CuentaCorriente::setcomensal (Comensal comensal)
{
    _idcomensal=comensal.getIDcomensal();
}
int CuentaCorriente::getcomensal ()
{
    return _idcomensal;
}
void CuentaCorriente::setestadodeuda (bool estadodeuda)
{
    _estadodeuda=estadodeuda;
}
bool CuentaCorriente::getestadodeuda ()
{
    return _estadodeuda;
}

/**std::string CuentaCorriente::toString()
{
    std::string strComprobante = Comprobante::toString();
    strComprobante += "/" + std::to_string(_saldoActual);
    strComprobante += "/" + std::to_string(_saldoAnterior);

    if (_tipoMovimiento)
    {
        strComprobante += "CARGO";
    }
    else
    {
        strComprobante += "PAGO";
    }

    return strComprobante;
    /// averiguar si asi esta bien pasar a texto un booleano
}*/
