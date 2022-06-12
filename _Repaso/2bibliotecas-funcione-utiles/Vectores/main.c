#include <stdio.h>
#include <stdlib.h>

#include "vectores.h"

#define TAM 7

#define N printf("\n");

int main()
{
    int vector[TAM]={1,1,1,4,1},
    cantElem=5;
    int i;


    printf("cant elem %d",cantElem);
    N
    eliminarTodaAparicion(vector,4,&cantElem);
    for(i=0;i<cantElem;i++)
    {
        printf("%d ",vector[i]);
    }
    N
    printf("cant elem %d",cantElem);


    return 0;
}
