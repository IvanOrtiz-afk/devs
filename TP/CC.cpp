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
    strncpy(_nombre, comensal.getNombre(), sizeof(_nombre) - 1);
    _nombre[sizeof(_nombre) - 1] = '\0';
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
void CuentaCorriente::setnombrecomensal (Comensal comensal)
{
    strncpy(_nombre, comensal.getNombre(), sizeof(_nombre) - 1);
    _nombre[sizeof(_nombre) - 1] = '\0';
}
const char *CuentaCorriente::getnombrecomensal ()
{
    return _nombre;
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

std::string CuentaCorriente::toString()
{
    std::string strComprobante;
    if (_estadodeuda==false)
    {
        strComprobante="CARGO";
    }
    else if (_estadodeuda==true)
    {
        strComprobante="PAGO";
    }
    return std::to_string(_numeracion) + "/" + std::to_string(_idcomensal) + "/" + std::string(_nombre) + "/$ " + std::to_string(_saldoActual) + "/" + std::string(strComprobante);
}
