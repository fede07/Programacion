#include <stdio.h>
#include <stdlib.h>
#include "zMatrizDinamica.h"

int** crearMatrizEnteros2(unsigned f, unsigned c)
{
    int i=0,j;
    int** iniM;
    int** m = malloc(sizeof(int*)*f); ///Asigna memoria a "columna" de punteros

    if(!m)
        return NULL;
    iniM = m;///necesito iniM para devolver la posicion inicial de la matriz

    *m = malloc(sizeof(int)*c);
    if(!*m)
    {
        free (m);///si no hay memoria disponible para crear la primer fila, libero la columna de punteros
        return NULL;
    }

    while(i<f && *m)
    {
        for(j=0;j<c;j++)
        {
            (*m)[j]=i+j;///cargo la matriz
        }
        m++;///paso a la siguiente posicion de la columna de punteros, para crear una nueva fila
        i++;


        if(i<f)///pido memoria para nuevas filas solamente si lo necesito
            *m = malloc(sizeof(int)*c);
    }

    if(!*m)
    {
        for(i=i;i>0;i--)///asi se libera la memoria?
            {
                m--;///como no se pudo reservar memoria para la posicion actual de m hay que ir a la anterior
                free(*m);///y liberar la fila de datos a la que apuntaba
            }
            free(m);///despues de eso, liberar el vector de punteros
            return NULL;
    }

    return iniM;
}


void mostrarMat(int ** matrizP, int f, int c)
{
    int i, j;

    for(i=0;i<f;i++)
    {
        printf("FILA %d:",i);
        for(j=0;j<c;j++)
        {
            printf("%5d",matrizP[i][j]);
        }
        printf("\n");
    }
}

void liberarMem (int **m, int f)
{
    int i,j;
    printf("%p",*m);
    m+=(f-1);///me paro en el puntero a la ultima fila de datos
    for(i=f;i>0;i--)
    {
        printf("\nantes de liberar\n");
        for(j=0;j<5;j++)
            printf("%d |",(*m)[j]);

        free(*m);///libero la fila de datos

        printf("\n\ndespues de liberar\n");
        for(j=0;j<5;j++)
            printf("%d |",(*m)[j]);

        m--;///muevo al puntero de la columna anterior
        printf("\n");
    }
    m++;///es necesario porque lo ultimo que hace el for antes de salir es un m--
    free(m);
}





