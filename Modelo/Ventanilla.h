//
// Created by nestor on 22/04/18.
//

#ifndef TP1_CONCULANDIA_VENTANILLA_H
#define TP1_CONCULANDIA_VENTANILLA_H

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


class Ventanilla {

public:
    void iniciarAtencion(int cantidadSellos);
};


#endif //TP1_CONCULANDIA_VENTANILLA_H
