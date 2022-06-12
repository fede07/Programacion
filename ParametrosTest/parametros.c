#include <stdio.h>
#include <stdlib.h>
#include "parametros.h"

void cargarVector(int *vect, int cant)
{
    int i;
    for(i=0;i<cant;i++)
    {
        printf("\nPosicion %d, Dato: ", i);
        scanf("%d", vect);
        vect++;
    }
}

void mostrarF(int *vec, int tam);
