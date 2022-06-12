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

    int i;
    int dato=90;
    t_lista lista1;


    crearLista(&lista1);
    for(i=0;i<5;i++)
        insertar(&lista1,&vec[i],sizeof(int));
    recorrerCirc(&lista1,accion);
    S

    eliminar (&lista1,&dato,sizeof(int));
    printf("%d",dato);
    S
    recorrerCirc(&lista1,accion);



    return 0;
}


