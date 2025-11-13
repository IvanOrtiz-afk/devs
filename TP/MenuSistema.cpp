#include <iostream>
#include "MenuSistema.h"
using namespace std;

MenuSistema::MenuSistema(){
  _cantidadOpciones = 7;
}

void MenuSistema::run(){
  int opcion;

  do{
    system("cls");
    opcion = seleccionOpcion();
    system("cls");
    ejecutarOpcion(opcion);
  }while(opcion != 0);
}

void MenuSistema::mostrarOpciones(){    /// lo arme a modo de ejemplo
  cout << "--- MENU PRINCIPAL ---" << endl;
  cout << "1- PLATOS "<<endl;
  cout << "2- ESTABLECIMIENTOS" <<endl;
  cout << "3- COMENSALES "<<endl;
  cout << "4- FACTURACION "<<endl;
  cout << "5- AJUSTE DE CUENTA CORRIENTE "<<endl;
  cout << "6- RECIBOS "<<endl;
  cout << "0- Salir "<<endl;
}

int MenuSistema::seleccionOpcion(){
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

void MenuSistema::ejecutarOpcion(int opcion){
  switch(opcion){
  case 1:
    /// ir mostrando el menu de cada clase, hay que armar un menu para almuerzos, facturas, etc..
  break;
  case 3:
  _menuComensal.run();
  break;
  case 0:
    cout << "Gracias por utilizar mi APP :) " << endl;
  break;
  }
}
