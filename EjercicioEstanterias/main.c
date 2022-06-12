#include <stdio.h>
#include <stdlib.h>

#define COL 2
#define FILMOD 3
#define FILMAT 2
#define FILRES FILMAT*FILMOD

void mostrarMatriz(int mat[][COL], int filas, int columnas);
void multiplicarContMat(int *matriz1, int *matriz2, int* matrizRes , int columnas, int filasmod, int filasmat, int filasres);

int main()
{
    int matModelos[][COL]={{1000,8000},{8000,6000},{4000,6000}};
    int matMateriales[][COL]={{16,6},{12,4}};
    int matResultado[FILRES][COL]={0};
    int *matMod=&matModelos[0][0];
    int *matMat=&matMateriales[0][0];
    int *matRes=&matResultado[0][0];

    printf("\n");
    mostrarMatriz(matModelos,FILMOD,COL);
    printf("\n");
    mostrarMatriz(matMateriales,FILMAT,COL);
    printf("\n");
    multiplicarContMat(matMod,matMat,matRes,COL,FILMOD,FILMAT,FILRES);
    mostrarMatriz(matResultado,FILRES,COL);
}

void mostrarMatriz(int mat[][COL], int filas, int columnas)
{
    int i, j;
    for(i=0; i<filas; i++)
    {
       for(j=0; j<columnas; j++)
        {
            printf("\t[%d][%d]=%d",i,j,mat[i][j]);
        }
        printf("\n");
    }
}

void multiplicarContMat(int *matriz1, int *matriz2, int* matrizRes , int columnas, int filasmod, int filasmat, int filasres)
{
    int i,j;

    for(i=0;i<filasres;i++)
    {
        for(j=0;j<columnas;j++)
        {
            *matrizRes=(*matriz1)*(*matriz2);
            matrizRes++;
            matriz2++;;
        }
        matriz1++;
        if(i&&!((i+1)%2))
        {
             matriz2-=(filasmat*columnas);
        }
    }
}
