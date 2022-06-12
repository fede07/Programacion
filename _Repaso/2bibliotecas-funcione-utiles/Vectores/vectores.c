#include <stdio.h>
#include "vectores.h"


void mostrarVec (int * vec, int * cantElem)
{
    int i;
    printf("*******************");
    for (i=0;i<*cantElem ;i++ )
    {
        printf("\nV[%d]: %d | posicion %d",i,*vec,i+1);
        vec++;
    }
    printf("\n*******************\n");

}

int valida (int opcion, int rangoMin, int rangoMax)
{
    if(opcion>=rangoMin && opcion<=rangoMax)
    {
        return 1;
    }
    return 0;
}


void insertaPos (int * vec, int numero, int posicion, int * cantElem, int tam)
{
    int * vecTemp;
    vec+=posicion-1;
    vecTemp = vec;
    vecTemp += *cantElem;

    while(vecTemp != vec)
    {
        *(vecTemp) = *(vecTemp-1);
        vecTemp--;
    }
    *vecTemp = numero;

    if(*cantElem<tam)
        (*cantElem)+=1;
}

void ordenar_seleccion(int * vec,int TAM, int ce)
{
    int i, *posicionMenor;
    for(i=ce; i>0 ; i--)
    {
        posicionMenor = buscarMenor(vec,ce);
        intercambiar(vec,posicionMenor);
        vec+=1;
        ce--;
    }
}

int * buscarMenor(int *v, int ce)
{
    int * min, i;
    min = v;
    for(i=0; i<ce; i++)
    {
        if(*min>*v)
        {

            min = v;
        }
        v++;
    }
    return min;
}

void intercambiar(int * vec, int * posicionMenor)
{
    int aux;
    aux = *vec;
    *vec = *posicionMenor;
    *posicionMenor = aux;
}

void insertarEnOrden (int * vec, int numero, int tam, int * cantElem)
{
    int * iniVec;
    iniVec = vec;
    vec += *cantElem;

    ordenar_seleccion(vec,tam,*cantElem);

    while(iniVec != vec && *(vec-1)>numero)
    {
        *(vec) = *(vec-1);
        vec--;
    }
    *vec = numero;

    if(*cantElem<tam)
        *cantElem+=1;
}

void eliminarPosicion (int * vec, int pos, int * ce)
{
    int i;
    vec += pos-1;
    for(i=0;i<*ce-pos;i++)
    {
        *vec = *vec+1;
        vec++;
    }

    *ce-=1;
}

void eliminarPrimeraAparicion(int *vec, int elemento, int * cantidad)
{
    int posRec=0, i;
    int * vecFin = vec + *cantidad;
    while(*vec!=elemento && vec!=vecFin)
    {
        vec++;
        posRec++;
    }

    for(i=0;i<*cantidad-posRec;i++)
    {
        *vec = *(vec+1);
        vec++;
    }

    if(posRec<=*cantidad)
        *cantidad -= 1;
}

void eliminarTodaAparicion(int *vec, int elemento, int * cantidad)
{
    int * tempVec = vec;
    int * finVec = vec + *cantidad - 1;
    while(finVec >= tempVec && cantidad>0)
    {
        while(*tempVec == elemento && finVec >= tempVec)
        {
            tempVec++;
            *cantidad-=1;
        }

        *vec = *tempVec;
        tempVec++;
        vec++;
    }
}












