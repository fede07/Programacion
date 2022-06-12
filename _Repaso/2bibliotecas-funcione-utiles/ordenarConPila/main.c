#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

#define N printf("\n");

#define TAM 12

///
int main()
{
    int vector[TAM]={3,1,5,2,6,0,4,-5,7,8,9,-4};
    int * v;
    int tope, i=0;
    t_pila ord1;
    t_pila ord2;

    v = vector;

    crearPila(&ord1);
    crearPila(&ord2);

    while(i<TAM && pilaLlena(&ord1,sizeof(int))==0 && pilaLlena(&ord2,sizeof(int))==0)
    {
        printf("***  tope<v %d<%d  ***",tope,*v);
        N
        if((pilaVacia(&ord1) || tope<*v)  && !pilaLlena(&ord1,sizeof(int)))
        {

            while(!pilaVacia(&ord1) && tope<*v)
            {
                sacarDePila(&ord1,&tope,sizeof(int));
                printf("sacando el %d de ord 1 y poniendolo en ord2",tope);
                N
                ponerEnPila(&ord2,&tope,sizeof(int));
                verTope(&ord1,&tope,sizeof(int));
            }
        printf("poniendo el %d en ord1",*v);
        N
            ponerEnPila(&ord1,v,sizeof(int));
        }
        else if((pilaVacia(&ord2) || tope>*v) && !pilaLlena(&ord2,sizeof(int)))
        {
            while(!pilaVacia(&ord2) && tope>*v )
            {
                sacarDePila(&ord2,&tope,sizeof(int));
                printf("sacando el %d de ord 2 y poniendolo en ord1",tope);
                N
                ponerEnPila(&ord1,&tope,sizeof(int));
                verTope(&ord2,&tope,sizeof(int));
            }
            printf("poniendo el %d en ord2",*v);
            N
            ponerEnPila(&ord2,v,sizeof(int));
        }
        verTope(&ord1,&tope,sizeof(int));
        v++;
        i++;
    }

    while(sacarDePila(&ord1,&tope,sizeof(int)))
    {
        ponerEnPila(&ord2,&tope,sizeof(int));
    }

    v = vector;
    for(i=0;i<TAM;i++)
    {
        sacarDePila(&ord2,&tope,sizeof(int));
        *v=tope;
        v++;
        printf("%d ",vector[i]);///muestro el vector cargado
    }

    return 0;
}
