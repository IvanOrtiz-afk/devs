#include <iostream>
#include <cstring>
#include "Login.h"

using namespace std;

void Login::run() {
    RepoUsuarios repo;

    char nombre[20];
    char pass[20];
    usuario u(0, "", "", 3);

    cout << "===== LOGIN =====\n";
    cout << "Usuario: ";
    cin >> nombre;

    bool encontrado = repo.buscarPorNombre(nombre, u);

    if (!encontrado) {
        cout << "\nUsuario inexistente.\n";
        system("pause");
        return;
    }

    cout << "Password: ";
    cin >> pass;

    if (strcmp(u.getPassword(), pass) != 0) {
        cout << "\nPassword incorrecto.\n";
        system("pause");
        return;
    }

    cout << "\nBienvenido " << u.getNombre()
         << " (" << u.getRol() << ")\n";

    system("pause");

    if (strcmp(u.getRol(), "admin") == 0) {
        cout << "Entrando al menu ADMIN...\n";
        system("pause");
        // menuAdmin();
    }
    else if (strcmp(u.getRol(), "encargado") == 0) {
        cout << "Entrando al menu ENCARGADO...\n";
        system("pause");
        // menuEncargado();
    }
    else if (strcmp(u.getRol(), "comensal") == 0) {
        cout << "Entrando al menu COMENSAL...\n";
        system("pause");
        // menuComensal();
    }
}
