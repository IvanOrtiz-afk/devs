#pragma once

class MenuPadreABML
{
public:
    MenuPadreABML();
    void salida(int);
    void line(char simbolo='-', int cant=30);
    int menuinicial();
    ~MenuPadreABML();
protected:
    int _opcion;
};
