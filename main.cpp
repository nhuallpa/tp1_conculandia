#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>


int main(int argc,char* argv[]) {
    int c;

    while (1)
    {
        static struct option long_options[] =
                {
                        {"ventanillas",  required_argument, 0, 'v'},
                        {"sellos",  required_argument, 0, 's'},
                        {0, 0, 0, 0}
                };
        /* getopt_long stores the option index here. */
        int option_index = 0;

        c = getopt_long (argc, argv, "v:s:",
                         long_options, &option_index);

        /* Detect the end of the options. */
        if (c == -1)
            break;

        switch (c)
        {

            case 'v':
                printf ("option -v with value `%s'\n", optarg);
                break;

            case 's':
                printf ("option -s with value `%s'\n", optarg);
                break;

            case '?':
                /* getopt_long already printed an error message. */
                break;

            default:
                abort ();
        }
    }


    /* Print any remaining command line arguments (not options). */
    if (optind < argc)
    {
        printf ("No es un parametro valido: ");
        while (optind < argc)
            printf ("%s ", argv[optind++]);
        putchar ('\n');
    }

    exit (0);
}