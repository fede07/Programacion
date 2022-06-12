#include <stdlib.h>
#include <string.h>

#include "listaColaCirc.h"

void crearLista(t_lista *listaC)
{
    *listaC = NULL;
}

int listaVacia(const t_lista *listaC)
{
    return *listaC == NULL;
}

int listaLlena(const t_lista *listaC, unsigned tamBy)
{
    t_lista temp = malloc (sizeof(t_nodo));
    if(!temp)
        return 1;

    temp->dato = malloc(tamBy);
    if(!temp->dato)
    {
        free(temp);
        return 1;
    }

    free(temp->dato);
    free(temp);

    return 0;
}

int agregarEnLista(t_lista *listaC, void *info, unsigned tamBy)
{
    t_nodo * nue = malloc (sizeof(t_nodo));
    if(!nue)
        return 0;
    nue->dato = malloc(tamBy);
    if(!nue->dato)
    {
        free(nue);
        return 0;
    }
    memcpy(nue->dato,info,tamBy);
    memcpy(&(nue->tam),&tamBy,sizeof(unsigned));
    if(!(*listaC))
    {
        *listaC = nue;
        nue->sig = nue;
    }
    else
    {
        nue->sig = (*listaC)->sig;
        (*listaC)->sig = nue;
        *listaC = nue;
    }
    return 1;
}

int sacarDeLista(t_lista *listaC, void *info, unsigned tamBy)
{
    t_nodo * elim;
    if(!(*listaC))
        return 0;

    elim = (*listaC)->sig;

    memcpy(info,elim->dato,MIN(elim->tam,tamBy));

    if(*listaC == elim)
    {
        *listaC = NULL;
    }
    else
    {
        (*listaC)->sig = elim->sig;
    }

    free(elim->dato);
    free(elim);

    return 1;
}

void vaciarLista(t_lista *listaC)
{
    t_nodo * elim = (*listaC)->sig;
    while(*listaC != elim)
    {
        (*listaC)->sig = elim->sig;
        free(elim->dato);
        free(elim);
        elim = (*listaC)->sig;
    }
    (*listaC) = NULL;
    free(elim->dato);
    free(elim);
}

int verPriLista(const t_lista *listaC, void *info, unsigned tamBy)
{
    if(!(*listaC))
        return 0;

    memcpy(info,((*listaC)->sig)->dato,MIN(tamBy,((*listaC)->sig)->tam));

    return 1;
}
