#include <iostream>
#include "App.h"
#include "MenuSistema.h"
using namespace std;

App::App(){
  _cantidadOpciones = 3;
}
void App::run(){
  int opcion;
///dentro de app vamos a correr todo el programa
///por mas que intente no pude usar polimorfismo ni tampoco use mucha herencia (aun la sigo usando pero para cosas minimas)
///perdi mucho tiempo intentando hacer el el codigo mas breve pero mas complejo con la herencia y polimorfismo
///yo diria que sigamos con lo que sabemos o con lo que nos es comodo de usar
///literalmente no le encontre utilidad alguna al polimorfismo, y la herencia la verdad que el heredar las propiedades de un menu a otros submenus
///que usan esas propiedades pero todos lo usan de forma diferente, no le encuentro sentido...si seguimos intentando con esto vamos a demorar mucho
///volvi a hacer pero de forma mas prolija lo que ya habia programado antes, vamos a ir plasmando todo el programa en app, cada submenu usara una o doa propiedades de menu padre
///ma¤ana domingo voy a seguir con "menucomensales", "menupadreABML" y "menu sistema"
  do{
    system("cls");
    opcion = seleccionOpcion();
    system("cls");
    ejecutarOpcion(opcion);
  }while(opcion != 0);
}

void App::mostrarOpciones(){    /// lo arme a modo de ejemplo
  cout << "--- HOLA! SELECCIONA UNA OPCION: ---" << endl;
  cout << "1- QUERES COMER? "<<endl;
  cout << "2- INGRESAR AL SISTEMA" <<endl;
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

}
