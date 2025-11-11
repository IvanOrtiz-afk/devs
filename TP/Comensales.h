#pragma once
#include <string>
#include "Fecha.h"
#include "Establecimientos.h"

class Comensal
{

public:

    Comensal(int idcomensal, const char *nombre, const char *direccion, Fecha fechanacimiento, Establecimientos idestablecimiento);
    Comensal();

    void setNombre (const char *nombre);
    const char* getNombre();

    void setIDcomensal (int IDcomensal);
    int getIDcomensal();

    void setDireccion (const char *direccion);
    const char* getDireccion ();

    void setFechaNacimiento (Fecha fechaNacimiento);
    Fecha getFechaNacimiento ();

    void setIDEstablecimiento (Establecimientos IDestablecimiento);
    Establecimientos getIDestablecimiento();

    std::string toString();


private:

    char _nombre[15];
    int _IDcomensal;
    char _direccion[30];
    Fecha _fechaNacimiento;
    Establecimientos _IDestablecimiento;

};
