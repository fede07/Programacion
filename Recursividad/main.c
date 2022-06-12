#include <stdio.h>
#include <stdlib.h>
#include "recursividad.h"

int main()
{
    unsigned numero = 5;
    char cadena [5]="hola";
    printf("Factorial de %d = %lu\n",numero,factorialRec(numero));
    printf("Cantidad de letras en <%s>: %d\n",cadena,strlenRec(cadena));
    return 0;
}
