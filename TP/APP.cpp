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
    login iniciar_sesion;
   /// MenuSistema menu_sistema;
    int opcion_general;
    do
    {
        system("cls");
        opcion_general=menu_entrada.menuinicial();
        system("cls");
        if(opcion_general==1)
        {
            menu_comer.ejecutarmenu();
        }
        else if(opcion_general==2)
        {
            iniciar_sesion.iniciarSesion();
           /// menu_sistema.mostrarOpciones();
        }
        else if(opcion_general==0)
        {
            _ejecutar_programa=false;
        }
    }
    while(_ejecutar_programa==true);
}


