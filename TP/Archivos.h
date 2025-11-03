#pragma once
#include <string>
#include "Establecimientos.h"
#include "Menues.h"

class Archivos
{
public:
    Archivos(std::string nombreArchivo);
    ///ARCHIVO ESTABLECIMIENTOS
    bool Guardar(Establecimientos registro);
    bool Guardar(Establecimientos registro, int posicion);
    int Buscar(int idestablecimiento);
    Establecimientos Leer(int posicion);
    int CantidadRegistros();
    void Leer(int cantidadRegistros, Establecimientos *vector);
    /*///ARCHIVO MENUES
    bool Guardar(Menues registro);
    bool Guardar(Menues registro, int posicion);
    int Buscar(int idmenu);
    Menues Leer(int posicion);
    int CantidadRegistros();
    void Leer(int cantidadRegistros, Menues *vector);*/

private:
    std::string _nombreArchivo;
};


