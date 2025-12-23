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
    int id;               /// ARREGLADO! SE GENERO SWICHT DINAMICO PARA QUE MUESTRE TODOS LOS MENUS DEL ESTABLECIMIENTO.
    unsigned int opcion;  /// SI UN ESTABLECIMIENTO NO TIENE NADA CARGADO NO LO MUESTRA. ANTES MOSTRABA UN MENU RANDOM (NO SE XQ PERO PUDE CORREGIRLO)
    bool loop=true;        //"unsigned" variable sin signos
    MenuPadreABML::line('*');
    std::cout << "  BIENVENIDO/A AL COMEDOR" << std::endl;
    MenuPadreABML::line('*');
    do
    {
        std::string entrada = entrada_valida("Por favor, ingrese su ID de CLIENTE, o pulse cero para volver:", NUMERO_ENTERO);
        id = std::stoi(entrada);
        if (entrada=="0")
        {
            return;
        }
        _clientebuscado=buscarcliente(id, loop);
    }
    while(loop==false);
    system("cls");

    //int idEstablecimiento = _clientebuscado.getIDestablecimiento();

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

    for (int unsigned i=0; i< menuesDisponibles.size(); i++)
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
    while ((opcion < 1) || (opcion > menuesDisponibles.size()));

    for (int unsigned i=0; i< menuesDisponibles.size(); i++)
    {
        if(opcion==i+1)
        {
            _menubuscado=menuesDisponibles[i];
        }
    }

    generarconsumo();

    std::cout << "Consumo cargado EXITOSAMENTE!" << std::endl; ///arreglar! no puede estar aca este mensaje!
}

