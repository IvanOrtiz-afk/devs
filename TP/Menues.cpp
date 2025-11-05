#include <iostream>
#include <string>
#include <cstring>
#include "Comensales.h"
#include "Fecha.h"
#include "Establecimientos.h"
#include "Archivos.h"

Menues::Menues(int idmenu, const char* nombremenu, float valorplato, TipoAlmuerzo tipo, Fecha fecha)
{
    _idmenu=idmenu;
    strncpy(_nombremenu, nombremenu, sizeof(_nombremenu) - 1);
    _nombremenu[sizeof(_nombremenu) - 1]='\0';
    _valorplato=valorplato;
    _tipo=tipo;
    _fecha=fecha;
};
Menues::Menues() {};
int Menues::getidmenu()
{
    return _idmenu;
};
const char* Menues::getnombremenu()
{
    return _nombremenu;
};
float Menues::getvalorplato()
{
    return _valorplato;
};
TipoAlmuerzo Menues::gettipo()
{
    return _tipo;
};
Fecha Menues::getfecha()
{
    return _fecha;
};
void Menues::setidmenu(int idmenu)
{
    _idmenu=idmenu;
};
void Menues::setnombremenu(const char* nombremenu)
{
    strncpy(_nombremenu, nombremenu, sizeof(_nombremenu) - 1);
    _nombremenu[sizeof(_nombremenu) - 1]='\0';
};
void Menues::setvalorplato(float valorplato)
{
    _valorplato=valorplato;
};
void Menues::settipo(TipoAlmuerzo tipo)
{
    _tipo=tipo;
};
void Menues::setfecha(Fecha fecha)
{
    _fecha=fecha;
};
std::string Menues::toString()
{
    return std::to_string(_idmenu) + "/" + std::string(_nombremenu) + "/" + std::to_string(_valorplato) + "/" + _tipo.toString() + "/" + _fecha.toString();
    ///Tengo que enviar como parametros los dos tipos de dato "TipoAlmuerzo" y "Fecha" que necesito imprimir como string
};


