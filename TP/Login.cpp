#include <iostream>
#include <string>
#include <cstring>
#include "Login.h"
#include "usuario.h"
#include "Archivos.h"
#include "MenuSistema.h"
#include "Utilidades.h"



login::login()
{

}

void login::crearNuevoUsuario()
{
    Archivos <usuario> archUsuario ("Usuario.dat");

    char nombreUsuario[20], password[20];
    int rol;

    system("cls");
    std::cout << "--- NUEVO USUARIO ---"  << std::endl;
    std::cout <<"---------------------------" << std::endl;
    std::cout << "Ingrese nombre de usuario, ";
    std::string entrada = entrada_valida("o pulse cero para volver", TEXTO_NO_VACIO);
    if (entrada == "0") return;
    strncpy(nombreUsuario, entrada.c_str(), 19);
    nombreUsuario[19] = '\0';

    int cantidad = archUsuario.CantidadRegistros();
    for (int i = 0; i < cantidad; i++)
    {
        usuario aux = archUsuario.Leer(i);
        if (aux.getNombreUsuario() == std::string(nombreUsuario))
        {
            std::cout << std::endl;
            std::cout << "[ERROR] El nombre de usuario '" << nombreUsuario << "' ya existe." << std::endl;
            std::cout << "Por favor, intente con otro nombre." << std::endl;
            system("pause");
            return;
        }
    }

    std::cout << "Ingrese contrasenia: " << std::endl;
    std::cin >> password;
    bool rolValido = false;
    do
    {
        std::cout << "El usuario es 1-Administrador, 2-Encargado o 3-Comensal?";
        entrada = entrada_valida(" pulse cero para volver", NUMERO_ENTERO);
        if (entrada == "0") return;
        rol= std::stoi(entrada);
        if (rol >= 1 && rol <= 3)
        {
            rolValido = true;
        }
        else
        {
            std::cout << "[ERROR] Opcion incorrecta. Debe ser 1, 2 o 3." << std::endl;
        }
    }
    while (!rolValido);

    usuario nuevoUsuario(nombreUsuario, password, rol);
    if (archUsuario.Guardar(nuevoUsuario) == true)
    {
        std::cout << "Usuario guardado exitosamente" << std::endl;
        system("pause");
        system("cls");
    }
    else
    {
        std::cout << "Algo salio mal, vuelva a intentar" << std::endl;
        system("pause");
        system("cls");
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
                else if (rol == 3)
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

