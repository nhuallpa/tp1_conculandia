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
#include <cstdio>
#include <cstdlib>
#include <sstream>

#include "Util.h"

using namespace std;

class Menu {

public:
    int inicializar(const t_parametros &params, const int *registroHijos);

#endif //TP1_CONCULANDIA_MENU_H
