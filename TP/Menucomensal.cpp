#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <vector>
#include "Menucomensal.h"
#include "MenuPadreABML.h"
#include "Comensales.h"
#include "Menues.h"
#include "Pagos.h"
#include "Archivos.h"
#include "Consumos.h"
#include "CC.h"
#include "Fecha.h"
#include "Menuadmin.h"
#include "Utilidades.h"

Menucomensal::Menucomensal(Comensal clientebuscado, Menues menubuscado)
    :MenuPadreABML()
{
    _clientebuscado=clientebuscado;
    _menubuscado=menubuscado;
}

Menucomensal::Menucomensal()
    :MenuPadreABML()
{

}

void Menucomensal::ejecutarmenu()  ///EVELYN -> BUG ENCONTRADO, SOLO MUESTRA TRES MENUES POR ESTABLECIMIENTO AUNQUE HAYAN MAS CARGADOS. (ESTO LO COMENTO ANGEL)
{
    int id;                       /// ARREGLADO! SE GENERO SWICHT DINAMICO PARA QUE MUESTRE TODOS LOS MENUS DEL ESTABLECIMIENTO.
    int opcion;                   /// SI UN ESTABLECIMIENTO NO TIENE NADA CARGADO NO LO MUESTRA. ANTES MOSTRABA UN MENU RANDOM (NO SE XQ PERO PUDE CORREGIRLO)
    bool loop=true;
    ///const int tipocom = 1; ///Com£n
    ///const int tipoveg = 2; ///Vegetariano
    ///const int tipocel = 3; ///Cel¡aco
    MenuPadreABML::line('*');
    std::cout << "  BIENVENIDO/A AL COMEDOR" << std::endl;
    MenuPadreABML::line('*');
    do
    {
        std::string entrada = entrada_valida("Por favor, ingrese su ID de cliente, o pulse cero para volver:", NUMERO_ENTERO);
        id = std::stoi(entrada);
        if (entrada=="0")
        {
            return;
        }
        _clientebuscado=buscarcliente(id, loop);
    }
    while(loop==false);
    system("cls");

    int idEstablecimiento = _clientebuscado.getIDestablecimiento();

    std::cout << "Bienvenido/a " << _clientebuscado.getNombre() << std::endl;
    system("pause");
    system("cls");

    std::vector<Menues> menuesDisponibles = buscarplatos();

    if (menuesDisponibles.empty())
    {
        std::cout << "Su establecimiento no tiene menus disponibles para el dia de hoy." << std::endl;
        system("pause");
        return;
    }

    std::cout << "--- MENUS DEL DIA (" << menuesDisponibles.size() << ") ---" << std::endl;
    line('-');

    for (size_t i = 0; i< menuesDisponibles.size(); i++)
    {

        std::cout << std::endl;
        std::cout << "OPCION # " << (i + 1) << std::endl;
        std::cout << menuesDisponibles[i].getdesctipo() << std::endl;
        std::cout << menuesDisponibles[i].getnombremenu() << std::endl;
        std::cout << "IMPORTE $" << menuesDisponibles[i].getvalorplato() << std::endl;
        line('-');
    }

    do
    {
        std::cout << "Seleccione la opcion deseada (1 - " << menuesDisponibles.size() << "):" << std::endl;
        std::string entrada = entrada_valida("Pulse 0 para volver", NUMERO_ENTERO);
        opcion = std::stoi(entrada);
        if (entrada=="0")
        {
            return;
        }
    }
    while (opcion < 1 || opcion > menuesDisponibles.size());
    _menubuscado = menuesDisponibles[static_cast<size_t>(opcion) - 1];
    generarconsumo();

    std::cout << "Consumo cargado!" << std::endl;
}

std::vector<Menues> Menucomensal::buscarplatos()
{
    Archivos <Menues> arch ("Menues.dat");
    std::vector<Menues> menuesDisponibles;
    Fecha fecha_actual;
    fecha_actual.hoy();
    int registros=arch.CantidadRegistros();
    for (int i=0; i<registros; i++)
    {
        Menues menu;
        menu=arch.Leer(i);
        if (fecha_actual.hoy()==menu.getfecha()&&_clientebuscado.getIDestablecimiento()==menu.getesta())
        {
            menuesDisponibles.push_back(menu);
        }
    }
    return menuesDisponibles;
}

Comensal Menucomensal::buscarcliente(int id, bool &loop)
{
    Archivos <Comensal> arch ("Comensales.dat");
    Comensal cliente;
    int i, registros=arch.CantidadRegistros();
    for (i=0; i<registros; i++)
    {
        cliente=arch.Leer(i);
        if (id==cliente.getIDcomensal())
        {
            loop=true;
            return cliente; ///en la linea donde este el return LA INSTRUCCION TERMINA FORZADAMENTE
        }
    }
    if (i==registros&&id!=cliente.getIDcomensal())
    {
        std::cout << "El ID ingresado no es v lido o no existe, intente nuevamente" << std::endl;
        loop=false;
    };

    return cliente;
}

