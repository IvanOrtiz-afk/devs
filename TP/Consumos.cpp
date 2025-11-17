#include <iostream>
#include <string>
#include <cstring>
#include "Comensales.h"
#include "Fecha.h"
#include "Establecimientos.h"
#include "Archivos.h"
#include "Consumos.h"
#include "Menues.h"

Consumos::Consumos(Fecha fecha, Comensal idcliente, CuentaCorriente tipo_movimiento, Menues plato, int valoracion)
{
    _fecha=fecha;
    _idcliente=idcliente.getIDcomensal();
    _tipo_movimiento=tipo_movimiento.getTipoMovimiento();
    _plato=plato.getnombremenu();
    _valoracion=valoracion; ///quizas esto lo podriamos poner directamente desde menu sistema
}       ///que el usuario sea el que pueda valorar cuando hace login en su perfil

void Consumos::setfecha(Fecha fecha)
{
    _fecha=fecha;
}
/*
bool Fecha::operator==(const Fecha& otra) const ///CREAR SOBRECARGA DE OPERADOR ==
*/

void Consumos::setcliente(Comensal cliente)
{
    _idcliente=idcliente.getIDcomensal();
}

void Consumos::settipo_mov(CuentaCorriente tipo_mov)
{
    _tipo_movimiento=tipo_movimiento.getTipoMovimiento();
}

void Consumos::setplatoconsumido(Menues plato)
{
    _plato=plato.getnombremenu();
}

void Consumos::setvaloracion(int valoracion)
{
    _valoracion=valoracion;
}

Fecha Consumos::getfecha()
{
    return _fecha;
}

int Consumos::getcliente()
{
    return _idcliente;
}

bool Consumos::gettipo_mov()
{
    return _tipo_movimiento;
}

const char* Consumos::getplato()
{
    return _plato;
}

int Consumos::getvaloracion()
{
    return _valoracion;
}

