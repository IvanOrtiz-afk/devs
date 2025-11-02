#include <iostream>
#include <string>
#include "Archivo.h"
#include "Establecimientos.h"
#include "Menues.h"

Archivo::Archivo(std::string nombreArchivo, int IDregistro)
{
    _nombreArchivo = nombreArchivo;
    _IDregistro=IDregistro;
}
template <typename T>
bool Archivo::Guardar(const T &registro)
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "ab");
    if(pArchivo == NULL)
    {
        return false;
    }
    bool ok = fwrite(&registro, sizeof(T), 1, pArchivo);
    fclose(pArchivo);
    return ok;
};
template <typename T>
bool Archivo::Guardar(const T &registro, int posicion)
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "ab");
    if(pArchivo == NULL)
    {
        return false;
    }
    bool ok = fwrite(&registro, sizeof(T), posicion, pArchivo);
    fclose(pArchivo);
    return ok;
};
int Archivo::getIDregistro()
{
    return _IDregistro;
};
void Archivo::setIDregistro(int IDregistro)
{
    _IDregistro=IDregistro;
};
template <typename T>
int Archivo::Buscar(int IDregistro)
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL)
    {
        return -1;
    }
    int i=0;
    T regis;
    while(fread(&IDregistro, sizeof(T), 1, pArchivo))
    {
        if(regis.getIDregistro() == IDregistro)
        {
            fclose(pArchivo);
            return i;
        }
        i++;
    }
    fclose(pArchivo);
    return 0;
};
template <typename T>
T Archivo::Leer(int posicion)
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL)
    {
        return -1;
    }
    T regis;
    fseek(pArchivo, sizeof(T) * posicion, SEEK_SET);
    fread(&regis, sizeof(T), 1, pArchivo);
    fclose(pArchivo);
    return regis;
};
template <typename T>
int Archivo::CantidadRegistros()
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL)
    {
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(T);
    fclose(pArchivo);
    return cantidadRegistros;
};
template <typename T>
void Archivo::Leer(int cantidadRegistros, T *vector)
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL)
    {
        return;
    }
    for(int i = 0; i < cantidadRegistros; i++)
    {
        fread(&vector[i], sizeof(T), 1, pArchivo);
    }
    fclose(pArchivo);
};


