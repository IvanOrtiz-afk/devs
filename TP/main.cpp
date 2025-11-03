#include <iostream>
#include "Archivos.h"
#include "Menues.h"
#include "Establecimientos.h"
#include "TipoAlmuerzo.h"
#include "Fecha.h"

using namespace std;

int main()
{
    Archivos <Establecimientos> archivo("TEST.dat");
    Archivos <Menues> archivo2("TEST2.dat");

    Establecimientos registro(123, "establecimiento test", "direccion test", "tipo test");
    Fecha fechatest (19, 05, 1991);
    TipoAlmuerzo tipotest (12, "vegano", "saludable");
    Menues registro3(13, "ensalada vegana", 2300.50, tipotest, fechatest);

    archivo.Guardar(registro);
    archivo2.Guardar(registro3);

    archivo2.Leer(0);
    archivo.Leer(0);

    cout << registro3.toString(tipotest, fechatest) << endl;
    cout << registro.toString() << endl;
    cout << "HOLA CHICOS ESTA ES UNA PRUEBA DEL TP!!!" << endl;
    return 0;
}
