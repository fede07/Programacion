#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "Generico_qsort.h"

int comparInt (const void *elem1, const void *elem2)
{
    return *((int*)(elem1)) - *((int*)(elem2));
}

int comparChar (const void *elem1, const void *elem2)
{
    return *((char*)(elem1)) - *((char*)(elem2));
}

int comparEmp (const void *elem1, const void *elem2)
{
    int comparacion = strcmp( ((t_emp*)(elem1))->apyn,((t_emp*)(elem2))->apyn );
    if( comparacion == 0)///mismo nombre
    {
        return (((t_emp*)(elem1))->dni - ((t_emp*)(elem2))->dni);
    }
    return comparacion;
}


void intercambio(void *elem1, void *elem2, size_t size) ///preguntar
{
    int i;
    char aux;

    for(i=0; i<size; i++)
    {
        ///el cambio de datos se hace byte a byte, usando el for para cambiar N bytes
        aux = *((char*)elem1);
        *((char*)elem1) = *((char*)elem2);
        *((char*)elem2) = aux;
        elem1++;
        elem2++;
    }
}

void * buscarMenor(void *punteroDatos, size_t nitems, size_t size, compar cmp)
{
    void *posMenor = punteroDatos;///por defecto el primer valor es el menor

    int i;
    punteroDatos+= size;///ubico en el segundo valor para no comparar el primero con el primero la primera vez
    for(i=0; i< nitems-1; i++)
    {
    ///cmp puede ser de int, chars, estructura, etc, dependiendo como se la haya llamado en el main a qsort2
        if(cmp(punteroDatos, posMenor)<0)
            posMenor = punteroDatos;///si se encuentra un nuevo menor hay que guardar esa posicion de memoria

        punteroDatos+= size;
    }
    return posMenor;
}
                            ///cmp puede variar cada vez que se llama a la funcion, por eso es generica
void qsort2(void * punteroDatos, size_t nitems, size_t size, compar cmp)
{
    void* posMenor = punteroDatos;///por defecto el primer valor es el menor
    int j;

    for(j=0; j< nitems; j++)
    {        ///el -j es para que reduzca la cantidad de pasadas cada vez que entra
        posMenor = buscarMenor(punteroDatos, (nitems-j), size, *cmp);

        ///si las posiciones de memoria son distintas, quiere decir que hay un nuevo menor
        if(posMenor!=punteroDatos)
            intercambio(posMenor, punteroDatos, size);
        punteroDatos += size;///para pasar a la siguiente posicion de memoria hay que sumar N bytes
    }
}

///invierte sobre el mismo dato enviado
void invertirGen (void * dato, size_t tam)///tama?o del dato completo
{
    char * fin = (char*)(dato+tam-1);///tomo el ultimo byte de los datos
    char temp;
    while( (fin)>((char*)(dato)) )
    {
        temp = *((char*)dato);
        *((char*)dato) = *fin;
        *fin = temp;
        fin--;
        dato++;
    }
}

void* memcpy2(void* destino, const void* origen, unsigned n)
{
    int i;
    destino += n-1;
    origen += n-1;

    for(i=0; i<n; i++)
    {
        *((char*)destino) = *((char*)origen);
        (char*)destino--;
        (char*)origen--;
    }

    return destino;
}


void *memmove_mio(void *str1, const void *str2, size_t n)
{
    int i;
    char temp[n];
    char* iniTemp=temp, * iniStr1=str1, * IniStr2=(char*)str2;

    for (i=0; i<n ; i++,IniStr2++,iniTemp++ )
    {
        *iniTemp=*((char*)IniStr2);
    }

    iniTemp=temp;
    for (i=0; i<n ; i++,str1++,iniTemp++ )
    {
        *((char*)str1)=*iniTemp;
    }
    return iniStr1;
}






