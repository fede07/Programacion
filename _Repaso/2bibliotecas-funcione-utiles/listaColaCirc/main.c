#include <stdio.h>
#include <stdlib.h>

#include "listaColaCirc.h"


int main()
{
    int vec[]={1};
    int i, dato=99;
    t_lista lista;
    crearLista(&lista);

    for(i=0;i<1;i++)
        agregarEnLista(&lista,&vec[i],sizeof(int));

    verPriLista(&lista,&dato,sizeof(int));
    printf("%d \n",dato);

    while(!listaVacia(&lista))
    {
        sacarDeLista(&lista,&dato,sizeof(int));
        printf("%d ",dato);
    }
    return 0;
}
