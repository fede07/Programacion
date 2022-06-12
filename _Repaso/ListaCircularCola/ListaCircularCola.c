#include "ListaCircularCola.h"
#include <stdlib.h>
#include <string.h>


void crearListaCC(t_lista* listaC)
{
    *listaC = NULL;
}

int ponerEnListaCC(t_lista* listaC, void* info, unsigned tamBy)
{
    t_nodo* nuevo = malloc(sizeof(t_nodo));
    if(!nuevo)
    {
        return 0;
    }
    nuevo->info = malloc(tamBy);
    if(!nuevo->info)
    {
        free(nuevo);
        return 0;
    }

    memcpy(nuevo->info, info, tamBy);
    memcpy(&(nuevo->tamBy), &tamBy, sizeof(unsigned));

    if(!(*listaC))
    {
        *listaC = nuevo;
        nuevo->sig = nuevo;
    }
    else
    {
        nuevo->sig = (*listaC)->sig;
        (*listaC)->sig = nuevo;
        *listaC = nuevo;
    }

    return 1;

}

int sacarDeListaCC(t_lista* listaC, void* info, unsigned tamBy)
{
    t_nodo* elim;
    if(!(*listaC))
    {
        return 0;
    }

    elim = (*listaC)->sig;

    memcpy(info, elim->info, MIN(elim->tamBy, tamBy));

    if(*listaC == elim)
    {
        *listaC = NULL;
    }
    else
    {
        (*listaC)->sig = elim->sig;
    }

    free(elim->info);
    free(elim);

    return 1;
}
int verPrimero(const t_lista* listaC, void* info, unsigned tamBy)
{
    if(!(*listaC))
    {
        return 0;
    }

    memcpy(info, ((*listaC)->sig)->info, MIN(tamBy, (*listaC)->tamBy));
    return 1;
}

int listaCCVacia(const t_lista* listaC)
{
    return (*listaC) == NULL;
}

int listaCCLlena(const t_lista* listaC, unsigned tamBy)
{
    t_nodo* temp = malloc(sizeof(t_nodo));

    if(!temp)
    {
        return 1;
    }

    temp->info = malloc(tamBy);

    if(!(temp->info))
    {
        free(temp);
        return 1;
    }

    free(temp->info);
    free(temp);
    return 0;
}

void vaciarListaCC(t_lista* listaC)
{
    t_nodo* elim = (*listaC)->sig;
    while((*listaC) != elim)
    {
        (*listaC)->sig = elim->sig;
        free(elim->info);
        free(elim);
        elim = (*listaC)->sig;
    }
    (*listaC) = NULL;
    free(elim->info);
    free(elim);
}
