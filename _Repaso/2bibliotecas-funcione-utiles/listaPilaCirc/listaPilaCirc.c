#include <stdlib.h>
#include <strings.h>

#include "listaPilaCirc.h"

void crearlistaP(t_listaP* listaP)
{
    *listaP = NULL;
}

int ponerEnlistaP(t_listaP* listaP, const void* info, unsigned tam)
{
    t_nodo * nue;

    nue = malloc(sizeof(t_nodo));
    if(!nue)
        return 0;
    nue->dato = malloc(tam);
    if(!nue->dato)
    {
        free(nue);
        return 0;
    }

    memcpy(nue->dato,info,tam);
    memcpy(&(nue->tam),&tam,sizeof(int));


    if((*listaP) == NULL )///es el primero de la lista
    {
        *listaP = nue;
        nue->sig = nue;
    }
    else
    {
        nue->sig = (*listaP)->sig;
        (*listaP)->sig = nue;
    }

    return 1;
}

int verTope(const t_listaP* listaP, void* info, unsigned tam)
{
    if(!(*listaP))
    {
        return 0;
    }

    memcpy(info, ((*listaP)->sig)->dato, MIN( ((*listaP)->sig)->tam,tam) );

    return 1;
}

int sacarDelistaP(t_listaP* listaP, void* info, unsigned tambytes)
{
    t_nodo * elim;
    if(!*listaP)
    {
        return 0;
    }

    elim = (*listaP)->sig;

    (*listaP)->sig = elim->sig;

    memcpy(info,elim->dato,MIN(elim->tam,tambytes));

    if((*listaP) == elim)
        *listaP = NULL;

    free(elim->dato);
    free(elim);


    return 1;

}

int listaPVacia(const t_listaP* listaP)
{
    return (*listaP)==NULL;
}

void vaciarlistaP(t_listaP* listaP)
{
    t_nodo * elim = (*listaP)->sig;
    while(*listaP != (elim))
    {
        (*listaP)->sig = elim->sig;
        free(elim->dato);
        free(elim);
        elim = (*listaP)->sig;
    }

    if((*listaP))
    {
        (*listaP) = NULL;
        free(elim->dato);
        free(elim);
    }
}

int listaPLlena(const t_listaP* listaP, unsigned tam)
{
    t_nodo * temp = malloc(sizeof(t_nodo));
    if(!temp)
    {
        return 1;
    }

    temp->dato = malloc(tam);
    if(!temp->dato)
    {
        free(temp);
        return 1;
    }

    free(temp->dato);
    free(temp);

    return 0;
}














