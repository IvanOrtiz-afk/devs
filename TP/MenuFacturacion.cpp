/**#include <iostream>
#include "MenuFacturacion.h"
#include "Facturas.h"
#include "Fecha.h"
#include "CC.h"
#include "Menues.h"
#include "Comensales.h"
using namespace std;

MenuFacturacion::MenuFacturacion()
    : _archivoFacturas("facturas.dat"),
    _archivoCC("cuentacorriente.dat")
{

}

void MenuFacturacion::registrarVenta (Comensal comensal, Menues menues)
{
    float importe = menues.getvalorplato();
    Fecha hoy;
    int numeroFactura = 1; /// getNuevoID(); /// implementar nuevo ID
    char medioDePago[20];

    Factura nuevaFactura (numeroFactura, comensal, hoy, menues, importe, "VER");

    char opcion;
    cout << "Sumar importe a la cuenta corriente? S/N" << endl;
    cin >> opcion;

    if (opcion == 'S' or opcion == 's')
    {

        cout << "Registrando en la Cuenta Corriente.." << endl;
        nuevaFactura.setMedioDePago ("Cuenta Corriente");


        int numeroCuenta = 1; // getNuevoID(); //
        float saldoAnterior = 1; ///getSaldoAnterior(comensal.getIDcomensal());
        ///VER!! FALTA IMPLEMENTAR EL BUSCAR SI EL CLIETNE YA TIENE UNA CUENTA CORRIENTE ACTIVA EN VEZ DE CREAR UNA NUEVA

        CuentaCorriente nuevoMovimiento(numeroCuenta, comensal, hoy, menues, importe, "noaplica" , saldoAnterior, true);
        _archivoCC.Guardar(nuevoMovimiento);

        cout << "Nuevo importe en CC n# " << numeroCuenta << " es de: " << nuevoMovimiento.getSaldoActual() << endl;
    }
    else
    {
        char medioDePago[30];
        cout << "Ingrese medio de pago" << endl;
        cin >> medioDePago;

    }

    nuevaFactura.setMedioDePago(medioDePago);

    _archivoFacturas.Guardar(nuevaFactura);
    cout << "Factura n # " << numeroFactura << " creada exitosamente." << endl;
}


*/
