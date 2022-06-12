#include <stdio.h>
#include "punteros.h"

void mostrar(int x, int y)
{
    printf("\nNota del alumno %d: %d",x, y);
}

void intercambio1(int x, int y)
{
    int aux;
    aux = x;
    x = y;
    y = aux;
}

void intercambio2(int *x, int *y)
{
    int *aux;
    aux = x;
    x = y;
    y = aux;
}

void intercambio3(int *x, int *y)
{
    int aux;
    aux = *x;
    *x = *y;
    *y = aux;
}


