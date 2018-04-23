//
// Created by nestor on 22/04/18.
//

#include "FilaEspera.h"


std::vector<Persona> FilaEspera::obtenerPersonas() {
    std::vector<Persona> personas;
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
    std::vector<Persona> personas = obtenerPersonas();

    static const std::string ARCHIVO_FIFO = "/tmp/archivo_fifo";

    FifoEscritura canal ( ARCHIVO_FIFO );
    canal.abrir();

    for (Persona persona : personas) {
        canal.escribir(persona.serializar(), Persona::TAMANIO_SERIALIZADO);
    }

    sleep(2);
    canal.cerrar();
    for (int i = 0; i < cantidadVentanillas; ++i) {
        wait(0);
    }
    canal.eliminar();

}