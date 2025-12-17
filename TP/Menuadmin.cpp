#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <cctype>
#include "MenuPadreABML.h"
#include "MenuSistema.h"
#include "Menuadmin.h"
#include "Archivos.h"
#include "TipoAlmuerzo.h"
#include "Pagos.h"
#include "Menues.h"
#include "Establecimientos.h"
#include "usuario.h"
#include "Utilidades.h"

Menuadmin::Menuadmin()
    :MenuPadreABML()
{

}

Menuadmin::~Menuadmin()
{

}

/* FALTA HACER:

#PRIORIDAD 1:
-TERMINAR CON LOS BUGS Y LOS IGNORE/GETLINE (menucomensal, facturas, CC, consumos) -> OK
-VER MENU POR FECHA -> OK
-CARGAR MENU DE TODA LA SEMANA  -> OK
-CREAR ELIMINACIONES DE REGISTROS -> OK
-EDITAR REGISTROS -> OK
-REPORTES:
CANT. DE PLATOS CONSUMIDOS POR FECHA -> OK
PLATOS MAS VENDIDOS -> OK
PLATOS MEJOR VALORADOS -> OK

#PRIORIDAD 2:
-CONFIGURACIONES:
REALIZAR COPIAS DE SEGURIDAD -> OK
RESTAURAR COPIA DE SEGURIDAD -> OK
EXPORTAR DATOS -> OK
CAMBIAR TEMA
-PONER TODO MAS LINDO

#PRIORIDAD 3:
-VER FACTURA POR FECHA
-VER CONSUMO POR FECHA
-VER FACTURA POR ESTABLECIMIENTO
*/


void Menuadmin::platosmejor_valor() ///Muestra siempre el top 3 de los platos mejor valorados de la semana
{
    Archivos <Menues> arch_menus ("Menues.dat");
    Archivos <Establecimientos> arch_esta ("Establecimientos.dat");
    Menues menu_muestra;
    Establecimientos esta_muestra;

    std::vector<int> dias_semana_mes;
    Fecha fecha_muestra;

    dias_semana_mes=fecha_muestra.obtenerDiasDeLaSemanaActual();
    std::vector <std::string> nombres_esta;
    std::vector <int> valoraciones;
    int valor_prom;

    int registros_esta=arch_esta.CantidadRegistros();
    int registros_menus=arch_menus.CantidadRegistros();
    for (int i=0; i<registros_menus; i++)
    {
        menu_muestra=arch_menus.Leer(i);
        if (std::find(dias_semana_mes.begin(), dias_semana_mes.end(), menu_muestra.getfecha().getDia()) != dias_semana_mes.end())
        {
            int cant_valoracion = menu_muestra.getcant_valoracion();
            if (cant_valoracion <= 0) continue;
            valor_prom = menu_muestra.getvaloracion() / cant_valoracion;

            for (int j=0; j<registros_esta; j++)
            {
                esta_muestra=arch_esta.Leer(j);
                if (esta_muestra.getidestablecimiento()==menu_muestra.getesta())
                {
                    nombres_esta.push_back(esta_muestra.getnombreestablecimiento());
                    valoraciones.push_back(valor_prom);
                    break; // Ya encontramos el nombre ÿ ÿ ÿ ÿ ÿ ÿ ÿ ÿ
                }
            }
        }
    }
    int valor_aux1=0;
    int valor_aux2=0;
    int valor_aux3=0;
    std::string nombre1 = "N/A";
    std::string nombre2 = "N/A";
    std::string nombre3 = "N/A";
    if (valoraciones.empty())
    {
        line('=');
        std::cout << "[AVISO] No se encontraron menus valorados esta semana." << std::endl;
        line('=');
        return;
    }
    for (int x=0; x<valoraciones.size(); x++)
    {
        if (valoraciones[x]>valor_aux1)
        {
            valor_aux3=valor_aux2;
            nombre3=nombre2;
            valor_aux2=valor_aux1;
            nombre2=nombre1;
            valor_aux1=valoraciones[x];
            nombre1=nombres_esta[x];
        }
        else if (valoraciones[x]>valor_aux2)
        {
            valor_aux3=valor_aux2;
            nombre3=nombre2;
            valor_aux2=valoraciones[x];
            nombre2=nombres_esta[x];
        }
        else if (valoraciones[x]>valor_aux3)
        {
            valor_aux3=valoraciones[x];
            nombre3=nombres_esta[x];
        }
    }
    line('=');
    std::cout << "TOP 3 DE MEJORES VALORACIONES DE ESTA SEMANA" << std::endl;
    line('=');
    if (valor_aux1 > 0)
    {
        std::cout << "1. " << std::setw(3) << valor_aux1 << " puntos - " << nombre1 << std::endl;
    }
    if (valor_aux2 > 0)
    {
        std::cout << "2. " << std::setw(3) << valor_aux2 << " puntos - " << nombre2 << std::endl;
    }
    if (valor_aux3 > 0)
    {
        std::cout << "3. " << std::setw(3) << valor_aux3 << " puntos - " << nombre3 << std::endl;
    }
}

void Menuadmin::platosmas_vendidos()
{
    Archivos <Consumos> arch_consu ("Consumos.dat");
    Consumos consumo_muestra;

    std::vector<int> dias_semana_mes= {};
    Fecha fecha_muestra;
    bool plato_encontrado, hubo_consumos=false;

    dias_semana_mes=fecha_muestra.obtenerDiasDeLaSemanaActual(); ///Esta funcion siempre va a contener los dias de la semana actual

    std::vector<PlatoVendido> platos;

    int registros_consu=arch_consu.CantidadRegistros();
    for (int i=0; i<registros_consu; i++)
    {
        consumo_muestra=arch_consu.Leer(i); ///Verifica si el dia del mes esta en la semana actual, si el dia ESTA en la semana entra este if
        if (std::find(dias_semana_mes.begin(), dias_semana_mes.end(), consumo_muestra.getfecha().getDia()) != dias_semana_mes.end())
        {
            plato_encontrado=false;
            hubo_consumos=true;
            for (auto& plato_actual : platos) ///auto declara una variable por referencia "plato_actual" que automaticamente es del mismo tipo
            {
                ///de dato que platos (un vector del struct "PlatoVendido") y va copiando los datos de platos para compararlos
                if (plato_actual.nombre==consumo_muestra.getplato()) ///a su vez con los de consumos, y si dan OK los almacena en el vector de struct
                {
                    plato_actual.cantidadVendida++;
                    plato_encontrado=true;
                    break;
                }
            }
            if (!plato_encontrado)
            {
                std::string nombre_aux=consumo_muestra.getplato();
                platos.push_back(PlatoVendido(nombre_aux, 1)); ///Comparar el string del struct con el const char*
            }
        }
    }
    if (!hubo_consumos)
    {
        std::cout << "[AVISO] No existen platos consumidos esta semana" << std::endl;
    }
    else if (hubo_consumos)
    {
        line('=');
        std::cout << "Se mostrara el top 3 de los platos mas vendidos" << std::endl;
        line('=');
        int cant1=0, cant2=0, cant3=0;
        std::string nombre1, nombre2, nombre3;
        for (int j=0; j<platos.size(); j++)
        {
            if (platos[j].cantidadVendida>cant1)
            {
                cant3=cant2;
                nombre3=nombre2;
                cant2=cant1;
                nombre2=nombre1;
                cant1=platos[j].cantidadVendida;
                nombre1=platos[j].nombre;
            }
            else if(platos[j].cantidadVendida>cant2)
            {
                cant3=cant2;
                nombre3=nombre2;
                cant2=platos[j].cantidadVendida;
                nombre2=platos[j].nombre;
            }
            else if(platos[j].cantidadVendida>cant3)
            {
                cant3=platos[j].cantidadVendida;
                nombre3=platos[j].nombre;
            }
        }
        if (cant1>0)
        {
            std::cout << "1er puesto" << std::endl;
            std::cout << nombre1 << " con una cantidad vendida de " << cant1 << " unidades" << std::endl;
            line('-');
        }
        if (cant2>0)
        {
            std::cout << "2do puesto" << std::endl;
            std::cout << nombre2 << " con una cantidad vendida de " << cant2 << " unidades" << std::endl;
            line('-');
        }
        if (cant3>0)
        {
            std::cout << "3er puesto" << std::endl;
            std::cout << nombre3 << " con una cantidad vendida de " << cant3 << " unidades" << std::endl;
            line('-');
        }
    }
}

void Menuadmin::cant_platosXfecha() ///CONTINUAR ACA
{
    Archivos <Consumos> arch_consu ("Consumos.dat");
    Consumos consumo_muestra;

    std::vector<int> dias_semana_mes= {};
    Fecha fecha_muestra;
    bool plato_encontrado, hubo_consumos=false, loop=false;

    time_t t = time(0);
    tm* now = localtime(&t);
    int anioActual = now->tm_year + 1900;

    std::vector<PlatoVendido> platos;
    do
    {
        int dia_muestra, mes_muestra, anio_muestra;
        bool fechaValida = false;
        line('*');
        std::cout << "Ingreso de fecha" << std::endl;
        line('*');


        do
        {
            std::string entrada=entrada_valida("Ingrese un dia del mes, pulse cero para volver", NUMERO_ENTERO);
            line('-');
            dia_muestra=std::stoi(entrada);
            if (entrada=="0")
            {
                break;
            }
            if (dia_muestra >= 1 && dia_muestra <= 31)
            {
                fechaValida = true;
            }
            else
            {
                std::cout << "[ERROR] Dia invalido. Por favor ingrese un numero entre 1 y 31." << std::endl;

            }
        }
        while(!fechaValida);
        fechaValida = false;
        do
        {
            std::string entrada=entrada_valida("Ingrese mes, pulse cero para volver", NUMERO_ENTERO);
            line('-');
            mes_muestra=std::stoi(entrada);
            if (entrada=="0")
            {
                break;
            }
            if (mes_muestra >= 1 && mes_muestra <= 12)
            {
                fechaValida = true;
            }
            else
            {
                std::cout << "[ERROR] Mes invalido. Por favor ingrese un numero entre 1 y 12." << std::endl;

            }


        }
        while(!fechaValida);
        fechaValida = false;
        do
        {
            std::string entrada=entrada_valida("Ingrese un anio, pulse cero para volver", NUMERO_ENTERO);
            line('-');
            anio_muestra=std::stoi(entrada);
            if (entrada=="0")
            {
                break;
            }
            if (anio_muestra >= 1900 && anio_muestra <= anioActual)
            {
                fechaValida = true;
            }
            else
            {
                std::cout << "[ERROR] Anio invalido." << std::endl;

            }

        }
        while(!fechaValida);
        ///Aca asigno los valores de entrada con fecha_muestra para luego comparar con el archivo .dat de consumos
        fecha_muestra.setDia(dia_muestra);
        fecha_muestra.setMes(mes_muestra);
        fecha_muestra.setAnio(anio_muestra);
        int registros_consu=arch_consu.CantidadRegistros();
        for (int i=0; i<registros_consu; i++)
        {
            consumo_muestra=arch_consu.Leer(i); ///Verifica si el dia del mes esta en la semana actual, si el dia ESTA en la semana entra este if
            if (fecha_muestra==consumo_muestra.getfecha())
            {
                plato_encontrado=false;
                hubo_consumos=true;
                for (auto& plato_actual : platos) ///auto declara una variable por referencia "plato_actual" que automaticamente es del mismo tipo
                {
                    ///de dato que platos (un vector del struct "PlatoVendido") y va copiando los datos de platos para compararlos
                    if (plato_actual.nombre==consumo_muestra.getplato()) ///a su vez con los de consumos, y si dan OK los almacena en el vector de struct
                    {
                        plato_actual.cantidadVendida++;
                        plato_encontrado=true;
                        break;
                    }
                }
                if (!plato_encontrado)
                {
                    std::string nombre_aux=consumo_muestra.getplato();
                    platos.push_back(PlatoVendido(nombre_aux, 1)); ///Comparar el string del struct con el const char*
                }
            }
        }
        if (!hubo_consumos)
        {
            int opcion;
            do
            {
                system("cls");
                std::cout << "[AVISO] No existen platos consumidos esta semana" << std::endl;
                std::string entrada=entrada_valida("Pulse 0 para salir o 1 para volver a ingresar fecha", NUMERO_ENTERO);
                line('-');
                opcion=std::stoi(entrada);
                if (opcion==0)
                {
                    loop=true;
                    break;
                }
                else if (opcion==1)
                {
                    break;
                }
                else
                {
                    std::cout << "[ERROR] Ingrese una entrada valida" << std::endl;
                }
            }
            while(opcion!=0||opcion!=1);
        }
        else if (hubo_consumos)
        {
            loop=true;
            line('=');
            std::cout << "Se mostraran los platos mas vendidos de la fecha " << fecha_muestra.toString() << std::endl;
            line('=');
            for (int j=0; j<platos.size(); j++)
            {
                std::cout << platos[j].nombre << " con una cantidad de " << platos[j].cantidadVendida << std::endl;
            }
        }
        system("pause");
    }
    while(loop==false);
}

