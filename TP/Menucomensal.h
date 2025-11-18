#pragma once
#include "MenuPadreABML.h"
#include "Comensales.h"
#include "Menues.h"
#include "Archivos.h"
#include "Consumos.h"
#include "CC.h"
#include "Fecha.h"

class Menucomensal : public MenuPadreABML
{
public:

    Menucomensal(Comensal clientebuscado, Menues menubuscado);
    Menucomensal();
    void ejecutarmenu();
    Menues buscarplatos(int tipo);
    Comensal buscarcliente(int id, bool &loop);
    void mostrar(int tipo, int num);
    void generarconsumo();
    bool tipodeconsumo();

private:

    Comensal _clientebuscado;
    Menues _menubuscado;
};
