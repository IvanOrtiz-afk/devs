#include <iostream>
#include <string>
#include <cstring>
#include "MenuPadreABML.h"
#include "MenuSistema.h"
#include "Menuadmin.h"
#include "usuario.h"
#include "Login.h"
using namespace std;


/// rol 1 = ADMIN
/// rol 2 = ENCARGADO
/// rol 0 = COMENSALES

MenuSistema::MenuSistema()
    :MenuPadreABML()
{
}

MenuSistema::MenuSistema(int rol)
    :MenuPadreABML()
{
    _rolActual=rol;
    _cantidadOpciones=8;
}

void MenuSistema::run()
{
    int opcion;
    do
    {
        system("cls");
        mostrarOpciones();
        std::cout << "Ingrese su opcion: " << std::endl;
        std::cin >> opcion;
        system("pause");

        switch(opcion)
        {
        case 1:
            system("cls");
            gestionarPlatos();
            break;
        case 2:
            system("cls");
            gestionarFacturas();
            break;
        case 3:
            system("cls");
            gestionarCC();
            break;
        case 4:
            system("cls");
            gestionarConsumos();
            break;
        case 5:
            system("cls");
            gestionarComensales();
            break;
        case 6:
            system("cls");
            gestionarEstablecimientos();
            break;
        case 7:
            system("cls");
            gestionarUsuarios();
            break;
        case 0:
            cout << "Saliendo del sistema... " << endl;
            break;
        }
        system("pause");
    }
    while(opcion != 0);
}

void MenuSistema::mostrarOpciones()
{
    cout << "--- MENU PRINCIPAL ---" << endl;
    cout << "-------------------------" << endl;
    cout << "1- PLATOS "<<endl;
    cout << "2- FACTURACION" <<endl;
    cout << "3- ESTADO CUENTA CORRIENTE "<<endl;
    cout << "4- CONSUMOS" << endl;

    if (_rolActual == 1 or _rolActual == 2)  // admin y establecimientos
    {
        cout << "5- GESTIONAR COMENSALES" << endl;
    }
    if (_rolActual == 1)  // admin
    {
        cout << "6- GESTIONAR ESTABLECIMIENTOS" << endl;
        cout << "7- GESTIONAR USUARIOS" << endl;

    }

    cout << "0- Salir" << endl;

}



void MenuSistema::gestionarPlatos()
{
    int opcion;
    do
    {
        cout << "--- GESTIONAR PLATOS ---" << endl;
        cout << "---------------------------" << endl;
        cout << "1- LISTADOS DE MENUES" << endl;
        cout << "2- VALORAR UN PLATO "<<endl;
        cout << "3- LISTAR VALORACIONES" << endl; /// chequear punto del parcial

        if (_rolActual == 1) // admin
        {
            cout << "4- CARGAR UN NUEVO PLATO "<<endl; /// admin
            cout << "5- ELIMINAR UN PLATO" <<endl;  /// admin
        };

        cout << "0- Volver al menu principal" << endl;
        cin >> opcion;

        switch(opcion)
        {
        case 1: ///listarmenu
            system("pause");
            system("cls");
            _ejecutarmenu.menuplatos();
            system("pause");
            system("cls");
            break;
        case 2: ///valorar
            system("pause");
            system("cls");
            _ejecutarmenu.cargarvaloracion();
            system("pause");
            system("cls");
            break;
        case 3: /// ver favoritos
            system("pause");
            system("cls");
            _ejecutarmenu.valoraciones();
            system("pause");
            system("cls");
            break;
        case 4:
            if (_rolActual == 1)
            {
                /// cargar();
                system("pause");
                system("cls");
                _ejecutarmenu.mostrarmenucargar();
                system("pause");
                system("cls");
            }
            else
            {
                cout << "Acceso denegado." << endl;
            }
            break;
        case 5:
            if (_rolActual == 1)
            {
                /// elminar();
                system("pause");
                system("cls");
                _ejecutarmenu.eliminarplatomenu();
                system("pause");
                system("cls"); ///HECHO
            }
            else
            {
                cout << "Acceso denegado." << endl;
            }
            break;
        case 0:
            cout << "Volviendo al menu principal... " << endl;
            break;
        }
    }
    while(opcion != 0);

}

void MenuSistema::gestionarFacturas()
{


    int opcion;
    do
    {
        cout << "--- FACTURACION ---" << endl;
        cout << "----------------------" << endl;
        cout << "1- LISTAR FACTURAS" << endl;


        if (_rolActual == 1) // admin
        {
            cout << "2- NUEVA FACTURA "<<endl;
        };

        cout << "0- Volver al menu principal" << endl;
        cin >> opcion;

        switch(opcion)
        {
        case 1: ///listar
            system("pause");
            system("cls");
            _ejecutarmenu.listarfacturas();
            system("pause");
            system("cls");
            break;
        case 2:
            if (_rolActual == 1)
            {
                /// cargar();
                system("pause");
                system("cls");
                _ejecutarmenu.cargarfactura();
                system("pause");
                system("cls");
            }
            else
            {
                cout << "Acceso denegado." << endl;
            }
            break;


        case 0:
            cout << "Volviendo al menu principal... " << endl;
            break;
        }
    }
    while(opcion != 0);

}


