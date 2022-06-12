#include <stdio.h>
#include <stdlib.h>
#include "punteros.h"

int main()
{
    int x = 2, y = 10;
    mostrar(x,y);//2 10
    intercambio1(x,y);
    mostrar(x,y); // 10 2
    intercambio2(&x,&y);
    mostrar(x,y); // 10 2
    intercambio3(&x,&y);
    mostrar(x,y); // 2 10
}
