#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <iomanip>
#include "Comensales.h"
#include "Fecha.h"
#include "Establecimientos.h"
#include "Archivos.h"

Menues::Menues(int idmenu, const char* nombremenu, Establecimientos esta, float valorplato, TipoAlmuerzo idtipo, Fecha fecha)
{
    _idmenu=idmenu;
    strncpy(_nombremenu, nombremenu, sizeof(_nombremenu) - 1);
    _nombremenu[sizeof(_nombremenu) - 1]='\0';
    _esta=esta.getidestablecimiento();
    _valorplato=valorplato;
    _idtipo=idtipo.getidtipo();
    _fecha=fecha;
    strncpy(_desctipo, idtipo.getnombretipo(), sizeof(_desctipo) - 1);
    _desctipo[sizeof(_desctipo) - 1]='\0';
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
int Menues::getidtipo()
{
    return _idtipo;
}
Fecha Menues::getfecha()
{
    return _fecha;
}
int Menues::getesta()
{
    return _esta;
}
const char* Menues::getdesctipo()
{
    return _desctipo;
}
void Menues::setdesctipo(TipoAlmuerzo desctipo)
{
    strncpy(_desctipo, desctipo.getnombretipo(), sizeof(_desctipo) - 1);
    _desctipo[sizeof(_desctipo) - 1]='\0';
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
void Menues::setidtipo(TipoAlmuerzo idtipo)
{
    _idtipo=idtipo.getidtipo();
}
void Menues::setfecha(Fecha fecha)
{
    _fecha=fecha;
}
std::string Menues::toString()
{
    //Crea un stringstream (llamado ss)
    std::stringstream ss;
    //En ss <== un fixed para que no use notacion cientifica/setprecision para que use dos decimales/el dato _valorplato
    ss << std::fixed << std::setprecision(2) << _valorplato;
    //El ss pasado a string
    std::string valor_plato_formateado = ss.str();
    return std::string(_desctipo) + "/" + std::string(_nombremenu) + "/" + valor_plato_formateado;
}


