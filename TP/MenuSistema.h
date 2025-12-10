#pragma once
#include "MenuPadreABML.h"
#include "MenuSistema.h"
#include "Menuadmin.h"
#include "usuario.h"
#include "Login.h"

class MenuSistema : public MenuPadreABML
{
  public:
    MenuSistema(int rol);
    MenuSistema();
    void run();

    void mostrarOpciones();
    void gestionarPlatos();
    void gestionarEstablecimientos();
    void gestionarComensales();
    void gestionarFacturas();
    void gestionarCC();
    void gestionarConsumos();
    void gestionarUsuarios();
    void menuConfiguracion();


  private:
    int _cantidadOpciones;
    int _rolActual;
    Menuadmin _ejecutarmenu;
};
