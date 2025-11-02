#pragma once
#include "TipoAlmuerzo.h"
#include "Fecha.h"

class Menues
{
public:
    Menues();
    Menues(int idmenu, const char* nombremenu, float valorplato, TipoAlmuerzo tipo, Fecha fecha);
    int getidmenu();
    const char* getnombremenu();
    float getvalorplato();
    TipoAlmuerzo gettipo();
    Fecha getfecha();
    void setidmenu(int);
    void setnombremenu(const char*);
    void setvalorplato(float);
    void settipo(TipoAlmuerzo);
    void setfecha(Fecha);

protected:
    char _nombremenu[30];
    TipoAlmuerzo _tipo;
    float _valorplato;
    Fecha _fecha;

private:
    int _idmenu;

};