void Menuadmin::menuplatos()
{
    int opcion;
    do
    {
        std::cout << "----MENUES----" << std::endl;
        line('-');
        std::cout << "1- VER MENU DE HOY" << std::endl;
        std::cout << "2- VER MENU FILTRANDO POR DIA" << std::endl;
        std::string entrada=entrada_valida("0- Atras", NUMERO_ENTERO);

        int opcion= std::stoi(entrada);

        switch(opcion)
        {
        case 1:
        {
            system("pause");
            system("cls");
            Fecha fecha_hoy;
            fecha_hoy = fecha_hoy.hoy();
            listarplatos(fecha_hoy);
            system("pause");
            system("cls");
            break;
        }
        case 2:
        {
            system("pause");
            system("cls");
            int dia, mes, anio;
            bool fechaValida = false;
            time_t t = time(0);
            tm* now = localtime(&t);
            int anioActual = now->tm_year + 1900;

            do
            {
                std::string entrada=entrada_valida("Ingrese DIA, pulse cero para volver", NUMERO_ENTERO);
                dia=std::stoi(entrada);
                if (entrada=="0")
                {
                    break;
                }

                if (dia >= 1 && dia <= 31)
                {
                    fechaValida = true;
                }
                else
                {
                    std::cout << "[ERROR] Dia invalido. Por favor ingrese un numero entre 1 y 31." << std::endl;

                }
            }
            while(!fechaValida);


            fechaValida = false;
            do
            {

                std::string entrada=entrada_valida("Ingrese MES, pulse cero para volver", NUMERO_ENTERO);
                mes=std::stoi(entrada);
                if (entrada=="0")
                {
                    break;
                }

                if (mes >= 1 && mes <= 12)
                {
                    fechaValida = true;
                }
                else
                {
                    std::cout << "[ERROR] Mes invalido. Por favor ingrese un numero entre 1 y 12." << std::endl;

                }
            }
            while(!fechaValida);

            fechaValida = false;
            do
            {
                std::string entrada=entrada_valida("Ingrese un anio, pulse cero para volver", NUMERO_ENTERO);
                line('-');
                anio=std::stoi(entrada);
                if (entrada=="0")
                {
                    break;
                }
                if (anio >= 1900 && anio <= anioActual)
                {
                    fechaValida = true;
                }
                else
                {
                    std::cout << "[ERROR] Anio invalido." << std::endl;

                }

            }
            while(!fechaValida);


            Fecha fechabusqueda(dia, mes, anio);
            listarplatos(fechabusqueda);

        }
        break;
        case 0:
            break;
        default:
            std::cout << "Opcion invalida. Intente nuevamente." << std::endl;
        }
    }
    while(opcion != 0);
}

void Menuadmin::eliminarplato(Fecha fechafiltrar) ///IVAN; parecido al de listar platos pero con el agregado que separa el plato seleccionado y elimina
///EVELYN: BUG ENCONTRADO AL MOMENTO DE LISTAR LOS PLATOS, SI HAY MAS DE UN MENU CARGADO NO LOS MUESTRA A TODOS
///ELIMINAR FUNCIONA OK, PERO CHEQUEAR LO QUE LISTA Y LAS VALIDACIONES DE ESTABLECIMIENTO YA QUE MUESTRA UN AVISO INCORRECTO
{
    Archivos <Menues> arch ("Menues.dat");
    Archivos <Establecimientos> arch2 ("Establecimientos.dat");
    Establecimientos esta_muestra;
    bool loop=false;
    std::vector <int> id_platos; ///vector dinamico, crece a medida que le asigno nuevos valores (no es un vector de tamanio fijo)
    std::vector <int> posicion;
    Menues plato_muestra;
    do
    {

        std::string entrada=entrada_valida("Ingrese ID de establecimiento, pulse cero para volver", NUMERO_ENTERO); /// Aca es el ingreso del usuario
        if (entrada=="0")
        {
            break;   /// Si el ingreso es CERO vuelve al menu anterior
        }
        int id_esta=std::stoi(entrada);
        int registros=arch2.CantidadRegistros();
        for (int i=0; i<registros; i++)
        {
            esta_muestra=arch2.Leer(i);
            if (id_esta==esta_muestra.getidestablecimiento())
            {
                int registros2=arch.CantidadRegistros();

                bool hayPlatos = false;

                for (int j=0; j<registros2; j++)
                {
                    plato_muestra=arch.Leer(j);
                    Fecha fArchivo = plato_muestra.getfecha();

                    if (esta_muestra.getidestablecimiento()==plato_muestra.getesta())
                    {
                        if (fechafiltrar==plato_muestra.getfecha()&&hayPlatos==false)
                        {
                            system("cls");
                            std::cout << "---LISTADO DE MENUS---" << std::endl;
                            line('-');
                        }
                        if (fechafiltrar==plato_muestra.getfecha()) //IVAN; la sobrecarga del operador == para objetos tipo fecha ya la habia codeado
                        {
                            std::cout << "ID #" << plato_muestra.getidmenu() << std::endl;
                            std::cout << plato_muestra.getdesctipo() << std::endl;
                            std::cout << plato_muestra.getnombremenu() << std::endl;
                            std::cout << "IMPORTE $" << plato_muestra.getvalorplato() << std::endl;
                            line('-');
                            id_platos.push_back(plato_muestra.getidmenu()); ///asigno un nuevo valor a mi vector dinamico
                            posicion.push_back(j);
                            hayPlatos = true;
                            loop=true;
                        }
                        else if (fechafiltrar.getDia() != plato_muestra.getfecha().getDia() && fechafiltrar.getMes() != plato_muestra.getfecha().getMes() && fechafiltrar.getAnio() != plato_muestra.getfecha().getAnio()&&registros2==j+1)
                        {
                            std::cout << "[AVISO] No se encontro ningun plato para " << esta_muestra.getnombreestablecimiento() << " en el dia de la fecha" << std::endl;
                            break;
                        }
                    }
                    else if (esta_muestra.getidestablecimiento()!=plato_muestra.getesta()&&j+1==registros2)
                    {
                        std::cout << "[AVISO] No se encontro ningun plato cargado para ese establecimiento" << std::endl;
                        break;
                    }
                }
                break;
            }
            else if (id_esta!=esta_muestra.getidestablecimiento()&&i+1==registros)
            {
                std::cout << "[ERROR] El establecimiento no existe o es incorrecto, intente nuevamente" << std::endl;
                break;
            }
        }
        if (loop==true)
        {
            int tamanio=id_platos.size(); ///tamanio ahora toma la cantidad de elementos guardados en el vector
            line('=');
            std::cout << "Seleccione el ID del plato que desea eliminar" << std::endl;
            line('=');
            std::string entrada=entrada_valida("Pulse cero para volver", NUMERO_ENTERO);
            if (entrada=="0")
            {
                break;
            }
            int id_buscado=std::stoi(entrada);
            for (int i=0; i<tamanio; i++)
            {
                if (id_buscado==id_platos[i])
                {
                    int pos=posicion[i];
                    loop=arch.Eliminar(pos);
                }
                else if (id_buscado!=id_platos[i]&&i+1==tamanio)
                {
                    std::cout << "[ERROR] Fallo con el ID ingresado, intente nuevamente" << std::endl;
                    loop=false;
                    break;
                }
            }
            if (loop==false)
            {
                std::cout << "[ERROR] Fallo al eliminar el plato, intente nuevamente" << std::endl;
                break;
            }
            else if (loop==true)
            {
                std::cout << "[AVISO] Plato eliminado correctamente" << std::endl;
                break;
            }
        }
    }
    while(loop==false);
}

void Menuadmin::listarplatos(Fecha fechafiltrar) ///IVAN; LLENO DE BUGS HAY QUE EMPROLIJAR TODA LA FUNCION DADO QUE NO ENCUENTRO EL ERROR
/// EVELYN: SE INTENTO EMPROLIJAR, SE CARGARON REGISTROS NUEVOS PARA EL DIA DE HOY 1/12/2025 Y PARA TODA LA SEMANA DEL ESTABLECIMIENTO ID 1
///SE HICIERON PRUEBAS DE LISTADO EN GESTIONAR PLATOS TANTO DE HOY COMO FILTRANDO POR FECHA QUE SE VISUALIZARON OK, TAMBIEN SE PROBARON LAS VALIDACIONES
///PARECIERA HABER QUEDADO BIEN, SEGUIR PROBANDO POR SI HAY ALGUN BUG QUE NO VI
///SE PROBO ELIMINAR UN PLATO Y SIGUE LISTANDOLOS OK
{
    Archivos <Menues> arch ("Menues.dat");
    Archivos <Establecimientos> arch2 ("Establecimientos.dat");
    Establecimientos esta_muestra;
    Menues plato_muestra;
    bool loop=true;
    do
    {
        std::string entrada=entrada_valida("Ingrese ID de establecimiento, pulse cero para volver", NUMERO_ENTERO); /// Aca es el ingreso del usuario
        if (entrada=="0")
        {
            break;   /// Si el ingreso es CERO vuelve al menu anterior
        }
        int id_esta=std::stoi(entrada);
        int registros=arch2.CantidadRegistros();
        bool establecimientoEncontrado = false;
        bool hayPlatos = false;
        for (int i=0; i<registros; i++)
        {
            esta_muestra=arch2.Leer(i);
            if (id_esta==esta_muestra.getidestablecimiento())
            {
                establecimientoEncontrado = true;
                int registros2=arch.CantidadRegistros();

                for (int j=0; j<registros2; j++)
                {
                    plato_muestra=arch.Leer(j);
                    Fecha fArchivo = plato_muestra.getfecha();

                    if (esta_muestra.getidestablecimiento()==plato_muestra.getesta()) //IVAN; modificaciones varias para resumir codigo y arreglar bug de iteraciones
                    {
                        if(fechafiltrar==plato_muestra.getfecha()&&hayPlatos==false)
                        {
                            system("pause");
                            system("cls");
                            std::cout << "---LISTADO DE PLATOS---" << std::endl;
                            line('-');
                        }

                        if (fechafiltrar==plato_muestra.getfecha())
                        {
                            std::cout << "ID #" << plato_muestra.getidmenu() << std::endl;
                            std::cout << plato_muestra.getdesctipo() << std::endl;
                            std::cout << plato_muestra.getnombremenu() << std::endl;
                            std::cout << "IMPORTE $" << plato_muestra.getvalorplato() << std::endl;
                            line('-');
                            hayPlatos=true;
                        }
                    }
                }
                if (hayPlatos==false)
                {
                    std::cout << "[AVISO] No se encontro ningun plato para " << esta_muestra.getnombreestablecimiento() << " en el dia de la fecha" << std::endl;
                    loop=true;
                    break;
                }
            }
        }
        if (establecimientoEncontrado == false) ///id_esta!=esta_muestra.getidestablecimiento()&&i+1==registros) ///ARREGLAR
        {
            std::cout << "[ERROR] El establecimiento no existe o es incorrecto, intente nuevamente" << std::endl;
            std::cout << std::endl;
            loop=false;
        }
    }
    while(loop==false);
}


