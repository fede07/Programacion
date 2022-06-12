#include <stdio.h>
#include <stdlib.h>

int abrirArchivo(FILE** archivo, char* nombre, char* modo)
{
    *archivo=fopen(nombre, modo);
    return (archivo)?1:0;
}
