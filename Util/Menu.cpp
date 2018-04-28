//
// Created by nestor on 28/04/18.
//

#include "Menu.h"

using namespace std;

/**
 * Inicia el menu interactivo para que el usuario pueda controlar
 * las ventanillas, fila de espera y el abm de personas de riesgo.
 * */
int Menu::inicializar(t_parametros params, int* registroHijos) {
    string input;
    while (input != "S") {
        cout << "MENU" << endl;
        cout << "S: Salir" << endl;
        cout << "Seleccione una opcion:" << endl;
        getline(cin, input);
    }

    // estoy saliendo, mato los procesos hijos
    for (int i = 0; i < params.cantVentanillas+1; i++) {
        cout << "Cerrando hijo: " << registroHijos[i] << endl;
        kill(registroHijos[i], SIGINT);
    }
}