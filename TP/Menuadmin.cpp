#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include "MenuPadreABML.h"
#include "MenuSistema.h"
#include "Menuadmin.h"
#include "Archivos.h"
#include "Pagos.h"
#include "Menues.h"
#include "Establecimientos.h"

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
    fecha_hoy.hoy();
    int registros=arch.CantidadRegistros();
    for (int i=0; i<registros; i++)
    {
        plato_muestra=arch.Leer(i);
        if (fecha_hoy.hoy()==plato_muestra.getfecha())
        {
            std::cout << plato_muestra.toString() << std::endl;
        }
        else if (fecha_hoy.hoy()!=plato_muestra.getfecha()&&registros==i-1)
        {
            std::cout << "No se encontro ningun plato para el d¡a de hoy" << std::endl;
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
    fecha_hoy.hoy();
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
    fecha_hoy.hoy();
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
                if (idesta!=esta_muestra.getidestablecimiento()&&j-1==registro)
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
    fecha_hoy.hoy();
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
            else if (id_comensal!=comensal_muestra.getIDcomensal()&&registros==i-1)
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
            else if (registros==i-1&&id_menu!=plato_muestra.getidmenu())
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
            else if (id_buscado!=cc_muestra.getcomensal()&&registros==i-1)
            {
                std::cout << "Usuario no encontrado o no existe, intente nuevamente" << std::endl;
                loop=false;
                break;
            }
        }
    }
    while(loop==false);
}

void Menuadmin::cargarestablecimiento()
{
    Archivos <Establecimientos> arch_establecimientos ("Establecimientos.dat");
    int idestablecimiento;
    std::string nombreestablecimiento, direccionesta, tipoesta;
    std::cout << "NUEVO ESTABLECIMIENTO" << std::endl;
    std::cout << "-----------------------------" << std::endl;
    std::cout << "ingrese el ID del nuevo establecimiento:" << std::endl;
    std::cin >> idestablecimiento;

    std::cout << "ingrese el nombre:" << std::endl;
    std::cin >> nombreestablecimiento;

    std::cout << "ingrese la direccion:" << std::endl;
    std::cin >> direccionesta;

    std::cout << "Ingrese el tipo de establecimiento:" << std::endl;
    std::cin >> tipoesta;

    Establecimientos esta_muestra(idestablecimiento, nombreestablecimiento.c_str(), direccionesta.c_str(), tipoesta.c_str());

    if (arch_establecimientos.Guardar(esta_muestra)== true)
    {
        system("pause");
        system("cls");
        std::cout << "El establecimiento se guardo exitosamente" << std::endl;
    }
    else
    {
        system("pause");
        system("cls");
        std::cout << "Algo salio mal. Intente mas tarde" << std::endl;
    }

}

void Menuadmin::listarestablecimientos()
{
    Archivos <Establecimientos> arch_establecimientos ("Establecimientos.dat");
    int cantidad = arch_establecimientos.CantidadRegistros();
    std::cout << "LISTADO DE ESTABLECIMIENTOS"  << std::endl;
    std::cout << "---------------------------------------"  << std::endl;
    for (int i= 0; i < cantidad; i++)
    {
        Establecimientos establecimientos_muestra = arch_establecimientos.Leer(i);
        mostrarestablecimientos(establecimientos_muestra);
        std::cout << "---------------------------------------" << std::endl;

    }
}

void Menuadmin::mostrarestablecimientos(Establecimientos establecimientos_muestra)
{

    std::cout << "ID: " << establecimientos_muestra.getidestablecimiento() << std::endl;
    std::cout << "Nombre: " << establecimientos_muestra.getnombreestablecimiento() << std::endl;
    std::cout << "Direccion: " << establecimientos_muestra.getdireccionesta() << std::endl;
    std::cout << "Tipo de establecimiento: " << establecimientos_muestra.gettipoesta() << std::endl;
}

