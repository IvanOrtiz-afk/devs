#include <iostream>
#include <cstring>
#include <string>
#include "Establecimientos.h"

Establecimientos::Establecimientos(){};
Establecimientos::Establecimientos(int idestablecimiento, const char *nombreestablecimiento, const char *direccionesta, const char*tipoesta)
{
    _idestablecimiento = idestablecimiento;
    // 1. Copiar el nombre de forma segura strncopy(_direcciondestino, direccionorigen, tama¤o en bytes a copiar en el destino -1 (para poder poner luego el \0)
    strncpy(_nombreestablecimiento, nombreestablecimiento, sizeof(_nombreestablecimiento) - 1);
    // Asegurar que la cadena siempre termine con \0
    _nombreestablecimiento[sizeof(_nombreestablecimiento) - 1] = '\0';

    strncpy(_direccionesta, direccionesta, sizeof(_direccionesta) - 1);
    _direccionesta[sizeof(_direccionesta) - 1] = '\0';

    strncpy(_tipoesta, tipoesta, sizeof(_tipoesta) - 1);
    _tipoesta[sizeof(_tipoesta) - 1] = '\0';
}

int Establecimientos::getidestablecimiento()
{
    return _idestablecimiento;
};
const char * Establecimientos::getnombreestablecimiento()
{
    return _nombreestablecimiento;
};
const char * Establecimientos::getdireccionesta()
{
    return _direccionesta;
};
const char * Establecimientos::gettipoesta()
{
    return _tipoesta;
};
void Establecimientos::setidestablecimiento(int idestablecimiento)
{
    _idestablecimiento=idestablecimiento;

};
void Establecimientos::setnombreestablecimiento(const char* nombreestablecimiento)
{
    strncpy(_nombreestablecimiento, nombreestablecimiento, sizeof(_nombreestablecimiento) - 1);
    _nombreestablecimiento[sizeof(_nombreestablecimiento) - 1] = '\0';
};
void Establecimientos::setdireccionesta(const char* direccionesta)
{
    strncpy(_direccionesta, direccionesta, sizeof(_direccionesta) - 1);
    _direccionesta[sizeof(_direccionesta) - 1] = '\0';
};
void Establecimientos::settipoesta(const char* tipoesta)
{
    strncpy(_tipoesta, tipoesta, sizeof(_tipoesta) - 1);
    _tipoesta[sizeof(_tipoesta) - 1] = '\0';
};

std::string Establecimientos::toString()
{
    return std::to_string(_idestablecimiento) + "/" + std::string(_nombreestablecimiento) + "/" + std::string(_direccionesta);
};


