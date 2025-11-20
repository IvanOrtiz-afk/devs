#pragma once
#include "MenuPadreABML.h"
#include "Establecimientos.h"
#include "Comensales.h"
#include "Consumos.h"
#include "Menues.h"


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
        void cargarfactura();
        void verCC();
        void cargarpago();
        void cargarestablecimiento();
        void listarestablecimientos();
        void cargarcomensales();
        void listarcomensales();
        void listarconsumos();

    protected:
        void mostrarestablecimientos(Establecimientos establecimientos_muestra);
        void mostrarcomensales(Comensal comensal_muestra);
        void mostrarconsumos(Consumos consumos_muestra);


    private:
};


