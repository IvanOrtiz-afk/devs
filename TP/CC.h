#pragma once
#include "Comensales.h"


class CuentaCorriente
{
public:
    CuentaCorriente();
    CuentaCorriente(int numeracion, Comensal comensal, float saldoactual, bool estadodeuda);

    void setSaldoActual (float saldoactual);
    float getSaldoActual ();

    void setnumeracion (int numeracion);
    int getnumeracion ();

    void setnombrecomensal (Comensal comensal);
    const char *getnombrecomensal ();

    void setcomensal (Comensal comensal);
    int getcomensal ();

    void setestadodeuda (bool estadodeuda);
    bool getestadodeuda ();

    std::string toString();

private:
    char _nombre[30];
    int _numeracion;
    int _idcomensal;
    float _saldoActual;
    bool _estadodeuda; /// si es true tiene deuda, si es false no tiene deuda

};