void Menuadmin::cargarcomensales()
{
    Archivos <Comensal> arch_comensales ("Comensales.dat");
    int idcomensal, idestablecimiento;
    std::string nombre, direccion;
    int dia, mes, anio;
    Establecimientos guardar_id;


    std::cout << "NUEVO COMENSAL" << std::endl;
    std::cout << "-----------------------------" << std::endl;
    std::cout << "ingrese el ID del nuevo comensal:" << std::endl;
    std::cin >> idcomensal;

    std::cout << "ingrese el nombre:" << std::endl;
    std::cin >> nombre;

    std::cout << "ingrese direccion" << std::endl;
    std::cin >> direccion;

    std::cout << "ingrese dia de nacimiento: ";
    std::cin >> dia;
    std::cout << "ingrese mes de nacimiento: ";
    std::cin >> mes;
    std::cout << "ingrese anio de nacimiento: ";
    std::cin >> anio;

    std::cout << "Ingrese el ID del establecimiento:" << std::endl;
    std::cin >> idestablecimiento;

    guardar_id.setidestablecimiento(idestablecimiento);
    Fecha fechanacimiento (dia, mes, anio);
    Comensal comensal_muestra(idcomensal, nombre.c_str(), direccion.c_str(), fechanacimiento, guardar_id);

    if (arch_comensales.Guardar(comensal_muestra)== true)
    {
        system("pause");
        system("cls");
        std::cout << "El comensal se guardo exitosamente" << std::endl;
    }
    else
    {
        system("pause");
        system("cls");
        std::cout << "Algo salio mal. Intente mas tarde" << std::endl;
    }
}

void Menuadmin::listarcomensales()
{
    Archivos <Comensal> arch_comensales ("Comensales.dat");
    int cantidad = arch_comensales.CantidadRegistros();
    std::cout << "LISTADO DE COMENSALES"  << std::endl;
    std::cout << "---------------------------------------"  << std::endl;
    for (int i= 0; i < cantidad; i++)
    {
        Comensal comensal_muestra = arch_comensales.Leer(i);
        mostrarcomensales(comensal_muestra);
        std::cout << "---------------------------------------" << std::endl;

    }
}

void Menuadmin::mostrarcomensales(Comensal comensal_muestra)
{
    std::cout << "ID: " << comensal_muestra.getIDcomensal() << std::endl;
    std::cout << "Nombre: " << comensal_muestra.getNombre() << std::endl;
    std::cout << "Direccion: " << comensal_muestra.getDireccion() << std::endl;
    std::cout << "Fecha de nacimiento: " << comensal_muestra.getFechaNacimiento().toString()<< std::endl;
    std::cout << "ID Establecimiento : " << comensal_muestra.getIDestablecimiento() << std::endl;
}

void Menuadmin::listarconsumos()
{
    Archivos <Consumos> arch_consumos ("Consumos.dat");
    int cantidad = arch_consumos.CantidadRegistros();
    std::cout << "LISTADO DE CONSUMOS"  << std::endl;
    std::cout << "---------------------------------------"  << std::endl;
    for (int i= 0; i < cantidad; i++)
    {
        Consumos consumos_muestra = arch_consumos.Leer(i);
        mostrarconsumos(consumos_muestra);
        std::cout << "---------------------------------------" << std::endl;
    }
}

void Menuadmin::mostrarconsumos(Consumos consumos_muestra)
{
    std::cout << "Fecha del consumo: " << consumos_muestra.getfecha().toString() << std::endl;
    std::cout << "ID del cliente: " << consumos_muestra.getcliente() << std::endl;
    std::cout << "Plato consumido: " << consumos_muestra.getplato() << std::endl;
}

