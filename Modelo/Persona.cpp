//
// Created by nestor on 22/04/18.
//

#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>
#include "Persona.h"


std::string Persona::serializar() {
    std::stringstream serializado;
    serializado << std::setw(4)<< this->getTipoPersona() << std::setw(11)<<this->getNumeroDocumento();
    return serializado.str();
}

void Persona::desserializar(const char * buffer) {
    std::string persona = buffer;
    this->setTipoPersona(atoi(persona.substr(0,4).c_str()));
    this->setNumeroDocumento(atoi(persona.substr(4,11).c_str()));
}

int Persona::getTipoPersona() const {
    return tipoPersona;
}

void Persona::setTipoPersona(int tipoPersona) {
    Persona::tipoPersona = tipoPersona;
}

int Persona::getNumeroDocumento() const {
    return numeroDocumento;
}

void Persona::setNumeroDocumento(int numeroDocumento) {
    Persona::numeroDocumento = numeroDocumento;
}
