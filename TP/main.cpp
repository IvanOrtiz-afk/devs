#include <iostream>
#include "Archivos.h"
#include "Menues.h"
#include "Establecimientos.h"
#include "TipoAlmuerzo.h"
#include "Fecha.h"

using namespace std;

int main()
{
    Archivos archivo("TEST.dat");
    Establecimientos registro(123, "establecimiento test", "direccion test", "tipo test");
    Establecimientos registro2;
    ///archivo.Guardar(registro);
    registro2=archivo.Leer(1);

    cout << registro2.toString() << endl;
    cout << "HOLA CHICOS ESTA ES UNA PRUEBA DEL TP!!!" << endl;
    return 0;
}
