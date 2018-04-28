#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <vector>
#include <cerrno>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <sstream>

#include "./Util/Util.h"
#include "./Util/Menu.h"
#include "./Fifos/FifoEscritura.h"
#include "./Fifos/FifoLectura.h"
#include "./Modelo/Persona.h"
#include "./Modelo/Ventanilla.h"
#include "./Modelo/FilaEspera.h"

using namespace std;

int main(int argc, char* argv[]) {

    t_parametros params = Util::tomarParametros(argc, argv);
    auto registroHijos = new int[params.cantVentanillas+1];
    int pid = 0;

    // es el proceso principal
    cout << "Soy el menu " << getpid() << endl;

    for (int i = 0; i < params.cantVentanillas; i++) {
        pid = fork();
        if (pid == 0) {
            // es un hijo ventanilla
            cout << "Soy la ventanilla " << getpid() << endl;
            Ventanilla ventanilla;
            ventanilla.iniciarAtencion(params.cantSellos);

            exit(0);
        }
        else registroHijos[i] = pid;
    }

    int pidFilaEspera = fork();
    if (pidFilaEspera == 0) {
        // es el hijo fila espera
        cout << "Soy la fila espera " << getpid() << endl;
        FilaEspera filaEspera;
        filaEspera.inicializar(params.cantVentanillas);

        exit(0);
    }
    registroHijos[params.cantVentanillas] = pidFilaEspera;

    Menu menu;
    menu.inicializar(params, registroHijos);

    // libero recursos
    delete registroHijos;

    cout << "Finalizando proceso principal " << getpid() << "..." << endl;

    return 0;
}

