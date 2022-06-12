#include <stdio.h>
#include "matrices.h"

#define N printf("%c PEPITO ES HERE %c\n",1,1);

///TRABAJO LA MATRIZ CON [FILA][COLUMNA] EN FUNCION
void llenarMatrizConsecutiva(int matriz[][COLM],int fila, int colum)
{
    int i,j, contador=1;
    for(i=0; i<fila; i++)
        for(j=0; j<colum; j++)
        {
            matriz[i][j]=contador;
            contador++;
        }
}

void mostrarMatriz(int matriz[][COLM], int fila, int colum)
{
    int i,j;
    for(i=0; i<fila; i++)
    {
        for(j=0; j<colum; j++)
            printf("%d\t",matriz[i][j]);
        printf("\n");
    }
}


int mostrarDiagPrincipal (int matriz[][COLM],int fila, int colum)
///muestro solo los valores con col==fila, con [i][i]
{
    int i;
    if(fila==colum)
    {
        for(i=0; i<fila; i++)
        {
            ponerEspacios(i);
            printf("%d\n",matriz[i][i]);
        }
    }
    else
        return 0;
    return 1;
}
int mostrarDiagSecundaria(int matriz[][COLM],int fila, int colum)///[j][i]
{
    int i,j;
    if(fila==colum)
    {
        i=0;
        ///recorre desde fila 0 y ultima columna, aumentando filas y restando columnas
        for(j=colum-1; j>=0; j--)
        {
            ponerEspacios(j);
            printf("%d\n",matriz[i][j]);
            i++;
        }
    }
    else
        return 0;
    return 1;
}

int mostrarTriangInfSinDPri(int matriz[][COLM], int fila, int colum)///sin diagonal p
{
    int i,j;
    printf("mostrarTriangInfSinDPri");
    N
    if(fila==colum)
    {
        j=0;
        for(i=1; i<colum; i++)///i=1 para ignorar diag principal
        {
            for(j=0; j<i; j++)///empieza en 1,0
            {
                printf("%d\t",matriz[i][j]);
            }
            N
        }
    }
    else
        return 0;
    return 1;
}

int mostrarTriangInfConDPri(int matriz[][COLM], int fila, int colum)///con diag pri
{
    int i,j;
    printf("mostrarTriangInfConDPri");
    N
    if(fila==colum)
    {
        j=0;
        for(i=0; i<colum; i++)///i=0 para incluir diag principal
        {
            for(j=0; j<=i; j++)///empieza en 0,0
            {
                printf("%d\t",matriz[i][j]);
            }
            N
        }
    }
    else
        return 0;
    return 1;
}

int mostrarTriangSupSinDPri(int matriz[][COLM], int fila, int colum)///sin diag principal
{
    int i,j;
    printf("mostrarTriangSupSinDPri");
    N
    if(fila==colum)
    {
        for(i=0; i<fila; i++)///
        {
            ponerEspacios(i+1);
            for(j=i+1; j<colum; j++)///arranca en j=1 para saltearse la diag principal
                ///empieza en 0,1
            {
                printf("%d\t",matriz[i][j]);
            }
            N
        }

    }
    else
        return 0;
    return 1;
}
int mostrarTriangSupConDPri(int matriz[][COLM], int fila, int colum)///con diag principal
{
    int i,j;
    printf("mostrarTriangSupConDPri");
    N
    if(fila==colum)
    {
        for(i=0; i<fila; i++)
        {
            ponerEspacios(i);
            for(j=i; j<colum; j++)///arranca en j=0 para incluir la diagonal principal
                ///empieza en 0,0
            {
                printf("%d\t",matriz[i][j]);
            }

            N
        }
    }
    else
        return 0;
    return 1;
}

int mostrarTiangSupSinDSec(int matriz[][COLM], int fila, int colum)///sin diag secundaria
{
    int i,j;
    printf("mostrarTiangSupSinDSec");
    N
    if(fila==colum)
    {
        for(i=0; i<fila; i++)
        {
            for(j=0; j<colum-i-1; j++)
            {
                printf("%d\t",matriz[i][j]);
            }
            N
        }
    }
    else
        return 0;
    return 1;
}
int mostrarTiangSupConDSec(int matriz[][COLM], int fila, int colum)///con diag secundaria
{
    int i,j;
    printf("mostrarTiangSupConDSec");
    N
    if(fila==colum)
    {
        for(i=0; i<fila; i++)
        {
            for(j=0; j<colum-i; j++)
            {
                printf("%d\t",matriz[i][j]);
            }
            N
        }
    }
    else
        return 0;
    return 1;
}
///Funciones para ver los calzones (triangulos t1,t2,t3,t4 en la matriz
int triagT1topSinDiagPri(int matriz[][COLM], int fila, int colum)///sin diagonales (superior)

