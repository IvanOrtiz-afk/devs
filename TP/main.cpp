#include <iostream>
#include <string>
#include <cstring>
#include "Comensales.h"
#include "Fecha.h"
#include "Establecimientos.h"
#include "Archivos.h"
#include "Facturas.h"
#include "CC.h"
#include "Recibo.h"
#include "APP.h"

using namespace std;

int main()
{
    /**Archivos <Comensal> arch ("Comensales.dat");
    //Establecimientos asd(12, "San juanito", "moreno", "empresa");
    //Fecha fechatest;
    //Comensal test(12, "Ivan", "Moreno", fechatest.hoy(), asd);
    Comensal test;
    //arch.Guardar(test);
    test=arch.Leer(0);

    cout << test.toString() << endl;*/

    /**Archivos <Menues> arch ("Menues.dat");
    TipoAlmuerzo tipotest (34, "Comun", "para gente normal");
    Establecimientos asd(12, "San juanito", "moreno", "empresa");
    Fecha fechatest;
    Menues menutest (32, "Milanesa con papas", asd, 2300.00, tipotest, fechatest.hoy());
    arch.Guardar(menutest);*/

    App app;
    app.run();

    return 0;
}
