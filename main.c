#include <stdio.h>
#include <stdlib.h>
#include <libsx.h>
#include "data.h"
#include "vue.h"


int main(int argc, char *argv[])
{

    // Accéder au serveur graphique
    if (OpenDisplay(argc, argv) == 0)
    {
        fprintf(stderr, "Can't open display\n");
        return EXIT_FAILURE;
    }
    equation D;
    // Initialiser l’inteface graphique
    init_display(argc, argv, &D);
    MainLoop();
    return EXIT_SUCCESS;
}
