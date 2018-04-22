#include <iostream>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "./Util/Util.h"
#include "./Fifos/FifoEscritura.h"
#include "./Fifos/FifoLectura.h"
#include "./Modelo/Persona.h"

using namespace std;


int main(int argc,char* argv[]) {


    t_parametros tParametros = Util::tomarParametros(argc,argv);

    static const int BUFFSIZE = 15;
    static const std::string ARCHIVO_FIFO = "/tmp/archivo_fifo";

    int pid = 0;
    for (int i = 0; i < tParametros.cantVentanillas; i++) {
        pid = fork();
        if (pid == 0) {
            break;
        }
    }


    if (pid == 0) {
        cout<< "Soy el hijo " << getpid() << std::endl;
        FifoLectura canal ( ARCHIVO_FIFO );
        canal.abrir();

        sleep(1);
        char buffer[BUFFSIZE];
        ssize_t bytesleidos = canal.leer(static_cast<void*>(buffer), BUFFSIZE);

        if (bytesleidos > 0) {
            string mensaje = buffer;
            Persona persona;
            persona.desserializar(buffer);
            cout<< "Soy una ventanilla  " << getpid() <<" y recibi la persona DNI "<< persona.getNumeroDocumento()<< std::endl;
        }

        canal.cerrar();
    } else {
        string mensaje = "Hola";
        Persona persona;
        persona.setNumeroDocumento(324435);
        persona.setTipoPersona(2);

        FifoEscritura canal ( ARCHIVO_FIFO );
        canal.abrir();

        canal.escribir ( static_cast<const void*>(persona.serializar().c_str()), 15);
        cout<< "Soy el padre " << getpid() << std::endl;

        wait(0);
        canal.cerrar();
        canal.eliminar();
    }


    return 0;
}