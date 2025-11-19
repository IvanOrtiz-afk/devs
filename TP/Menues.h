#pragma once
#include "TipoAlmuerzo.h"
#include "Fecha.h"
#include "Establecimientos.h"

class Menues
{
public:
    Menues(int idmenu, const char* nombremenu, Establecimientos esta, float valorplato, TipoAlmuerzo idtipo, Fecha fecha);
    Menues();
    int getidmenu();
    const char* getnombremenu();
    float getvalorplato();
    int getidtipo();
    Fecha getfecha();
    int getesta();
    const char *getdesctipo();
    int getvaloracion();
    void setvaloracion(int);
    void setdesctipo(TipoAlmuerzo);
    void setesta(Establecimientos);
    void setidmenu(int);
    void setnombremenu(const char*);
    void setvalorplato(float);
    void setidtipo(TipoAlmuerzo);
    void setfecha(Fecha);
    std::string toString();

protected:
    int _esta;
    char _nombremenu[30];
    int _idtipo;
    int _valoracion;
    char _desctipo[20];
    float _valorplato;
    Fecha _fecha;

private:
    int _idmenu;

};

