#pragma once
#include <string>

class Archivo
{
public:
    Archivo(std::string nombreArchivo, int IDregistro);
    template <typename T>
    bool Guardar(const T &registro);
    template <typename T>
    bool Guardar(const T &registro, int posicion);
    template <typename T>
    int Buscar(int IDregistro);
    template <typename T>
    T Leer(int posicion);
    template <typename T>
    int CantidadRegistros();
    template <typename T>
    void Leer(int cantidadRegistros, T *vector);
    int getIDregistro();
    void setIDregistro(int);

private:
    std::string _nombreArchivo;
    int _IDregistro;
};
