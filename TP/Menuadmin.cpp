#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include "MenuPadreABML.h"
#include "MenuSistema.h"
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

void Menuadmin::cargarvaloracion()
{
    Archivos <Menues> arch ("Menues.dat");
    Menues plato_muestra;
    Fecha fecha_hoy;
    bool ejecutar_ok=false;
    int valoracion=0;
    int numero, j=0;
    std::vector<int> id_aux;
    int registros=arch.CantidadRegistros();
    for (int i=0; i<registros; i++)
    {
        plato_muestra=arch.Leer(i);
        if (fecha_hoy.hoy()==plato_muestra.getfecha())
        {
            id_aux.push_back(plato_muestra.getidmenu());
            j++;
            std::cout << "Plato del d¡a Nø " << j << std::endl;
            std::cout << plato_muestra.toString() << std::endl;
        }
    }
    do
    {
        line('-');
        std::cout << "Seleccione el plato que desea agregar una valoraci¢n" << std::endl;
        line('-');
        std::cin >> numero;
        for (size_t i=0; i<id_aux.size(); i++) ///uso size_t porque int es un entero que puede ser negativo
        {
            ///y id_aux.size() me devuelve un entero SIN SIGNOS, size_t es igual a int solo que no usa signos
            if (numero==id_aux[i])
            {
                for (int x=0; x<registros; x++)
                {
                    plato_muestra=arch.Leer(x);
                    if (numero==plato_muestra.getidmenu())
                    {
                        std::cout << "Agregar una valoraci¢n: ";
                        std::cin >> valoracion;
                        system ("pause");
                        plato_muestra.setvaloracion(valoracion); ///no pude agregar comprobacion de guardado
                        ejecutar_ok=arch.Guardar(plato_muestra);
                        if (ejecutar_ok==false)
                        {
                            std::cout << "Error de guardado, intente nuevamente" << std::endl;
                            break;
                        }
                        break;
                    }
                }
            }
        }
        if (ejecutar_ok==false&&valoracion==0)
        {
            std::cout << "N£mero de plato NO v lido, intente nuevamente" << std::endl;
            system ("pause");
            system ("cls");
        }
    }
    while(ejecutar_ok==false);
}

void Menuadmin::cargarplato()
{
    Archivos <Menues> arch ("Menues.dat");
    Archivos <Establecimientos> arch2 ("Establecimientos.dat");
    Archivos <TipoAlmuerzo> arch3 ("TipoAlmuerzo.dat");
    std::string nombremenu;
    int idesta;
    float importe;
    const char *nombre_aux= {};
    int tipomenu, i=0;
    bool guardar_ok, loop=true;
    Establecimientos esta_muestra;
    Menues plato_muestra;
    Fecha fecha_hoy;
    do
    {
        std::cout << "Ingrese el nombre del men£ nuevo" << std::endl;
        std::cin >> nombremenu;
        nombre_aux=nombremenu.c_str();
        plato_muestra.setnombremenu(nombre_aux);
        do
        {
            std::cout << "Ingrese el ID del establecimiento" << std::endl;
            std::cin >> idesta;
            int registro=arch2.CantidadRegistros();
            for (int j=0; j<registro; j++)
            {
                esta_muestra=arch2.Leer(i);
                if (idesta==esta_muestra.getidestablecimiento())
                {
                    plato_muestra.setesta(esta_muestra);
                }
                if (idesta!=esta_muestra.getidestablecimiento()&&j==registro)
                {
                    std::cout << "ID ingresado no v lido o no existe, intente nuevamente" << std::endl;
                    loop=false;
                    break;
                }
            }
        }
        while(loop==false);
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
                break;
            }
            else
            {
                plato_muestra.setidtipo(tipomenu);
            }
        }
        while(loop==false);
        i=arch.CantidadRegistros()+1;
        plato_muestra.setidmenu(i);
        plato_muestra.setfecha(fecha_hoy.hoy());
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
            break;
        }
    }
    while(guardar_ok==false);
}

void Menuadmin::eliminarplato()
{
///aca vamos a usar un funcion que vamos a hacer en Archivos.h
    /**
    Aclaraci¢n sobre el Flujo de Nombres
    El flujo siempre es:

    El archivo que todas las funciones usan se llama menues.dat.

    Para borrar, el programa crea temp.dat.

    Una vez finalizada la copia filtrada, el programa borra menues.dat.

    Finalmente, el programa renombra temp.dat a menues.dat.

    De esta manera, las dem s funciones siempre operan sobre menues.dat.
    */
}

