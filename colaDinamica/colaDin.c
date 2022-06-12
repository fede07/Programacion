#include "colaDin.h"
#include <stdlib.h>
#include <string.h>

#define FAIL 0
#define SUCCESS 1
#define MIN(x,y) ((x)<(y)?(x):(y))


void crearCola (t_cola *cola)
{
    cola->pri = NULL;
    cola->ult = NULL;
}

int colaVacia(const t_cola *cola)
{
    return (cola->pri == NULL);
}

int colaLlena(const t_cola *cola, unsigned tamBytes)
{
    t_nodo *temp = malloc(sizeof(t_nodo));

    if(temp == NULL)
    {
        return 1;
    }

    temp->dato = malloc(tamBytes);

    if(temp->dato == NULL)
    {
        free(temp);
        return 1;
    }

    free(temp->dato);

    free(temp);

    return 0;
}

int ponerEnCola(t_cola *cola, void* dato, unsigned tamByte)
{
    t_nodo *nuevo = malloc(sizeof(t_nodo));
    if(!nuevo)
    {
        return FAIL;
    }
    nuevo->dato = malloc(tamByte);

    if(!(nuevo->dato))
    {
        free(nuevo);
        return FAIL;
    }

    if(cola->pri == NULL)
    {
        cola->pri = nuevo;
    }
    else
    {
        cola->ult->sig = nuevo;
    }

    nuevo->sig = NULL;

    memcpy(nuevo->dato, dato, tamByte);

    nuevo->tambyte = tamByte;

    cola->ult=nuevo;

    return 1;
}

int sacarDeCola(t_cola* cola, void* dato, unsigned tamBytes)
{
    t_nodo *elim;

    if(cola->pri == NULL)
    {
        return FAIL;
    }

    elim=cola->pri;

    memcpy(dato, elim->dato, MIN(tamBytes, elim->tambyte));

    cola->pri = elim->sig;

    if(cola->pri == NULL)
    {
        cola->ult = NULL;
    }

    free(elim->dato);
    free(elim);

    return 1;
}

void vaciarCola(t_cola* cola)
{
    t_nodo *elim;
    while(cola->pri)
    {
        elim=cola->pri;
        cola->pri=elim->sig;
        free(elim->dato);
        free(elim);
    }
    cola->ult = NULL;
}

int verPrim(const t_cola* cola, void* dato, unsigned tamBytes)
{
    if(cola->pri == NULL)
    {
        return FAIL;
    }

    memcpy(dato, cola->pri->dato, MIN(tamBytes, cola->pri->tambyte));

    return SUCCESS;
}
