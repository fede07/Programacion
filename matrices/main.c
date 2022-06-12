#include <stdio.h>
#include <stdlib.h>
#include "matrices.h"

int main()
{
//    int i, j;
//    int mat[FIL][COL];
//    int mat1[FIL][COL]={0};
//    int mat2[FIL][COL]={{0}};
//    int mat3[FIL][COL]={{1,2},{3,4,5,6,7,8}};
    int mat4[][COL]= {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}};
//    int mat4[][COL]= {{1,2,3,4,5,99},{6,7,8,9,10,98},{11,12,13,14,15,97},{16,17,18,19,20,96},{21,22,23,24,25,95},{26,27,28,29,30,94}};
//    int mat5[FIL][]={{1,2,3,4},{5,6,7,8}};

//    printf("\nDireccion de mat: %p",mat4);
//    printf("\nDireccion de mat: %p",&mat4);
//    printf("\nDireccion de mat: %p",&mat4[0]);
//    printf("\nDireccion de mat: %p",mat4[0]);
//    printf("\nDireccion de mat: %p",mat4[1]);
//    printf("\nDireccion de mat: %p",mat4[5]);
//    printf("\nDireccion de mat: %p",*mat4);
    printf("\nMatriz:\n");
    mostrarMatriz(mat4, FIL, COL);
    printf("\nDiagonal:\n");
    mostrarDiagonal(mat4, FIL);
    printf("\nTriangulo Superior sin diagonal:\n");
    mostrarTrianguloSupSinDiagPrin(mat4, FIL);
    printf("\nTranspuesta:\n");
    mostrarMatrizTranspuesta(mat4, FIL);
    printf("\nDiagonal Secundaria\n");
    mostrarDiagonalSecundaria(mat4, FIL);
    printf("\nTriangulo Superior con diagonal:\n");
    mostrarTrianguloSupConDiagPrin(mat4, FIL);
    printf("\nTriangulo Inferior sin diagonal:\n");
    mostrarTrianguloInfSinDiagPrin(mat4, FIL);
    printf("\nTriangulo Inferior con diagonal:\n");
    mostrarTrianguloInfConDiagPrin(mat4, FIL);
    printf("\nTriangulo Superior respecto a la DS:\n");
    mostrarTrianguloSupSinDiagSec(mat4, FIL);
    printf("\nTriangulo Superior respecto a la DS con Diag:\n");
    mostrarTrianguloSupConDiagSec(mat4, FIL);
    printf("\nTriangulo Inferior respecto a la DS:\n");
    mostrarTrianguloInfSinDiagSec(mat4, FIL);
    printf("\nTriangulo Inferior respecto a la DS con Diag:\n");
    mostrarTrianguloInfConDiagSec(mat4, FIL);

}