void Menucomensal::generarconsumo()
{
    Archivos <Factura> arch3 ("Facturas.dat");
    Archivos <Consumos> arch ("Consumos.dat");
    Archivos <CuentaCorriente> arch2 ("CC.dat");
    Archivos <Pagos> arch4 ("Pagos.dat");
    bool cliente_encontrado=false, tiene_deuda=false;
    bool tipo_consumo=tipodeconsumo();
    Fecha fecha_generar;
    fecha_generar.hoy();
    Consumos consumodelcomensal(fecha_generar.hoy(), _clientebuscado, _menubuscado);
    ///que la funcion tipo_consumo pueda avisar al resto si el cliente desea cancelar toda la operacion
    arch.Guardar(consumodelcomensal); //podria pasar esta linea abajo de todo para validar antes si quiero cancelar
    CuentaCorriente actualizar_cuenta;
    int cantregistros=arch2.CantidadRegistros();
    for (int i=0; i<cantregistros; i++)
    {
        actualizar_cuenta=arch2.Leer(i);
        if (_clientebuscado.getIDcomensal()==actualizar_cuenta.getcomensal())
        {
            if (tipo_consumo==true)
            {
                float saldoauxiliar=actualizar_cuenta.getSaldoActual();
                saldoauxiliar=actualizar_cuenta.getSaldoActual()+(consumodelcomensal.getimporte()-consumodelcomensal.getimporte()/10);
                if (saldoauxiliar<0)
                {
                    tiene_deuda=true;
                }
                CuentaCorriente actualizar_cuenta(i, _clientebuscado, saldoauxiliar, tiene_deuda);

                arch2.Guardar(actualizar_cuenta, i); ///uso la posicion i porque es una sobreescritura
                Pagos pago_guardar (_clientebuscado, _menubuscado.getvalorplato(), fecha_generar.hoy());
                arch4.Guardar(pago_guardar); ///aca guardo un pago
                int cantregistros2=arch3.CantidadRegistros();
                Factura fc_consumo(cantregistros2+1, _clientebuscado, fecha_generar.hoy(), _menubuscado, _menubuscado.getvalorplato(), tipo_consumo);
                arch3.Guardar(fc_consumo); ///0002-00001
                cliente_encontrado=true;
                break;
            }
            else ///esto es si paga por cuenta corriente
            {
                float saldoauxiliar=actualizar_cuenta.getSaldoActual();
                saldoauxiliar=actualizar_cuenta.getSaldoActual()-consumodelcomensal.getimporte();
                if (saldoauxiliar<0)
                {
                    tiene_deuda=true;
                }
                CuentaCorriente actualizar_cuenta(i, _clientebuscado, saldoauxiliar, tiene_deuda);
                arch2.Guardar(actualizar_cuenta, i); ///uso la posicion i porque es una sobreescritura
                int cantregistros2=arch3.CantidadRegistros();
                Factura fc_consumo(cantregistros2+1, _clientebuscado, fecha_generar.hoy(), _menubuscado, _menubuscado.getvalorplato(), tipo_consumo);
                arch3.Guardar(fc_consumo);
                cliente_encontrado=true;
                break;
            }
        }
    }
    if (cliente_encontrado==false)
    {
        cantregistros=arch2.CantidadRegistros()+1;
        float saldoauxiliar=actualizar_cuenta.getSaldoActual();
        saldoauxiliar=actualizar_cuenta.getSaldoActual()-consumodelcomensal.getimporte();
        tiene_deuda=true;
        CuentaCorriente actualizar_cuenta(cantregistros+1, _clientebuscado, 0-saldoauxiliar, tiene_deuda);
        arch2.Guardar(actualizar_cuenta);
        int cantregistros2=arch3.CantidadRegistros();
        Factura fc_consumo(cantregistros2+1, _clientebuscado, fecha_generar.hoy(), _menubuscado, _menubuscado.getvalorplato(), tipo_consumo);
        arch3.Guardar(fc_consumo);
    }
}

bool Menucomensal::tipodeconsumo()
{
    bool loop=false, result;
    int opcion;
    do
    {
        system("cls");
        line('-');
        std::cout << "Desea abonar ahora o generar deuda en cuenta corriente?" << std::endl;
        line('-');
        std::cout << "Pulse 1 para abonar ahora, 2 para cargar deuda en cuenta corriente, 0 para volver" << std::endl;
        std::string entrada = entrada_valida("Seleccione una opcion: ", NUMERO_ENTERO);
        opcion = std::stoi(entrada);
        switch(opcion)
        {
        case 1:
            std::cout << "Gracias por abonar, pago generado exitosamente!" << std::endl;
            system("pause");
            system("cls");
            loop=true;
            result=true;
            break;
        case 2:
            std::cout << "Se genero una deuda en su cuenta corriente, puede abonarla mas tarde" << std::endl;
            system("pause");
            system("cls");
            loop=true;
            result=false;
            break;
        case 0:
            break;
        default:
            std::cout << "Opci¢n incorrecta, intente nuevamente" << std::endl;
            system("pause");
            system("cls");
            break;
        }
    }
    while(loop==false);
    return result;
}

/*
void Menucomensal::mostrar(int tipo, int num)
{
    std::vector<Menues> _menubuscado = buscarplatos(tipo); ///falta validar por si falta de los otros tipos
    line('-');
    if (_menubuscado.empty())
    {
        std::cout << "Opción # " << num << " (No disponible)" << std::endl;
        return;
    }
    std::cout << "Opci¢n # " << num << std::endl;
    std::cout << _menubuscado.toString() << std::endl;
}
*/

