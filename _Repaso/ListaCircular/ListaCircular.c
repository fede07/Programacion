#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaCircular.h"

void crearLista (t_lista * lista)
{
    *lista = NULL;
}

int insertar (t_lista * lista, const void * dato, unsigned tamBy)
{
    t_nodo * nue = malloc(sizeof(t_nodo));
    if(!nue)
    {
        return 0;
    }
    nue->dato = malloc(tamBy);
    if(!nue->dato)
    {
        free(nue);
        return 0;
    }

    memcpy(nue->dato,dato,tamBy);
    memcpy(&(nue->tam),&tamBy,sizeof(unsigned));

    if(!(*lista))///primer elemento de la lista circular
    {
        nue->sig = nue;
        *lista = nue;
    }
    else
    {
        nue->sig = (*lista)->sig;
        (*lista)->sig = nue;
    }

    return 1;
}

int insertarAlFinal (t_lista * lista, const void * dato, unsigned tamBy)
{
    t_nodo * nue = malloc(sizeof(t_nodo));
    void * iniLista;
    if(!nue)
    {
        return 0;
    }
    nue->dato = malloc(tamBy);
    if(!nue->dato)
    {
        free(nue);
        return 0;
    }

    memcpy(nue->dato,dato,tamBy);
    memcpy(&(nue->tam),&tamBy,sizeof(unsigned));

    if(!(*lista))///primer elemento de la lista circular
    {
        nue->sig = nue;
        *lista = nue;
    }
    else
    {
        iniLista = (*lista);
        nue->sig = (*lista)->sig;

        if(*lista)
        {
            do
            {

                lista=&(*lista)->sig;
            }
            while(*lista != iniLista);
        }

        (*lista)->sig = nue;
    }


    return 1;
}

void recorrerCirc(t_lista* lista,void(*accion)(const void*))
{
    void* iniLista = (*lista);
    if(*lista)
    {
        do
        {
            accion((*lista)->dato);
            lista=&((*lista)->sig);
        }
        while((*lista) && (*lista) != iniLista);
    }
}

int eliminar (t_lista * lista, void * dato, unsigned tamBy)
{
    t_nodo * elim;
    if(!(*lista))
    {
        return 0;
    }

    elim = (*lista);
    memcpy(dato,elim->dato,MIN(tamBy,elim->tam));///recupero el dato

    if((*lista)->sig == *lista)///hay un solo elemento en la lista
    {
        *lista = NULL;
    }
    else///si hay 2 o mas elementos en la lista
    {
        *lista = elim->sig;

        while((*lista)->sig != elim)
        {
            lista=&(*lista)->sig;
        }

        (*lista)->sig = elim->sig;
    }
    free(elim->dato);
    free(elim);

    return 1;
}