void Menuadmin::modificarplatos()
{
    Archivos <Menues> arch ("Menues.dat");
    std::cout << "---MODIFICAR PLATOS---" << std::endl;
    line('-');
    Menues platomodificado;
    int pos = -1;
    bool loop = false;
    do
    {
        std::string entrada=entrada_valida("Ingrese el ID del plato que desee modificar, o pulse cero para volver", NUMERO_ENTERO);
        int IDplato=std::stoi(entrada);
        if (entrada=="0")
        {
            return;

        }


        int cantidad = arch.CantidadRegistros();

        for (int i=0; i< cantidad; i++)
        {
            Menues auxplato = arch.Leer(i);
            if (auxplato.getidmenu() == IDplato)
            {
                pos = i;
                platomodificado = auxplato;
                loop = true;
                break;
            }
        }

        if(loop == false)
        {
            std::cout << "[AVISO] ID incorrecto o el plato no existe. Intente nuevamente." << std::endl;
            system("pause");

        }
    }
    while(loop == false);

    int opcion;
    bool hubocambios = false;
    do
    {
        system("cls");
        std::cout << "MODIFICANDO PLATO ID: #" << platomodificado.getidmenu() << std::endl;
        line('-');
        std::cout << "1- Cambiar NOMBRE    (Actual: " << platomodificado.getnombremenu() << ")" << std::endl;
        std::cout << "2- Cambiar ID TIPO DE MENU  (Actual: " << platomodificado.getidtipo() << " - " << platomodificado.getdesctipo() << ")" << std::endl;
        std::cout << "3- Cambiar FECHA DEL MENU (Actual: " << platomodificado.getfecha().toString() << ")" << std::endl;
        std::cout << "4- Cambiar ID ESTABLECIMIENTO (Actual: " << platomodificado.getesta() << ")" << std::endl;
        std::cout << "5- Cambiar VALOR DEL PLATO (Actual: $" << platomodificado.getvalorplato() << ")" << std::endl;
        std::cout << "0- Guardar y Salir" << std::endl;
        line('-');
        std::cout << "Elija que desea modificar: ";
        std::string entrada=entrada_valida("", NUMERO_ENTERO);
        opcion=stoi(entrada);

        switch(opcion)
        {
        case 1:
        {
            std::string nuevoNombre;
            std::cout << "Ingrese nuevo NOMBRE, ";
            std::string entrada=entrada_valida("o pulse 0 para salir", TEXTO_NO_VACIO);
            nuevoNombre = entrada;
            if (entrada=="0")
            {
                return;
            }

            platomodificado.setnombremenu(nuevoNombre.c_str());
            hubocambios = true;
            break;
        }
        case 2:
        {
            int nuevoIDtipomenu;
            bool loop = false;

            do
            {
                std::cout << "Ingrese nuevo ID TIPO DE MENU, ";
                std::string entrada=entrada_valida("o pulse 0 para salir", TEXTO_NO_VACIO);
                nuevoIDtipomenu=stoi(entrada);

                if (entrada=="0")
                {
                    return;
                }

                int cantidad = arch.CantidadRegistros();
                for (int i = 0; i < cantidad; i++)
                {
                    if(arch.Leer(i).getidtipo() == nuevoIDtipomenu)
                        loop = true;
                }
                if(loop == false)
                {

                    std::cout << "[ERROR] No se encontro un tipo de menu con ese ID. Reintente nuevamente." << std::endl;

                }
            }
            while (loop = false);

            platomodificado.setidtipo(nuevoIDtipomenu);
            hubocambios = true;
            break;
        }
        case 3:
        {
            int dia, mes, anio;
            bool fechaValida = false;
            time_t t = time(0);
            tm* now = localtime(&t);
            int anioActual = now->tm_year + 1900;

            do
            {
                std::cout << "Ingrese DIA DE PUBLICACION DEL MENU, ";
                std::string entrada=entrada_valida("o pulse 0 para salir", NUMERO_ENTERO);
                dia = std::stoi(entrada);
                if (entrada=="0")
                {
                    return;
                }

                if (dia >= 1 && dia <= 31)
                {
                    fechaValida = true;
                }
                else
                {
                    std::cout << "[ERROR] Dia invalido. Por favor ingrese un numero entre 1 y 31." << std::endl;

                }

            }
            while(!fechaValida);

            fechaValida = false;

            do
            {
                std::cout << "Ingrese MES DE PUBLICACION DEL MENU, ";
                entrada=entrada_valida("o pulse 0 para salir", NUMERO_ENTERO);
                mes = std::stoi(entrada);
                if (entrada=="0")
                {
                    return;
                }

                if (mes >= 1 && mes <= 12)
                {
                    fechaValida = true;
                }
                else
                {
                    std::cout << "[ERROR] Mes invalido. Por favor ingrese un numero entre 1 y 12." << std::endl;

                }

            }
            while(!fechaValida);

            fechaValida = false;

            do
            {
                std::cout << "Ingrese ANIO DE PUBLICACION DEL MENU, ";
                entrada=entrada_valida("o pulse 0 para salir", NUMERO_ENTERO);
                anio = std::stoi(entrada);
                if (entrada=="0")
                {
                    return;
                }


                if (anio >= 1900 && anio <= anioActual)
                {
                    fechaValida = true;
                }
                else
                {
                    std::cout << "[ERROR] Anio invalido." << std::endl;

                }
            }
            while(!fechaValida);

            Fecha nuevafecha(dia, mes, anio);
            platomodificado.setfecha(nuevafecha);

            hubocambios = true;
            break;
        }
        case 4:
        {
            Archivos <Establecimientos> arch_establecimientos ("Establecimientos.dat");
            bool loop = false;
            Establecimientos guardar_id;
            int nuevoIDestablecimiento;
            do
            {
                std::cout << "Ingrese nuevo ID de establecimiento, ";
                std::string entrada=entrada_valida("o pulse 0 para salir", NUMERO_ENTERO);
                nuevoIDestablecimiento = std::stoi(entrada);
                if (entrada=="0")
                {
                    return;
                }

                int cantidad = arch_establecimientos.CantidadRegistros();
                for (int i=0; i<cantidad; i++)
                {
                    if(arch_establecimientos.Leer(i).getidestablecimiento() == nuevoIDestablecimiento)
                    {
                        loop = true;

                    }
                }
                if(loop == false)
                {

                    std::cout << "[ERROR] No se encontro un establecimiento con ese ID. Reintente nuevamente." << std::endl;

                }
            }
            while(loop == false);

            guardar_id.setidestablecimiento(nuevoIDestablecimiento);

            platomodificado.setesta(guardar_id);
            hubocambios = true;
            break;

        }
        case 5:
        {
            float nuevoImporte;
            std::cout << "Ingrese nuevo IMPORTE, ";
            std::string entrada=entrada_valida("o pulse 0 para salir", NUMERO_FLOTANTE);
            nuevoImporte=stof(entrada);
            if (entrada=="0")
            {
                return;
            }

            platomodificado.setvalorplato(nuevoImporte);
            hubocambios = true;
            break;
        }
        case 0:

            break;
        default:
            std::cout << "Opcion invalida" << std::endl;
            system("pause");
            break;
        }

    }
    while (opcion != 0);


    if (hubocambios == true)
    {

        if (arch.Guardar(platomodificado, pos))
        {

            std::cout << "Cambios guardados correctamente" << std::endl;
        }
        else
        {
            std::cout << "[ERROR] No se pudo guardar la modificaciÃ³n." << std::endl;
        }
    }
    else
    {
        std::cout << "No se realizaron cambios." << std::endl;
    }

    system("pause");
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
        valoracion=plato_muestra.getvaloracion(); /// Funcion que hace un promedio
        ///de las valoraciones en base a la cantidad de gente que la valoro
        int cant_val=plato_muestra.getcant_valoracion();
        if (valoracion!=0&&cant_val!=0)
        {
            line('-');
            std::cout << "Listado de platos valorados por los comensales" << std::endl;
            line('-');
            std::cout << "El plato: " << std::endl;
            std::cout << plato_muestra.toString() << std::endl;
            std::cout << "Con una valoracion promedio de: " << valoracion/cant_val << std::endl;
            line('-');
        }
    }
}

void Menuadmin::cargarvaloracion()
{
    Archivos <Menues> arch ("Menues.dat");
    Menues plato_muestra;
    Fecha fecha_hoy;
    fecha_hoy.hoy();
    bool ejecutar_ok=false;
    int j=0;
    std::vector<int> id_aux;
    do
    {
        int registros=arch.CantidadRegistros();
        j=0;
        for (int i=0; i<registros; i++)
        {
            plato_muestra=arch.Leer(i);
            if (fecha_hoy.hoy()==plato_muestra.getfecha())
            {
                id_aux.push_back(plato_muestra.getidmenu());
                j++;
                line('=');
                std::cout << "Plato del dia Num. " << j << std::endl;
                std::cout << "Bejo el ID Numero " << plato_muestra.getidmenu() << std::endl;
                std::cout << plato_muestra.toString() << std::endl;
                line('=');
            }
        }
        std::cout << "Seleccione el ID del plato que desea agregar una valoracion, ";
        std::string entrada=entrada_valida("pulse cero para volver", NUMERO_ENTERO);
        line('-');
        int numero=std::stoi(entrada);
        if (entrada=="0")
        {
            break;
        }
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
                        std::cout << "Agregar una valoracion (del 1 al 10), ";
                        std::string entrada=entrada_valida("o pulse cero para volver", NUMERO_ENTERO);
                        int valoracion=std::stoi(entrada);
                        if (entrada=="0")
                        {
                            break;
                        }
                        if (valoracion<1||valoracion>10)
                        {
                            std::cout << "[ERROR] Ingreso invalido, intente nuevamente" << std::endl;
                            break;
                        }
                        else if (valoracion>0||valoracion<11)
                        {
                            int valor_anterior;
                            valor_anterior=plato_muestra.getvaloracion();
                            int valor_nuevo;
                            valor_nuevo=valor_anterior+valoracion; /// Suma con la valoracion que ya tenia el plato
                            plato_muestra.setvaloracion(valor_nuevo); ///seteo de valoracion
                            int cant_anterior;
                            cant_anterior=plato_muestra.getcant_valoracion();
                            int cant_actual=cant_anterior+1;
                            plato_muestra.setcant_valoracion(cant_actual); ///seteo de cant de valoraciones
                            ejecutar_ok=arch.Guardar(plato_muestra, x); /// Sobreescritura, JAMAS una sobreescritura
                            if (ejecutar_ok==false)                     /// va a ir en un x+1
                            {
                                std::cout << "[ERROR] guardado fallido, intente nuevamente" << std::endl;
                                break;
                            }
                            break;
                        }
                    }
                }
                break;
            }
            else if (ejecutar_ok==false&&numero!=id_aux[i]&&i+1==id_aux.size())
            {
                std::cout << "[ERROR] Numero de plato NO valido, intente nuevamente" << std::endl;
                system ("pause");
                system ("cls");
                break;
            }
        }
    }
    while(ejecutar_ok==false);
}

