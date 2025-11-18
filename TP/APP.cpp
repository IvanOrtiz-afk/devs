#include <iostream>
#include <string>
#include "App.h"
#include "MenuSistema.h"
#include "Menucomensal.h"
#include "MenuPadreABML.h"


App::App()
{

}

void App::run()
{
    MenuPadreABML menu_entrada;
    Menucomensal menu_comer;

    do
    {
        system("cls");
        menu_entrada.menuinicial();
        system("cls");
        if(menu_entrada.menuinicial()==1)
        {
            menu_comer.ejecutarmenu();
        }
        else if(menu_entrada.menuinicial()==2)
        {
            ///ACA ARRANCA MENU SISTEMA CON EL LOGIN Y DEMAS COSAS
        }
        else if(menu_entrada.menuinicial()==0)
        {
            _ejecutar_programa=false;
        }
    }
    while(_ejecutar_programa=true);
}


