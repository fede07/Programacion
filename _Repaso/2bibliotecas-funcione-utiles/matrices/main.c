#include <stdio.h>
#include <stdlib.h>
#include "matrices.h"

#define N printf("\n");


#define SEPARADOR  printf("\n---------------------------------------------\n");

///#define FILA 5
///#define COLM 5

int main()
{
    int matrizInt[FILA][COLM];

    int mat[5][COLM]= {{1,2,3,4,5},
                    {2,1,7,5,3},
                    {1,1,5,1,1},
                    {0,1,1,1,1},
                    {0,1,0,0,1},
                    };

    llenarMatrizConsecutiva(matrizInt,FILA,COLM);
    puts("\t***MATRIZ DE ENTEROS***");
    mostrarMatriz(matrizInt,FILA,COLM);
    N

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
/// rotarMatriz180(matrizInt,FILA,COLM);
/// printf("%d",esSimetrica(mat,5,5));
///productoMatricial(matrizInt,mat,FILA,5);
mostrarSubMatriz(matrizInt,FILA,COLM,1,2);

///matrizTranpuesta (matrizInt,FILA,COLM);



/*    printf("matriz identidad %d",esMatrizIdentidad(mat,5));
printf("matriz identidad %d",esMatrizIdentidad(matrizInt,FILA));*/


    return 0;
}
