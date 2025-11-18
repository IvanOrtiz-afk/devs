#include <iostream>
#include <string>
#include <cstring>
#include "Comensales.h"
#include "Fecha.h"
#include "Establecimientos.h"
#include "Archivos.h"

Menues::Menues(int idmenu, const char* nombremenu, Establecimientos esta, float valorplato, TipoAlmuerzo tipo, Fecha fecha)
{
    _idmenu=idmenu;
    strncpy(_nombremenu, nombremenu, sizeof(_nombremenu) - 1);
    _nombremenu[sizeof(_nombremenu) - 1]='\0';
    _esta=esta.getidestablecimiento();
    _valorplato=valorplato;
    strncpy(_tipo, tipo.getnombretipo(), sizeof(_tipo) - 1);
    _tipo[sizeof(_tipo) - 1]='\0';
    _fecha=fecha;
}
Menues::Menues() {}
int Menues::getidmenu()
{
    return _idmenu;
}
const char* Menues::getnombremenu()
{
    return _nombremenu;
}
float Menues::getvalorplato()
{
    return _valorplato;
}
const char* Menues::gettipo()
{
    return _tipo;
}
Fecha Menues::getfecha()
{
    return _fecha;
}
int Menues::getesta()
{
    return _esta;
}
void Menues::setesta(Establecimientos esta)
{
    _esta=esta.getidestablecimiento();
}
void Menues::setidmenu(int idmenu)
{
    _idmenu=idmenu;
}
void Menues::setnombremenu(const char* nombremenu)
{
    strncpy(_nombremenu, nombremenu, sizeof(_nombremenu) - 1);
    _nombremenu[sizeof(_nombremenu) - 1]='\0';
}
void Menues::setvalorplato(float valorplato)
{
    _valorplato=valorplato;
}
void Menues::settipo(TipoAlmuerzo tipo)
{
    strncpy(_tipo, tipo.getnombretipo(), sizeof(_tipo) - 1);
    _tipo[sizeof(_tipo) - 1]='\0';
}
void Menues::setfecha(Fecha fecha)
{
    _fecha=fecha;
}
std::string Menues::toString()
{
    return std::string(_nombremenu) + "/" + std::to_string(_valorplato);
    ///Tengo que enviar como parametros los dos tipos de dato "TipoAlmuerzo" y "Fecha" que necesito imprimir como string
}


