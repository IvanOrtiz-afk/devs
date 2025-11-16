#include <vector>
#include <string>
#include <cstring>
#include <cstdlib>
#include "MenuPadreABML.h"

MenuPadreABML::MenuPadreABML()
{

}

MenuPadreABML::~MenuPadreABML()
{

}

/**void MenuPadreABML::run()
{
    do
    {
        system("cls");
        _opcion = seleccionOpcion();
        system("cls");
        ejecutarOpcion(_opcion);
    }
    while(_opcion != 0);
}*/

void MenuPadreABML::line(char simbolo, int cant)
{
    for (int i=0; i<cant; i++)
    {
        std::cout << simbolo;
    }
    std::cout << "\n";
}

void MenuPadreABML::menuinicial()
{
    line('*', 40);
    std::cout << "BIENVENIDO A NUESTRO SISTEMA DE CONTROL DE ALMUERZOS" << endl;
    line('*', 40);
    system("cls");
}

