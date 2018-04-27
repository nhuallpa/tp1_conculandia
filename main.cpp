#include <iostream>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <vector>
#include <cerrno>
#include <cstring>



#include "./Util/Util.h"
#include "./Fifos/FifoEscritura.h"
#include "./Fifos/FifoLectura.h"
#include "./Modelo/Persona.h"
#include "./Modelo/Ventanilla.h"
#include "./Modelo/FilaEspera.h"
#include <stdio.h>
#include <stdlib.h>
#include <sstream>


int main(int argc,char* argv[]) {

    t_parametros tParametros = Util::tomarParametros(argc,argv);
    int* registroHijos = new int[tParametros.cantVentanillas+1];
    int pid = 0;
    int i = 0;
    for (i = 0; i < tParametros.cantVentanillas; i++) {
        pid = fork();
        if (pid == 0) {
            break;
        } else {
            registroHijos[i] = pid;
        }
    }

    if (pid == 0) {
        Ventanilla ventanilla;
        ventanilla.iniciarAtencion(tParametros.cantSellos);
    } else {
        pid = fork();  // Fila espera
        if (pid == 0) {
            FilaEspera filaEspera;
            filaEspera.inicializar(tParametros.cantVentanillas);
        } else {
            std::cout<<"filaEspera "<<pid<<std::endl;
            registroHijos[tParametros.cantVentanillas] = pid;
        }

        std::string input = "";
        std::cout<<"S: Salir"<<std::endl;
        std::cout<<"Seleccione una opcion:"<<std::endl;
        getline(std::cin, input);

        while (input != "S") {
            std::cout<<"S: Salir"<<std::endl;
            std::cout<<"Seleccione una opcion:"<<std::endl;
            getline(std::cin, input);
        }
        for (int i = 0; i < tParametros.cantVentanillas+1; i++) {
            std::cout<<"Cerrando hijo:"<<registroHijos[i]<<std::endl;
            kill(registroHijos[i], SIGINT);
        }
        delete registroHijos;
        std::cout<<"Esperando principal:"<<std::endl;
        sleep(5);
    }

    return 0;
}


