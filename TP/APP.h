#pragma once
#include "MenuSistema.h"


class App
{
  public:
    App();
    void run();

  protected:
    void mostrarOpciones();
    int seleccionOpcion();
    void ejecutarOpcion(int opcion);

    ///agregar aca los menu que va a mostrar adentro del menu principal una vez esten hechos
  private:
    int _cantidadOpciones;
///    MenuSistema _menuSistema;
};
