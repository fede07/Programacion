#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lotes.h"


int crearLoteVar()
{
    char doc[TAM][LARGO] =
    {
        "Pepito Feliz|12345678|D|99.999\n",
        "Pepita Rica|420|R|400\n",
        "Pepito Vacio||V|0\n",
        "Feliz|Pepito|D|99.999\n",
        "Mario Feliz|1234|D|yo\n",
        "Pepito Soltero|65|so|99.999\n",
        "15613456|23456789|A|10\n",
        "Pepito Triste",
    };
    int i;
    FILE * pf;
    pf=fopen(NOMBREARCHLOTE,"wt");
    if(!pf)
    {
        return ERROR_ARCH;
    }
    for(i=0; i<TAM; i++)
    {
        fputs(doc[i],pf);
    }

    fclose(pf);

    return TODO_OK;
}

int abrirArchivo(FILE** archivo, char* nombre, char* modo)
{
    *archivo=fopen(nombre, modo);
    return (archivo)?1:0;
}

int parseo(char* cadena, t_alumno *alumno)
{
    char* posicion;
    posicion=strrchr(cadena, '|');
    if(posicion)
    {
        sscanf(posicion+1, "%f", &alumno->promedio);
        *posicion='\0';
    }
    else
        return 0;
    posicion=strrchr(cadena, '|');
    if(posicion)
    {
        sscanf(posicion+1, "%c", &alumno->dpto);
        *posicion='\0';
    }
    else
        return 0;
    posicion=strrchr(cadena, '|');
    if(posicion)
    {
        sscanf(posicion+1, "%d", &alumno->dni);
        *posicion='\0';
    }
    else
        return 0;
    if(posicion)
    {
        strcpy(alumno->nyap, cadena);
    }
    else
        return 0;
    return 1;
}
