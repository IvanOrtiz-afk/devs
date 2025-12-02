#pragma once
#include <string>
#include <cstdio>
#include "Establecimientos.h"
#include "Menues.h"
#include "Comensales.h"
#include "Comprobante.h"
#include "Facturas.h"
#include "CC.h"
#include "usuario.h"
#include "Login.h"

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
            if(j == idbuscado)  ///NO SE USA DE MOMENTO
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

    bool Eliminar(int registro_eliminar)
    {
        std::string nombre_temporal="temp.dat";
        FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
        FILE *pArchivo2 = fopen(nombre_temporal.c_str(), "wb");
        Tipos registro;
        bool ok=true;
        if(pArchivo == NULL)
        {
            return false;
        }
        if(pArchivo2 == NULL)
        {
            fclose(pArchivo);
            return false;
        }
        fseek(pArchivo, 0, SEEK_END);
        int cantidadRegistros = ftell(pArchivo) / sizeof(Tipos);
        fseek(pArchivo, 0, SEEK_SET);
        for (int i=0; i<cantidadRegistros; i++)
        {
            if (fread(&registro, sizeof(Tipos), 1, pArchivo)!=1) ///lee un registro y avanza el puntero una posicion
            {
                ok=false;
                break;
            }
            if (registro_eliminar!=i) ///si NO es el registro a eliminar, lo guarda en el temporal
            {
                if (fwrite(&registro, sizeof(Tipos), 1, pArchivo2)!=1)
                {
                    ok=false;
                    break;
                }
            }
        }
        fclose(pArchivo);
        fclose(pArchivo2);
        if (ok==true)
        {
            if (std::remove(_nombreArchivo.c_str())==0)
            {
                if (std::rename(nombre_temporal.c_str(), _nombreArchivo.c_str())==0)
                {
                    ok=true;
                }
                else
                {
                    ok=false;
                }
            }
            else
            {
                ok=false;
            }
        }
        return ok;
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


