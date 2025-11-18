#pragma once
#include <string>
#include "Establecimientos.h"
#include "Menues.h"
#include "Comensales.h"
#include "Comprobante.h"
#include "Facturas.h"
#include "CC.h"

template <typename Tipos>
class Archivos
{
public:
    Archivos(std::string nombreArchivo)
    {
        _nombreArchivo = nombreArchivo;
    }

    bool Guardar(Tipos registro)
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

    bool Guardar(Tipos registro, int posicion)
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

    int Buscar(int idbuscado)
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

    Tipos Leer(int posicion)
    {
        Tipos registro;
        FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
        if(pArchivo == NULL)
        {
            return registro; ///ARREGLAR ACA
        }
        fseek(pArchivo, sizeof(Tipos) * posicion, SEEK_SET);
        fread(&registro, sizeof(Tipos), 1, pArchivo);
        fclose(pArchivo);
        return registro;
    }


    int CantidadRegistros()
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

    void Leer(int cantidadRegistros, Tipos *vector)
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
    }

private:
    int _id_registro=0;
    std::string _nombreArchivo;
};


