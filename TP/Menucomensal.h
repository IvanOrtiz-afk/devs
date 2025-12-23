#pragma once
#include <vector>
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
    std::vector<Menues> buscarplatos();
    Comensal buscarcliente(int id, bool &loop);
    ///void mostrar(int tipo, int num);
    void generarconsumo();
    int tipodeconsumo(bool &cancel);
    void mostrarTicket(Factura fc, std::string textoPago);

private:

    Comensal _clientebuscado;
    Menues _menubuscado;
};
