#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pila2.h"

void crearPila(t_pila* pila)
{
    *pila=NULL;

}

int ponerEnPila(t_pila* pila,const void* info, unsigned tam)
{
    t_nodo* nNuevo=malloc(sizeof(t_nodo)); //Se reserva memoria para todo el nodo/estructura

    if(!nNuevo)
    {
        return 0;
    }

    nNuevo->dato=malloc(tam); //Aca se reserva memoria para el contenido del puntero a info
    if(!(nNuevo->dato))
    {
        free(nNuevo);
        return 0;
    }

    memcpy(nNuevo->dato,info,tam);

    nNuevo->tam=tam;

    nNuevo->sig=*pila;

    *pila=nNuevo;

    return 1;
}

int sacarDePila (t_pila* p,void* info,unsigned tam)
{
    t_nodo* elim=*p;

    if(!(*p))
    {
        return 0;
    }

    memcpy(info,elim->dato,MIN(tam,elim->tam));///se usa el min porque podria no saberse cuanto ocupa el dato
                                            ///si fueran cadenas tienen distintas longitudes
                                            ///si bien la pila guarda la cantidad de caracteres, el usuario podria
                                            ///querer menos bytes de los que estan escritos

    free(elim->dato);

    *p=elim->sig;
    free(elim);
    return 1;

}

int verTope(const t_pila* pila,void* info,unsigned tam)
{
    if(!(*pila))
    {
        return 0;
    }

    memcpy(info,(*pila)->dato,MIN(tam,(*pila)->tam));
    return 1;
}

int pilaVacia (const t_pila* pila)
{
    return (*pila)==NULL;
}

void vaciarPila (t_pila* pila)
{
    t_nodo* elim=*pila;

    while(*pila)
    {
        *pila=elim->sig;
        free(elim->dato);
        free(elim);
        elim=*pila;
    }
}

int pilaLlena (const t_pila* pila,unsigned tam)
{
    t_nodo* nNodo=malloc(sizeof(t_nodo));

    if(!nNodo)
    {
        return 1;
    }

    nNodo->dato=malloc(tam);

    if(!nNodo->dato)
    {
        free(nNodo);
        return 1;
    }
    free(nNodo->dato);
    free(nNodo);
    return 0;
}
