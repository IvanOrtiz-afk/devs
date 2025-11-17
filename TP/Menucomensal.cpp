#include <iostream>
#include <string>
#include <cstring>
#include "Menucomensal.h"
#include "Comensales.h"
#include "Menues.h"
#include "Archivos.h"
#include "Consumos.h"

Menucomensal::Menucomensal(Comensal clientebuscado, Menues menubuscado)
{
    _clientebuscado=clientebuscado;
    _menubuscado=menubuscado;
}

void Menucomensal::ejecutarmenu()
{
    int id;
    int opcion;
    bool loop=false;
    const char* tipocom = {"Com£n"};
    const char* tipoveg = {"Vegetariano"};
    const char* tipocel = {"Cel¡aco"};
    line('*');
    std::cout << "BIENVENIDO AL COMEDOR" << endl;
    line('*');
    do
    {
        std::cout << "Por favor ingrese su ID de cliente:";
        cin >> id;
        _clientebuscado=buscarcliente(id, loop);
    }
    while(loop==false);
    system("cls");
    std::cout << "Bienvenido " << _clientebuscado.getNombre() << std::endl;
    system("cls");
    std::cout << "Estos son los men£s del d¡a:" << std::endl;
    mostrar(tipocom, 1);
    mostrar(tipoveg, 2);
    mostrar(tipocel, 3);
    std::cout << "Seleccione la opcion deseada:";
    cin >> opcion;
    switch (opcion)
    {
    case 1:
        _menubuscado=buscarplatos(tipocom); ///aca se carga el consumo

        break;
    case 2:
        _menubuscado=buscarplatos(tipoveg); ///aca se carga el consumo
        break;
    case 3:
        _menubuscado=buscarplatos(tipocel); ///aca se carga el consumo
        break;
    }
}

Menues Menucomensal::buscarplatos(const char* tipo)
{
    Archivos <Menues> arch ("Menues.dat");
    Menues menu;
    Fecha fecha_actual;
    int registros=arch.CantidadRegistros();
    for (int i=0; i<registros; i++)
    {
        menu=arch.Leer(i);
        if (fecha_actual.hoy()==menu.getfecha()&&_clientebuscado.getIDestablecimiento()==menu.getesta()&&strcmp(tipo, menu.gettipo())==0)
        {
            return menu;
            break;
        }
        else
        {
            return menu=Menues();
            break;
        };
    }
    return menu;
}

Comensal Menucomensal::buscarcliente(int id, bool &loop)
{
    Archivos <Comensal> arch ("Comensales.dat");
    Comensal cliente;
    int registros=arch.CantidadRegistros();
    for (int i=0; i<registros; i++)
    {
        cliente=arch.Leer(i);
        if (id==cliente.getIDcomensal())
        {
            return cliente;
            break;
        }
        else
        {
            std::cout << "El ID ingresado no es v lido o no existe, intente nuevamente" << std::endl;
            loop=false;
            return cliente=Comensal();
            break;
        };
    }
    return cliente;
}

void Menucomensal::generarconsumo()
{
    Fecha fecha_generar;
    int id_generar;
    bool tipomov_generar;
    const char* plato_generar;
    float precio_generar;
    const char* tipomenu_generar;
    Consumos consumodelcomensal;
    fecha_generar=_menubuscado.getfecha();
    id_generar=_clientebuscado.getIDcomensal();
    tipomov_generar=tipodeconsumo(); ///pasar la clase completa
    plato_generar=_menubuscado.getnombremenu();
    precio_generar=_menubuscado.getvalorplato();
    tipomenu_generar=_menubuscado.gettipo();
    consumodelcomensal(_menubuscado.getfecha(), _clientebuscado.getIDcomensal(), )

}

bool Menucomensal::tipodeconsumo()
{
    system("cls");
    line('-');
    std::cout << "Desea abonar ahora o generar deuda en cuenta corriente?" << std::endl;
    line('-');
    std::cout << "Pulse 1 para abonar ahora o 2 para cargar deuda en cuenta corriente" << std::endl;
    cin >> opcion;
    switch(opcion)
    {
    case 1:
        return true;
        break;
    case 2:
        return false;
        break;
    }
}

void Menucomensal::mostrar(const char* tipo, int num)
{
    _menubuscado=buscarplatos(tipo);
    std::cout << "Opci¢n # " << num << std::endl;
    std::cout << _menubuscado.toString() << std::endl;
}

