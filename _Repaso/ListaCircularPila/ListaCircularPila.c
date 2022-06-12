#include "ListaCircularPila.h"
#include <stdlib.h>
#include <string.h>

void crearListaCircP(t_lista* lista)
{
    *lista = NULL;
}

int ponerEnListaP(t_lista* listaP, const void* info, unsigned tamBy)
{
    t_nodo* nuevo = malloc(sizeof(t_nodo));
    if(!nuevo)
    {
        return 0;
    }

    nuevo->info = malloc(tamBy);
    if(!(nuevo->info))
    {
        free(nuevo);
        return 0;
    }

    memcpy(nuevo->info, info, tamBy);
    memcpy(&(nuevo->tamBy), &tamBy, sizeof(unsigned));

    if((*listaP) == NULL)
    {
        *listaP = nuevo;
        nuevo->sig = nuevo;
    }
    else
    {
        nuevo->sig = (*listaP)->sig;
        (*listaP)->sig = nuevo;
    }
    return 1;
}

int verTope(const t_lista* listaP, void* info, unsigned tamBy)
{
    if(!(*listaP))
    {
        return 0;
    }

    memcpy(info, (*listaP)->info, tamBy);
    return 1;
}

int sacarDeListaP(t_lista* listaP, void* info, unsigned tamBy)
{
    t_nodo* elim;

    if(!*listaP)
    {
        return 0;
    }

    elim = (*listaP)->sig;

    (*listaP)->sig = elim->sig;

    memcpy(info, elim->info, MIN(tamBy, elim->tamBy));

    if((*listaP) == elim)
    {
        *listaP = NULL;
    }

    free(elim->info);
    free(elim);

    return 1;

}

int listaPVacia(const t_lista* listaP)
{
    return (*listaP) == NULL;
}
void vaciarListaP(t_lista* listaP)
{
    t_nodo* elim = (*listaP)->sig;
    while((*listaP) != elim)
    {
        (*listaP)->sig = elim->sig;
        free(elim->info);
        free(elim);
        elim = (*listaP)->sig;
    }

    if((*listaP))
    {
        (*listaP) = NULL;
        free(elim->info);
        free(elim);
    }

}
int listaPLlena(const t_lista* listaP, unsigned tamBy)
{
    t_nodo* temp = malloc(sizeof(t_nodo));
    if(!temp)
    {
        return 1;
    }

    temp->info= malloc(sizeof(tamBy));
    if(!(temp->info))
    {
        free(temp);
        return 1;
    }

    free(temp->info);
    free(temp);
    return 0;

}
