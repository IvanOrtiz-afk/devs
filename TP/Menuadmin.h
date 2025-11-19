#pragma once
#include "MenuPadreABML.h"

class Menuadmin : public MenuPadreABML
{

    public:
        Menuadmin();
        ~Menuadmin();
        void listarplatos();
        void cargarplato();
        void valoraciones();
        void eliminarplato();
        void cargarvaloracion();
        void listarfacturas();

    protected:

    private:
};


