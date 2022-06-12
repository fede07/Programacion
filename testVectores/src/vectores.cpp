#include <stdio.h>
#include "vectores.h"

int mostrarVectInt(int vect[], int cant)
{
    int i;
    for(i=0;i<cant;i++)
    {
        printf("\t%d",vect[i]);
    }
    return 1;
}
