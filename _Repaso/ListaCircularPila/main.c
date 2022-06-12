#include <stdio.h>
#include <stdlib.h>
#include "ListaCircularPila.h"

#define TAM 5

int main()
{
    int vec[TAM] = {1,2,3,4,5};
    int i, dato = 99, tope = -1;
    t_lista listaP;

    crearListaCircP(&listaP);

    for(i=0; i<5; i++)
    {
        ponerEnListaP(&listaP, &vec[i], sizeof(int));
        verTope(&listaP, &dato, sizeof(int));
        printf("%d\n", dato);
    }

    printf("\n-----------\n");
    dato = 99;

    while(!listaPVacia(&listaP))
    {
        verTope(&listaP, &tope, sizeof(int));
        sacarDeListaP(&listaP, &dato, sizeof(int));
        printf("Tope: %d, Dato: %d\n", tope, dato);
    }
    vaciarListaP(&listaP);

    printf("Dato: %d, VerTope: %d\n",dato, verTope(&listaP, &dato, sizeof(int)));

    return 0;
}
