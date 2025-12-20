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
    ///enum TipoEntrada {NUMERO_ENTERO, TEXTO_NO_VACIO, NUMERO_FLOTANTE};
    std::string volver();
    void platosmejor_valor();
    void platosmas_vendidos();
    void cant_platosXfecha();
    struct PlatoVendido ///Un struct necesita su propio constructor
    {
        std::string _nombre;
        int _cantidadVendida;
        PlatoVendido(std::string nombre, int cantidadVendida)
        {
            _nombre=nombre;
            _cantidadVendida=cantidadVendida;
        }
    };
    void listarplatos(Fecha fechafiltrar);
    void listarplatos_semana();
    void cargarplato();
    Fecha setear_fecha();
    void valorar_x_fecha();
    void menuValoraciones();
    void listar_valoraciones();
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
    void modificarplatos();
    void modificarusuarios();
    void realizarBackup();
    void restaurarBackup();
    void exportarDatosCSV();
    void listarUsuarios();

    /* std::string entrada_valida(const std::string&, TipoEntrada);
     std::string entrada_cruda(const std::string&);*/

protected:
    void mostrarestablecimientos(Establecimientos establecimientos_muestra);
    void mostrarcomensales(Comensal comensal_muestra);
    void mostrarconsumos(Consumos consumos_muestra);

private:
    bool copiarArchivo(std::string origen, std::string destino);

};


