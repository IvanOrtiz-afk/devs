/* #include <iostream>
#include "ComensalManager.h"
#include "Comensales.h"
#include "Archivos.h"
#include "Fecha.h"
#include "Establecimientos.h"

using namespace std;



ComensalManager::ComensalManager(std::string nombreArchivo) 
    : _archivoComensales(nombreArchivo)
{
    
}

int ComensalManager::getNuevoID()
{
    int cantidad = _archivoComensales.CantidadRegistros();
    if (cantidad == 0) {
        return 1;
    }
    
    _archivoComensales.Leer(cantidad - 1);
    /// return getIDcomensal() + 1;
}

void ComensalManager::cargar() /// ver
{
    int id;
    char nombre[30];
    char direccion[50];
    int dia, mes, anio, idestablecimiento;
    
    id = getNuevoID();

    cout << "Cargar Nuevo Comensal ----" << endl;
    cout << "ID: " << id << endl;
    cout << "Ingrese nombre: ";
    cin >> nombre;
    cout << "Ingrese direccion: ";
    cin >> direccion;
    cout << "Ingrese Fecha Nacimiento (DD MM AAAA): ";
    cin >> dia >> mes >> anio;
    Fecha fechaNac(dia, mes, anio);
    cout << "Ingrese ID de Establecimiento: ";
    cin >> idestablecimiento;
    Establecimientos est; /// modificiar set id

    if(_archivoComensales.Guardar(Comensal(id, nombre, direccion, fechanacimiento, idestablecimiento)))
    {
        cout << "Se agrego correctamente" << endl;
    }
    else
    {
        cout << "Error al intentar guardar el personal." << endl;
    }

}

void ComensalManager::mostrar()
{
    int cantidad = _archivoComensales.getCantidadRegistros();
    Comensal *vComensal = new Comensal[cantidad];
    if(vComensal == nullptr)
    {
        cout << "No se pudo asignar memoria..." << endl;
        exit(-100);
    }

    _archivoComensales.leer(vComensal, cantidad);

    for(int i=0; i<cantidad; i++)
    {
        mostrarLista(vComensal[i]);
    }

    delete [] vComensal;
}

/* void ComensalManager::eliminar()
{
  
}

void ComensalManager::actualizar()
{

} 

void ComensalManager::mostrarLista(Comensal Comensal)
{
    cout << "ID: "<< Comensal.getIDcomensal() << endl;
    cout << "Nombre: "<< Comensal.getNombre() << endl;
    cout << "Direccion: " << Comensal.getDireccion () << endl;
    cout << "Fecha de nacimento: " << Comensal.getFechaNacimiento.toString () << endl;
    cout << "ID establecimiento: " << Comensal.getIDestablecimiento () << endl;
    cout << "------------" <<endl;
}*/