void MenuSistema::gestionarCC() /// MIRAR! quizas haya que agregarle parametros para que el ADMIN pueda ver todos los pagos
{


    int opcion;
    do
    {
        cout << "--- CUENTA CORRIENTE ---" << endl;
        cout << "---------------------------" << endl;
        cout << "1- VER ESTADO DE CUENTA CORRIENTE (DEUDA)" << endl;
        cout << "2- REALIZAR UN PAGO "<<endl;
        cout << "3- LISTAR PAGOS REALIZADOS" << endl;
        cout << "0- Volver al menu principal" << endl;
        cin >> opcion;

        switch(opcion)
        {
        case 1: ///deuda
            system("pause");
            system("cls");
            _ejecutarmenu.verCC();
            system("pause");
            system("cls"); //de momento solo hice que se pueda ver la CC (sea deuda o no)
            break;
        case 2:
            system("pause");
            system("cls");
            _ejecutarmenu.cargarpago();
            system("pause");
            system("cls");

            break;
        case 3:
            system("pause");
            system("cls");
            _ejecutarmenu.listarpago();
            system("pause");
            system("cls");
            break;
        case 0:
            cout << "Volviendo al menu principal... " << endl;
            break;
        }
    }
    while(opcion != 0);
}

void MenuSistema::gestionarConsumos()
{

    int opcion;

    do
    {
        cout << "--- CONSUMOS ---" << endl;
        cout << "-------------------" << endl;
        cout << "1- LISTAR CONSUMOS" << endl;
        cout << "0- Volver al menu principal" << endl;
        cin >> opcion;

        switch(opcion)
        {
        case 1:
            system("pause");
            system("cls");
            _ejecutarmenu.listarconsumos(); /// REPARADO!!!
            system("pause");
            system("cls");
            break;
        case 0:
            cout << "Volviendo al menu principal... " << endl;
            break;
        }
    }
    while(opcion != 0);


}



void MenuSistema::gestionarComensales()
{
    int opcion;

    do
    {
        cout << "--- GESTIONAR COMENSALES ---" << endl;
        cout << "------------------------------" << endl;
        cout << "1- LISTAR COMENSALES" << endl;


        if (_rolActual == 1)
        {
            cout << "2- CARGAR UN NUEVO COMENSAL "<<endl; /// admin
            cout << "3- ELIMINAR UN COMENSAL" <<endl;  /// admin
        };

        cout << "0- Volver al menu principal" << endl;
        cin >> opcion;
        switch(opcion)
        {
        case 1:
            if (_rolActual == 1 or _rolActual == 2)
            {
                system("pause");
                system("cls");
                _ejecutarmenu.listarcomensales();
                system("pause");
                system("cls");
            }
            else
            {
                cout << "Acceso denegado." << endl;
            }
            break;

        case 2:
            if (_rolActual == 1)
            {
                system("pause");
                system("cls");
                _ejecutarmenu.cargarcomensales();
                system("pause");
                system("cls");
            }
            else
            {
                cout << "Acceso denegado." << endl;
            }
            break;
        case 3:
            if (_rolActual == 1)
            {
                system("pause");
                system("cls");
                _ejecutarmenu.eliminarcomensal();
                system("pause");
                system("cls");
            }
            else
            {
                cout << "Acceso denegado." << endl;
            }
            break;
        case 0:
            cout << "Volviendo al menu principal... " << endl;
            break;
        }
    }
    while (opcion != 0);
}

void MenuSistema::gestionarEstablecimientos()
{
    int opcion;

    do
    {
        cout << "--- GESTIONAR ESTABLECIMIENTOS ---" << endl;
        cout << "-------------------------------------" << endl;

        if (_rolActual == 1) // admin
        {
            cout << "1- CARGAR UN NUEVO ESTABLICIMIENTO "<<endl; /// admin
            cout << "2- ELIMINAR UN ESTABLECIMIENTO" <<endl;  /// admin
            cout << "3- LISTAR ESTABLECIMIENTOS" << endl;/// admin
            cout << "0- Volver al menu principal" << endl;
        }
        else
        {
            cout << "Acceso denegado.." << endl;
        }

        cin >> opcion;
        switch(opcion)
        {
        case 1:
            if (_rolActual == 1)
            {
                system("pause");
                system("cls");
                _ejecutarmenu.cargarestablecimiento();
                system("pause");
                system("cls");
            }
            else
            {
                cout << "Acceso denegado." << endl;
            }
            break;

        case 2:
            if (_rolActual == 1)
            {
                system("pause");
                system("cls");
                _ejecutarmenu.eliminar_esta();
                system("pause");
                system("cls");
            }
            else
            {
                cout << "Acceso denegado." << endl;
            }

            break;
        case 3:
            if (_rolActual == 1)
            {
                system("pause");
                system("cls");
                _ejecutarmenu.listarestablecimientos();
                system("pause");
                system("cls");
            }
            else
            {
                cout << "Acceso denegado." << endl;
            }
            break;

        case 0:
            cout << "Volviendo al menu principal... " << endl;
            break;
        }
    }
    while(opcion != 0);
}

void MenuSistema::gestionarUsuarios()
{
    int opcion;

    do
    {
        cout << "--- GESTIONAR USUARIOS ---" << endl;
        cout << "-------------------------------------" << endl;

        if (_rolActual == 1)
        {
            cout << "1- CREAR UN NUEVO USUARIO "<<endl; /// admin
            cout << "2- ELIMINAR USUARIO" << endl;
            cout << "0- Volver al menu principal" << endl;
        }
        else
        {
            cout << "Acceso denegado.." << endl;
        }

        cin >> opcion;
        switch(opcion)
        {
        case 1:
            if (_rolActual == 1)
            {
                system("cls");
                login nuevo_usuario;
                nuevo_usuario.crearNuevoUsuario();
                system("cls");

            }
        case 2:
            if (_rolActual == 1)
            {
                system("pause");
                system("cls");
                _ejecutarmenu.eliminarusuario();
                system("pause");
                system("cls");

            }
            else
            {
                cout << "Acceso denegado." << endl;
            }
            break;

        case 0:
            cout << "Volviendo al menu principal... " << endl;
            break;
        }
    }
    while (opcion != 0);
}

