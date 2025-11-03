#include <iostream>
#include "Archivos.h"

Archivos::Archivos(std::string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}

///ARCHIVO ESTABLECIMIENTOS

bool Archivos::Guardar(Establecimientos registro){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "ab");
    if(pArchivo == NULL){
        return false;
    }
    bool ok = fwrite(&registro, sizeof(Establecimientos), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

bool Archivos::Guardar(Establecimientos registro, int posicion){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb+");
    if(pArchivo == NULL){
        return false;
    }
    fseek(pArchivo, sizeof(Establecimientos) * posicion, SEEK_SET);
    bool ok = fwrite(&registro, sizeof(Establecimientos), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

int Archivos::Buscar(int idestablecimiento){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return -1;
    }
    Establecimientos registro;
    int i = 0;
    while(fread(&registro, sizeof(Establecimientos), 1, pArchivo)){
        if(registro.getidestablecimiento() == idestablecimiento){
            fclose(pArchivo);
            return i;
        }
        i++;
    }
    fclose(pArchivo);
    return -1;
}

Establecimientos Archivos::Leer(int posicion){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return Establecimientos();
    }
    Establecimientos registro;
    fseek(pArchivo, sizeof(Establecimientos) * posicion, SEEK_SET);
    fread(&registro, sizeof(Establecimientos), 1, pArchivo);
    fclose(pArchivo);
    return registro;
}

int Archivos::CantidadRegistros(){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(Establecimientos);
    fclose(pArchivo);
    return cantidadRegistros;
}

void Archivos::Leer(int cantidadRegistros, Establecimientos *vector){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return;
    }
    for(int i = 0; i < cantidadRegistros; i++){
        fread(&vector[i], sizeof(Establecimientos), 1, pArchivo);
    }
    fclose(pArchivo);
}


