#include <stdio.h>
#include <stdlib.h>
#include "matrices2.h"

#define N printf("\n");


#define SEPARADOR  printf("\n---------------------------------------------\n");

///#define FILA 5
///#define COLM 5

int main()
{
    int matrizInt[FILA][COLM];
    /*int mat[5][5]= {{1,0,0,0,0},
                    {0,1,0,0,0},
                    {0,0,5,0,0},
                    {0,0,0,1,0},
                    {0,0,0,0,1},
                    };*/

    llenarMatrizConsecutiva(matrizInt,FILA,COLM);
    puts("\t***MATRIZ DE ENTEROS***");
    mostrarMatriz(matrizInt,FILA,COLM);
    N

    rotarMatriz(matrizInt, FILA, COLM);
    mostrarMatriz(matrizInt,FILA,COLM);
    N

    mostrarTriangInfConDSec_2(matrizInt, FILA, COLM);

/// mostrarTriangInfSinDPri(matrizInt,FILA,COLM);
/// mostrarTriangInfConDPri(matrizInt,FILA,COLM);
/// mostrarTriangSupSinDPri(matrizInt,FILA,COLM);
/// mostrarTriangSupConDPri(matrizInt,FILA,COLM);
/// mostrarTiangSupSinDSec(matrizInt,FILA,COLM);
/// mostrarTiangSupConDSec(matrizInt,FILA,COLM);
/// triagT1topSinDiagPri(matrizInt,FILA,COLM);
/// triagT1topConDiags(matrizInt,FILA,COLM);
/// triagT2rightSinDiags(matrizInt,FILA,COLM);
/// triagT2rightConDiags(matrizInt,FILA,COLM);
/// triagT3bottomSinDiags(matrizInt,FILA,COLM);
/// triagT3bottomConDiags(matrizInt,FILA,COLM);
/// triagT4leftSinDiags(matrizInt,FILA,COLM);
/// triagT4leftConDiags(matrizInt,FILA,COLM);



/*    printf("matriz identidad %d",esMatrizIdentidad(mat,5));
printf("matriz identidad %d",esMatrizIdentidad(matrizInt,FILA));*/


    return 0;
}
