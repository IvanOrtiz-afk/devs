#pragma once
#include <string>
#include "Comensales.h"
#include "Fecha.h"

class Pagos
{
    public:
        Pagos(int numeracion, Comensal comensal, float importe, Fecha fecha);
        Pagos();
        void setfecha(Fecha);
        void setIDcomensal(Comensal);
        void setnombre(Comensal);
        void setimporte(float);
        float getimporte();
        int getIDcomensal();
        int getNumeracion();
        void setNumeracion(int);
        Fecha getfecha();
        const char *getnombre();
        std::string toString();

    private:
        int _numeracion;
        int _idcomensal;
        char _nombre[30];
        float _importe;
        Fecha _fecha;
};
