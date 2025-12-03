#include <iostream>
#include <string>
#include <cstring>
#include <ctime>
#include "Comensales.h"
#include "Fecha.h"
#include "Establecimientos.h"
#include "Archivos.h"

Fecha::Fecha()
{
    _dia=0;
    _mes=0;
    _anio=0;
}
Fecha::Fecha(int dia, int mes, int anio)
{
    _dia=dia;
    _mes=mes;
    _anio=anio;
}
bool Fecha::operator==(const Fecha& otra) const
{
    // Compara el d¡a, mes y a¤o del objeto actual con el objeto 'otra'
    if (_dia==otra._dia&&_mes==otra._mes&&_anio==otra._anio)
    {
        return true;
    }
    return false;
}
bool Fecha::operator!=(const Fecha& otra) const
{
    // Compara el d¡a, mes y a¤o del objeto actual con el objeto 'otra'
    if (_dia!=otra._dia||_mes!=otra._mes||_anio!=otra._anio)
    {
        return true;
    }
    return false;
}
Fecha Fecha::hoy()
{
    std::time_t tiempoAhora = std::time(nullptr);
    std::tm* tmLocal = std::localtime(&tiempoAhora);
    int dia = tmLocal->tm_mday;
    int mes = tmLocal->tm_mon + 1;      // tm_mon es 0-basado
    int anio = tmLocal->tm_year + 1900; // tm_year es a¤os desde 1900

    return Fecha(dia, mes, anio);
}

int Fecha::dia_desemana()
{
    std::time_t tiempoAhora = std::time(nullptr);
    std::tm* tmLocal = std::localtime(&tiempoAhora);
    int indice_dia = tmLocal->tm_wday; /// tm_info->tm_wday contiene un valor entero de 0 (Domingo) a 6 (Sabado)
    if (indice_dia==0)
    {
        int domingo=indice_dia+7;
        return domingo;
    }
    else
    {
        return indice_dia;
    }
}

void Fecha::sumarDias(int diasASumar) {
    _dia += diasASumar;
    while (_dia > 30) {
        _dia -= 30;
        _mes++;
        if (_mes > 12) {
            _mes = 1;
            _anio++;
        }
    }
}
int Fecha::getDia()
{
    return _dia;
}
int Fecha::getMes()
{
    return _mes;
}
int Fecha::getAnio()
{
    return _anio;
}
void Fecha::setDia(int dia)
{
    _dia=dia;
}
void Fecha::setMes(int mes)
{
    _mes=mes;
}
void Fecha::setAnio(int anio)
{
    _anio=anio;
}
std::string Fecha::toString()
{
    return std::to_string(_dia) + "/" + std::to_string(_mes) + "/" + std::to_string(_anio);
}

