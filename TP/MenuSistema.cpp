#include <iostream>
#include <string>
#include <cstring>
#include "Utilidades.h"
#include "MenuPadreABML.h"
#include "MenuSistema.h"
#include "Menuadmin.h"
#include "usuario.h"
#include "Login.h"
using namespace std;




MenuSistema::MenuSistema()
    :MenuPadreABML()
{
}

MenuSistema::MenuSistema(int rol)
    :MenuPadreABML()
{
    _rolActual=rol;
    _cantidadOpciones=9;
}

void MenuSistema::run()
{
    int opcion;
    do
    {
        system("cls");
        mostrarOpciones();
        std::string entrada = entrada_valida("Seleccione una opcion: ", NUMERO_ENTERO);
        opcion = std::stoi(entrada);
       

        switch(opcion)
        {
        case 1:
            
            gestionarPlatos();
            break;
        case 2:
            
            gestionarFacturas();
            break;
        case 3:
           
            gestionarCC();
            break;
        case 4:
            
            gestionarConsumos();
            break;
        case 5:
           
            gestionarComensales();
            break;
        case 6:
            
            gestionarEstablecimientos();
            break;
        case 7:
            
            gestionarUsuarios();
            break;
        case 8:
            
            menuConfiguracion();
        case 0:
            cout << "Saliendo del sistema... " << endl;
            system("pause");
            break;
        default:

            cout << "[ERROR] Opcion incorrecta, intente de nuevo." << endl;
            system("pause");
            break;
        }
        
    }
    while(opcion != 0);
}

void MenuSistema::mostrarOpciones()
{
    cout << "--- MENU PRINCIPAL ---" << endl;
    line('-');
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
        cout << "8- CONFIGURACION" << endl;

    }
    line('-');
    cout << "0- Salir" << endl;
    line('-');

}

