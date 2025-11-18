#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

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
