#include <stdio.h>
#include <stdlib.h>
#include "normalizar.h"


int main()
{
    char cadena1[60] = "     Hay       esPacios    dE    mAs            ";
    char cadena2[60] = "   pRimER   leTra    dE  cAda    paLaBrA a MaYuS    ";
    char cadena3[60] = "      pRIMER    Letra  A         MayuSCULa    ";

    printf("\nCadena original: *%s*", cadena1);
    printf("\nCadena sin espacios: *%s*", borrarEspaciosExtra(cadena1));

    printf("\nCadena original: *%s*", cadena2);
    printf("\nCadena sin espacios: *%s*", primerLetraDeCadaMayus(cadena2));

    printf("\nCadena original: *%s*", cadena3);
    printf("\nCadena sin espacios: *%s*", primerLetraMayus(cadena3));


    return 0;


//    int fact=5, result=1, absoluto=-10, entero;
//    float decimal=10.8;
//    FACTORIAL(fact, result);
//    ABS(absoluto);
//    PARTEENTERA(decimal, entero);
//    printf("\nFactorial: %d",result);
//    printf("\nAbsoluto: %d",absoluto);
//    printf("\nDecimal: %f, Entero: %d",decimal, entero);
    return 0;
}
