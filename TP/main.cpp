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
    Archivos <Menues> arch2 ("Menues.dat");
    Establecimientos asd(12, "San juanito", "moreno", "empresa");
    Fecha fechatest;
    TipoAlmuerzo tipotest (1);
    TipoAlmuerzo tipotest2 (2);
    TipoAlmuerzo tipotest3 (3);
    Comensal test(12, "Ivan", "Moreno", fechatest.hoy(), asd);
    Menues menutest (32, "Milanesa con papas", asd, 2300, tipotest, fechatest.hoy());
    Menues menutest2 (33, "Milanesa integral", asd, 2000, tipotest2, fechatest.hoy());
    Menues menutest3 (34, "Milanesa sin TACC", asd, 3000, tipotest3, fechatest.hoy());
    //Comensal test;
    arch.Guardar(test);
    arch2.Guardar(menutest);
    arch2.Guardar(menutest2);
    arch2.Guardar(menutest3);

    test=arch.Leer(0);

    cout << test.toString() << endl;
    cout << menutest.toString() << endl;*/

    App app;
    app.run();

    return 0;
}
