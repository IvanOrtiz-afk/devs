#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <iomanip>
#include "CC.h"
#include "Comensales.h"

CuentaCorriente::CuentaCorriente()
{

}
CuentaCorriente::CuentaCorriente(int numeracion, Comensal comensal, float saldoactual, bool estadodeuda)
{
    const int LIMITE_CORRELATIVO = 9999;
    const size_t TAMANO_ID = 6;
    if (numeracion < 1)
    {
        numeracion = 1;
    }
    int indice_letra = (numeracion - 1) / LIMITE_CORRELATIVO;
    int correlativo = ((numeracion - 1) % LIMITE_CORRELATIVO) + 1;
    char letra = 'A' + (indice_letra % 26);
    std::snprintf(_numeracion, TAMANO_ID, "%c%04d", letra, correlativo);

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
    const int LIMITE_CORRELATIVO = 9999;
    const size_t TAMANO_ID = 6;
    if (numeracion < 1)
    {
        numeracion = 1;
    }
    int indice_letra = (numeracion - 1) / LIMITE_CORRELATIVO;
    int correlativo = ((numeracion - 1) % LIMITE_CORRELATIVO) + 1;
    char letra = 'A' + (indice_letra % 26);
    std::snprintf(_numeracion, TAMANO_ID, "%c%04d", letra, correlativo);
}
const char * CuentaCorriente::getnumeracion ()
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
bool CuentaCorriente::getestadodeuda()
{
    return _estadodeuda;
}

std::string CuentaCorriente::toString()
{
    std::string strComprobante;
    if (_estadodeuda==false)
    {
        strComprobante="AL DIA";
    }
    else if (_estadodeuda==true)
    {
        strComprobante="DEUDA";
    }
    //Crea un stringstream (llamado ss)
    std::stringstream ss;
    //En ss <== un fixed para que no use notacion cientifica/setprecision para que use dos decimales/el dato _valorplato
    ss << std::fixed << std::setprecision(2) << _saldoActual;
    //El ss pasado a string
    std::string valor_plato_formateado = ss.str();

    return "Numero de cuenta corriente: " + std::string(_numeracion) +
    "\nID cliente: " + std::to_string(_idcomensal) +
    "\nNombre del cliente: " + std::string(_nombre) +
    "\nSaldo actual: $" + valor_plato_formateado +
    "\nEstado de la cuenta: " + std::string(strComprobante);
}
