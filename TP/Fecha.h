#pragma once
#include <vector>

class Fecha
{
private:
    int _dia, _mes, _anio;

public:
    Fecha();
    Fecha(int dia, int mes, int anio);
    int getDia();
    int getMes();
    int getAnio();
    std::vector<int> obtenerDiasDeLaSemanaActual();
    bool operator==(const Fecha& otra) const;
    bool operator!=(const Fecha& otra) const;
    Fecha hoy();
    void setDia(int dia);
    void setMes(int mes);
    void setAnio(int anio);
    void sumarDias(int diasASumar);
    std::string toString();
};


