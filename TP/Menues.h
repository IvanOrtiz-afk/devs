#pragma once
#include "TipoAlmuerzo.h"
#include "Fecha.h"
#include "Establecimientos.h"

class Menues
{
public:
    Menues(int idmenu, const char* nombremenu, Establecimientos esta, float valorplato, TipoAlmuerzo tipo, Fecha fecha);
    Menues();
    int getidmenu();
    const char* getnombremenu();
    float getvalorplato();
    const char* gettipo();
    Fecha getfecha();
    int getesta();
    void setesta(Establecimientos);
    void setidmenu(int);
    void setnombremenu(const char*);
    void setvalorplato(float);
    void settipo(TipoAlmuerzo);
    void setfecha(Fecha);
    std::string toString();

protected:
    int _esta;
    char _nombremenu[30];
    const char* _tipo;
    float _valorplato;
    Fecha _fecha;

private:
    int _idmenu;

};