void Menuadmin::mostrarmenucargar() /// EVELYN-> SE AGREGO SUBMENUS EN PLATOS PARA QUE NOS DEJE CARGAR MENU DEL DIA O MENU DE LA SEMANA
{
    int opcion;
    do
    {
        std::cout << "---CARGAR MENUES---" << std::endl;
        line('-');
        std::cout << "1- CARGAR MENU DEL DIA" << std::endl;
        std::cout << "2- CARGAR MENU DE TODA LA SEMANA" << std::endl;
        std::cout << "0- Volver al menu de platos" << std::endl;
        line('-');
        std::string entrada = entrada_valida("", NUMERO_ENTERO);
        opcion= std::stoi(entrada);
        switch(opcion)
        {
        case 1:
            system("pause");
            system("cls");
            cargarplato();
            system("pause");
            system("cls");
            break;
        case 2:
            system("pause");
            system("cls");
            cargarmenutodalasemana();
            system("pause");
            system("cls");
            break;
        case 0:
            std::cout << "Volviendo al menu principal" << std::endl;
            break;
        default:
            std::cout << "Opcion invalida. Intente nuevamente" << std::endl;
            break;
        }
    }
    while(opcion !=0);


}

void Menuadmin::cargarplato() ///IVAN; ahora busca establecmiento OK y lo muestra
{
    Archivos <Menues> arch ("Menues.dat");
    Archivos <Establecimientos> arch2 ("Establecimientos.dat");
    Archivos <TipoAlmuerzo> arch3 ("TipoAlmuerzo.dat");
    int idesta;
    float importe;
    const char *nombre_aux;
    int tipomenu;
    bool guardar_ok=false, loop=true;
    Establecimientos esta_muestra;
    Menues plato_muestra;
    Fecha fecha_hoy;
    do
    {
        std::cout << "Ingrese el nombre del menu nuevo";
        std::string nombremenu=entrada_valida(", o pulse cero para volver", TEXTO_NO_VACIO);
        line('-');
        if (nombremenu=="0")
        {
            break;
        }
        nombre_aux=nombremenu.c_str();
        plato_muestra.setnombremenu(nombre_aux);
        do
        {
            std::cout << "Ingrese el ID del establecimiento";
            std::string entrada=entrada_valida(", o pulse cero para volver", NUMERO_ENTERO);
            line('-');
            idesta=std::stoi(entrada);
            if (entrada=="0")
            {
                break;
            }
            int registro=arch2.CantidadRegistros();
            for (int i=0; i<registro; i++)
            {
                esta_muestra=arch2.Leer(i);
                if (idesta==esta_muestra.getidestablecimiento())
                {
                    plato_muestra.setesta(esta_muestra);
                    std::cout << "Establecimiento encontrado: " << esta_muestra.getnombreestablecimiento() << std::endl;
                    loop=true;
                    break;
                }
                else if (idesta!=esta_muestra.getidestablecimiento()&&i+1==registro)
                {
                    std::cout << "[ERROR] ID ingresado no valido o no existe, intente nuevamente" << std::endl;
                    loop=false;
                    break;
                }
            }
        }
        while(loop==false);
        
        bool precioValido = false;
        std::string entrada;
        do{
        std::cout << "Ingrese el valor del plato";
        entrada=entrada_valida(", o pulse cero para volver", NUMERO_FLOTANTE);
        line('-');
        
        if (entrada=="0")
        {
            break;
        }
        importe=std::stof(entrada);
        
        if (importe < 0)
        {
            std::cout << "[ERROR] No se puede establecer un precio negativo!" << std::endl;
            
        }
        else
        {
            plato_muestra.setvalorplato(importe);
            precioValido = true;
        }
    
        }while(!precioValido);
        
        if (entrada == "0") {
            break; 
        }
        do
        {
            std::cout << "Ingrese el tipo de plato" << std::endl;
            std::cout << "1. Menu estandar" << std::endl;
            std::cout << "2. Menu vegetariano" << std::endl;
            std::cout << "3. Menu celiaco" << std::endl;
            std::string entrada=entrada_valida("Pulse cero para volver", NUMERO_ENTERO);
            line('-');
            if (entrada=="0")
            {
                break;
            }
            tipomenu=std::stoi(entrada);
            if (tipomenu<1||tipomenu>3)
            {
                std::cout << "[ERROR] Opcion no valida, intente nuevamente" << std::endl;
                system("pause");
                system("cls");
                loop=false;
                break;
            }
            else
            {
                TipoAlmuerzo tipo_muestra(tipomenu);
                plato_muestra.setidtipo(tipo_muestra);
                plato_muestra.setdesctipo(tipo_muestra);
                loop=true;
            }
        }
        while(loop==false);
        int registros=arch.CantidadRegistros()+1;
        plato_muestra.setidmenu(registros);
        plato_muestra.setfecha(fecha_hoy.hoy());
        plato_muestra.setcant_valoracion(0);
        plato_muestra.setvaloracion(0);
        guardar_ok=arch.Guardar(plato_muestra);
        if (guardar_ok==true)
        {
            system("pause");
            system("cls");
            std::cout << "Menu cargado satisfactoriamente bajo el ID Num. " << registros << std::endl;
        }
        else
        {
            system("pause");
            system("cls");
            std::cout << "[ERROR] Falla de carga del registro, intente nuevamente" << std::endl;
            break;
        }
    }
    while(guardar_ok==false);
}

void Menuadmin::cargarmenutodalasemana()  /// EVELYN -> SE AGREGO ESTA FUNCION CON LO MISMO DE CARGARPLATOS, PERO CON UN CICLO COMBINADO PARA CARGAR LOS 7 DIAS DE LA SEMANA
{
    Archivos <Menues> arch ("Menues.dat");
    Archivos <Establecimientos> arch2 ("Establecimientos.dat");
    Archivos <TipoAlmuerzo> arch3 ("TipoAlmuerzo.dat");
    int idesta;
    float importe;
    const char *nombre_aux;
    int tipomenu;
    bool guardar_ok=false, loop=true;
    Establecimientos esta_muestra;
    Menues plato_muestra;
    Fecha fecha_hoy;

    do
    {
        std::cout << "Ingrese el ID del establecimiento";
        std::string entrada=entrada_valida(" o pulse cero para volver", NUMERO_ENTERO);
        line('-');
        idesta=std::stoi(entrada);
        if (entrada=="0")
        {
            break;
        }
        int registro=arch2.CantidadRegistros();
        for (int i=0; i<registro; i++)
        {
            esta_muestra=arch2.Leer(i);
            if (idesta==esta_muestra.getidestablecimiento())
            {
                plato_muestra.setesta(esta_muestra);
                std::cout << "Establecimiento encontrado: " << esta_muestra.getnombreestablecimiento() << std::endl;
                loop=true;
                break;
            }
            else if (idesta!=esta_muestra.getidestablecimiento()&&i+1==registro)
            {
                std::cout << "[ERROR] ID ingresado no valido o no existe, intente nuevamente" << std::endl;
                loop=false;
                break;
            }
        }
    }
    while(loop==false);

    for(int dia = 0; dia <7; dia ++)
    {
        Fecha fechadelmenu = fecha_hoy.hoy();
        fechadelmenu.sumarDias(dia);

        std::cout << std::endl;
        std::cout << "CARGANDO MENU PARA EL DIA " << fechadelmenu.toString() << std::endl;

        int opcion;
        std::string entrada;
        do
        {
            std::cout << "Ingrese el nombre del menu nuevo";
            std::string nombremenu=entrada_valida(", o pulse cero para volver", TEXTO_NO_VACIO);
            line('-');
            if (nombremenu=="0")
            {
                break;
            }
            nombre_aux=nombremenu.c_str();
            plato_muestra.setnombremenu(nombre_aux);

            bool precioValido = false;
            do{
            std::cout << "Ingrese el valor del plato, ";
            entrada=entrada_valida("o pulse cero para volver", NUMERO_FLOTANTE);
            line('-');
            
            if (entrada=="0")
            {
                break;
            }
            importe=std::stof(entrada);
            
            if (importe < 0)
            {
                std::cout << "[ERROR] No se puede establecer un precio negativo." << std::endl;
    
            }
            else
            {
                plato_muestra.setvalorplato(importe);
                loop=true;
                precioValido=true;
            }
            }while (!precioValido);
            if (entrada=="0")
            {
                break;
            }
            
            do
            {
                std::cout << "Ingrese el tipo de plato" << std::endl;
                std::cout << "1. Menu estandar" << std::endl;
                std::cout << "2. Menu vegetariano" << std::endl;
                std::cout << "3. Menu celiaco" << std::endl;
                std::string entrada=entrada_valida("Pulse cero para volver", NUMERO_ENTERO);
                line('-');
                if (entrada=="0")
                {
                    break;
                }
                tipomenu=std::stoi(entrada);
                if (tipomenu<1||tipomenu>3)
                {
                    std::cout << "[ERROR] Opcion no valida, intente nuevamente" << std::endl;
                    system("pause");
                    system("cls");
                    loop=false;
                    break;
                }
                else
                {
                    TipoAlmuerzo tipo_muestra(tipomenu);
                    plato_muestra.setidtipo(tipo_muestra);
                    plato_muestra.setdesctipo(tipo_muestra);
                    loop=true;
                }
            }
            while(loop==false);
            int registros=arch.CantidadRegistros()+1;
            plato_muestra.setidmenu(registros);
            plato_muestra.setfecha(fechadelmenu);
            plato_muestra.setcant_valoracion(0);
            plato_muestra.setvaloracion(0);
            guardar_ok=arch.Guardar(plato_muestra);
            if (guardar_ok==true)
            {
                system("pause");
                system("cls");
                std::cout << "Menu cargado satisfactoriamente bajo el ID Num. " << registros << std::endl;
            }
            else
            {
                system("pause");
                system("cls");
                std::cout << "[ERROR] Falla de carga del registro, intente nuevamente" << std::endl;
                break;
            }
            loop=true;
            do
            {
                std::string entrada=entrada_valida("Desea agregar otro plato para esta misma fecha? (1- SI/0-NO): ", NUMERO_ENTERO);

                if (entrada == "1")
                {
                    opcion = 1;
                    loop = false;
                }
                else if (entrada == "0")
                {
                    opcion = 0;
                    loop = false;
                }
                else
                {

                    std::cout << "[ERROR] Opcion no valida. Ingrese unicamente 1 o 0." << std::endl;
                    loop = true;
                }

            }
            while (loop == true);

        }
        while (opcion == 1);
        std::cout << "Fin de la carga para el dia " << fechadelmenu.toString() << std::endl;
        system("pause");

    }
    std::cout << "Carga semanal completa!" << std::endl; //IVAN; saque un pause porque lo hacia dos veces
}

void Menuadmin::eliminarplatomenu() ///IVAN; parecido al de listar platos pero con el agregado que separa el plato seleccionado y elimina
{
    int opcion;
    do
    {
        std::cout << "---ELIMINAR UN PLATO---" << std::endl;
        line('-');
        std::cout << "1- ELIMINAR PLATO DE HOY" << std::endl;
        std::cout << "2- ELIMINAR PLATO POR DIA ESPECIFICO" << std::endl;
        std::string entrada=entrada_valida("0- Atras", NUMERO_ENTERO);

        int opcion= std::stoi(entrada);

        switch(opcion)
        {
        case 1:
        {
            system("pause");
            system("cls");
            Fecha fecha_hoy;
            fecha_hoy = fecha_hoy.hoy();
            eliminarplato(fecha_hoy);
            system("pause");
            system("cls");
            break;
        }
        case 2:
        {
            system("pause");
            system("cls");
            int dia, mes, anio;
            bool fechaValida = false;
            time_t t = time(0);
            tm* now = localtime(&t);
            int anioActual = now->tm_year + 1900;

            do
            {
                std::cout << "Ingrese DIA";
                std::string entrada=entrada_valida(", o pulse cero para volver", NUMERO_ENTERO);
                dia=std::stoi(entrada);
                if (entrada=="0")
                {
                    break;
                }
                if (dia >= 1 && dia <= 31)
                {
                    fechaValida = true;
                }
                else
                {
                    std::cout << "[ERROR] Dia invalido. Por favor ingrese un numero entre 1 y 31." << std::endl;

                }
            }
            while(!fechaValida);

            fechaValida = false;

            do
            {
                std::cout << "Ingrese MES";
                entrada=entrada_valida(", o pulse cero para volver", NUMERO_ENTERO);
                mes=std::stoi(entrada);
                if (entrada=="0")
                {
                    break;
                }
                if (mes >= 1 && mes <= 12)
                {
                    fechaValida = true;
                }
                else
                {
                    std::cout << "[ERROR] Mes invalido. Por favor ingrese un numero entre 1 y 12." << std::endl;

                }
            }
            while(!fechaValida);


            fechaValida = false;
            do
            {
                std::cout << "Ingrese ANIO";
                entrada=entrada_valida("", NUMERO_ENTERO);
                anio=std::stoi(entrada);
                if (entrada=="0")
                {
                    break;
                }
                if (anio >= 1900 && anio <= anioActual)
                {
                    fechaValida = true;
                }
                else
                {
                    std::cout << "[ERROR] Anio invalido" << std::endl;

                }
            }
            while(!fechaValida);

            Fecha fechabusqueda(dia, mes, anio);
            eliminarplato(fechabusqueda);

            system("pause");
            system("cls");
        }
        break;
        case 0:
            break;
        default:
            std::cout << "Opcion invalida. Intente nuevamente" << std::endl;
        }
    }
    while(opcion != 0);
}

