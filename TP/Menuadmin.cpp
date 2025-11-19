#include <iostream>
#include <string>
#include "MenuPadreABML.h"
#include "Menuadmin.h"
#include "Archivos.h"
#include "Menues.h"

Menuadmin::Menuadmin()
    :MenuPadreABML()
{

}

Menuadmin::~Menuadmin()
{

}

void Menuadmin::listarplatos()
{
    Archivos <Menues> arch ("Menues.dat");
    Menues plato_muestra;
    Fecha fecha_hoy;
    int registros=arch.CantidadRegistros();
    for (int i=0; i<registros; i++)
    {
        plato_muestra=arch.Leer(i);
        if (fecha_hoy.hoy()==plato_muestra.getfecha())
        {
            std::cout << plato_muestra.toString() << std::endl;
        }
    }
}

void Menuadmin::valoraciones()
{
    Archivos <Menues> arch ("Menues.dat");
    Menues plato_muestra;
    int valoracion;
    int registros=arch.CantidadRegistros();
    for (int i=0; i<registros; i++)
    {
        plato_muestra=arch.Leer(i);
        valoracion=plato_muestra.getvaloracion(); ///construir una funcion para que sume las valoraciones
        std::cout << "El plato: " << std::endl;
        std::cout << plato_muestra.toString() << std::endl;
        std::cout << "Con una valoracion de " << valoracion << std::endl;
    }
}

void Menuadmin::cargarplato()
{
    Archivos <Menues> arch ("Menues.dat");
    Archivos <Establecimientos> arch2 ("Establecimientos.dat");
    Archivos <TipoAlmuerzo> arch3 ("TipoAlmuerzo.dat");
    std::string nombremenu;
    int idesta; ///MAL
    float importe;
    int tipomenu, i=0; ///MAL
    bool guardar_ok;
    Establecimientos esta_muestra;
    TipoAlmuerzo tipo_muestra;
    Menues plato_muestra;
    Fecha fecha_hoy;
    do
    {
        std::cout << "Ingrese el nombre del men£ nuevo" << std::endl;
        std::cin >> nombremenu;
        do
        {
            std::cout << "Ingrese el ID del establecimiento" << std::endl;
            std::cin >> idesta;
            int registro=arch2.CantidadRegistros();
            bool loop=true;
            for (int j=0; j<registro; j++)
            {
                esta_muestra=arch2.Leer(i);
                if (idesta!=esta_muestra.getidestablecimiento()&&j==registro)
                {
                    std::cout << "ID ingresado no v lido o no existe, intente nuevamente" << std::endl;
                    loop=false;
                }
            }
        }
        while(loop==false); ///CONTINUAR A PARTIR DE ACA, TODO ROTO
        std::cout << "Ingrese el valor del plato" << std::endl;
        std::cin >> importe;
        loop=true;
        do
        {
            std::cout << "Ingrese el tipo de plato" << std::endl;
            std::cout << "1. Men£ com£n" << std::endl;
            std::cout << "2. Men£ vegetariano" << std::endl;
            std::cout << "3. Men£ cel¡aco" << std::endl;
            std::cin >> tipomenu;
            if (tipomenu<1||tipomenu>3)
            {
                std::cout << "Opci¢n no v lida, intente nuevamente" << std::endl;
                loop=false;
            }
        }
        while(loop==false);
        i=arch.CantidadRegistros()+1;
        plato_muestra(i, nombremenu, idesta, importe, tipomenu, fecha_hoy.hoy());
        guardar_ok=arch.Guardar(plato_muestra);
        if (guardar_ok==true)
        {
            system("pause");
            system("cls");
            std::cout << "Men£ cargado satisfactoriamente bajo el ID Nø " << i << std::endl;
        }
        else
        {
            system("pause");
            system("cls");
            std::cout << "ERROR del sistema al cargar el registro, intente nuevamente" << std::endl;
        }
    }
    while(guardar_ok==false);
}

void Menuadmin::eliminarplato()
{




}
