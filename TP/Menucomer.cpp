#include <iostream>
#include <ctime>
#include <cstring>
#include <string>
#include "Menucomer.h"
#include "Menuapp.h"
#include "Fecha.h"
#include "Comensales.h"
#include "Archivos.h"

Menucomer::Menucomer()
{
    idcliente=0;
}

void Menucomer::menugeneral()
{
    int id;
    const char tipocom[]= {"Com£n"};
    const char tipocel[]= {"Cel¡aco"};
    const char tipoveg[]= {"Vegetariano"};
    line('=');
    std::cout << "BIENVENIDO AL COMEDOR!" << std::endl;
    line('=');
    std::cout << "Ingrese su ID de cliente" << std::endl;
    line('-');
    std::cin >> id;
    setidcliente(id);
    ejecutor();
    line ('*');
    std::cout << "Bienvenido!" << clientebuscado.getNombre() << std::endl; ///hacerlo por un to_string
    line ('*');
    std::cout << "Estos son los menues de hoy" << std::endl;
    line ('*');
    menues(tipocom);
    if (strcmp(menubuscado.gettipo(), tipocom)!=0)
    {
        std::cout << "No existen menues comunes cargados para el dia de la fecha" << std::endl;
    }
    else
    {
        std::cout << "Opci¢n 1: Men£ standar" << std::endl;
        std::cout << menubuscado.toString() << std::endl;
    }
    menues(tipocel);
    if (strcmp(menubuscado.gettipo(), tipocel)!=0)
    {
        std::cout << "No existen menues cel¡acos cargados para el dia de la fecha" << std::endl;
    }
    else
    {
        std::cout << "Opci¢n 2: Men£ cel¡aco" << std::endl;
        std::cout << menubuscado.toString() << std::endl;
    }
    menues(tipoveg);
    if (strcmp(menubuscado.gettipo(), tipoveg)!=0)
    {
        std::cout << "No existen menues vegetarianos cargados para el dia de la fecha" << std::endl;
    }
    else
    {
        std::cout << "Opci¢n 3: Men£ vegetariano" << std::endl;
        std::cout << menubuscado.toString() << std::endl;
    }
    seleccion();
};

/**void Menucomer::seleccion()
{
    ingresopcion();
    switch (opcionmenu)
    {
    case '1':
///crear clase de consumo

    case '2':
///crear clase de consumo

    case '3':
///crear clase de consumo
    };
};*/

void Menucomer::formadepago()
{


};

Menues Menucomer::menues(const char* tipo)
{
    Fecha fecha_actual;
    Archivos <Menues> arch ("Menues.h");
    int registros=arch.CantidadRegistros();
    for (int i=0; i<registros; i++)
    {
        menubuscado=arch.Leer(i);
        if (fecha_actual.hoy()==menubuscado.getfecha()&&clientebuscado.getIDestablecimiento()==menubuscado.getesta()&&strcmp(tipo, menubuscado.gettipo())==0)
        {
            return menubuscado;
            break;
        };
    }
    return Menues();
};

void Menucomer::ejecutor()
{
    bool ingreso_ok=true;
    do
    {
        ingreso_ok=ingreso();
        if(ingreso_ok==false)
        {
            std::cout << "El ID no es v lido, intente nuevamente" << std::endl;
        };
    }
    while(ingreso_ok==false);
};

void Menucomer::setidcliente(int id)
{
    idcliente=id;
};

int Menucomer::getidcliente()
{
    return idcliente;
};

bool Menucomer::ingreso()
{
    Archivos <Comensal> arch ("Comensales.h");
    clientebuscado=arch.Leer(idcliente);
    if (clientebuscado.getIDcomensal()!=idcliente)
    {
        return false;
    };
    return true;
};
