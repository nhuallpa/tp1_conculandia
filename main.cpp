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



int main(int argc,char* argv[]) {

    t_parametros tParametros = Util::tomarParametros(argc,argv);
    int pid = Util::crearProcesosHijos(tParametros.cantVentanillas);

    if (pid == 0) {
        Ventanilla ventanilla;
        ventanilla.iniciarAtencion(tParametros.cantSellos);
    } else {
        FilaEspera filaEspera;
        filaEspera.inicializar(tParametros.cantVentanillas);
    }

    return 0;
}


