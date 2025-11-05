#include <iostream>
#include "Archivos.h"
#include "Menues.h"
#include "Establecimientos.h"
#include "TipoAlmuerzo.h"
#include "Fecha.h"
#include "Comensales.h"

using namespace std;

int main()
{
    Archivos <Establecimientos> archivo("TEST.dat");
    Archivos <Menues> archivo2("TEST2.dat");
    Archivos <Comensal> archivo3("TEST3.dat");

    Establecimientos registro(123, "establecimiento test", "direccion test", "tipo test");
    Fecha fechatest(19, 05, 1991);
    TipoAlmuerzo tipotest(12, "vegano", "saludable");
    Menues registro3(13, "ensalada vegana", 2300.50, tipotest, fechatest);
    Comensal registro10(10, "Ivan", "La villa", fechatest, registro);

    ///Comensal(int idcomensal, const char *nombre, const char *direccion, Fecha fechanacimiento, Establecimientos idestablecimiento);

    archivo3.Guardar(registro10);
    archivo.Guardar(registro);
    archivo2.Guardar(registro3);

    archivo3.Leer(1);
    archivo2.Leer(1);
    archivo.Leer(1);

    ///ESTE registro3.tostring(tipotest, fechatest) ES SOLO PARA TESTEOS CON HARDCODEO, DUDO MUCHO QUE LO USEMOS ASI PARA LA VERSION FINAL
    cout << registro10.toString(fechatest, registro) << endl;
    cout << registro3.toString(tipotest, fechatest) << endl; ///ENVIO COMO PARAMETROS LOS DOS DATOS QUE HARCODIE DESDE MAIN, DADO QUE SE HARDCODEARON EN MAIN TENGO QUE USAR tostring DE ESTA FORMA
    cout << registro.toString() << endl;
    cout << "HOLA CHICOS ESTA ES UNA PRUEBA DEL TP!!!!!!" << endl;
    return 0;
}
