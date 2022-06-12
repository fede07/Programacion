#include <stdio.h>
#include <stdlib.h>

#include "archivos.h"

int main()
{
    FILE * pf;
    if(crearLote()==0)
    {
        printf("error 1");
        exit(0);
    }

    if(abrirArchivo(&pf,"lotePrueba2.txt","rt")==0)
    {
        printf("error 2");
        exit(1);
    }
    invPalDeArch(pf);///pepito nos hace el favor de dar vuelta las palabras

    fclose(pf);

    return 0;
}