void Menuadmin::cargarpago()
{
    Archivos <Pagos> arch ("Pagos.dat");
    Archivos <Comensal> arch2 ("Comensales.dat");
    Archivos <CuentaCorriente> arch3 ("CC.dat");
    Archivos <Factura> arch4 ("Facturas.dat");
    Fecha fecha_actual;
    fecha_actual.hoy();
    Pagos pago_cargar;
    CuentaCorriente CC_buscado;
    Factura fc_generar;
    Comensal comensal_buscado;
    int id_buscado;
    float importe_cargar;
    float saldo_final;
    bool loop=false;
    do
    {
        std::cout << "Seleccione el ID del comensal" << std::endl;
        std::cin >> id_buscado;
        int registros=arch2.CantidadRegistros();
        for (int i=0; i<registros; i++)
        {
            comensal_buscado=arch2.Leer(i);
            if (id_buscado==comensal_buscado.getIDcomensal())
            {
                std::cout << "Comensal encontrado bajo el ID Nø " << comensal_buscado.getIDcomensal() << std::endl;
                loop=true;
                break;
            }
            else if (id_buscado!=comensal_buscado.getIDcomensal()&&registros==i-1)
            {
                std::cout << "Comensal NO encontrado, intente nuevamente" << std::endl;
            }
        }
    }
    while(loop==false);
    do
    {
        std::cout << "Indique el importe para cargar el pago" << std::endl;
        line('-');
        std::cout << "Importe: $";
        std::cin >> importe_cargar;
        int registros=arch3.CantidadRegistros();
        for (int i=0; i<registros; i++)
        {
            CC_buscado=arch3.Leer(i);
            if (CC_buscado.getcomensal()==comensal_buscado.getIDcomensal())
            {
                pago_cargar.setIDcomensal(comensal_buscado);
                pago_cargar.setimporte(importe_cargar);
                pago_cargar.setfecha(fecha_actual.hoy());
                saldo_final=CC_buscado.getSaldoActual()-importe_cargar;
                CC_buscado.setSaldoActual(saldo_final);
                if (arch3.Guardar(CC_buscado, i)==true&&arch.Guardar(pago_cargar)==true) ///sobreescritura
                {
                    loop=true;
                    std::cout << "Pago agregado exitosamente, Cuenta corriente actualizada" << std::endl;
                    break;
                }
            }
            else if((arch3.Guardar(CC_buscado, i)==false)||(arch.Guardar(pago_cargar)==false))
            {
                std::cout << "Error de guardado, intente nuevamente" << std::endl;
            }
        }
    }
    while(loop==false);
    int seleccion;
    std::cout << "Desea generar factura para el pago cargado?" << std::endl;
    std::cout << "1. Si / 2. No" << std::endl;
    std::cin >> seleccion;
    switch (seleccion)
    {
    case '1':
        do
        {
            int registro=arch4.CantidadRegistros();
            for (int i=0; i<registro; i++)
            {
                fc_generar=arch4.Leer(i);
                if (fc_generar.getIDcomensal()==comensal_buscado.getIDcomensal())
                {
                    fc_generar.setNumeracion(registro+1);
                    fc_generar.setIDcomensal(comensal_buscado);
                    fc_generar.setFecha(fecha_actual.hoy());
                    fc_generar.setImporte(saldo_final);
                    if (arch4.Guardar(fc_generar)==true)
                    {
                        std::cout << "Factura generada correctamente" << std::endl;
                        break;
                    }
                    else if (arch4.Guardar(fc_generar)!=true)
                    {
                        std::cout << "Error al generar la factura, intente nuevamente" << std::endl;
                        loop=false;
                        break;
                    }
                }
            }
        }
        while(loop==false);
    case '2':
        std::cout << "Recuerde que debe generarla la factura mas tarde" << std::endl;
        break;
    }
}

void Menuadmin::listarpago()
{
    Archivos <Pagos> arch ("Pagos.dat"); ///si se puede, listar pagos por comensal
    Pagos pago_listado;

    line('*');
    std::cout << "Listando pagos cargados" << std::endl;
    line('*');

    int registros=arch.CantidadRegistros();
    for (int i=0; i<registros; i++)
    {
        pago_listado=arch.Leer(i);
        std::cout << pago_listado.toString() << std::endl;
        line('-', 50);
    }
}
