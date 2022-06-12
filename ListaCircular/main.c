#include <stdio.h>
#include <stdlib.h>
#include "listaCircular.h"

#define S printf("\n**********\n");
#define N printf("\n");

void accion (const void * a)
{
    printf("%d\n",*((int*)a));
}

int main()
{
    int vec [5] = {1,2,3,4,5};
    int vec2 [5] = {1,2,3,4,5};
    int i;
    t_lista lista1;
    t_lista lista2;

    crearLista(&lista1);
    for(i=0;i<5;i++)
        insertar(&lista1,&vec[i],sizeof(int));
    recorrerCirc(&lista1,accion);
    S
    crearLista(&lista2);
    for(i=0;i<5;i++)
        insertarAlFinal(&lista2,&vec2[i],sizeof(int));


    recorrerCirc(&lista2,accion);



    return 0;
}
