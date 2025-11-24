#include <iostream>
#include <string>
#include <cstring>
#include "Comensales.h"
#include "Fecha.h"
#include "Establecimientos.h"
#include "TipoAlmuerzo.h"
#include "Menues.h"
#include "Archivos.h"
#include "Facturas.h"
#include "CC.h"
#include "Recibo.h"
#include "APP.h"

using namespace std;

int main()
{
    /*Archivos <Menues> arch ("Menues.dat");
    Menues menu_test;
    Establecimientos esta_test (345, "Roberto carlos", "direccion test", "empresa");
    TipoAlmuerzo tipo_test (2);
    Fecha fecha_test;
    fecha_test.hoy();

    Menues menu_test2(37, "pechuga", esta_test, 3000, tipo_test, fecha_test);

    int regitros=arch.CantidadRegistros();
    for (int i=0; i<regitros; i++)
    {
        menu_test=arch.Leer(i);
        std::cout << menu_test.toString() << std::endl;
    }

    std::cout << menu_test2.toString() << std::endl;*/

    App app;
    app.run();

    return 0;
}
