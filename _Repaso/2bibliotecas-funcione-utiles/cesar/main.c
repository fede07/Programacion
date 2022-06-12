#include <stdio.h>
#include <stdlib.h>
#include "cesar.h"

int main()
{
    int desp;///desplazamiento

    char cadena1[60]="pepito is love 123";
    printf("\nCadena original: *%s*", cadena1);
    printf("\nKey: ");
    scanf("%d", &desp);
//    fflush(stdin);
//    printf("\nLetra: ");
//    scanf("%c", &letra);

    printf("\nCadena codificada: *%s*", codificarACesar(cadena1,desp));
    printf("\nCadena decodificada: *%s*", decodificarCesar(cadena1,desp));

    return 0;

}


//#define NOMBREARCHIN "citasOfuscado.txt"
//#define NOMBREARCHOUT "citasDecifrado.txt"
//#define TAM 90
//#define DESP -3
//int main()
//{
//    char cadena[TAM];
//    char codigo[]="acegiknpsuvz";
//    FILE* pf;
//    FILE* pfSalida;
//
//    pf=fopen(NOMBREARCHIN, "rt");
//    pfSalida=fopen(NOMBREARCHOUT, "wt");
//
//    if(!pf)
//    {
//        printf("No se pudo abrir el archivo para lectura");
//        return 100;
//    }
//
//    if(!pfSalida)
//    {
//        printf("No se pudo abrir el archivo para escritura");
//        fclose(pf);
//        return 200;
//    }
//
//    decodificar(cadena, pf, pfSalida, codigo, DESP, TAM);
//
//    fclose(pf);
//    fclose(pfSalida);
//    return 0;
//}
