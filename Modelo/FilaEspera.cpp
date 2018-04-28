//
// Created by nestor on 22/04/18.
//

#include "FilaEspera.h"

using namespace std;

vector<Persona> FilaEspera::obtenerPersonas() {
    vector<Persona> personas;
    FILE *fp;
    int numeroDocumento;
    int tipoDocumento;

    fp = fopen("personas.txt", "r");
    if (fp != NULL) {
        while( fscanf(fp, "%d,%d\n", &tipoDocumento, &numeroDocumento) != EOF ) {
            Persona persona(tipoDocumento, numeroDocumento);
            personas.push_back(persona);
        }
        fclose(fp);
    } else {
        printf("Error abriendo archivo de clientes\n");
    }

    return personas;
}


void FilaEspera::inicializar(int cantidadVentanillas) {
    vector<Persona> personas = obtenerPersonas();

    static const string ARCHIVO_FIFO = "/tmp/archivo_fifo";

    SIGINT_Handler sigint_handler;
    SignalHandler::getInstance()->registrarHandler(SIGINT, &sigint_handler);

    FifoEscritura canal ( ARCHIVO_FIFO );
    canal.abrir();

    for (Persona persona : personas) {
        sleep(2);
        canal.escribir(persona.serializar(), Persona::TAMANIO_SERIALIZADO);
        if (sigint_handler.getGracefulQuit() == 1) {
            break;
        }
    }

    canal.cerrar();
    for (int i = 0; i < cantidadVentanillas; ++i) {
        wait(0);
    }
    canal.eliminar();
    SignalHandler::destruir();
    cout << "Fila espera " << getpid() << " finalizo correctamente" << endl;
}