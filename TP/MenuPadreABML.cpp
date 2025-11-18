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

void MenuPadreABML::salida(int saliroatras)
{
    if (saliroatras==0)
    {
        std::cout << "0. Salir" << std::endl;
    }
    else if (saliroatras==1)
    {
        std::cout << "0. Volver atras" << std::endl;
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
    line('*', 40);
    std::cout << "BIENVENIDO A NUESTRO SISTEMA DE CONTROL DE ALMUERZOS" << std::endl;
    line('*', 40); ///QUIZAS DERIVEMOS DE ACA MISMO LA PREGUNTA DE SI DESEA COMER O HACER LOGIN AL SISTEMA
    system("pause");
    system("cls");
    do
    {
        line('-', 40);
        std::cout << "Seleccione la opcion deseada" << std::endl;
        line('-', 40);
        std::cout << "1. Comer en comedor" << std::endl;
        std::cout << "2. Ingresar al sistema" << std::endl;
        salida(0); ///si es 0 va a imprimir "salir" si es 1 va a imprimir "atras"
        cin >> opcion;
        if (opcion>=0&&opcion<=2)
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
}

