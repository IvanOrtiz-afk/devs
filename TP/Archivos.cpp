/**#include <iostream>
#include "Archivos.h"

template <typename Tipos>
Archivos::Archivos(std::string nombreArchivo)
{
    _nombreArchivo = nombreArchivo;
}

bool Archivos::Guardar(Tipos registro)
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "ab");
    if(pArchivo == NULL)
    {
        return false;
    }
    bool ok = fwrite(&registro, sizeof(Tipos), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

bool Archivos::Guardar(Tipos registro, int posicion)
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb+");
    if(pArchivo == NULL)
    {
        return false;
    }
    fseek(pArchivo, sizeof(Tipos) * posicion, SEEK_SET);
    bool ok = fwrite(&registro, sizeof(Tipos), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

int Archivos::Buscar(int idbuscado)
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL)
    {
        return -1;
    }
    Tipos registro;
    int i = 0, j=1;

    while(fread(&registro, sizeof(Tipos), 1, pArchivo))
    {
        if(j == idbuscado)  ///ARREGLAR ACA
        {
            fclose(pArchivo);
            return i;
        }
        j++;
        i++;
    }
    fclose(pArchivo);
    return -1;
}

Tipos Archivos::Leer(int posicion)
{
    std::string mensaje="No se pudo leer el archivo" << endl;
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL)
    {
        return Tipos(); ///ARREGLAR ACA
    }
    Tipos registro;
    fseek(pArchivo, sizeof(Tipos) * posicion, SEEK_SET);
    fread(&registro, sizeof(Tipos), 1, pArchivo);
    fclose(pArchivo);
    return registro;
}

int Archivos::CantidadRegistros()
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL)
    {
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(Tipos);
    fclose(pArchivo);
    return cantidadRegistros;
}

void Archivos::Leer(int cantidadRegistros, Tipos *vector)
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL)
    {
        return;
    }
    for(int i = 0; i < cantidadRegistros; i++)
    {
        fread(&vector[i], sizeof(Tipos), 1, pArchivo);
    }
    fclose(pArchivo);
}*/



