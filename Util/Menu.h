//
// Created by nestor on 28/04/18.
//

#ifndef TP1_CONCULANDIA_MENU_H
#define TP1_CONCULANDIA_MENU_H
#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <vector>
#include <cerrno>
#include <cstring>
#include "Util.h"

class Menu {

public:
    int inicializar(t_parametros params, int* registroHijos);
};


#endif //TP1_CONCULANDIA_MENU_H
