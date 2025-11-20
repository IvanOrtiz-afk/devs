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
    /*
    Archivos <TipoAlmuerzo> tipo_almuerzo ("TipoAlmuerzo.dat");
    Archivos <Comensal> arch ("Comensales.dat");
    Archivos <Menues> arch2 ("Menues.dat");
    ///Archivos <TipoAlmuerzo> arch3 ("TipoAlmuerzo.dat");
    Establecimientos asd(4, "San juanito", "moreno", "empresa");
    Fecha fechatest;
    
    TipoAlmuerzo tipotest(1);
    TipoAlmuerzo tipotest2(2);
    TipoAlmuerzo tipotest3(3);
    Comensal test(1, "Ivan", "Moreno", fechatest.hoy(), asd);
    Comensal test1(2, "Evelyn", "Tigre", fechatest.hoy(), asd);
    Comensal test2(3, "Bruno", "Moron", fechatest.hoy(), asd);
    Comensal test3(4, "Pedro", "Pacheco", fechatest.hoy(), asd);
    Comensal test4(5, "Felix", "San Fernadno", fechatest.hoy(), asd);
    Menues menutest (1, "Milanesa con papas", asd, 2300, tipotest, fechatest.hoy());
    Menues menutest2 (2, "Milanesa integral", asd, 2000, tipotest2, fechatest.hoy());
    Menues menutest3 (3, "Milanesa sin TACC", asd, 3000, tipotest3, fechatest.hoy());
    //Comensal test;
    arch.Guardar(test);
    arch.Guardar(test1);
    arch.Guardar(test2);
    arch.Guardar(test3);
    arch.Guardar(test4);
    arch2.Guardar(menutest);
    arch2.Guardar(menutest2);
    arch2.Guardar(menutest3);
    */


    App app;
    app.run();

    return 0;
}