void Menuadmin::listarfacturas()
{
    Archivos <Factura> arch ("Facturas.dat");
    Factura fc_muestra;
    bool loop=true;
    int seleccion_id, j=0;
    do
    {
        std::cout << "Seleccione su/el ID de usuario" << std::endl;
        std::cin >> seleccion_id;
        int registros=arch.CantidadRegistros();
        for (int i=0; i<registros; i++)
        {
            fc_muestra=arch.Leer(i);
            if (fc_muestra.getIDcomensal()==seleccion_id)
            {
                j++;
                std::cout << "Factura del comensal " << std::string(fc_muestra.getnombrecomensal()) << " Nø " << j << std::endl;
                std::cout << fc_muestra.FCtoString() << std::endl;
            }
            else
            {
                std::cout << "ID no encontrado o no v lido, intente nuevamente" << std::endl;
                loop=false;
                break;
            }
        }
    }
    while(loop==false);
}

void Menuadmin::cargarfactura()
{
    Archivos <Factura> arch ("Facturas.dat");
    Archivos <Comensal> arch2 ("Comensales.dat");
    Archivos <Menues> arch3 ("Menues.dat");
    Menues plato_muestra;
    Factura fc_muestra;
    Comensal comensal_muestra;
    Fecha fecha_hoy;
    float importe_muestra;
    int id_comensal;
    bool loop=true;
    do
    {
        std::cout << "Seleccione su/el ID de usuario para generar factura" << std::endl;
        std::cin >> id_comensal;
        int registros=arch2.CantidadRegistros();
        for (int i=0; i<registros; i++)
        {
            comensal_muestra=arch2.Leer(i);
            if (id_comensal==comensal_muestra.getIDcomensal())
            {
                std::cout << "Comenzal " << std::string(comensal_muestra.getNombre()) << " encontrado" << std::endl;
                fc_muestra.setIDcomensal(comensal_muestra);
            }
            else if (id_comensal!=comensal_muestra.getIDcomensal()&&registros==i)
            {
                std::cout << "Comenzal NO encontrado o no existe, intente nuevamente" << std::endl;
                loop=false;
                break;
            }
        }
    }
    while(loop==false);
    std::cout << "Ingrese el importe a facturar: "; ///verificar valores negativos
    std::cin >> importe_muestra;
    fc_muestra.setImporte(importe_muestra);
    bool mediopago_muestra=false;
    fc_muestra.setMedioDePago(mediopago_muestra);
    do
    {
        std::cout << "Seleccione el ID de el men£ consumido por el comensal" << std::endl;
        int registros=arch3.CantidadRegistros();
        for (int i=0; i<registros; i++)
        {
            plato_muestra=arch3.Leer(i);
            if (fecha_hoy.hoy()==plato_muestra.getfecha())
            {
                std::cout << plato_muestra.toString() << " ID n£mero " << plato_muestra.getidmenu() << std::endl;
            }
        }
        int id_menu=0;
        std::cin >> id_menu;
        registros=arch3.CantidadRegistros();
        for (int i=0; i<registros; i++)
        {
            plato_muestra=arch3.Leer(i);
            if (fecha_hoy.hoy()==plato_muestra.getfecha()&&id_menu==plato_muestra.getidmenu())
            {
                fc_muestra.setIDmenu(plato_muestra);
                loop=true;
            }
            else if (registros==i&&id_menu!=plato_muestra.getidmenu())
            {
                std::cout << "Men£ no encontrado o no existe, intente nuevamente" << std::endl;
                loop=false;
                break;
            }
        }
        registros=arch.CantidadRegistros()+1;
        fc_muestra.setNumeracion(registros);
        loop=arch.Guardar(fc_muestra);
        if (loop==false)
        {
            std::cout << "Error en guardado del archivo, intente nuevamente" << std::endl;
        }
    }
    while(loop==false);
}

void Menuadmin::verCC()
{
    Archivos <CuentaCorriente> arch ("CC.dat");
    CuentaCorriente cc_muestra;
    bool loop=true;
    int id_buscado;
    do
    {
        std::cout << "Ingrese el ID de usuario para ver cuenta corriente" << std::endl;
        std::cin >> id_buscado;
        int registros=arch.CantidadRegistros();
        for (int i=0; i<registros; i++)
        {
            cc_muestra=arch.Leer(i);
            if (id_buscado==cc_muestra.getcomensal())
            {
                std::cout << "Estado de cuenta del usuario " << std::string(cc_muestra.getnombrecomensal()) << ":" << std::endl;
                std::cout << cc_muestra.toString() << std::endl;
                loop=true;
            }
            else if (id_buscado!=cc_muestra.getcomensal()&&registros==i)
            {
                std::cout << "Usuario no encontrado o no existe, intente nuevamente" << std::endl;
                loop=false;
                break;
            }
        }
    }
    while(loop==false);
}



