//
// Created by nestor on 28/04/18.
//

#include "Menu.h"


/**
 * Imprimo y loopeo sobre el menu
 * @param params
 * @param registroHijos
 * @return
 */

int Menu::inicializar(const t_parametros &params, const int *registroHijos) {
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


