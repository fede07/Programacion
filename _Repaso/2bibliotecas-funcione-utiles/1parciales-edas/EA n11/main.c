#include <stdio.h>
#include <stdlib.h>
#include "n11.h"



int main()
{
//    char cadena[100]="normannormannornorman";
//    char busqueda[20]="norman";
    t_pila pila;
    FILE * pLect;

//    printf("repeticiones %d",sinRepeticion(cadena,busqueda));
//    N
//
//    int matrizInt[FILA][COLM];
//    llenarMatrizConsecutiva(matrizInt,FILA,COLM);
//    puts("\t***MATRIZ DE ENTEROS***");
//    mostrarMatriz(matrizInt,FILA,COLM);
//    N
//
//    rotarMatriz180(matrizInt,FILA,COLM);
//    printf("******************************\n");
//    mostrarMatriz(matrizInt,FILA,COLM);
//    N
//    mostrarTiangInfConDSec(matrizInt,FILA,COLM);

    pLect = fopen("datos.txt","rt");
    if(!pLect)
    {
        printf("error apertura archivo");
        return 1;
    }
    crearPila(&pila);
    leerYordenarArchivo(pLect,&pila,&comparaVerso);

    ///falta escribir el archivo / mostrar resultado por pantalla
    escribirArchivo (&pila);

    fclose(pLect);
    return 0;
}
