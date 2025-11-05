#include <iostream>
#include <string>
#include <cstring>
#include "Comensales.h"
#include "Fecha.h"
#include "Establecimientos.h"
#include "Archivos.h"

using namespace std;

int main()
{
    Archivos <Establecimientos> archivo("TEST.dat");
    Archivos <Menues> archivo2("TEST2.dat");
    Archivos <Comensal> archivo3("TEST3.dat");

    Establecimientos registro;
    Menues registro3;
    Comensal registro10;

    ///HARDCODEO QUE HICE PARA GUARDAR LOS ARCHIVOS TEST, ESTA COMENTADO PARA VER SI ME TRAE ESTOS DATOS DESDE EL .DAT
    ///AHORA FUNCIONA!!!
    /**Establecimientos registro(123, "establecimiento test", "direccion test", "tipo test");
    Fecha fechatest(19, 05, 1991);
    TipoAlmuerzo tipotest(12, "vegano", "saludable");
    Menues registro3(13, "ensalada vegana", 2300.50, tipotest, fechatest);
    Comensal registro10(10, "Ivan", "La villa", fechatest, registro);

    archivo3.Guardar(registro10);
    archivo.Guardar(registro);
    archivo2.Guardar(registro3);*/

    registro10=archivo3.Leer(0); ///NOS OLVIDAMOS DE IGUALAR LA VARIABLE CREADA CON LO LEIDO EN EL ARCHIVO!
    registro3=archivo2.Leer(0); ///POR ESO NO LEIA!!!
    registro=archivo.Leer(0);

    ///ESTE registro3.tostring(tipotest, fechatest) ES SOLO PARA TESTEOS CON HARDCODEO, DUDO MUCHO QUE LO USEMOS ASI PARA LA VERSION FINAL
    cout << "HOLA CHICOS ESTA ES UNA PRUEBA DEL TP!!!!!!" << endl;
    cout << registro10.toString() << endl;
    cout << registro3.toString() << endl; ///ENVIO COMO PARAMETROS LOS DOS DATOS QUE HARCODIE DESDE MAIN, DADO QUE SE HARDCODEARON EN MAIN TENGO QUE USAR tostring DE ESTA FORMA
    cout << registro.toString() << endl;

    return 0;
}
