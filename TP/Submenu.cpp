#include "Submenu.h"

Submenu::~Submenu()
{
}

void Submenu::run(){
  int opcion;

  do{
    system("cls");
    opcion = seleccionOpcion();
    system("cls");
    ejecutarOpcion(opcion);
  }while(opcion != 0);
}


void Submenu::mostrarOpciones(){   
  cout << "--- MENU" << getTitulo() <<  "---" << endl;
  cout << "1- NUEVO" << endl;
  cout << "2- MODIFICAR" <<endl;
  cout << "3- ELIMINAR"<< endl;
  cout << "4- LISTADO" << endl; 
  cout << "0- Volver al menu principal" << endl;
}


int Submenu::seleccionOpcion(){
  int opcion;
  mostrarOpciones();
  cout << "---------------" << endl;
  cout << "Opcion: ";
  cin >> opcion;

  return opcion;
}

void Submenu::ejecutarOpcion(int opcion){
  switch(opcion){
        case 1:
            cargar(); // Llama a alta() (el método virtual puro)
            break;  // C++ llamará a la versión de MenuComensal
        case 2:
            modificar(); 
            break;
        case 3:
            eliminar(); 
            break;
        case 4:
            mostrar(); 
            break;
        case 0:
            cout << "Volviendo al menu principal..." << endl;
            break;
        default:
            cout << "Opcion incorrecta." << endl;
            cout << "Opcion: ";
            cin >> opcion;
            break;
    }
  }
