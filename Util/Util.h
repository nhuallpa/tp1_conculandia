//
// Created by nestor on 20/04/18.
//

#ifndef TP1_CONCULANDIA_UTIL_H
#define TP1_CONCULANDIA_UTIL_H

#include <unistd.h>
#include <getopt.h>
#include <stdlib.h>

typedef struct parametros {
    int cantVentanillas;
    int cantSellos;
} t_parametros;

class Util {

public:
    static t_parametros tomarParametros(int argc,char* argv[]);

    static int crearProcesosHijos(int cantidadHijos);
};


#endif //TP1_CONCULANDIA_UTIL_H
