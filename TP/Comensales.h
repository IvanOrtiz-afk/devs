#pragma once
#include <string>
#include "Fecha.h"
#include "Establecimientos.h"

class Comensal
{

private:
    char _nombre[15];
    int _IDcomensal;
    char _direccion[30];
    Fecha _fechaNacimiento;
    Establecimientos _IDestablecimiento;

public:
    Comensal(int idcomensal, const char *nombre, const char *direccion, Fecha fechanacimiento, Establecimientos idestablecimiento);
    Comensal();
    void setNombre (const char *nombre);
    void setIDcomensal (int IDcomensal);
    void setDireccion (const char *direccion);
    void setFechaNacimiento (Fecha fechaNacimiento);
    void setIDEstablecimiento (Establecimientos IDestablecimiento);
    std::string toString();

    const char* getNombre();
    int getIDcomensal();
    const char* getDireccion ();
    Fecha getFechaNacimiento ();
    Establecimientos getIDestablecimiento();

};
