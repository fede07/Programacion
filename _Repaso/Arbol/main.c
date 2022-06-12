#include <stdio.h>
#include <stdlib.h>
#include "arbol.h"

int compararInt(const void * a, const void * b);
void mostrarEntero(const void* a);
int main()
{
///arbol dibujado
//int vec[]={100,120,135,110,100,140,130,75,80,50};

///arbol balanceado h=4
//int vec[]={20, 0, 40, 10, -10, 30, 50, -15, -5, 5 ,15, 25, 35, 45, 55,-17, -12, -7, -2, 2 ,7 ,12, 17,22,27, 32, 37, 42, 47, 52, 57};

///arbol balanceado
//int vec[]={10,20, 0 ,15, 25, -5, 5};

///tiene nodos extra en las puntas
int vec[]={10,20, 0 ,15, 24, -4, 5,-6,-7,-5,-3,4,6,14,16,23,26,27,25};

    int i;
    int nivel = 2;
  ///  int nivel = 999;
    t_arbol arbolito;
    crearArbol(&arbolito);
    for(i=0;i<sizeof(vec)/sizeof(int);i++)
    {
        insertarArbol(&arbolito,&vec[i],sizeof(int),compararInt);
    }

    rotar90g_i(&arbolito,mostrarEntero);
    printf("Cantidad de nodos desde n%d: %d\n", nivel, contarNodosDesdeN(&arbolito, nivel));
    puts("--------------------------------------");
    talar(&arbolito);
    rotar90g_i(&arbolito,mostrarEntero);



//printf("resultado %d",balanceado(&arbolito));
//printf("resultado %d",nivelComp(&arbolito));

    return 0;
}

int compararInt(const void * a, const void * b)
{
    return *(int*)a-*(int*)b;
}

void mostrarEntero(const void* a)
{
    printf("%d\n",*((int*)a));
}