void Menuadmin::eliminarusuario()
{
    Archivos <usuario> arch ("Usuario.dat");
    usuario user_buscado;
    bool loop=false;
    const char* nombre_aux;
    do
    {
        std::cout << "Ingrese el nombre de usuario que desea eliminar";
        std::string entrada=entrada_valida(", o pulse cero para volver", TEXTO_NO_VACIO);
        line('-');
        if (entrada=="0")
        {
            break;
        }
        nombre_aux=entrada.c_str();
        int registros=arch.CantidadRegistros();
        for (int i=0; i<registros; i++)
        {
            user_buscado=arch.Leer(i);
            if (nombre_aux==user_buscado.getNombreUsuario()) ///VER
            {
                if (arch.Eliminar(i)==true)
                {
                    std::cout << "[AVISO] El usuario se elimino exitosamente" << std::endl;
                    loop=true;
                    system("pause");
                    system("cls");
                    break;
                }
            }
            else if (nombre_aux!=user_buscado.getNombreUsuario()&&i+1==registros)
            {
                std::cout << "[ERROR] Usuario no encontrado, intente nuevamente" << std::endl;
                system("pause");
                system("cls");
                break;
            }
        }
    }
    while(loop==false);
}

void Menuadmin::eliminarcomensal()
{
    Archivos <Comensal> arch ("Comensales.dat");
    Comensal comensal_buscado;
    bool loop=false;
    int id_buscado;
    do
    {
        std::cout << "Ingrese el ID del comensal que desea eliminar";
        std::string entrada=entrada_valida(", o pulse cero para volver", NUMERO_ENTERO);
        line('-');
        if (entrada=="0")
        {
            break;
        }
        id_buscado=std::stoi(entrada);
        int registros=arch.CantidadRegistros();
        for (int i=0; i<registros; i++)
        {
            comensal_buscado=arch.Leer(i);
            if (id_buscado==comensal_buscado.getIDcomensal()) ///VER
            {
                if (arch.Eliminar(i)==true)
                {
                    std::cout << "[AVISO] El comensal se elimino exitosamente" << std::endl;
                    loop=true;
                    system("pause");
                    system("cls");
                    break;
                }
            }
            else if (id_buscado!=comensal_buscado.getIDcomensal()&&i+1==registros)
            {
                std::cout << "[ERROR] Comensal no encontrado, intente nuevamente" << std::endl;
                system("pause");
                system("cls");
                break;
            }
        }
    }
    while(loop==false);
}

void Menuadmin::eliminar_esta()
{
    Archivos <Establecimientos> arch ("Establecimientos.dat");
    Establecimientos esta_aux;
    bool loop=false;
    int id_buscado;
    do
    {
        std::cout << "Ingrese el ID del establecimiento que desea eliminar";
        std::string entrada=entrada_valida(", o pulse cero para volver", NUMERO_ENTERO);
        line('-');
        if (entrada=="0")
        {
            break;
        }
        id_buscado=std::stoi(entrada);
        int registros=arch.CantidadRegistros();
        for (int i=0; i<registros; i++)
        {
            esta_aux=arch.Leer(i);
            if (id_buscado==esta_aux.getidestablecimiento()) ///VER
            {
                if (arch.Eliminar(i)==true)
                {
                    std::cout << "[AVISO] El establecimiento se elimino exitosamente" << std::endl;
                    loop=true;
                    system("pause");
                    system("cls");
                    break;
                }
            }
            else if (id_buscado!=esta_aux.getidestablecimiento()&&i+1==registros)
            {
                std::cout << "[ERROR] Establecimiento no encontrado, intente nuevamente" << std::endl;
                system("pause");
                system("cls");
                break;
            }
        }
    }
    while(loop==false);
}

