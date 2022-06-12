#include <stdio.h>
#include <stdlib.h>
#include "listaPilaCirc.h"

#define S printf("\n***************\n");

int main()
{
    int vec[5] = {1,2,3,4,5};
    int i;
    int dato=99, tope =-1;
    t_listaP listaP;

    crearlistaP(&listaP);

    for(i=0;i<5;i++)
    {
        ponerEnlistaP(&listaP,&vec[i],sizeof(int));
        verTope(&listaP,&dato,sizeof(int));
        printf("%d\n",dato);
    }
    S
    dato=99;
//    while(!listaPVacia(&listaP))
//    {
//        verTope(&listaP,&tope,sizeof(int));
//        sacarDelistaP(&listaP,&dato,sizeof(int));
//        printf("tope %d dato %d\n",tope,dato);
//    }
    vaciarlistaP(&listaP);

    printf("dato %d, return %d",dato,verTope(&listaP,&dato,sizeof(int)));


    return 0;
}
