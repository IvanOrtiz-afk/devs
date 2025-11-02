#include <iostream>
#include "Archivo.h"
#include "Menues.h"
#include "Establecimientos.h"
#include "TipoAlmuerzo.h"
#include "Fecha.h"

using namespace std;

int main()
{
    Archivo archivo("TEST.dat", 1);
    Establecimientos registro(123, "establecimiento test", "direccion test", "tipo test");

archivo.Guardar(registro);

cout << registro.getdireccionesta() << endl;

/**
void Examen::Punto2()
{
    ArchivoOrdenProduccion archivo("ordenes_produccion.dat");
    OrdenProduccion registro;
    int i, cantidadRegistros = archivo.CantidadRegistros();
    float maquinas[15]= {};
    int cantmaquinas=0;

    for(i = 0; i < cantidadRegistros; i++)
    {
        registro = archivo.Leer(i);
        if (registro.getIDTipoPieza()==15)
        {
            maquinas[registro.getIDMaquina()-1]+=registro.getCosto();
        }
    }
    for (i=0; i<15; i++)
    {
        if (maquinas[i]>90000)
        {
            cantmaquinas++;
        }
    }
    cout << "PUNTO #2" << endl;
    cout << "La cantidad de m quinas distintas que gastaron m s de 90000 en total en la producci¢n de la pieza 15 son " << cantmaquinas << " m quinas" << endl;
}

std::string OrdenProduccion::toCSV() {
    return std::to_string(_IDProduccion) + "," +
           std::to_string(_IDMaquina) + "," +
           std::to_string(_IDTipoPieza) + "," +
           std::to_string(_cantidad) + "," +
           std::to_string(_costo) + "," +
           std::to_string(_tiempoEnHoras) + "," +
           std::to_string(_cantidadMateriaPrima) + "," +
           _fecha.toString();
}*/
    ///int i, cantidadRegistros = archivo.CantidadRegistros();

    cout << "HOLA CHICOS ESTA ES UNA PRUEBA DEL TP!!!" << endl;
    return 0;
}
