//
// Created by nestor on 22/04/18.
//

#include "Ventanilla.h"


void Ventanilla::iniciarAtencion(int cantidadSellos) {

    static const std::string ARCHIVO_FIFO = "/tmp/archivo_fifo";

    FifoLectura canal ( ARCHIVO_FIFO );
    canal.abrir();
    sleep(2);
    char buffer[Persona::TAMANIO_SERIALIZADO];

    ssize_t bytesleidos = canal.leer(static_cast<void*>(buffer), Persona::TAMANIO_SERIALIZADO);

    while (bytesleidos > 0) {
        if (bytesleidos == Persona::TAMANIO_SERIALIZADO) {
            std::string mensaje = buffer;
            Persona persona;
            persona.deserializar(buffer);
            std::cout<< "Soy una ventanilla  " << getpid() <<" y recibi la persona DNI "<< persona.getNumeroDocumento()<< std::endl;
        } else if (bytesleidos > 0){
            std::cout << "La cantidad de bytes leidos no coincide " << std::endl;
        }
        bytesleidos = canal.leer(static_cast<void*>(buffer), Persona::TAMANIO_SERIALIZADO);
    }
    if (bytesleidos == -1) {
        std::cout << "Error al atender personas " << std::strerror(errno) << std::endl;
    }
    canal.cerrar();
}