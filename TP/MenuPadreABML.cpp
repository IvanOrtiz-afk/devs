#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include "MenuPadreABML.h"
#include "Menuadmin.h"
#include "MenuSistema.h"
#include "Comensales.h" ///OJO COMO SE AGREGAN LAS LIBRERIAS, CUANDO MANEJAMOS HERENCIA LLEVAN UN ORDEN ESTAS
#include "Menues.h"
#include "Archivos.h"
#include "Consumos.h"
#include "CC.h"
#include "Fecha.h"
#include "Utilidades.h"

MenuPadreABML::MenuPadreABML()
{

}

MenuPadreABML::~MenuPadreABML()
{

}

void MenuPadreABML::salida(int saliroatras)
{
    if (saliroatras==0)
    {
        std::cout << "0- Salir" << std::endl;
        line('-');
    }
    else if (saliroatras==1)
    {
        std::cout << "0- Volver atras" << std::endl;
    }
}

void MenuPadreABML::line(char simbolo, int cant)
{
    for (int i=0; i<cant; i++)
    {
        std::cout << simbolo;
    }
    std::cout << "\n";
}

int MenuPadreABML::menuinicial()
{
    int opcion;
    system("cls");
    std::cout << std::endl;
    line('=', 60);
    std::cout << "   BIENVENIDO A NUESTRO SISTEMA DE CONTROL DE ALMUERZOS" << std::endl;
    line('=', 60); ///QUIZAS DERIVEMOS DE ACA MISMO LA PREGUNTA DE SI DESEA COMER O HACER LOGIN AL SISTEMA
    std::cout << std::endl;
    system("pause");
    do
    {
        system("cls");
        std::cout << "--- CONTROL DE ALMUERZOS --- " << std::endl;
        line('-');
        std::cout << "1- COMER EN COMEDOR" << std::endl;
        std::cout << "2- INGRESAR AL SISTEMA" << std::endl;
        salida(0); ///si es 0 va a imprimir "salir" si es 1 va a imprimir "atras"
        std::string entrada = entrada_valida("Seleccione una opcion: ", NUMERO_ENTERO);
        opcion = std::stoi(entrada);
        if ((opcion>0&&opcion<3)||opcion==0)
        {
            _opcion=opcion;
            return _opcion;
        }
        else
        {
            std::cout << "Opci¢n inv lida, intente nuevamente" << std::endl;
            system("pause");
            system("cls");
        }
    }
    while(opcion<0||opcion>2);
    return _opcion;
}

