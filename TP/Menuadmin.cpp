#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cctype>
#include "MenuPadreABML.h"
#include "MenuSistema.h"
#include "Menuadmin.h"
#include "Archivos.h"
#include "TipoAlmuerzo.h"
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

std::string Menuadmin::entrada_cruda(const std::string& mensaje)
{
    std::string entrada;
    std::cout << mensaje << std::endl;
    if (std::cin.fail() || std::cin.peek() == '\n')
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::getline(std::cin, entrada);
    return entrada;
}

std::string Menuadmin::entrada_valida(const std::string& mensaje, TipoEntrada tipo) ///Ahora usamos esto en ves de solo ignore y getline
{                                                                                  ///En discord te explico como funciona
    std::string entrada_str;
    // El bucle se repite hasta que se encuentra una entrada válida.
    while (true)
    {
        // Obtenemos la entrada como string
        entrada_str = entrada_cruda(mensaje);
        // Bloque switch para manejar la lógica de validación específica.
        switch (tipo)
        {
        case NUMERO_ENTERO:
        {
            try // Se usa por si el programa tiene un error, y en ves de finalizar primero intenta esta solucion
            {
                // Intenta convertir el string a entero.
                // Si falla (por ejemplo, si el usuario ingresa "abc"), salta al 'catch'.
                std::stoi(entrada_str);
                // Si la conversión fue exitosa, la entrada es válida.
                return entrada_str;
            }
            catch (const std::invalid_argument& e)
            {
                std::cout << "[ERROR] Entrada inválida. Por favor, ingrese un NÚMERO ENTERO válido" << std::endl;
            }
            catch (const std::out_of_range& e)
            {
                std::cout << "[ERROR] El número ingresado es demasiado grande o pequeño. Intente con un valor razonable" << std::endl;
            }
            // Si hubo un error, el ciclo continúa.
            break;
        }
        case TEXTO_NO_VACIO:
        {
            // 1. Verificamos si la cadena está vacía
            if (entrada_str.empty())
            {
                std::cout << "[ERROR] La entrada no puede estar vacia. Intente de nuevo" << std::endl;
                break; // Continúa el ciclo
            }
            // 2. Verificamos si la cadena contiene solo espacios en blanco
            // Utilizamos una copia temporal para eliminar espacios y verificar si queda algo más.
            std::string temp = entrada_str;
            temp.erase(std::remove_if(temp.begin(), temp.end(), ::isspace), temp.end());
            if (temp.empty())
            {
                std::cout << "[ERROR] La entrada no puede contener solo espacios en blanco. Ingrese texto válido" << std::endl;
                break; // Continúa el ciclo
            }
            // Si pasó ambas validaciones, la entrada es un texto válido.
            return entrada_str;
        }
        case NUMERO_FLOTANTE:
        {
            try
            {
                // Lo mismo que hicimos con NUMERO_ENTERO
                std::stof(entrada_str);
                return entrada_str;
            }
            catch (const std::invalid_argument& e)
            {
                std::cout << "[ERROR] Entrada inválida. Por favor, ingrese un NÚMERO válido" << std::endl;
            }
            catch (const std::out_of_range& e)
            {
                std::cout << "[ERROR] El número ingresado es demasiado grande o pequeño. Intente con un valor razonable" << std::endl;
            }
            break;
        }
        default:
            std::cout << "[ERROR INTERNO] Tipo de entrada no reconocido" << std::endl;
            return ""; // Retornar vacío en caso de error interno
        }
    }
}

