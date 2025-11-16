#include "MenuPadreABML.h"
#include "Comensales.h"
#include "Menues.h"
#include <string>

class Menucomensal : public MenuPadreABML
{

public:

    Menucomensal(Comensal clientebuscado, Menues menubuscado);
    void ejecutarmenu();
    Menues buscarplatos(const char* tipo);
    Comensal buscarcliente(int id, bool &loop);
    void mostrar(const char* tipo, int num);

private:

    Comensal _clientebuscado;
    Menues _menubuscado;
};
