#include <iostream>
#include "App.h"
using namespace std;

App::App(){
  _cantidadOpciones = 7;
}
void App::run(){
  int opcion;

  do{
    system("cls");
    opcion = seleccionOpcion();
    system("cls");
    ejecutarOpcion(opcion);
  }while(opcion != 0);
}

void App::mostrarOpciones(){    /// lo arme a modo de ejemplo
  cout << "--- MENU PRINCIPAL ---" << endl;
  cout << "1- ALMUERZOS "<<endl;
  cout << "2- FACTURACION" <<endl;
  cout << "3- CUENTA CORRIENTE" << endl;
  cout << "4- PAGOS" << endl;
  cout << "5- ESTABLECIMIENTOS" << endl;
  cout << "6- COMENSALES" << endl;
  cout << "0- Salir "<<endl;
}

int App::seleccionOpcion(){
  int opcion;
  mostrarOpciones();
  cout << "---------------" << endl;
  cout << "Opcion: ";
  cin >> opcion;

  while(opcion < 0 || opcion > _cantidadOpciones){
    cout << "Opcion incorrecta..."<<endl;
    cout << "Opcion: ";
    cin >> opcion;
  }
  return opcion;
}

void App::ejecutarOpcion(int opcion){
  switch(opcion){
  case 1:
    /// ir mostrando el menu de cada clase, hay que armar un menu para almuerzos, facturas, etc..
  break;
  case 0:
    cout << "Gracias por utilizar mi APP :) " << endl;
    break;
  }
}
