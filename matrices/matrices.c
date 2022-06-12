#include "matrices.h"
#include <stdio.h>

void mostrarMatriz(int mat[][COL], int filas, int columnas)
{
    int i, j;
    for(i=0; i<filas; i++)
    {
       for(j=0; j<columnas; j++)
        {
            printf("\t[%d][%d]%d0",i,j,mat[i][j]);
        }
        printf("\n");
    }
}

void mostrarDiagonal(int mat[][COL], int filas)
{
    int i;
    for(i=0; i<filas; i++)
    {
        printf("\t%d\n",mat[i][i]);
    }
}

void mostrarTrianguloSupSinDiagPrin(int matriz[][COL],int tam)
{
    int i, j;
    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            printf("\t%d",matriz[i][j]);
        }
        printf("\n");
    }
}

void mostrarMatrizTranspuesta(int mat[][COL], int tam)
{
    int i, j;
    for(j=0; j<tam; j++)
    {
        for(i=0; i<tam; i++)
        {
            printf("\t%d",mat[i][j]);
        }
        printf("\n");
    }
}

void mostrarDiagonalSecundaria(int matriz[][COL],int tam)
{
    int i, j=0;
    for(i=tam-1; i>=0; i--, j++)
    {
        printf("\t%d\n",matriz[i][j]);
    }
}

void mostrarTrianguloSupConDiagPrin(int matriz[][COL], int tam)
{
    int i, j;
    for(i=0; i<tam; i++)
    {
        for(j=i; j<tam; j++)
        {
            printf("\t%d",matriz[i][j]);
        }
        printf("\n");
    }
}

void mostrarTrianguloInfSinDiagPrin(int matriz[][COL], int tam)
{
    int i, j;
    for(i=1; i<tam; i++)
    {
        for(j=0; j<i; j++)
        {
            printf("\t%d",matriz[i][j]);
        }
        printf("\n");
    }
}

void mostrarTrianguloInfConDiagPrin(int matriz[][COL], int tam)
{
    int i, j;
    for(i=0; i<tam; i++)
    {
        for(j=0; j<=i; j++)
        {
            printf("\t%d",matriz[i][j]);
        }
        printf("\n");
    }
}

void mostrarTrianguloSupSinDiagSec(int matriz[][COL], int tam) ///5)TS con respecto a la DS, sin diagonal.
{
    int i, j;
    for(i=0; i<tam-1; i++)
    {
        for(j=0; j<tam-i-1; j++)
        {
            printf("\t%d",matriz[i][j]);
        }
        printf("\n");
    }
}

void mostrarTrianguloSupConDiagSec(int matriz[][COL], int tam)
{
    int i, j;
    for(i=0; i<tam; i++)
    {
        for(j=0; j<tam-i; j++)
        {
            printf("\t%d",matriz[i][j]);
        }
        printf("\n");
    }
}

void mostrarTrianguloInfSinDiagSec(int matriz[][COL], int tam)
{
    int i, j;
    for(i=1; i<tam; i++)
    {
//        for(k=1;k<tam-i;k++)
//            printf("\t");
        for(j=tam-1; j>=tam-i; j--)
        {
            printf("\t%d",matriz[i][j]);
        }
        printf("\n");
    }
}

void mostrarTrianguloInfConDiagSec(int matriz[][COL], int tam)
{
    int i, j, k;
    for(i=0; i<tam; i++)
    {
        for(k=0;k<tam-i;k++)
           printf("\t");
        for(j=tam-i-1;j<tam;j++)
        {
            printf("\t%d",matriz[i][j]);
        }
        printf("\n");
    }
}

int buscarElemento (int *mat, int i, int j, int columnas)
{
    mat+= ((i*columnas)+j);
    return *mat;
}