std::vector<Menues> Menucomensal::buscarplatos()
{
    Archivos <Menues> arch ("Menues.dat");
    std::vector<Menues> menuesDisponibles;
    Fecha fecha_actual;
    Menues menu;
    fecha_actual.hoy();
    int registros=arch.CantidadRegistros();
    for (int i=0; i<registros; i++)
    {
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

    bool cliente_encontrado=false, tiene_deuda=false, cancel=false;
 std::string txtPago;
    int tipo_consumo=tipodeconsumo(cancel);

    if (cancel==false)
    {
        Fecha fecha_generar;
        fecha_generar.hoy();
        Consumos consumodelcomensal(fecha_generar.hoy(), _clientebuscado, _menubuscado);
        arch.Guardar(consumodelcomensal);

        CuentaCorriente actualizar_cuenta;
        int cantregistros=arch2.CantidadRegistros();

        for (int i=0; i<cantregistros; i++)
        {
            actualizar_cuenta=arch2.Leer(i);
            if (_clientebuscado.getIDcomensal()==actualizar_cuenta.getcomensal()) ///si el cliente esta en el .dat
            {
                if (tipo_consumo==1 or tipo_consumo==2) 
                {
                    float importe_final;
                
                    if (tipo_consumo == 1)
                    {
                        importe_final = consumodelcomensal.getimporte() - (consumodelcomensal.getimporte()/10);
                        txtPago = "Efectivo (Desc. 10%)";
                    }
                    else
                    {
                        importe_final = consumodelcomensal.getimporte();
                        txtPago = "Tarjeta / QR";
                    }
                    
                    cantregistros=arch2.CantidadRegistros()+1;
                    float saldo_actual=actualizar_cuenta.getSaldoActual();
                    if (actualizar_cuenta.getSaldoActual()<0)
                    {
                        tiene_deuda=true;
                    }
                    CuentaCorriente actualizar_cuenta(cantregistros, _clientebuscado, saldo_actual, tiene_deuda);
                    arch2.Guardar(actualizar_cuenta, i); ///uso la posicion i porque es una sobreescritura

                    ///Pagos pago_guardar;
                    ///int nuevoID = arch4.CantidadRegistros() + 1;
                    /// pago_guardar.setNumeracion(nuevoID);
                    ///pago_guardar (nuevoID, _clientebuscado, saldo_C_descuento, fecha_generar.hoy());
                    /// arch4.Guardar(pago_guardar); ///aca guardo un pago
                    int cantregistros2=arch3.CantidadRegistros();
                    Factura fc_consumo(cantregistros2+1, _clientebuscado, fecha_generar.hoy(), _menubuscado, importe_final, tipo_consumo);
                    arch3.Guardar(fc_consumo); ///0002-00001
                    mostrarTicket(fc_consumo, txtPago);
                    cliente_encontrado=true;
                    break;
                }
                else if (tipo_consumo==3) //paga en cuenta corriente
                {
                    txtPago = "Cuenta Corriente";
                    float saldoauxiliar=actualizar_cuenta.getSaldoActual();
                    saldoauxiliar=actualizar_cuenta.getSaldoActual()-consumodelcomensal.getimporte();
                    if (saldoauxiliar<0)
                    {
                        tiene_deuda=true;
                    }
                    cantregistros=arch2.CantidadRegistros()+1;
                    CuentaCorriente actualizar_cuenta(cantregistros, _clientebuscado, saldoauxiliar, tiene_deuda);
                    arch2.Guardar(actualizar_cuenta, i); ///uso la posicion i porque es una sobreescritura
                    int cantregistros2=arch3.CantidadRegistros();
                    Factura fc_consumo(cantregistros2+1, _clientebuscado, fecha_generar.hoy(), _menubuscado, _menubuscado.getvalorplato(), tipo_consumo);
                    arch3.Guardar(fc_consumo);
                     
                mostrarTicket(fc_consumo, txtPago);
                    cliente_encontrado=true;
                    break;
                }
            }
        }
        if (cliente_encontrado==false) ///si el cliente NO esta en el .dat
        {
            if (tipo_consumo == 1 || tipo_consumo == 2) 
            {
                
                float importe_final;
                if (tipo_consumo == 1) {
                    importe_final = consumodelcomensal.getimporte() - (consumodelcomensal.getimporte()/10);
                    txtPago = "Efectivo (Desc. 10%)";
                } else {
                    importe_final = consumodelcomensal.getimporte();
                    txtPago = "Tarjeta / QR";
                }
                cantregistros=arch2.CantidadRegistros()+1;
                tiene_deuda=false;
                CuentaCorriente actualizar_cuenta(cantregistros, _clientebuscado, 0, tiene_deuda);
                arch2.Guardar(actualizar_cuenta);
                ///Pagos pago_guardar (_clientebuscado, _menubuscado.getvalorplato(), fecha_generar.hoy());
                ///arch4.Guardar(pago_guardar); ///aca guardo un pago
                int cantregistros2=arch3.CantidadRegistros();
                Factura fc_consumo(cantregistros2+1, _clientebuscado, fecha_generar.hoy(), _menubuscado, _menubuscado.getvalorplato(), tipo_consumo);
                arch3.Guardar(fc_consumo);
                mostrarTicket(fc_consumo, txtPago);
               
            }
            else if (tipo_consumo==3) //paga en cuenta corriente
            {
                txtPago = "Cuenta Corriente";
                cantregistros=arch2.CantidadRegistros()+1;
                float saldoauxiliar=consumodelcomensal.getimporte();
                tiene_deuda=true;
                CuentaCorriente actualizar_cuenta(cantregistros, _clientebuscado, 0-saldoauxiliar, tiene_deuda);
                arch2.Guardar(actualizar_cuenta);
                int cantregistros2=arch3.CantidadRegistros();
                Factura fc_consumo(cantregistros2+1, _clientebuscado, fecha_generar.hoy(), _menubuscado, _menubuscado.getvalorplato(), tipo_consumo);
                arch3.Guardar(fc_consumo);
                mostrarTicket(fc_consumo, txtPago);
            }
        }
    }
}

int Menucomensal::tipodeconsumo(bool &cancel)
{
    bool loop=false;
    int result=0;
    int opcion;
    do
    {
        system("cls");
        line('=');
        std::cout << "SELECCIONE METODO DE PAGO " << std::endl;
        line('=');
        std::cout << std::endl;
        std::cout << "1- Efectivo (10% DE DESCUENTO)" << std::endl;
        std::cout << "2- Tarjeta / QR / Transferencia" << std::endl;
        std::cout << "3- Cargar a Cuenta Corriente (Deuda)" << std::endl;
        std::cout << "0- Cancelar Operacion" << std::endl;
        line('-');
        std::string entrada = entrada_valida("Opcion: ", NUMERO_ENTERO);
        opcion = std::stoi(entrada);
        switch(opcion)
        {
        case 1:
            std::cout << "Gracias por abonar, factura generada EXITOSAMENTE!" << std::endl;
            
            system("pause");
            loop=true;
            result=1; ///abono en efectivo
            break;
        case 2:

            std::cout << "Pago APROBADO. Gracias por su compra!" << std::endl;
            system("pause");
            loop = true;
            result = 2;
            break;
        case 3:
            std::cout << "Se genero una deuda en su CUENTA CORRIENTE, puede abonarla mas tarde" << std::endl;
            system("pause");
            loop=true;
            result=3; ///deuda en CC
            break;
        case 0:
            std::cout << "Operacion CANCELADA." << std::endl;
            cancel=true;
            loop=true;
            result = 0;
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

void Menucomensal::mostrarTicket(Factura fc, std::string textoPago)
{
    system("cls");
    line('=',50);
    std::cout << "COMPROBANTE GENERADO EXITOSAMENTE " << std::endl;
    line('=',50);
    std::cout << "--------------------------------------" << std::endl;
    std::cout << "| FACTURA NRO: " << fc.getnumfc() << std::endl; 
    std::cout << "--------------------------------------" << std::endl;
    std::cout << "| FECHA:       " << fc.getFecha().toString() << std::endl;
    std::cout << "| CLIENTE:     " << fc.getnombrecomensal() << " " << fc.getApellidocomensal() << std::endl;
    std::cout << "| MEDIO PAGO:  " << textoPago << std::endl;
    std::cout << "|                                      " << std::endl;
    std::cout << "| TOTAL:       $ " << fc.getImporte() << std::endl;
    std::cout << "--------------------------------------" << std::endl;
    std::cout << std::endl;
    system("pause");
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

