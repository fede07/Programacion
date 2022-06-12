#include <stdio.h>
#include <stdlib.h>
#include "zMatrizDinamica.h"

int main()
{

    int f = 5, c = 5;
    int **matrizP;

    matrizP = crearMatrizEnteros2(f,c);

    mostrarMat(matrizP,f,c);

    liberarMem (matrizP,f);

    printf("\n");
    printf("\n");

    ///mostrarMat(matrizP,f,c);

    return 0;
}
