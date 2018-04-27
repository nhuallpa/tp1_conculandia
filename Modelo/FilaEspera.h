//
// Created by nestor on 22/04/18.
//

#ifndef TP1_CONCULANDIA_FILAESPERA_H
#define TP1_CONCULANDIA_FILAESPERA_H

#include <iostream>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <vector>
#include <cerrno>
#include <cstring>



#include "../Util/Util.h"
#include "../Fifos/FifoEscritura.h"
#include "../Fifos/FifoLectura.h"
#include "Persona.h"
#include <stdio.h>
#include <stdlib.h>


#include "../Util/SignalHandler.h"
#include "../Util/SIGINT_Handler.h"


class FilaEspera {
private:
    std::vector<Persona> obtenerPersonas();
public:
    void inicializar(int cantidadVentanillas);
};


#endif //TP1_CONCULANDIA_FILAESPERA_H