void Menuadmin::listarplatos() ///IVAN; reparado de mostrar platos
{
    Archivos <Menues> arch ("Menues.dat");
    Archivos <Establecimientos> arch2 ("Establecimientos.dat");
    Establecimientos esta_muestra;
    bool loop=false;
    Menues plato_muestra;
    Fecha fecha_hoy;
    fecha_hoy.hoy();
    do
    {
        std::cout << "Ingrese ID de establecimiento" << std::endl;
        std::string entrada=entrada_valida("Pulse cero para volver", NUMERO_ENTERO); /// Aca es el ingreso del usuario
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
                for (int j=0; j<registros2; j++)
                {
                    plato_muestra=arch.Leer(j);
                    if (esta_muestra.getidestablecimiento()==plato_muestra.getesta())
                    {
                        if (fecha_hoy.hoy()==plato_muestra.getfecha())
                        {
                            std::cout << plato_muestra.toString() << std::endl;
                            loop=true;
                        }
                        else if (fecha_hoy.hoy()!=plato_muestra.getfecha()&&registros2==j+1)
                        {
                            std::cout << "[AVISO] No se encontro ningun plato para " << esta_muestra.getnombreestablecimiento() << " el dia de hoy" << std::endl;
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
    }
    while(loop==false);
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
        line('-');
        std::cout << "El plato: " << std::endl;
        std::cout << plato_muestra.toString() << std::endl;
        std::cout << "Con una valoracion promedio de: " << valoracion/cant_val << std::endl;
        line('-');
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
        std::cout << "Seleccione el ID del plato que desea agregar una valoracion" << std::endl;
        std::string entrada=entrada_valida("Pulse cero para volver", NUMERO_ENTERO);
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
                        std::cout << "Agregar una valoracion (del 1 al 10): ";
                        std::string entrada=entrada_valida("Pulse cero para volver", NUMERO_ENTERO);
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
                            valoracion=plato_muestra.getvaloracion()+valoracion; /// Suma con la valoracion que ya tenia el plato
                            plato_muestra.setvaloracion(valoracion);
                            int cant;
                            cant=plato_muestra.getcant_valoracion()+1;
                            plato_muestra.setcant_valoracion(cant);
                            ejecutar_ok=arch.Guardar(plato_muestra, x); /// Sobreescritura
                            if (ejecutar_ok==false)
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
        std::cout << "Ingrese el nombre del menu nuevo" << std::endl;
        std::string nombremenu=entrada_valida("Pulse cero para volver", TEXTO_NO_VACIO);
        line('-');
        if (nombremenu=="0")
        {
            break;
        }
        nombre_aux=nombremenu.c_str();
        plato_muestra.setnombremenu(nombre_aux);
        do
        {
            std::cout << "Ingrese el ID del establecimiento" << std::endl;
            std::string entrada=entrada_valida("Pulse cero para volver", NUMERO_ENTERO);
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
        std::cout << "Ingrese el valor del plato" << std::endl;
        std::string entrada=entrada_valida("Pulse cero para volver", NUMERO_FLOTANTE);
        line('-');
        importe=std::stof(entrada);
        if (entrada=="0")
        {
            break;
        }
        if (importe < 0)
        {
            std::cout << "[ERROR] No se puede establecer un precio negativo!" << std::endl;
            loop=false;
            break;
        }
        else
        {
            plato_muestra.setvalorplato(importe);
        }
        loop=true;
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

void Menuadmin::eliminarplato()
{
///aca vamos a usar un funcion que vamos a hacer en Archivos.h
    /**
    Aclaración sobre el Flujo de Nombres
    El flujo siempre es:

    El archivo que todas las funciones usan se llama menues.dat.

    Para borrar, el programa crea temp.dat.

    Una vez finalizada la copia filtrada, el programa borra menues.dat.

    Finalmente, el programa renombra temp.dat a menues.dat.

    De esta manera, las demás funciones siempre operan sobre menues.dat.
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
        std::string entrada=entrada_valida("Pulse cero para volver", NUMERO_ENTERO);
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

            }
            else
            {
                std::cout << "[ERROR] ID no encontrado o no valido, intente nuevamente" << std::endl;
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
    bool loop=false;
    do
    {
        std::cout << "Seleccione su/el ID de usuario para generar factura" << std::endl;
        std::string entrada=entrada_valida("Pulse cero para volver", NUMERO_ENTERO);
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
        std::cout << "Ingrese el importe a facturar: "; ///verificar valores negativos
        entrada=entrada_valida("Pulse cero para volver", NUMERO_FLOTANTE);
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
        std::cout << "Ingrese el ID de usuario para ver cuenta corriente" << std::endl;
        std::string entrada=entrada_valida("Pulse cero para volver", NUMERO_ENTERO);
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
        std::cout << "NUEVO ESTABLECIMIENTO" << std::endl;
        std::cout << "-----------------------------" << std::endl;
        std::cout << "Nuevo establecimiento bajo el ID #:" << idestablecimiento << std::endl;
        std::cout << std::endl;
        std::cout << "ingrese el nombre:" << std::endl;
        std::string nombreestablecimiento=entrada_valida("Pulse cero para volver", TEXTO_NO_VACIO);
        line('-');
        if (nombreestablecimiento=="0")
        {
            break;
        }
        std::cout << "ingrese la direccion:" << std::endl;
        std::string direccionesta=entrada_valida("Pulse cero para volver", TEXTO_NO_VACIO);
        line('-');
        if (direccionesta=="0")
        {
            break;
        }
        std::cout << "Ingrese el tipo de establecimiento:" << std::endl;
        std::string tipoesta=entrada_valida("Pulse cero para volver", TEXTO_NO_VACIO);
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

    std::cout << "ID #: " << establecimientos_muestra.getidestablecimiento() << std::endl;
    std::cout << "Nombre: " << establecimientos_muestra.getnombreestablecimiento() << std::endl;
    std::cout << "Direccion: " << establecimientos_muestra.getdireccionesta() << std::endl;
    std::cout << "Tipo de establecimiento: " << establecimientos_muestra.gettipoesta() << std::endl;
}

void Menuadmin::cargarcomensales()   /// se agrego getline y cin.ignore para que nos deje ingresar cadenas con espacios.
////Se agrego validacion para uqe no deje cargar un establecimiento que no existe
{
    Archivos <Comensal> arch_comensales ("Comensales.dat");
    Archivos <Establecimientos> arch_establecimientos ("Establecimientos.dat");
    int  idestablecimiento;
    Establecimientos guardar_id;
    int dia, mes, anio;
    bool loop=false;
    do
    {
        int idcomensal = arch_comensales.CantidadRegistros()+1;
        if (idcomensal == 0)
        {
            idcomensal=1;
        }
        std::cout << "NUEVO COMENSAL" << std::endl;
        std::cout << "-----------------------------" << std::endl;
        std::cout << "Nuevo comensal bajo el ID #:" << idcomensal << std::endl;
        std::cout << std::endl;
        std::cout << "ingrese nombre/s:" << std::endl;
        std::string nombre=entrada_valida("Pulse cero para volver", TEXTO_NO_VACIO);
        line('-');
        if (nombre=="0")
        {
            break;
        }
        std::cout << "ingrese apellido/s:" << std::endl;
        std::string apellido=entrada_valida("Pulse cero para volver", TEXTO_NO_VACIO);
        line('-');
        if (apellido=="0")
        {
            break;
        }
        std::cout << "ingrese direccion" << std::endl;
        std::string direccion=entrada_valida("Pulse cero para volver", TEXTO_NO_VACIO);
        line('-');
        if (direccion=="0")
        {
            break;
        }
        std::cout << "ingrese dia de nacimiento: ";
        std::string entrada=entrada_valida("Pulse cero para volver", NUMERO_ENTERO);
        line('-');
        if (entrada=="0")
        {
            break;
        }
        dia=std::stoi(entrada);
        if (mes<=0)
        {
            std::cout << "[ERROR] Numero invalido!" << std::endl;
            loop=false;
            break;
        }
        std::cout << "ingrese mes de nacimiento: ";
        entrada=entrada_valida("Pulse cero para volver", NUMERO_ENTERO);
        line('-');
        if (entrada=="0")
        {
            break;
        }
        mes=std::stoi(entrada);
        if (mes<=0)
        {
            std::cout << "[ERROR] Numero invalido!" << std::endl;
            loop=false;
            break;
        }
        std::cout << "ingrese anio de nacimiento: ";
        entrada=entrada_valida("Pulse cero para volver", NUMERO_ENTERO);
        line('-');
        if (entrada=="0")
        {
            break;
        }
        anio=std::stoi(entrada);
        if (anio<=0)
        {
            std::cout << "[ERROR] Numero invalido!" << std::endl;
            loop=false;
            break;
        }
        std::cout << std::endl;
        std::cout << "Ingrese el ID del establecimiento:" << std::endl;
        entrada=entrada_valida("Pulse cero para volver", NUMERO_ENTERO);
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
    std::cout << "ID #: " << comensal_muestra.getIDcomensal() << std::endl;
    std::cout << "Nombre/s: " << comensal_muestra.getNombre() << std::endl;
    std::cout << "Apellido/s: " << comensal_muestra.getApellido() << std::endl;
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
    for (int i= 0; i < cantidad; i++) ///IVAN; saque el <=, no nos olvidemos que i arranca en 0, i al arrancar en 0 debe llegar a cantidad-1
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
        std::string entrada=entrada_valida("Pulse cero para volver", NUMERO_ENTERO);
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
                std::cout << "Comensal encontrado bajo el ID N° " << comensal_buscado.getIDcomensal() << std::endl;
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
