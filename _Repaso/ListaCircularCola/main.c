#include <stdio.h>
#include <stdlib.h>
#include "ListaCircularCola.h"

#define TAM 5

int main()
{
    int vec[TAM]={1,2,3,4,5};
    int i, dato=99;
    t_lista lista;
    crearListaCC(&lista);

    for(i=0;i<TAM;i++)
    {
        ponerEnListaCC(&lista,&vec[i],sizeof(int));
    }

    verPrimero(&lista,&dato,sizeof(int));
    printf("%d \n",dato);

    while(!listaCCVacia(&lista))
    {
        sacarDeListaCC(&lista,&dato,sizeof(int));
        printf("%d ",dato);
    }

    return 0;
}