void Menuadmin::listarfacturas()
{
    Archivos <Factura> arch ("Facturas.dat");
    Factura fc_muestra;
    bool loop=true, comensal_encontrado=false;
    int seleccion_id, j=0;
    do
    {
        std::cout << "Seleccione su/el ID de usuario";
        std::string entrada=entrada_valida(", o pulse cero para volver", NUMERO_ENTERO);
        line('-');
        if (entrada=="0")
        {
            break;
        }
        seleccion_id=std::stoi(entrada);
        int registros=arch.CantidadRegistros();
        for (int i=0; i<registros; i++)
        {
            fc_muestra=arch.Leer(i);
            if (fc_muestra.getidcomen()==seleccion_id)
            {
                j++;
                line('+');
                std::cout << "Factura del comensal " << std::string(fc_muestra.getnombrecomen()) << " Num. #" << j << std::endl;
                std::cout << "Bajo el Num. de factura " << fc_muestra.getnumfc() << std::endl;
                line('-');
                std::cout << "Consumo en la fecha de " << fc_muestra.getFecha().toString() << std::endl;
                std::cout << "Por un total de $" << fc_muestra.getImporte() << std::endl;
                line('+');
                comensal_encontrado=true;

            }
        }
        if (!comensal_encontrado)
        {
            std::cout << "[ERROR] ID no encontrado o no valido, intente nuevamente" << std::endl;
            loop=false;
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
    bool loop=false;
    do
    {
        std::cout << "Seleccione su/el ID de usuario para generar factura";
        std::string entrada=entrada_valida(", o pulse cero para volver", NUMERO_ENTERO);
        line('-');
        if (entrada=="0")
        {
            loop=true;
            break;
        }
        id_comensal=std::stoi(entrada);
        int registros=arch2.CantidadRegistros();
        for (int i=0; i<registros; i++)
        {
            comensal_muestra=arch2.Leer(i);
            if (id_comensal==comensal_muestra.getIDcomensal())
            {
                std::cout << "Comensal " << std::string(comensal_muestra.getNombre()) << " encontrado" << std::endl;
                fc_muestra.setidcomen(comensal_muestra);
                fc_muestra.setnombrecomen(comensal_muestra);
                loop=true;
            }
            else if (id_comensal!=comensal_muestra.getIDcomensal()&&registros==i-1)
            {
                std::cout << "[ERROR] Comensal NO encontrado o no existe, intente nuevamente" << std::endl;
                loop=false;
                break;
            }
        }
        std::cout << "Ingrese el importe a facturar"; ///verificar valores negativos
        entrada=entrada_valida(", o pulse cero para volver", NUMERO_FLOTANTE);
        line('-');
        if (entrada=="0")
        {
            loop=true;
            break;
        }
        importe_muestra=std::stof(entrada);
        if (importe_muestra==0||importe_muestra<0)
        {
            std::cout << "[ERROR] No se puede ingresar cero o valores negativos!" << std::endl;
            loop=false;
            break;
        }
        fc_muestra.setImporte(importe_muestra);
        bool mediopago_muestra=false;
        fc_muestra.setMedioDePago(mediopago_muestra);
        std::cout << "Seleccione el ID de el menu consumido por el comensal" << std::endl;
        registros=arch3.CantidadRegistros();
        for (int i=0; i<registros; i++)
        {
            plato_muestra=arch3.Leer(i);
            if (fecha_hoy.hoy()==plato_muestra.getfecha())
            {
                line('-');
                std::cout << plato_muestra.toString() << " ID numero " << plato_muestra.getidmenu() << std::endl;
                line('-');
            }
        }
        entrada=entrada_valida("Pulse cero para volver", NUMERO_ENTERO);
        line('-');
        int id_menu=std::stoi(entrada);
        registros=arch3.CantidadRegistros();
        for (int i=0; i<registros; i++)
        {
            plato_muestra=arch3.Leer(i);
            if (fecha_hoy.hoy()==plato_muestra.getfecha()&&id_menu==plato_muestra.getidmenu())
            {
                fc_muestra.setIDmenu(plato_muestra);
                std::cout << "Factura generada exitosamente" << std::endl;
                loop=true;
            }
            else if (registros==i+1&&id_menu!=plato_muestra.getidmenu())
            {
                std::cout << "[ERROR] Menu no encontrado o no existe, intente nuevamente" << std::endl;
                loop=false;
                break;
            }
        }
        registros=arch.CantidadRegistros()+1;
        fc_muestra.setnumfc(registros+1);
        fc_muestra.setFecha(fecha_hoy.hoy());
        loop=arch.Guardar(fc_muestra);
        if (loop==false)
        {
            std::cout << "[ERROR] Error en guardado del archivo, intente nuevamente" << std::endl;
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
        std::cout << "Ingrese el ID de usuario para ver cuenta corriente";
        std::string entrada=entrada_valida(", o pulse cero para volver", NUMERO_ENTERO);
        line('-');
        if (entrada=="0")
        {
            loop=true;
            break;
        }
        id_buscado=std::stoi(entrada);
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
                std::cout << "[ERROR] Usuario no encontrado o no existe, intente nuevamente" << std::endl;
                loop=false;
                break;
            }
        }
    }
    while(loop==false);
}

void Menuadmin::cargarestablecimiento() /// se agrego getline y cin.ignore para que nos deje ingresar cadenas con espacios.
{
    Archivos <Establecimientos> arch_establecimientos ("Establecimientos.dat");
    bool loop=false;
    do
    {
        int idestablecimiento = arch_establecimientos.CantidadRegistros()+1;
        if (idestablecimiento == 0)
        {
            idestablecimiento=1;
        }
        std::cout << "--- NUEVO ESTABLECIMIENTO ---" << std::endl;
        line('-');
        std::cout << "Nuevo establecimiento bajo el ID #:" << idestablecimiento << std::endl;
        std::cout << std::endl;
        std::cout << "ingrese el nombre,";
        std::string nombreestablecimiento=entrada_valida(" o pulse cero para volver", TEXTO_NO_VACIO);
        line('-');
        if (nombreestablecimiento=="0")
        {
            break;
        }
        std::cout << "ingrese la direccion, ";
        std::string direccionesta=entrada_valida("o pulse cero para volver", TEXTO_NO_VACIO);
        line('-');
        if (direccionesta=="0")
        {
            break;
        }
        std::cout << "Ingrese el tipo de establecimiento, ";
        std::string tipoesta=entrada_valida("o pulse cero para volver", TEXTO_NO_VACIO);
        line('-');
        if (tipoesta=="0")
        {
            break;
        }
        Establecimientos esta_muestra(idestablecimiento, nombreestablecimiento.c_str(), direccionesta.c_str(), tipoesta.c_str());

        if (arch_establecimientos.Guardar(esta_muestra)== true)
        {
            system("pause");
            system("cls");
            std::cout << "El establecimiento se guardo exitosamente" << std::endl;
            loop=true;
        }
        else
        {
            system("pause");
            system("cls");
            std::cout << "[ERROR] Algo salio mal. Intente mas tarde" << std::endl;
        }
    }
    while(loop==false);
}

void Menuadmin::listarestablecimientos()
{
    Archivos <Establecimientos> arch_establecimientos ("Establecimientos.dat");
    int cantidad = arch_establecimientos.CantidadRegistros();
    std::cout << "--- LISTADO DE ESTABLECIMIENTOS ---"  << std::endl;
    line('-');
    for (int i= 0; i < cantidad; i++)
    {
        Establecimientos establecimientos_muestra = arch_establecimientos.Leer(i);
        mostrarestablecimientos(establecimientos_muestra);
        line('-');
    }
}

void Menuadmin::mostrarestablecimientos(Establecimientos establecimientos_muestra)
{

    std::cout << "ID #: " << establecimientos_muestra.getidestablecimiento() << std::endl;
    std::cout << "Nombre: " << establecimientos_muestra.getnombreestablecimiento() << std::endl;
    std::cout << "Direccion: " << establecimientos_muestra.getdireccionesta() << std::endl;
    std::cout << "Tipo de establecimiento: " << establecimientos_muestra.gettipoesta() << std::endl;
}


void Menuadmin::modificarestablecimientos()
{
    Archivos <Establecimientos> arch_establecimientos ("Establecimientos.dat");
    std::cout << "---MODIFICAR ESTABLECIMIENTOS---" << std::endl;
    line('-');
    std::cout << "Ingrese el ID del establecimiento que desee modificar, ";
    std::string entrada=entrada_valida("o pulse cero para volver", NUMERO_ENTERO);
    int IDesta=std::stoi(entrada);
    if (entrada=="0")
    {
        return;
    }
    Establecimientos estamodificado;

    int cantidad = arch_establecimientos.CantidadRegistros();
    int pos = -1;

    for (int i=0; i< cantidad; i++)
    {
        Establecimientos auxesta = arch_establecimientos.Leer(i);
        if (auxesta.getidestablecimiento() == IDesta)
        {
            pos = i;
            estamodificado = auxesta;
        }
    }

    if(pos == -1)
    {
        std::cout << "[AVISO] ID incorrecto o el establecimiento no existe. Intente nuevamente." << std::endl;
        system("pause");
        return;
    }

    int opcion;
    bool hubocambios = false;
    do
    {
        system("cls");
        std::cout << "MODIFICANDO ESTABLECIMIENTO ID: #" << estamodificado.getidestablecimiento() << std::endl;
        line('-');
        std::cout << "1- Cambiar NOMBRE    (Actual: " << estamodificado.getnombreestablecimiento() << ")" << std::endl;
        std::cout << "2- Cambiar TIPO ESTABLECIMIENTO  (Actual: " << estamodificado.gettipoesta() << ")" << std::endl;
        std::cout << "3- Cambiar DIRECCION (Actual: " << estamodificado.getdireccionesta() << ")" << std::endl;
        std::cout << "0- Guardar y Salir" << std::endl;
        line('-');
        std::cout << "Elija que desea modificar: ";
        std::string entrada=entrada_valida("", NUMERO_ENTERO);
        opcion=stoi(entrada);

        switch(opcion)
        {
        case 1:
        {
            std::string nuevoNombre;
            std::cout << "Ingrese nuevo NOMBRE, ";
            std::string entrada=entrada_valida("o pulse 0 para salir", TEXTO_NO_VACIO);
            nuevoNombre = entrada;
            if (entrada=="0")
            {
                return;
            }

            estamodificado.setnombreestablecimiento(nuevoNombre.c_str());
            hubocambios = true;
            break;
        }
        case 2:
        {
            std::string nuevotipoesta;
            std::cout << "Ingrese nuevo TIPO DE ESTABLECIMIENTO, ";
            std::string entrada=entrada_valida("o pulse 0 para salir", TEXTO_NO_VACIO);
            nuevotipoesta = entrada;
            if (entrada=="0")
            {
                return;
            }

            estamodificado.settipoesta(nuevotipoesta.c_str());
            hubocambios = true;
            break;
        }
        case 3:
        {
            std::string nuevaDireccion;
            std::cout << "Ingrese nueva DIRECCION, ";
            std::string entrada=entrada_valida("o pulse 0 para salir", TEXTO_NO_VACIO);
            nuevaDireccion = entrada;
            if (entrada=="0")
            {
                return;
            }

            estamodificado.setdireccionesta(nuevaDireccion.c_str());
            hubocambios = true;
            break;
        }
        case 0:

            break;
        default:
            std::cout << "Opcion invalida" << std::endl;
            system("pause");
            break;
        }

    }
    while (opcion != 0);


    if (hubocambios == true)
    {

        if (arch_establecimientos.Guardar(estamodificado, pos))
        {
            std::cout << "Cambios guardados correctamente" << std::endl;
        }
        else
        {
            std::cout << "[ERROR] No se pudo guardar la modificacion." << std::endl;
        }
    }
    else
    {
        std::cout << "No se realizaron cambios." << std::endl;
    }

    system("pause");
}

void Menuadmin::cargarcomensales()

{
    Archivos <Comensal> arch_comensales ("Comensales.dat");
    Archivos <Establecimientos> arch_establecimientos ("Establecimientos.dat");
    int  idestablecimiento;
    Establecimientos guardar_id;
    int dia, mes, anio;
    time_t t = time(0);
    tm* now = localtime(&t);
    int anioActual = now->tm_year + 1900;
    bool loop=false;
    do
    {
        int idcomensal = arch_comensales.CantidadRegistros()+1;
        if (idcomensal == 0)
        {
            idcomensal=1;
        }
        std::cout << "--- NUEVO COMENSAL --- " << std::endl;
        line('-');
        std::cout << "Nuevo comensal bajo el ID #:" << idcomensal << std::endl;
        std::cout << std::endl;
        std::cout << "ingrese nombre/s:" << std::endl;
        std::string nombre=entrada_valida("Pulse cero para volver", TEXTO_NO_VACIO);
        line('-');
        if (nombre=="0")
        {
            break;
        }
        std::cout << "Ingrese apellido/s, " << std::endl;
        std::string apellido=entrada_valida("o pulse cero para volver", TEXTO_NO_VACIO);
        line('-');
        if (apellido=="0")
        {
            break;
        }
        std::cout << "Ingrese direccion," << std::endl;
        std::string direccion=entrada_valida(" o pulse cero para volver", TEXTO_NO_VACIO);
        line('-');
        if (direccion=="0")
        {
            break;
        }

        bool fechaValida = false;
        do
        {
            std::cout << "Ingrese dia de nacimiento, ";
            std::string entrada=entrada_valida("o pulse cero para volver", NUMERO_ENTERO);
            line('-');
            if (entrada=="0")
            {
                break;
            }
            dia=std::stoi(entrada);
            if (dia >= 1 && dia <= 31)
            {
                fechaValida = true;
            }
            else
            {
                std::cout << "[ERROR] Dia invalido. Por favor ingrese un numero entre 1 y 31." << std::endl;

            }
        }
        while(!fechaValida);

        fechaValida = false;

        do
        {
            std::cout << "ingrese mes de nacimiento, ";
            std::string entrada=entrada_valida("o pulse cero para volver", NUMERO_ENTERO);
            line('-');
            if (entrada=="0")
            {
                break;
            }
            mes=std::stoi(entrada);


            if (mes >= 1 && mes <= 12)
            {
                fechaValida = true;
            }
            else
            {
                std::cout << "[ERROR] Dia invalido. Por favor ingrese un numero entre 1 y 12." << std::endl;

            }
        }
        while(!fechaValida);

        fechaValida = false;

        do
        {
            std::cout << "Ingrese anio de nacimiento, ";
            std::string entrada=entrada_valida("o pulse cero para volver", NUMERO_ENTERO);
            line('-');
            if (entrada=="0")
            {
                break;
            }
            anio=std::stoi(entrada);
            if (anio >= 1900 && anio <= anioActual)
            {
                fechaValida = true;
            }
            else
            {
                std::cout << "[ERROR] Anio invalido." << std::endl;

            }
        }
        while(!fechaValida);

        std::cout << std::endl;
        std::cout << "Ingrese el ID del establecimiento," << std::endl;
        std::string entrada=entrada_valida(" o pulse cero para volver", NUMERO_ENTERO);
        line('-');
        if (entrada=="0")
        {
            break;
        }
        idestablecimiento=std::stoi(entrada);
        if (idestablecimiento<=0)
        {
            std::cout << "[ERROR] Numero invalido!" << std::endl;
            loop=false;
            break;
        }
        int cantidad = arch_establecimientos.CantidadRegistros();
        for (int i=0; i<cantidad; i++)
        {
            if(arch_establecimientos.Leer(i).getidestablecimiento() == idestablecimiento)
            {
                loop = true;
                ///nombreesta = arch_establecimientos.Leer(i).getnombreestablecimiento();
            }
        }
        if(!loop)
        {
            std::cout << "[ERROR] No se encontro un establecimiento con ese ID. Reintente nuevamente." << std::endl;
            break;
        }

        guardar_id.setidestablecimiento(idestablecimiento);

        Fecha fechanacimiento (dia, mes, anio);
        Comensal comensal_muestra(idcomensal, nombre.c_str(), apellido.c_str(), direccion.c_str(), fechanacimiento, guardar_id);

        if (arch_comensales.Guardar(comensal_muestra)== true)
        {
            std::cout << "El comensal se guardo exitosamente" << std::endl;
            loop=true;
            system("pause");
            system("cls");
        }
        else
        {
            std::cout << "[ERROR] Algo salio mal. Intente mas tarde" << std::endl;
            loop=false;
            system("pause");
            system("cls");
            break;
        }
    }
    while(loop==false);
}

void Menuadmin::listarcomensales()
{
    Archivos <Comensal> arch_comensales ("Comensales.dat");
    std::string nombreesta;
    int cantidad = arch_comensales.CantidadRegistros();
    std::cout << "---LISTADO DE COMENSALES---"  << std::endl;
    line('-');
    for (int i= 0; i < cantidad; i++)
    {
        Comensal comensal_muestra = arch_comensales.Leer(i);
        mostrarcomensales(comensal_muestra);
        line('-');
    }
}

void Menuadmin::mostrarcomensales(Comensal comensal_muestra)
{
    std::cout << "ID #: " << comensal_muestra.getIDcomensal() << std::endl;
    std::cout << "Nombre/s: " << comensal_muestra.getNombre() << std::endl;
    std::cout << "Apellido/s: " << comensal_muestra.getApellido() << std::endl;
    std::cout << "Direccion: " << comensal_muestra.getDireccion() << std::endl;
    std::cout << "Fecha de nacimiento: " << comensal_muestra.getFechaNacimiento().toString()<< std::endl;
    std::cout << "ID Establecimiento : " << comensal_muestra.getIDestablecimiento() << std::endl;
}

void Menuadmin::modificarcomensales()
{
    Archivos <Comensal> arch_comensales ("Comensales.dat");
    std::cout << "---MODIFICAR COMENSALES---" << std::endl;
    line('-');
    std::cout << "Ingrese el ID del comensal que desee modificar, ";
    std::string entrada=entrada_valida("o pulse cero para volver", NUMERO_ENTERO);
    int IDcomensal=std::stoi(entrada);
    if (entrada=="0")
    {
        return;
    }
    Comensal comensalmodificado;

    int cantidad = arch_comensales.CantidadRegistros();
    int pos = -1;

    for (int i=0; i< cantidad; i++)
    {
        Comensal auxcomensal = arch_comensales.Leer(i);
        if (auxcomensal.getIDcomensal() == IDcomensal)
        {
            pos = i;
            comensalmodificado = auxcomensal;
        }
    }

    if(pos == -1)
    {
        std::cout << "[AVISO] ID incorrecto o el comensal no existe. Intente nuevamente." << std::endl;
        system("pause");
        return;
    }

    int opcion;
    bool hubocambios = false;
    do
    {
        system("cls");
        std::cout << "MODIFICANDO COMENSAL ID: #" << comensalmodificado.getIDcomensal() << std::endl;
        line('-');
        std::cout << "1- Cambiar NOMBRE    (Actual: " << comensalmodificado.getNombre() << ")" << std::endl;
        std::cout << "2- Cambiar APELLIDO  (Actual: " << comensalmodificado.getApellido() << ")" << std::endl;
        std::cout << "3- Cambiar DIRECCION (Actual: " << comensalmodificado.getDireccion() << ")" << std::endl;
        std::cout << "4- Cambiar FECHA DE NACIMIENTO (Actual: " << comensalmodificado.getFechaNacimiento().toString() << ")" << std::endl;
        std::cout << "5- Cambiar ID ESTABLECIMIENTO (Actual: " << comensalmodificado.getIDestablecimiento() << ")" << std::endl;
        std::cout << "0- Guardar y Salir" << std::endl;
        line('-');
        std::cout << "Elija que desea modificar: ";
        std::string entrada=entrada_valida("", NUMERO_ENTERO);
        opcion=stoi(entrada);

        switch(opcion)
        {
        case 1:
        {
            std::string nuevoNombre;
            std::cout << "Ingrese nuevo NOMBRE, ";
            std::string entrada=entrada_valida("o pulse 0 para salir", TEXTO_NO_VACIO);
            nuevoNombre = entrada;
            if (entrada=="0")
            {
                return;
            }

            comensalmodificado.setNombre(nuevoNombre.c_str());
            hubocambios = true;
            break;
        }
        case 2:
        {
            std::string nuevoApellido;
            std::cout << "Ingrese nuevo APELLIDO, ";
            std::string entrada=entrada_valida("o pulse 0 para salir", TEXTO_NO_VACIO);
            nuevoApellido = entrada;
            if (entrada=="0")
            {
                return;
            }

            comensalmodificado.setApellido(nuevoApellido.c_str());
            hubocambios = true;
            break;
        }
        case 3:
        {
            std::string nuevaDireccion;
            std::cout << "Ingrese nueva DIRECCION, ";
            std::string entrada=entrada_valida("o pulse 0 para salir", TEXTO_NO_VACIO);
            nuevaDireccion = entrada;
            if (entrada=="0")
            {
                return;
            }

            comensalmodificado.setDireccion(nuevaDireccion.c_str());
            hubocambios = true;
            break;
        }
        case 4:
        {
            int dia, mes, anio;
            bool fechaValida = false;

            time_t t = time(0);
            tm* now = localtime(&t);
            int anioActual = now->tm_year + 1900;

            do
            {
                std::cout << "Ingrese DIA DE NACIMIENTO, ";
                std::string entrada=entrada_valida("o pulse 0 para salir", NUMERO_ENTERO);
                dia = std::stoi(entrada);
                if (entrada=="0")
                {
                    return;
                }
                if (dia >= 1 && dia <= 31)
                {
                    fechaValida = true;
                }
                else
                {
                    std::cout << "[ERROR] Dia invalido. Por favor ingrese un numero entre 1 y 31." << std::endl;

                }
            }
            while(!fechaValida);
            fechaValida = false;

            do
            {
                std::cout << "Ingrese MES DE NACIMIENTO, ";
                entrada=entrada_valida("o pulse 0 para salir", NUMERO_ENTERO);
                mes = std::stoi(entrada);
                if (entrada=="0")
                {
                    return;
                }
                if (mes >= 1 && mes  <= 12)
                {
                    fechaValida = true;
                }
                else
                {
                    std::cout << "[ERROR] Mes invalido. Por favor ingrese un numero entre 1 y 12." << std::endl;

                }
            }
            while(!fechaValida);
            fechaValida = false;
            do
            {
                std::cout << "Ingrese ANIO DE NACIMIENTO, ";
                entrada=entrada_valida("o pulse 0 para salir", NUMERO_ENTERO);
                anio = std::stoi(entrada);
                if (entrada=="0")
                {
                    return;
                }
                if (anio >= 1900 && anio <= anioActual)
                {
                    fechaValida = true;
                }
                else
                {
                    std::cout << "[ERROR] Anio invalido." << std::endl;

                }
            }
            while(!fechaValida);

            Fecha nuevafecha(dia, mes, anio);
            comensalmodificado.setFechaNacimiento(nuevafecha);

            hubocambios = true;
            break;
        }
        case 5:
        {
            Archivos <Establecimientos> arch_establecimientos ("Establecimientos.dat");
            bool loop = false;
            Establecimientos guardar_id;
            int nuevoIDestablecimiento;
            do
            {
                std::cout << "Ingrese nuevo ID de establecimiento, ";
                std::string entrada=entrada_valida("o pulse 0 para salir", NUMERO_ENTERO);
                nuevoIDestablecimiento = std::stoi(entrada);
                if (entrada=="0")
                {
                    return;
                }

                int cantidad = arch_establecimientos.CantidadRegistros();
                for (int i=0; i<cantidad; i++)
                {
                    if(arch_establecimientos.Leer(i).getidestablecimiento() == nuevoIDestablecimiento)
                    {
                        loop = true;

                    }
                }
                if(loop == false)
                {

                    std::cout << "[ERROR] No se encontro un establecimiento con ese ID. Reintente nuevamente." << std::endl;

                }
            }
            while(loop == false);

            guardar_id.setidestablecimiento(nuevoIDestablecimiento);

            comensalmodificado.setIDEstablecimiento(guardar_id);
            hubocambios = true;
            break;

        }
        case 0:

            break;
        default:
            std::cout << "Opcion invalida" << std::endl;
            system("pause");
            break;
        }

    }
    while (opcion != 0);


    if (hubocambios == true)
    {

        if (arch_comensales.Guardar(comensalmodificado, pos))
        {

            std::cout << "Cambios guardados correctamente" << std::endl;
        }
        else
        {
            std::cout << "[ERROR] No se pudo guardar la modificaciÃ³n." << std::endl;
        }
    }
    else
    {
        std::cout << "No se realizaron cambios." << std::endl;
    }

    system("pause");
}


void Menuadmin::listarconsumos()
{
    Archivos <Consumos> arch_consumos ("Consumos.dat");
    int cantidad = arch_consumos.CantidadRegistros();
    std::cout << "--- LISTADO DE CONSUMOS ---"  << std::endl;
    line('-');
    for (int i= 0; i < cantidad; i++) ///IVAN; saque el <=, no nos olvidemos que i arranca en 0, i al arrancar en 0 debe llegar a cantidad-1
    {
        Consumos consumos_muestra = arch_consumos.Leer(i);
        mostrarconsumos(consumos_muestra);
        line('-');
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
        std::cout << "Seleccione el ID del comensal";
        std::string entrada=entrada_valida(", o pulse cero para volver", NUMERO_ENTERO);
        line('-');
        if (entrada=="0")
        {
            break;
        }
        id_buscado=std::stoi(entrada);
        int registros=arch2.CantidadRegistros();
        for (int i=0; i<registros; i++)
        {
            comensal_buscado=arch2.Leer(i);
            if (id_buscado==comensal_buscado.getIDcomensal())
            {
                std::cout << "Comensal encontrado bajo el ID N#° " << comensal_buscado.getIDcomensal() << std::endl;
                loop=true;
                break;
            }
            else if (id_buscado!=comensal_buscado.getIDcomensal()&&registros==i-1)
            {
                std::cout << "[ERROR] Comensal NO encontrado, intente nuevamente" << std::endl;
            }
        }
    }
    while(loop==false);
    do
    {
        std::cout << "Indique el importe para cargar el pago" << std::endl;
        line('-');
        std::cout << "Importe: $";
        std::string entrada=entrada_valida("Pulse cero para volver", NUMERO_FLOTANTE);
        line('-');
        if (entrada=="0")
        {
            break;
        }
        importe_cargar=std::stof(entrada);
        if (importe_cargar < 0)
        {
            std::cout << "[ERROR] No puede cargar un pago negativo!" << std::endl;
        }
        int registros=arch3.CantidadRegistros();
        for (int i=0; i<registros; i++)
        {
            CC_buscado=arch3.Leer(i);
            if (CC_buscado.getcomensal()==comensal_buscado.getIDcomensal())
            {
                pago_cargar.setIDcomensal(comensal_buscado);
                pago_cargar.setimporte(importe_cargar);
                pago_cargar.setfecha(fecha_actual.hoy());
                saldo_final=CC_buscado.getSaldoActual()+importe_cargar;
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
                std::cout << "[ERROR] Falla de guardado, intente nuevamente" << std::endl;
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
                        std::cout << "[ERROR] Fallo al generar la factura, intente nuevamente" << std::endl;
                        loop=false;
                        break;
                    }
                }
            }
        }
        while(loop==false);
    case '2':
        std::cout << "[AVISO] Recuerde que debe generarla la factura mas tarde" << std::endl;
        break;
    case 0:
        break;
    default:
        std::cout << "[ERROR] Opcion invalida" << std::endl;
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

void Menuadmin::modificarusuarios()
{
    Archivos <usuario> arch_usuarios ("Usuario.dat");
    std::cout << "---MODIFICAR USUARIOS---" << std::endl;
    line('-');
    bool loop = false;
    usuario usuariomodificado;
    int pos = -1;


    do
    {
        std::string nombreUsuario;
        std::cout << "Ingrese el USUARIO que desee modificar ";
        std::string entrada=entrada_valida("o pulse cero para volver", TEXTO_NO_VACIO);
        nombreUsuario=entrada;

        if (entrada=="0")
        {
            return;
        }

        int cantidad = arch_usuarios.CantidadRegistros();


        for (int i=0; i< cantidad; i++)
        {
            usuario auxusuario = arch_usuarios.Leer(i);
            if (auxusuario.getNombreUsuario() == nombreUsuario)
            {
                pos = i;
                usuariomodificado = auxusuario;
                loop = true;
            }
        }

        if(pos == -1)
        {
            std::cout << "[AVISO] USUARIO incorrecto o inexistente. Intente nuevamente." << std::endl;
            system("pause");
            loop = false;
        }
    }
    while(loop== false);

    int opcion;
    bool hubocambios = false;
    do
    {
        system("cls");
        std::cout << "EDITAR USUARIO: #" << usuariomodificado.getNombreUsuario() << std::endl;
        line('-');
        std::cout << "1- Cambiar CONTRASEÑA" << std::endl;
        std::cout << "2- Cambiar ROL  (Actual: " << usuariomodificado.getRol() << ")" << std::endl;
        std::cout << "0- Guardar y Salir" << std::endl;
        line('-');
        std::cout << "Elija que desea modificar: ";
        std::string entrada=entrada_valida("", NUMERO_ENTERO);
        opcion=stoi(entrada);

        switch(opcion)
        {
        case 1:
        {
            std::string nuevaContrasenia;
            std::cout << "Ingrese nueva CONTRASEÑA, ";
            std::string entrada=entrada_valida("o pulse 0 para salir", TEXTO_NO_VACIO);
            nuevaContrasenia = entrada;
            if (entrada=="0")
            {
                return;
            }

            usuariomodificado.setPassword(nuevaContrasenia.c_str());
            hubocambios = true;
            break;
        }
        case 2:
        {
            int nuevoRol;
            bool loop = false;
            do
            {
                std::cout << "Ingrese nuevo ROL, 1 = ADMIN, 2 = ENCARGADO, 3 = COMENSALES" << std:: endl;
                std::string entrada=entrada_valida("o pulse 0 para salir", NUMERO_ENTERO);
                nuevoRol = stoi(entrada);
                if (entrada=="0")
                {
                    return;
                }


                int cantidad = arch_usuarios.CantidadRegistros();
                for (int i=0; i < cantidad; i++)
                {
                    if (arch_usuarios.Leer(i).getRol() == nuevoRol )
                    {
                        loop = true;
                    }
                }
                if (loop == false)
                {
                    std::cout << "[ERROR] Rol inexistente, intente de nuevo" << std::endl;
                }
            }
            while(loop == false);

            usuariomodificado.setRol(nuevoRol);
            hubocambios = true;
            break;
        }
        case 0:

            break;
        default:
            std::cout << "Opcion invalida" << std::endl;
            system("pause");
            break;
        }

    }
    while (opcion != 0);


    if (hubocambios == true)
    {

        if (arch_usuarios.Guardar(usuariomodificado, pos))
        {
            std::cout << "Cambios guardados correctamente" << std::endl;
        }
        else
        {
            std::cout << "[ERROR] No se pudo guardar la modificaciÃ³n." << std::endl;
        }
    }
    else
    {
        std::cout << "No se realizaron cambios." << std::endl;
    }

    system("pause");
}

bool Menuadmin::copiarArchivo(std::string origen, std::string destino)
{
    std::ifstream fuente(origen, std::ios::binary); /// Abrimos el archivo ORIGINAL para LEER
    std::ofstream dest(destino, std::ios::binary); /// Abrimos o creamos el archivo COPIA para ESCRIBIR
    if (!fuente.is_open() || !dest.is_open())      /// Verificamos si ambos se pudieron abrir
    {
        return false;
    }

    dest << fuente.rdbuf();   /// Copia todo el contenido

    fuente.close();
    dest.close();
    return true;

    ///NOTA: ifstream (Input File Stream): Es una herramienta de C++ diseñada solo para leer archivos.


}


void Menuadmin::realizarBackup()
{
    std::cout << "--- REALIZANDO COPIA DE SEGURIDAD ---" << std::endl;
    line('-');

    if (copiarArchivo("Menues.dat", "Menues.bkp") &&
            copiarArchivo("Usuario.dat", "Usuario.bkp") &&
            copiarArchivo("Establecimientos.dat", "Establecimientos.bkp") &&
            copiarArchivo("Comensales.dat", "Comensales.bkp")&&
            copiarArchivo("Consumos.dat", "Consumos.bkp")&&
            copiarArchivo("CC.dat", "CC.bkp")&&
            copiarArchivo("Facturas.dat", "Facturas.bkp")

       )
    {
        std::cout << "Copia de seguridad creada correctamente (.bkp)" << std::endl;
    }
    else
    {
        std::cout << "[ERROR] No se pudieron copiar algunos archivos." << std::endl;
    }
    system("pause");
}


void Menuadmin::restaurarBackup()
{
    std::cout << "--- RESTAURAR COPIA DE SEGURIDAD ---" << std::endl;
    line('-');
    std::cout << "[ADVERTENCIA] Esto sobrescribira los datos actuales con la copia guardada." << std::endl;
    std::cout << "Esta seguro? (S/N): ";
    char confirmacion;
    std::cin >> confirmacion;

    if (confirmacion == 's' || confirmacion == 'S')
    {
        if (copiarArchivo("Menues.bkp", "Menues.dat") &&
                copiarArchivo("Usuario.bkp", "Usuario.dat") &&
                copiarArchivo("Establecimientos.bkp", "Establecimientos.dat") &&
                copiarArchivo("Comensales.bkp", "Comensales.dat")&&
                copiarArchivo("Consumos.bkp", "Consumos.dat")&&
                copiarArchivo("CC.bkp", "CC.dat")&&
                copiarArchivo("Facturas.bkp", "Facturas.dat"))
        {
            std::cout << "Sistema restaurado correctamente." << std::endl;
        }
        else
        {
            std::cout << "[ERROR] No se encontro el archivo de backup (.bkp) o hubo un error." << std::endl;
        }
    }
    else
    {
        std::cout << "Operacion cancelada." << std::endl;
    }
    system("pause");
}



void Menuadmin::exportarDatosCSV()
{
    int opcion;
    do
    {
        system("cls");
        std::cout << "--- EXPORTAR A EXCEL (CSV) ---" << std::endl;
        line('-');
        std::cout << "1- Exportar MENUES" << std::endl;
        std::cout << "2- Exportar ESTABLECIMIENTOS" << std::endl;
        std::cout << "3- Exportar USUARIOS" << std::endl;
        std::cout << "4- Exportar COMENSALES" << std::endl;
        std::cout << "5- Exportar FACTURAS" << std::endl;
        std::cout << "6- Exportar CONSUMOS" << std::endl;
        std::cout << "7- Exportar CUENTAS CORRIENTES" << std::endl;
        std::cout << "0- Volver" << std::endl;
        line('-');

        std::string entrada = entrada_valida("Seleccione una opcion: ", NUMERO_ENTERO);
        opcion = std::stoi(entrada);

        switch(opcion)
        {
        case 1:
        {
            Archivos<Menues> arch("Menues.dat");
            std::string nombreArchivo = "Menues_Exportados.csv";
            std::ofstream salida(nombreArchivo);

            if (!salida.is_open())
            {
                std::cout << "[ERROR] No se pudo crear el archivo." << std::endl;
                break;
            }


            salida << "ID;Nombre;Tipo;DesTipo;Precio;Fecha;ID_Establecimiento\n";

            int cant = arch.CantidadRegistros();
            for (int i = 0; i < cant; i++)
            {
                Menues aux = arch.Leer(i);
                salida << aux.getidmenu() << ";"
                       << aux.getnombremenu() << ";"
                       << aux.getidtipo() << ";"
                       << aux.getdesctipo() << ";"
                       << aux.getvalorplato() << ";"
                       << aux.getfecha().toString() << ";"
                       << aux.getesta() << "\n";  /// Para escribir en archivos dentro de un for, hay que usar siempre \n


            }
            salida.close();
            std::cout << "Se exportaron " << cant << " menues a '" << nombreArchivo << "'" << std::endl;
            system("pause");
            break;
        }

        case 2:
        {
            Archivos<Establecimientos> arch("Establecimientos.dat");
            std::string nombreArchivo = "Establecimientos_Exportados.csv";
            std::ofstream salida(nombreArchivo);

            if (!salida.is_open())
            {
                std::cout << "[ERROR] No se pudo crear el archivo." << std::endl;
                break;
            }


            salida << "ID;Nombre;Direccion;Localidad\n";

            int cant = arch.CantidadRegistros();
            for (int i = 0; i < cant; i++)
            {
                Establecimientos aux = arch.Leer(i);
                salida << aux.getidestablecimiento() << ";"
                       << aux.getnombreestablecimiento() << ";"
                       << aux.gettipoesta() << ";"
                       << aux.getdireccionesta() << "\n";
            }
            salida.close();
            std::cout << "Se exportaron " << cant << " establecimientos." << std::endl;
            system("pause");
            break;
        }

        case 3:
        {
            Archivos<usuario> arch("Usuario.dat");
            std::string nombreArchivo = "Usuarios_Exportados.csv";
            std::ofstream salida(nombreArchivo);

            if (!salida.is_open()) break;

            salida << "Usuario;Rol\n";

            int cant = arch.CantidadRegistros();
            for (int i = 0; i < cant; i++)
            {
                usuario aux = arch.Leer(i);

                std::string nombreRol;
                if(aux.getRol() == 1) nombreRol = "ADMIN";
                else if(aux.getRol() == 2) nombreRol = "ENCARGADO";
                else if(aux.getRol() == 3) nombreRol = "COMENSAL";

                salida << aux.getNombreUsuario() << ";"
                       << nombreRol << "\n";
            }
            salida.close();
            std::cout << "Usuarios exportados." << std::endl;
            system("pause");
            break;
        }

        case 4:
        {
            Archivos<Comensal> arch("Comensales.dat");
            std::string nombreArchivo = "Comensales_Exportados.csv";
            std::ofstream salida(nombreArchivo);

            if (!salida.is_open())
            {
                std::cout << "[ERROR] No se pudo crear el archivo." << std::endl;
                break;
            }


            salida << "ID;Nombre;Apellido;Direccion;FechaNacimiento;IDestablecimiento\n";

            int cant = arch.CantidadRegistros();
            for (int i = 0; i < cant; i++)
            {
                Comensal aux = arch.Leer(i);
                salida << aux.getIDcomensal() << ";"
                       << aux.getNombre() << ";"
                       << aux.getApellido() << ";"
                       << aux.getDireccion() << ";"
                       << aux.getFechaNacimiento().toString() << ";"
                       << aux.getIDestablecimiento() << "\n";

            }
            salida.close();
            std::cout << "Se exportaron " << cant << " establecimientos." << std::endl;
            system("pause");
            break;

        }
        case 5:
        {
            Archivos<Factura> arch("Facturas.dat");
            std::string nombreArchivo = "Facturas_Exportados.csv";
            std::ofstream salida(nombreArchivo);

            if (!salida.is_open())
            {
                std::cout << "[ERROR] No se pudo crear el archivo." << std::endl;
                break;
            }


            salida << "IDcomensal;Nombre;IDmenu;MedioDePago;Importe;Fecha;Numeracion;NumFac\n";

            int cant = arch.CantidadRegistros();
            for (int i = 0; i < cant; i++)
            {
                Factura aux = arch.Leer(i);
                salida << aux.getIDcomensal() << ";"
                       << aux.getnombrecomensal() << ";"
                       << aux.getIDmenu() << ";"
                       << aux.getMedioDePago() << ";"
                       << aux.getImporte() << ";"
                       << aux.getFecha().toString() << ";"
                       << aux.getnumfc() << ";"
                       << aux.getNumeracion() << "\n";

            }
            salida.close();
            std::cout << "Se exportaron " << cant << " facturas." << std::endl;
            system("pause");
            break;

        }
        case 6:
        {
            Archivos<Consumos> arch("Consumos.dat");
            std::string nombreArchivo = "Consumos_Exportados.csv";
            std::ofstream salida(nombreArchivo);

            if (!salida.is_open())
            {
                std::cout << "[ERROR] No se pudo crear el archivo." << std::endl;
                break;
            }


            salida << "Cliente;Plato;Importe;Fecha\n";

            int cant = arch.CantidadRegistros();
            for (int i = 0; i < cant; i++)
            {
                Consumos aux = arch.Leer(i);
                salida << aux.getcliente() << ";"
                       << aux.getplato() << ";"
                       << aux.getimporte() << ";"
                       << aux.getfecha().toString() << "\n";
            }
            salida.close();
            std::cout << "Se exportaron " << cant << " consumos." << std::endl;
            system("pause");
            break;

        }
        case 7:
        {
            Archivos<CuentaCorriente> arch("CC.dat");
            std::string nombreArchivo = "CC_Exportados.csv";
            std::ofstream salida(nombreArchivo);

            if (!salida.is_open())
            {
                std::cout << "[ERROR] No se pudo crear el archivo." << std::endl;
                break;
            }


            salida << "Numeracion;Comensal;EstadoDeuda;SaldoActual\n";

            int cant = arch.CantidadRegistros();
            for (int i = 0; i < cant; i++)
            {
                CuentaCorriente aux = arch.Leer(i);
                salida << aux.getnumeracion() << ";"
                       << aux.getcomensal() << ";"
                       << aux.getnombrecomensal() << ";"
                       << aux.getestadodeuda() << ";"
                       << aux.getSaldoActual() << "\n";

            }
            salida.close();
            std::cout << "Se exportaron " << cant << " Cuentas Corrientes." << std::endl;
            system("pause");
            break;

        }
        case 0:
            break;

        default:
            std::cout << "Opcion invalida." << std::endl;
            system("pause");
            break;
        }

    }
    while (opcion != 0);

    ///NOTA: ofstream (Output File Stream): Es la herramienta para crear y escribir archivos de texto.
}
