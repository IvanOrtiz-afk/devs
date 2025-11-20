#pragma once
#include "Menues.h" 
#include "Fecha.h"


class Consumos
{
    public:
        Consumos(Fecha fecha, Comensal idcliente, Menues plato);
        Consumos();
        void setfecha(Fecha fecha);
        void setcliente(Comensal idcliente);
        void setplatoconsumido(Menues plato);
        Fecha getfecha();
        int getcliente();
        const char* getplato();
        float getimporte();
        void setimporte(Menues plato);

    protected:

    private:
        Fecha _fecha;
        int _idcliente;
        char _plato[30];
        float _importe;
};


