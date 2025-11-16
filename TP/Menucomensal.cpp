#include <iostream>
#include <string>
#include <cstring>
#include "Menucomensal.h"
#include "Comensales.h"
#include "Menues.h"
#include "Archivos.h"

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
    if (opcion==1)
    {
        _menubuscado=buscarplatos(tipocom); ///aca se carga el consumo
    }
    else if (opcion==2)
    {
        _menubuscado=buscarplatos(tipoveg); ///aca se carga el consumo
    }
    else if (opcion==3)
    {
        _menubuscado=buscarplatos(tipocel); ///aca se carga el consumo
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
        { ///agregar id de establecimiento a la clase menues
            return menu;
            break;
        }
        else
        {
            return menu=Menues();
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
        };
    }
    return cliente;
}

void Menucomensal::mostrar(const char* tipo, int num)
{
    _menubuscado=buscarplatos(tipo);
    std::cout << "Opci¢n # " << num << std::endl;
    std::cout << _menubuscado.toString() << std::endl;
}

