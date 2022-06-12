#include <stdio.h>
#include <stdlib.h>
#include "memDinamica.h"
#include <string.h>

#define TAM 5

int main()
{
    char* cadena1;
    char cadena2[] = " mundo";
    char* cadenaF;

    cadena1 = (char*) malloc(TAM);

    strcpy(cadena1, "Hola");

    cadenaF = mconcat(cadena1,cadena2);

    printf("*%s*", cadenaF);

    free(cadenaF);

    return 0;
}