void MenuSistema::gestionarPlatos()
{
    int opcion;
    do
    {
        system("cls");
        cout << "--- GESTIONAR PLATOS ---" << endl;
        line('-');
        cout << "1- LISTADOS DE MENUES" << endl;
        cout << "2- VALORAR UN PLATO "<<endl;
        cout << "3- LISTAR VALORACIONES" << endl; /// chequear punto del parcial
        cout << "4- PLATOS MEJOR VALORADOS" << endl;

        if (_rolActual == 1) // admin
        {
            cout << "5- CARGAR UN NUEVO PLATO "<<endl; /// admin
            cout << "6- ELIMINAR UN PLATO" <<endl;  /// admin
            cout << "7- MODIFICAR UN PLATO" <<endl;

        };
        line('-');
        cout << "0- Volver al menu principal" << endl;
        line('-');
        std::string entrada = entrada_valida("Seleccione una opcion: ", NUMERO_ENTERO);
        opcion = std::stoi(entrada);

        switch(opcion)
        {
        case 1: ///listarmenu
        
            
            _ejecutarmenu.menuplatos();
            
            break;
        case 2: ///valorar
            
            _ejecutarmenu.cargarvaloracion();
            
            break;
        case 3: /// ver favoritos
            
            _ejecutarmenu.valoraciones();
            break;
        case 4:
           
            _ejecutarmenu.platosmejor_valor();
            
            break;
        case 5:
            if (_rolActual == 1)
            {

                
                _ejecutarmenu.mostrarmenucargar();
                
            }
            else
            {
                cout << "Acceso denegado." << endl;
                system("pause");
            }
            break;
        case 6:
            if (_rolActual == 1)
            {

                
                _ejecutarmenu.eliminarplatomenu();
                
            }
            else
            {
                cout << "Acceso denegado." << endl;
                system("pause");
            }
            break;
        case 7:
            if (_rolActual == 1)
            {

                
                _ejecutarmenu.modificarplatos();
               
            }
            else
            {
                cout << "Acceso denegado." << endl;
                system("pause");
            }
            break;
        case 0:
            cout << "Volviendo al menu principal... " << endl;
            system("pause");
            break;

        default:
            cout << "[ERROR] Opcion incorrecta, intente de nuevo." << endl;
            system("pause");
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
        system("cls");
        cout << "--- FACTURACION ---" << endl;
        line('-');
        cout << "1- LISTAR FACTURAS" << endl;


        if (_rolActual == 1) // admin
        {
            cout << "2- NUEVA FACTURA "<<endl;
        };
        line('-');
        cout << "0- Volver al menu principal" << endl;
        line('-');
        std::string entrada = entrada_valida("Seleccione una opcion: ", NUMERO_ENTERO);
        opcion = std::stoi(entrada);

        switch(opcion)
        {
        case 1: 
           
            _ejecutarmenu.listarfacturas();
            
            break;
        case 2:
            if (_rolActual == 1)
            {
                
                _ejecutarmenu.cargarfactura();
               
            }
            else
            {
                cout << "Acceso denegado." << endl;
                system("pause");
            }
            break;


        case 0:
            cout << "Volviendo al menu principal... " << endl;
            system("pause");
            break;

        default:

            cout << "[ERROR] Opcion incorrecta, intente de nuevo." << endl;
            system("pause");
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
        system("cls");
        cout << "--- CUENTA CORRIENTE ---" << endl;
        line('-');
        cout << "1- VER ESTADO DE CUENTA CORRIENTE (DEUDA)" << endl;
        cout << "2- REALIZAR UN PAGO "<<endl;
        cout << "3- LISTAR PAGOS REALIZADOS" << endl;
        line('-');
        cout << "0- Volver al menu principal" << endl;
        line('-');
        std::string entrada = entrada_valida("Seleccione una opcion: ", NUMERO_ENTERO);
        opcion = std::stoi(entrada);

        switch(opcion)
        {
        case 1: ///deuda
            
            _ejecutarmenu.verCC();
            
            break;
        case 2:
           
            _ejecutarmenu.cargarpago();
            

            break;
        case 3:
           
            _ejecutarmenu.listarpago();
            
            break;
        case 0:
            cout << "Volviendo al menu principal... " << endl;
            system("pause");
            break;
        default:

            cout << "[ERROR] Opcion incorrecta, intente de nuevo." << endl;
            system("pause");
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
        system("cls");
        cout << "--- CONSUMOS ---" << endl;
        line('-');
        cout << "1- LISTAR CONSUMOS" << endl;
        cout << "2- VER CONSUMOS POR FECHA" << endl;
        cout << "3- PLATOS MAS VENDIDOS" << endl;
        line('-');
        cout << "0- Volver al menu principal" << endl;
        line('-');
        std::string entrada = entrada_valida("Seleccione una opcion: ", NUMERO_ENTERO);
        opcion = std::stoi(entrada);

        switch(opcion)
        {
        case 1:
            
            _ejecutarmenu.listarconsumos(); /// REPARADO!!!
           
            break;
        case 2:
            
            _ejecutarmenu.cant_platosXfecha();
            
            break;
        case 3:
            
            _ejecutarmenu.platosmas_vendidos();
            
            break;
        case 0:
            cout << "Volviendo al menu principal... " << endl;
            system("pause");
            break;
        default:

            cout << "[ERROR] Opcion incorrecta, intente de nuevo." << endl;
            system("pause");
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
        system("cls");
        cout << "--- GESTIONAR COMENSALES ---" << endl;
        line('-');
        cout << "1- LISTAR COMENSALES" << endl;


        if (_rolActual == 1)
        {
            cout << "2- CARGAR UN NUEVO COMENSAL "<<endl; /// admin
            cout << "3- ELIMINAR UN COMENSAL" <<endl;  /// admin
            cout << "4- MODIFICAR UN COMENSAL" <<endl;  /// admin
        };
        line('-');
        cout << "0- Volver al menu principal" << endl;
        line('-');
        std::string entrada = entrada_valida("Seleccione una opcion: ", NUMERO_ENTERO);
        opcion = std::stoi(entrada);
        switch(opcion)
        {
        case 1:
            if (_rolActual == 1 or _rolActual == 2)
            {
                
                _ejecutarmenu.listarcomensales();
                
            }
            else
            {
                cout << "Acceso denegado." << endl;
                system("pause");
            }
            break;

        case 2:
            if (_rolActual == 1)
            {
               
                _ejecutarmenu.cargarcomensales();
            }
            else
            {
                cout << "Acceso denegado." << endl;
                system("pause");
            }
            break;
        case 3:
            if (_rolActual == 1)
            {
                
                _ejecutarmenu.eliminarcomensal();
                
            }
            else
            {
                cout << "Acceso denegado." << endl;
                system("pause");
            }
            break;
        case 4:
            if (_rolActual == 1)
            {
                
                _ejecutarmenu.modificarcomensales();
                
            }
            else
            {
                cout << "Acceso denegado." << endl;
                system("pause");
            }
            break;
        case 0:
            cout << "Volviendo al menu principal... " << endl;
            system("pause");
            break;

        default:

            cout << "[ERROR] Opcion incorrecta, intente de nuevo." << endl;
            system("pause");

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
        system("cls");
        cout << "--- GESTIONAR ESTABLECIMIENTOS ---" << endl;
        line('-');

        if (_rolActual == 1) // admin
        {
            cout << "1- CARGAR UN NUEVO ESTABLICIMIENTO "<<endl; /// admin
            cout << "2- ELIMINAR UN ESTABLECIMIENTO" <<endl;  /// admin
            cout << "3- LISTAR ESTABLECIMIENTOS" << endl;/// admin
            cout << "4- MODIFICAR ESTABLECIMIENTOS"<< endl;
            line('-');
            cout << "0- Volver al menu principal" << endl;
            line('-');
        }
        else
        {
            cout << "Acceso denegado.." << endl;
            system("pause");
        }

        std::string entrada = entrada_valida("Seleccione una opcion: ", NUMERO_ENTERO);
        opcion = std::stoi(entrada);
        switch(opcion)
        {
        case 1:
            if (_rolActual == 1)
            {
                
                _ejecutarmenu.cargarestablecimiento();
               
            }
            else
            {
                cout << "Acceso denegado." << endl;
                system("pause");
            }
            break;

        case 2:
            if (_rolActual == 1)
            {
               
                _ejecutarmenu.eliminar_esta();
               
            }
            else
            {
                cout << "Acceso denegado." << endl;
                system("pause");
            }

            break;
        case 3:
            if (_rolActual == 1)
            {
                
                _ejecutarmenu.listarestablecimientos();
                
            }
            else
            {
                cout << "Acceso denegado." << endl;
                system("pause");
            }
            break;
        case 4:
            if (_rolActual == 1)
            {
                
                _ejecutarmenu.modificarestablecimientos();
               
            }
            else
            {
                cout << "Acceso denegado." << endl;
                system("pause");
            }
            break;
        case 0:
            cout << "Volviendo al menu principal... " << endl;
            system("pause");
            break;
        default:

            cout << "[ERROR] Opcion incorrecta, intente de nuevo." << endl;
            system("pause");
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
        system("cls");
        cout << "--- GESTIONAR USUARIOS ---" << endl;
        line('-');

        if (_rolActual == 1)
        {
            cout << "1- CREAR UN NUEVO USUARIO "<<endl; /// admin
            cout << "2- ELIMINAR USUARIO" << endl;
            cout << "3- MODIFICAR USUARIO" << endl;
            cout << "4- LISTAR USUARIOS" << endl;
            line('-');
            cout << "0- Volver al menu principal" << endl;
            line('-');
        }
        else
        {
            cout << "Acceso denegado.." << endl;
            system("pause");
        }

        std::string entrada = entrada_valida("Seleccione una opcion: ", NUMERO_ENTERO);
        opcion = std::stoi(entrada);
        switch(opcion)
        {
        case 1:
            if (_rolActual == 1)
            {
                
                login nuevo_usuario;
                nuevo_usuario.crearNuevoUsuario();
                

            }
        case 2:
            if (_rolActual == 1)
            {
                
                _ejecutarmenu.eliminarusuario();
               
            }
            else
            {
                cout << "Acceso denegado." << endl;
                system("pause");
            }
            break;
        case 3:

            if (_rolActual == 1)
            {
                
                _ejecutarmenu.modificarusuarios();
                
            }
            else
            {
                cout << "Acceso denegado." << endl;
                system("pause");
            }
            break;
        case 4:
            if (_rolActual == 1)
            {
               
                _ejecutarmenu.listarUsuarios();
               

            }
            else
            {
                cout << "Acceso denegado." << endl;
                system("pause");
            }
            break;

        case 0:
            cout << "Volviendo al menu principal... " << endl;
            system("pause");
            break;

        default:

            cout << "[ERROR] Opcion incorrecta, intente de nuevo." << endl;
            system("pause");
            break;
        }
        
    }
    while (opcion != 0);
}

void MenuSistema::menuConfiguracion()
{
    int opcion;
    do
    {
        system("cls");
        std::cout << "--- CONFIGURACION ---" << std::endl;
        line('-');
        std::cout << "1- Realizar Copia de Seguridad" << std::endl;
        std::cout << "2- Restaurar Copia de Seguridad" << std::endl;
        std::cout << "3- Exportar Datos a Excel (.csv)" << std::endl;
        line('-');
        std::cout << "0- Salir" << std::endl;
        line('-');
        std::string entrada = entrada_valida("Seleccione una opcion: ", NUMERO_ENTERO);
        opcion = std::stoi(entrada);
        /// std::string entrada = entrada_valida("Seleccione una opcion: ", NUMERO_ENTERO);
        /// opcion = std::stoi(entrada);

        switch(opcion)
        {
        case 1:

            _ejecutarmenu.realizarBackup();


            break;
        case 2:
            if (_rolActual == 1)
            {
                
                _ejecutarmenu.restaurarBackup();
               
            }
            else
            {
                cout << "Acceso denegado." << endl;
                system("pause");
            }
            break;
        case 3:
            if (_rolActual == 1)
            {
                
                _ejecutarmenu.exportarDatosCSV();
            }
            else
            {
                cout << "Acceso denegado." << endl;
                system("pause");
            }
            break;
        case 0:
            break;
        default:

            cout << "[ERROR] Opcion incorrecta, intente de nuevo." << endl;
            system("pause");

            break;

        }
       
    }
    while(opcion != 0);
}
