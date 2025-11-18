#pragma once
#include <cstdlib>
#include <string>
#include "MenuPadreABML.h"
#include "Comensales.h"
#include "Menues.h"

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