{
    int i,j,mitad;
    printf("triagT1topSinDiagPri");
    N
    if(fila==colum)
    {
        mitad = fila/2;
        for(i=0; i<mitad; i++)
        {
            ponerEspacios(i+1);
            for(j=i+1; j<colum-i-1; j++)
            {
                printf("%d\t",matriz[i][j]);
            }
            N
        }
        return 1;
    }
    return 0;
}

int triagT1topConDiags(int matriz[][COLM], int fila, int colum)///con diagonales (superior)

{
    int i,j,mitad;
    printf("triagT1topConDiags");
    N
    if(fila==colum)
    {
        mitad = fila/2;
        for(i=0; i<=mitad; i++)
        {
            ponerEspacios(i);
            for(j=i; j<colum-i; j++)
            {
                printf("%d\t",matriz[i][j]);
            }
            N
        }
        return 1;
    }
    return 0;
}

int triagT2rightSinDiags(int matriz[][COLM], int fila, int colum)///sin diagonales (derecha)
{
    int i, j, mitad;
    printf("triagT2rightSinDiags");
    N
    if(colum == fila)
    {
        mitad = colum/2;
        for(i=1; i<mitad; i++)
        {
            ponerEspacios(colum-i);
            for(j=colum-i; j<colum; j++)
            {
                printf("%d\t",matriz[i][j]);
            }
            N
        }
        for(i=mitad; i<fila-1; i++)
        {
            ponerEspacios(i+1);
            for(j=i+1; j<colum; j++)
            {
                printf("%d\t",matriz[i][j]);
            }
            N
        }
    }
    else
        return 0;

    return 1;
}

int triagT2rightConDiags(int matriz[][COLM], int fila, int colum)///sin diagonales (derecha)
{
    int i, j, mitad;
    printf("triagT2rightConDiags");
    N
    if(colum == fila)
    {
        mitad = colum/2;
        for(i=0; i<mitad; i++)
        {
            ponerEspacios(colum-i);
            for(j=colum-i-1; j<colum; j++)
            {
                printf("%d\t",matriz[i][j]);
            }
            N
        }
        for(i=mitad; i<fila; i++)
        {
            ponerEspacios(i+1);
            for(j=i; j<colum; j++)
            {
                printf("%d\t",matriz[i][j]);
            }
            N
        }
    }
    else
        return 0;

    return 1;
}

int triagT3bottomSinDiags(int matriz[][COLM], int fila, int colum)
{
    int i, j, mitad;
    printf("triagT3bottomSinDiags");
    N
    if(colum == fila)
    {
        mitad = fila/2;
        for(i=mitad+1; i<fila; i++)
        {
            ponerEspacios(colum-i);
            for(j=colum-i; j<i; j++)
            {
                printf("%d\t",matriz[i][j]);
            }
            N
        }
    }
    else
        return 0;
    return 1;
}

int triagT3bottomConDiags(int matriz[][COLM], int fila, int colum)
{
    int i, j, mitad;
    printf("triagT3bottomSinDiags");
    N
    if(colum == fila)
    {
        mitad = fila/2;
        for(i=mitad; i<fila; i++)
        {
            ponerEspacios(colum-i);
            for(j=colum-i-1; j<=i; j++)
            {
                printf("%d\t",matriz[i][j]);
            }
            N
        }
    }
    else
        return 0;
    return 1;
}

int triagT4leftSinDiags(int matriz[][COLM], int fila, int colum)
{
    int i, j, mitad;
    printf("triagT4bottomSinDiags");
    N
    if(colum == fila)
    {
        mitad = fila/2;
        for(i=1; i<mitad; i++)
        {
            for(j=0; j<i; j++)
            {
                printf("%d\t",matriz[i][j]);
            }
            N
        }

        for(i=mitad; i<fila; i++)
        {
            for(j=0; j<colum-i-1; j++)
            {
                printf("%d\t",matriz[i][j]);
            }
            N
        }

    }
    else
        return 0;

    return 1;
}

