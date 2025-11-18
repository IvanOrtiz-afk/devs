#include <iostream>
#include <string>
#include <cstring>
#include "Comensales.h"
#include "Fecha.h"
#include "Establecimientos.h"
#include "Archivos.h"

TipoAlmuerzo::TipoAlmuerzo(int idtipo, const char* nombretipo, const char* desctipo)
{
    _idtipo=idtipo;
    strncpy(_nombretipo, nombretipo, sizeof(_nombretipo) - 1);
    _nombretipo[sizeof(_nombretipo) - 1]='\0';
    strncpy(_desctipo, desctipo, sizeof(_desctipo) - 1);
    _desctipo[sizeof(_desctipo)-1]='\0';
}
TipoAlmuerzo::TipoAlmuerzo() {}
int TipoAlmuerzo::getidtipo()
{
    return _idtipo;
}
const char* TipoAlmuerzo::getnombretipo()
{
    return _nombretipo;
}
const char* TipoAlmuerzo::getdesctipo()
{
    return _desctipo;
}
void TipoAlmuerzo::setidtipo(int idtipo)
{
    _idtipo=idtipo;
}
void TipoAlmuerzo::setnombretipo(const char* nombretipo)
{
    strncpy(_nombretipo, nombretipo, sizeof(_nombretipo ) - 1);
    _nombretipo[sizeof(_nombretipo) - 1]='\0';
}
void TipoAlmuerzo::setdesctipo(const char* desctipo)
{
    strncpy(_desctipo, desctipo, sizeof(_desctipo) - 1);
    _desctipo[sizeof(_desctipo)-1]='\0';
}
std::string TipoAlmuerzo::toString()
{
    return std::to_string(_idtipo) + "/" + std::string(_nombretipo) + "/" + std::string(_desctipo);
}
