#include <iostream>
#include <string>
#include <cstring>
#include "Comensales.h"
#include "Fecha.h"
#include "Establecimientos.h"
#include "Archivos.h"
#include "Consumos.h"
#include "Menues.h"

Consumos::Consumos(Fecha fecha, Comensal idcliente, Menues plato)
{
    _fecha=fecha;
    _idcliente=idcliente.getIDcomensal();
    strncpy(_plato, plato.getnombremenu(), sizeof(_plato) - 1);
    _plato[sizeof(_plato) - 1] = '\0';
    _importe=plato.getvalorplato();
}
Consumos::Consumos()
{

}
void Consumos::setfecha(Fecha fecha)
{
    _fecha=fecha;
}
/*
bool Fecha::operator==(const Fecha& otra) const ///CREAR SOBRECARGA DE OPERADOR ==
*/

void Consumos::setcliente(Comensal idcliente)
{
    _idcliente=idcliente.getIDcomensal();
}

void Consumos::setplatoconsumido(Menues plato)
{
    strncpy(_plato, plato.getnombremenu(), sizeof(_plato) - 1);
    _plato[sizeof(_plato) - 1] = '\0';
}

Fecha Consumos::getfecha()
{
    return _fecha;
}

int Consumos::getcliente()
{
    return _idcliente;
}

const char* Consumos::getplato()
{
    return _plato;
}
float Consumos::getimporte()
{
    return _importe;
}
void Consumos::setimporte(Menues plato)
{
    _importe=plato.getvalorplato();
}

