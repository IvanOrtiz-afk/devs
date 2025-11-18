#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include "Menucomensal.h"
#include "Comensales.h"
#include "Menues.h"
#include "Archivos.h"
#include "Consumos.h"
#include "CC.h"
#include "Fecha.h"

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

void Menucomensal::ejecutarmenu()
{
    int id;
    int opcion;
    bool loop=true;
    int tipocom = 1;
    int tipoveg = 2;
    int tipocel = 3;
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
    system("pause");
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
        generarconsumo();
        break;
    case 2:
        _menubuscado=buscarplatos(tipoveg); ///aca se carga el consumo
        generarconsumo();
        break;
    case 3:
        _menubuscado=buscarplatos(tipocel); ///aca se carga el consumo
        generarconsumo();
        break;
    }
}

Menues Menucomensal::buscarplatos(const char tipo)
{
    Archivos <Menues> arch ("Menues.dat");
    Menues menu;
    arch.Guardar(menu); ///SACAR DESPUES
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
    arch.Guardar(cliente); ///SACAR DESPUES
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
        return cliente=Comensal();
    };

    return cliente;
}

void Menucomensal::generarconsumo()
{
    Archivos <Factura> arch3 ("Facturas.dat");
    bool tipo_consumo=tipodeconsumo();
    Fecha fecha_generar;
    fecha_generar.hoy();
    Consumos consumodelcomensal(fecha_generar, _clientebuscado, _menubuscado);
    bool cliente_encontrado=false, tiene_deuda=false;
    Archivos <Consumos> arch ("Consumos.dat");
    arch.Guardar(consumodelcomensal);
    Archivos <CuentaCorriente> arch2 ("CC.dat");
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
                saldoauxiliar=actualizar_cuenta.getSaldoActual()-(consumodelcomensal.getimporte()-consumodelcomensal.getimporte()/10);
                if (saldoauxiliar<0)
                {
                    tiene_deuda=true;
                }
                CuentaCorriente actualizar_cuenta(i, _clientebuscado, saldoauxiliar, tiene_deuda);
                arch2.Guardar(actualizar_cuenta, i); ///uso la posicion i porque es una sobreescritura
                int cantregistros2=arch3.CantidadRegistros();
                if (cantregistros2==0)
                {
                    cantregistros2=1;
                }
                Factura fc_consumo(cantregistros2, _clientebuscado, fecha_generar, _menubuscado, _menubuscado.getvalorplato(), tipo_consumo);
                arch3.Guardar(fc_consumo); ///0002-00001
                cliente_encontrado=true;
                break;
            }
            else ///esto es lo mismo que arriba, solo que la cuenta no resta el 10%
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
                if (cantregistros2==0)
                {
                    cantregistros2=1;
                }
                Factura fc_consumo(cantregistros2, _clientebuscado, fecha_generar, _menubuscado, _menubuscado.getvalorplato(), tipo_consumo);
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
        CuentaCorriente actualizar_cuenta(cantregistros, _clientebuscado, saldoauxiliar, tiene_deuda);
        arch2.Guardar(actualizar_cuenta);
        int cantregistros2=arch3.CantidadRegistros();
        if (cantregistros2==0)
        {
            cantregistros2=1;
        }
        Factura fc_consumo(cantregistros2, _clientebuscado, fecha_generar, _menubuscado, _menubuscado.getvalorplato(), tipo_consumo);
        arch3.Guardar(fc_consumo);
    }
}

bool Menucomensal::tipodeconsumo()
{
    bool loop=false;
    do
    {
        system("cls");
        line('-');
        std::cout << "Desea abonar ahora o generar deuda en cuenta corriente?" << std::endl;
        line('-');
        std::cout << "Pulse 1 para abonar ahora o 2 para cargar deuda en cuenta corriente" << std::endl;
        cin >> _opcion;
        switch(_opcion)
        {
        case 1:
            loop=true;
            return true;
            break;
        case 2:
            loop=true;
            return false;
            break;
        default:
            std::cout << "Opci¢n incorrecta, intente nuevamente" << std::endl;
            break;
        }
    }
    while(loop==false);
}

void Menucomensal::mostrar(const char tipo, int num)
{
    _menubuscado=buscarplatos(tipo);
    std::cout << "Opci¢n # " << num << std::endl;
    std::cout << _menubuscado.toString() << std::endl;
}


