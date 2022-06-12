#include <stdio.h>
#include <stdlib.h>
#include "codificacion.h"

int main()
{
    int desp;
    char cadena1[60] = "Mi mensaje secreto es: AaZzBbXx 0978 Pepito.";
//    char cadena2[60];
//    char letra;
    printf("\nCadena original: *%s*", cadena1);
//    printf("\nCadena original: ");
//    gets(cadena1);
    printf("\nKey: ");
    scanf("%d", &desp);
    fflush(stdin);
//    printf("\nLetra: ");
//    scanf("%c", &letra);
    printf("\nCadena codificada: *%s*", codificarACesar(cadena1,desp));
    printf("\nCadena decodificada: *%s*", decodificarCesar(cadena1,desp));
//    printf("\nCadena codificada con letra %c: *%s*",letra, codificarACesarCondicionado(cadena1,letra,desp));
//    printf("\nCadena decodificada con letra %c: *%s*",letra, decodificarCesarCondicionado(cadena1,letra,desp));

    return 0;

}
