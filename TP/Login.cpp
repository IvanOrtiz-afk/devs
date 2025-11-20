#include <iostream>
#include <string>
#include <cstring>
#include "Login.h"
#include "usuario.h"
#include "Archivos.h"
#include "MenuSistema.h"



login::login()
{

}

void login::crearNuevoUsuario()
{
    Archivos <usuario> archUsuario ("Usuario.dat");

    char nombreUsuario[20], password[20];
    int rol;

    std::cout << "---NUEVO USUARIO---"  << std::endl;
    std::cout << "----------------------" << std::endl;
    std::cout << "Ingrese nombre de usuario:" << std::endl;
    std::cin >> nombreUsuario;
    std::cout << "Ingrese contraseña: " << std::endl;
    std::cin >> password;
    std::cout << "El usuario es 1-Administrador, 2-Encargado o 0-Comensal?" << std::endl;
    std::cin >> rol;

    usuario nuevoUsuario(nombreUsuario, password, rol);
    if (archUsuario.Guardar(nuevoUsuario) == true)
    {
        std::cout << "Usuario guardado exitosamente" << std::endl;
    }
    else
    {
        std::cout << "Algo salio mal, vuelva a intentar" << std::endl;
    }



}

void login::iniciarSesion()
{

    Archivos <usuario> archUsuario ("Usuario.dat");
    int cantidad = archUsuario.CantidadRegistros();

    std::string nombreUsuario;
    std::string password;
    bool encontrado = false;

    do
    {
        std::cout << "===== INICIAR SESION =====" << std::endl;
        std::cout << "Usuario: "<< std::endl;
        std::cin >> nombreUsuario;
        std::cout << "Password: "<< std::endl;
        std::cin >> password;

        for (int i=0; i<cantidad; i++)
        {
            usuario usuario_buscado=archUsuario.Leer(i);

            if (nombreUsuario==usuario_buscado.getNombreUsuario()&&password==usuario_buscado.getPassword())
            {
                encontrado = true;
                int rol = usuario_buscado.getRol();
                if (rol == 1)
                {   
                    system("cls");
                    std::cout << "Sesion iniciada como Administrador" << std::endl;
                    system("pause");
                }
                else if (rol == 2)
                {
                    system("cls");
                    std::cout << "Sesion iniciada como Encargado" << std::endl;
                    system("pause");
                }
                else
                {
                    system("cls");
                    std::cout << "Sesion iniciada como Comensal" << std::endl;
                    system("pause");
                }

                MenuSistema menu_sistema(rol);
                menu_sistema.run();

                return;
            }
        }
        if (encontrado == false)
        {
            std::cout << "Credenciales incorrectas. Intente nuevamente" << std::endl;
            system("pause");
            system("cls");
        }




    }
    while(encontrado == false);
}

