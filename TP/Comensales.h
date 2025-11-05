#pragma once
#include "Fecha.h"
#include "Establecimientos.h"

class Comensal {

private:
    char _nombre[15];
    int _IDcomensal;
    char _direccion[30];
    Fecha _fechaNacimiento;
    Establecimientos _IDestablecimiento;

public:
    Comensal();
    void setNombre (char nombre);
    void setIDcomensal (int IDcomensal);
    void setDireccion (char direccion);
    void setFechaNacimiento (Fecha fechaNacimiento);
    void setIDEstablecimiento (Establecimientos IDestablecimiento);

    const char* getNombre();
    int getIDcomensal();
    const char* getDireccion ();
    Fecha getFechaNacimiento ();
    Establecimientos getIDestablecimiento();

};
