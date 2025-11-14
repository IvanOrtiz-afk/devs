#pragma once
#include <iostream>

using namespace std;

class MenuPadreABML
{
public:

    void run();
    virtual ~MenuPadreABML();  // destructor virtual

protected:
    void mostrarOpciones();
    int seleccionOpcion();
    void ejecutarOpcion(int opcion);

    //ESTO ES DE VIRTUAL ES POLIMORFISMO ---> (virtuales puros) <---
    // (= 0) significa que el .cpp NO tiene código
    // Obliga a las clases hijas a implementarlos SI O SI.

    virtual void cargar() = 0;
    virtual void modificar() = 0;
    virtual void eliminar() = 0;
    virtual void mostrar() = 0;
    virtual string getTitulo() = 0;
};
