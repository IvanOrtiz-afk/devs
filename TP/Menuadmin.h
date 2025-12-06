#pragma once
#include "MenuPadreABML.h"
#include "Establecimientos.h"
#include "Comensales.h"
#include "Consumos.h"
#include "Menues.h"
#include "Fecha.h"


class Menuadmin : public MenuPadreABML
{

public:
    Menuadmin();
    ~Menuadmin();
    enum TipoEntrada {NUMERO_ENTERO, TEXTO_NO_VACIO, NUMERO_FLOTANTE};
    std::string volver();
    void platosmejor_valor();
    void platosmas_vendidos();
    void cant_platosXfecha();
    struct PlatoVendido
    {
        std::string nombre;
        int cantidadVendida = 0;
    };
    void listarplatos(Fecha fechafiltrar);
    void cargarplato();
    void valoraciones();
    void eliminarplato(Fecha fechafiltrar);
    void eliminarplatomenu();
    void eliminarcomensal();
    void eliminar_esta();
    void eliminarusuario();
    void cargarvaloracion();
    void listarfacturas();
    void cargarfactura();
    void verCC();
    void cargarpago();
    void listarpago();
    void cargarestablecimiento();
    void listarestablecimientos();
    void cargarcomensales();
    void listarcomensales();
    void listarconsumos();
    void mostrarmenucargar();
    void cargarmenutodalasemana();
    void menuplatos();
    void modificarestablecimientos();
    void modificarcomensales();
    std::string entrada_valida(const std::string&, TipoEntrada);
    std::string entrada_cruda(const std::string&);

protected:
    void mostrarestablecimientos(Establecimientos establecimientos_muestra);
    void mostrarcomensales(Comensal comensal_muestra);
    void mostrarconsumos(Consumos consumos_muestra);

private:

};


