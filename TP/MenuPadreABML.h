#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class MenuPadreABML
{
public:
    MenuPadreABML();
    void run();
    void line(char simbolo='-', int cant=30);
    void menuinicial();
    ~MenuPadreABML();
protected:
    int _opcion;
};
