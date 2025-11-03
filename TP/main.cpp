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
    Establecimientos registro(123, "establecimiento test", "direccion test", "tipo test");
    Fecha fechatest (19, 05, 1991);
    TipoAlmuerzo tipotest (12, "vegano", "saludable");
    Menues registro3(13, "ensalada vegana", 2300.54, tipotest, fechatest);
    Establecimientos registro2;
    Menues registro4;

    ///archivo.Guardar(registro);
    archivo.Guardar(registro3);

    registro4=archivo.Leer(13);
    registro2=archivo.Leer(1);

    ///TESTEO DE TEMPLATE <Tipos>, FALTA TERMINAR CLASE MENUES PARA PROBAR!!!
    cout << registro4.toString() << endl;
    cout << registro2.toString() << endl;
    cout << "HOLA CHICOS ESTA ES UNA PRUEBA DEL TP!!!" << endl;
    return 0;
}