int triagT4leftConDiags(int matriz[][COLM], int fila, int colum)
{
    int i, j, mitad;
    printf("triagT4bottomConDiags");
    N
    if(colum == fila)
    {
        mitad = fila/2;
        for(i=0; i<mitad; i++)
        {
            for(j=0; j<=i; j++)
            {
                printf("%d\t",matriz[i][j]);
            }
            N
        }

        for(i=mitad; i<fila; i++)
        {
            for(j=0; j<colum-i; j++)
            {
                printf("%d\t",matriz[i][j]);
            }
            N
        }

    }
    else
        return 0;

    return 1;
}

int rotarMatriz180(int matriz[][COLM], int fila, int colum)
{
    int i,j, temp,mitad=fila/2;
    for(i=0; i<mitad; i++) //si no funciono AGREGALE LA MITAD GEGE
    {
        for(j=0; j<colum; j++)
        {
            temp=matriz[i][j];
            matriz[i][j]=matriz[fila-i-1][colum-j-1];
            matriz[fila-i-1][colum-j-1]=temp;
        }
    }
    if(fila%2==1)
    {
        for(j=0; j<colum-j-1; j++)
        {
            temp=matriz[mitad][j];
            matriz[mitad][j]=matriz[mitad][colum-j-1];
            matriz[mitad][colum-j-1]=temp;
        }
    }
    return 1;
}

int esMatrizIdentidad(int matriz[][COLM],int filas)
{
    int i, j, identidad = 1;
    if(filas==COLM)
    {
        i=0;
        while(identidad==1 && i<filas)
        {
            j=i+1;
            if(matriz[i][i]!=1)
                identidad = 0;

            while(identidad==1 && j<COLM)
            {
                if(matriz[i][j]!=0 || matriz[j][i]!=0)
                    identidad = 0;
                j++;
            }
            i++;
        }
    }
    return identidad;
}

int esSimetrica (int mat[][COLM], int filas, int colum)
{
    int i,j, simetrica = 0;
    if(filas == colum)
    {
        i=0;
        simetrica = 1;
        while(simetrica==1 && i<filas)
        {
            j=i+1;
            while(j<colum && simetrica==1)
            {
                if(mat[i][j]!=mat[j][i])
                    simetrica = 0;
                j++;
            }
            i++;
        }
    }
    return simetrica;
}

int productoMatricial(int mat1[][COLM],int mat2[][COLM], int filasM1, int filasM2)  //Funciona ʕっ•ᴥ•ʔっ
{
    int i, j, k, resTemp;
    printf("productoMatricial");
    N
    if(COLM == filasM2)
    {
        for(k=0; k<filasM1; k++)
        {
            for(i=0; i<COLM; i++)
            {
                resTemp=0;
                for(j=0; j<filasM2; j++)
                {
                    resTemp += mat1[k][j]*mat2[j][i];
                }
                printf("%d\t",resTemp);
            }
        }
    }
    else
        return 0;

    return 1;
}

void matrizTranpuesta (int mat[][COLM],int fila, int colum)
{
    int i, j;
    for(i=0; i<colum; i++)
    {
        for(j=0; j<fila; j++)
        {
            printf("%d\t",mat[j][i]);
        }
        N
    }
}

void mostrarSubMatriz (int matriz[][COLM], int fila, int colum, int x, int y)
{
    int i, j;
    for(i=(x-1); i<fila-x+1; i++)
    {
        for(j=(y-1); j<colum-y+1; j++)
            printf("%d\t",matriz[i][j]);
        printf("\n");
    }

}

void matricesDadoIJ (int mat[][COLM],int f,int x, int y)
{
    int i,j;
///superior izquierda
    for(i=0; i<y; i++)
    {
        for(j=0; j<x; j++)
        {
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }

///superior derecha
    for(i=0; i<y; i++)
    {
        for(j=x; j<f-1; j++)
        {
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }

///inferior izquierda
    for(i=y; i<f; i++)
    {
        for(j=0; j<x; j++)
        {
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
///inferior derecha
    for(i=y; i<f; i++)
    {
        for(j=x; j<f-1; j++)
        {
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }

}


void ponerEspacios(int cant)
{
    int veces=0;
    while(veces<cant&&cant!=0)
    {
        printf("\t");
        veces++;
    }
}
