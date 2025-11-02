#include <iostream>
#include <cstring>
#include "Menues.h"
#include "TipoAlmuerzo.h"

Menues::Menues(){};
Menues::Menues(int idmenu, const char* nombremenu, float valorplato, TipoAlmuerzo tipo, Fecha fecha)
{
    _idmenu=idmenu;
    strncpy(_nombremenu, nombremenu, sizeof(_nombremenu) - 1);
    _nombremenu[sizeof(_nombremenu) - 1]='\0';
    _valorplato=valorplato;
    _tipo=tipo;
    _fecha=fecha;
}

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


