#include <iostream>
#include <string>
#include <cstring>
#include "Menuadmin.h"
#include "Comensales.h"
#include "Fecha.h"
#include "Establecimientos.h"
#include "Archivos.h"

TipoAlmuerzo::TipoAlmuerzo(int idtipo)
{
    _idtipo=idtipo;
    if (idtipo==1)
    {
        strncpy(_nombretipo, "Com£n", sizeof(_nombretipo) - 1);
        _nombretipo[sizeof(_nombretipo) - 1]='\0';
        strncpy(_desctipo, "Almuerzo est ndar", sizeof(_desctipo) - 1);
        _desctipo[sizeof(_desctipo)-1]='\0';
    }
    if (idtipo==2)
    {
        strncpy(_nombretipo, "Vegetariano", sizeof(_nombretipo) - 1);
        _nombretipo[sizeof(_nombretipo) - 1]='\0';
        strncpy(_desctipo, "Opci¢n vegetariana", sizeof(_desctipo) - 1);
        _desctipo[sizeof(_desctipo)-1]='\0';
    }
    if (idtipo==3)
    {
        strncpy(_nombretipo, "Cel¡aco", sizeof(_nombretipo) - 1);
        _nombretipo[sizeof(_nombretipo) - 1]='\0';
        strncpy(_desctipo, "Apto cel¡aco", sizeof(_desctipo) - 1);
        _desctipo[sizeof(_desctipo)-1]='\0';
    }
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
void TipoAlmuerzo::setnombretipo(int idtipo)
{
    if (idtipo==1)
    {
        strncpy(_nombretipo, "Com£n", sizeof(_nombretipo) - 1);
        _nombretipo[sizeof(_nombretipo) - 1]='\0';
    }
    if (idtipo==2)
    {
        strncpy(_nombretipo, "Vegetariano", sizeof(_nombretipo) - 1);
        _nombretipo[sizeof(_nombretipo) - 1]='\0';
    }
    if (idtipo==3)
    {
        strncpy(_nombretipo, "Cel¡aco", sizeof(_nombretipo) - 1);
        _nombretipo[sizeof(_nombretipo) - 1]='\0';
    }
}
void TipoAlmuerzo::setdesctipo(int idtipo)
{
    if (idtipo==1)
    {
        strncpy(_desctipo, "Almuerzo est ndar", sizeof(_desctipo) - 1);
        _desctipo[sizeof(_desctipo)-1]='\0';
    }
    if (idtipo==2)
    {
        strncpy(_desctipo, "Opci¢n vegetariana", sizeof(_desctipo) - 1);
        _desctipo[sizeof(_desctipo)-1]='\0';
    }
    if (idtipo==3)
    {
        strncpy(_desctipo, "Apto cel¡aco", sizeof(_desctipo) - 1);
        _desctipo[sizeof(_desctipo)-1]='\0';
    }
}
std::string TipoAlmuerzo::toString_tipo()
{
    return std::to_string(_idtipo) + "/" + std::string(_nombretipo) + "/" + std::string(_desctipo);
}
