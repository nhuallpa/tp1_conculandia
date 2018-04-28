//
// Created by nestor on 22/04/18.
//

#include "Ventanilla.h"

using namespace std;

/**
 * Inicia la atension de una ventanilla de aduana para recibir personas.
 * @param cantidadSellos
 */
void Ventanilla::iniciarAtencion(int cantidadSellos) {

    static const string ARCHIVO_FIFO = "/tmp/archivo_fifo";


    SIGINT_Handler sigint_handler;
    SignalHandler::getInstance()->registrarHandler(SIGINT, &sigint_handler);

    FifoLectura canal ( ARCHIVO_FIFO );
    canal.abrir();
    sleep(2);
    char buffer[Persona::TAMANIO_SERIALIZADO];

    ssize_t bytesleidos = canal.leer(static_cast<void*>(buffer), Persona::TAMANIO_SERIALIZADO);

    while (bytesleidos > 0 && sigint_handler.getGracefulQuit() == 0) {
        if (bytesleidos == Persona::TAMANIO_SERIALIZADO) {
            string mensaje = buffer;
            Persona persona;
            persona.deserializar(buffer);
            cout<< "Soy una ventanilla " << getpid() <<" y recibi la persona DNI "<< persona.getNumeroDocumento()<< endl;
        } else if (bytesleidos > 0){
            cout << "La cantidad de bytes leidos no coincide " << endl;
        }
        bytesleidos = canal.leer(static_cast<void*>(buffer), Persona::TAMANIO_SERIALIZADO);
    }
    if (bytesleidos == -1) {
        if (errno == EINTR) {
            cout << "Se interrumpio la atencion " << strerror(errno) << endl;
        } else {
            cout << "Error al atender personas " << strerror(errno) << endl;
        }
    }

    canal.cerrar();
    SignalHandler::destruir();
    cout << "Ventanilla " << getpid() << " finalizo correctamente" << endl;
}