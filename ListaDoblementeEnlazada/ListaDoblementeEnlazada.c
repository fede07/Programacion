#include "ListaDoblementeEnlazada.h"
#include <stdlib.h>
#include <string.h>

void crearLista(t_lista* lista)
{
    *lista = NULL;
}

int insertarListaOrd(t_lista* lista, void* info, unsigned tamBy, int(*comparar)(const void*, const void*))
{
    t_nodo  *nuevo,
            *auxSig,
            *auxAnt,
            *actual;
    int cmp = 1;

    if(!(*lista))
    {
        auxAnt = NULL;
        auxSig = NULL;
    }
    else
    {
        actual = *lista;
        cmp = comparar(info, actual->info);
        while(actual->sig && cmp > 0)
        {
            actual = actual->sig;
            cmp = comparar(info, actual->info);
        }
        while(actual->ant && comparar(info, actual->info)<0)
        {
            actual = actual->ant;
            cmp = comparar(info, actual->info);
        }

        if(cmp<0)
        {
            auxSig = actual;
            auxAnt = actual->ant;
        }
        else if(cmp>0)
        {
            auxAnt = actual;
            auxSig = actual->sig;
        }
    }
    if(cmp == 0)
    {
        *lista = actual;
        return 1;
    }

    nuevo = malloc(sizeof(t_nodo));
    if(!nuevo)
    {
        return 0;
    }
    nuevo->info = (t_nodo*)malloc(tamBy);
    if(!(nuevo->info))
    {
        free(nuevo);
        return 0;
    }

    memcpy(nuevo->info, info, tamBy);
    nuevo->tamBy = tamBy;

    nuevo->ant = auxAnt;
    nuevo->sig = auxSig;

    if(auxAnt)
    {
        auxAnt->sig = nuevo;
    }

    if(auxSig)
    {
        auxSig->ant = nuevo;
    }

    *lista = nuevo;

    return 1;

}

int insertarEnLista(t_lista *lista, void *info, unsigned tamBy)
{
    t_nodo* auxAnt, *auxSig, *nuevo;

    nuevo = (t_nodo*)malloc(sizeof(t_nodo));
    if(!nuevo)
        return 0;

    nuevo->info = malloc(tamBy);
    if(!(nuevo->info))
    {
        free(nuevo);
        return 0;
    }

    if(!*lista)
    {
        ///inserto primer nodo de la lista
        auxAnt = NULL;
        auxSig = NULL;
    }
    else
    {
        if((*lista)->sig)///si hay un nodo a la derecha
        {
            auxSig = (*lista)->sig;
        }
        else
        {
            auxSig = NULL;
        }

        auxAnt = (*lista);
    }

    memcpy(nuevo->info, info, tamBy);
    memcpy(&(nuevo->tamBy),&tamBy,sizeof(unsigned));
    nuevo->ant = auxAnt;
    nuevo->sig = auxSig;

    if(auxAnt)
        auxAnt->sig = nuevo;
    if(auxSig)
        auxSig->ant = nuevo;
    *lista = nuevo;

    return 1;
}

int insertarAcumListaOrd(t_lista* lista, void* info, unsigned tamBy, int(*comparar)(const void*, const void*), void(*acumular)(void*, const void*))
{
    t_nodo  *nuevo,
            *auxSig,
            *auxAnt,
            *actual;
    int cmp = 1;

    if(!(*lista))
    {
        auxAnt = NULL;
        auxSig = NULL;
    }
    else
    {
        actual = *lista;
        cmp = comparar(info, actual->info);
        while(actual->sig && cmp > 0)
        {
            actual = actual->sig;
            cmp = comparar(info, actual->info);
        }
        while(actual->ant && comparar(info, actual->info)<0)
        {
            actual = actual->ant;
            cmp = comparar(info, actual->info);
        }

        if(cmp<0)
        {
            auxSig = actual;
            auxAnt = actual->ant;
        }
        else
        {
            auxAnt = actual;
            auxSig= actual->sig;
        }
    }

    if(cmp == 0)
    {
        *lista = actual;
        acumular(actual->info, info);
        return 1;
    }

    nuevo = malloc(sizeof(t_nodo));
    if(!nuevo)
    {
        return 0;
    }
    nuevo->info = (t_nodo*)malloc(tamBy);
    if(!(nuevo->info))
    {
        free(nuevo);
        return 0;
    }

    memcpy(nuevo->info, info, tamBy);
    nuevo->tamBy = tamBy;

    nuevo->ant = auxAnt;
    nuevo->sig = auxSig;

    if(auxAnt)
    {
        auxAnt->sig = nuevo;
    }

    if(auxSig)
    {
        auxSig->ant = nuevo;
    }

    *lista = nuevo;

    return 1;
}

int insertarAlFinal(t_lista *lista, void *info, unsigned tamBy)
{
    t_nodo *nuevo, *auxSig;

    nuevo = malloc(sizeof(t_nodo));
    if(!nuevo)
        return 0;

    nuevo->info = malloc(tamBy);
    if(!nuevo->info)
    {
        free(nuevo);
        return 0;
    }



    memcpy(nuevo->info,info,tamBy);
    memcpy(&(nuevo->tamBy),&tamBy,sizeof(unsigned));

    if(!*lista)
    {
        nuevo->ant = NULL;
        nuevo->sig = NULL;
        *lista = nuevo;
        return 1;
    }

    auxSig = *lista;

    while(auxSig->sig)
    {
        auxSig = auxSig->sig;
    }

    auxSig->sig = nuevo;
    nuevo->ant = auxSig;
    nuevo->sig = NULL;



    *lista = nuevo;

    return 1;
}

t_nodo* buscarMenor (t_nodo *actual, int(*comparar)(const void *, const void *))
{
    t_nodo *menor = actual;
    while(actual->sig)
    {
        actual = actual->sig;
        if(comparar(menor->info,actual->info)>0)
        {
            menor = actual;
        }
    }
    return menor;
}

void ordenarLista(t_lista *lista, int(*comparar)(const void *, const void *))
{
    t_nodo *actual, *menor, *auxAnt, *auxSig;

    if(!(*lista))
    {
        return;
    }

    actual = *lista;

    while(actual->ant)
    {
        actual = actual->ant;
    }

    while(actual->sig)
    {
        menor = buscarMenor(actual,comparar);
        if(menor != actual)
        {
            auxAnt = menor->ant;
            auxSig = menor->sig;
            if(auxAnt)
                auxAnt->sig = auxSig;
            if(auxSig)
                auxSig->ant = auxAnt;
            menor->ant = actual->ant;
            menor->sig = actual;
            if(actual->ant)
            {
                auxAnt = actual->ant;
                auxAnt->sig = menor;
            }
            actual->ant = menor;
        }
        else
            actual = actual->sig;
    }
}

void intercambiarDatos (t_nodo *menor, t_nodo *actual)
{
    unsigned tamAux;
    void *datoAux;

    datoAux = menor->info;
    tamAux = menor->tamBy;
    menor->info = actual->info;
    menor->tamBy = actual->tamBy;
    actual->info = datoAux;
    actual->tamBy = tamAux;
}

void ordenarDatos(t_lista *lista ,int(*comparar)(const void *, const void *))
{
    t_nodo *menor, *actual;

    if(!(*lista))
    {
        return;
    }

    actual = *lista;

    while(actual->ant)///voy al primer nodo a la izquierda
    {
        actual = actual->ant;
    }

    while(actual->sig)
    {
        menor = buscarMenor(actual,comparar);
        if(menor != actual)
        {
            intercambiarDatos (menor,actual);
        }
        else
            actual = actual->sig;
    }
}

int eliminarPorClave(t_lista *lista, void *info, unsigned tamBy, int (*comparar)(const void*, const void*))
{
    t_nodo* elim;
    t_nodo* auxSig;
    t_nodo* auxAnt;

    if(!(*lista))
    {
        return 0;
    }

    elim=*lista;

    while(elim->sig && (comparar(info,elim->info))>0)
    {
        elim=elim->sig;
    }
    while(elim->ant && (comparar(info,elim->info))<0)
    {
        elim=elim->ant;
    }
    if((comparar(info,elim->info))!=0)
    {
        return 0;
    }

    auxAnt=elim->ant;
    auxSig=elim->sig;

    if(auxAnt!=NULL)
    {
        auxAnt->sig=auxSig;
        *lista=auxAnt;
    }
    if(auxSig!=NULL)
    {
        auxSig->ant=auxAnt;
        *lista=auxSig;
    }

    if(!auxAnt && !auxSig)
    {
        *lista=NULL;
    }

    memcpy(info,elim->info,MIN(tamBy,elim->tamBy));

    free(elim->info);
    free(elim);

    return 1;
}

int eliminarActual(t_lista *lista, void *info, unsigned tamBy)
{
    t_nodo * elim, * auxAnt, *auxSig;
    if(!*lista)
        return 0;

    elim = *lista;

    auxSig = elim->sig;
    auxAnt = elim->ant;

    if(!auxAnt && !auxSig)
    {
        ///era el ultimo nodo y ahora esta vacia
        free(elim->info);
        free(elim);
        *lista = NULL;
        return 1;
    }

    if(auxAnt)
    {
        auxAnt->sig = auxSig;
    }
    if(auxSig)
    {
        auxSig->ant = auxAnt;
    }

    memcpy(info,elim->info,MIN(elim->tamBy,tamBy));

    free(elim->info);
    free(elim);

    if(auxAnt)
    {
        *lista = auxAnt;
    }
    else
    {
        *lista = auxSig;
    }

    return 1;
}

void filtrarListaOrd(t_lista* lista, void* info, int(*filtro)(const void*, const void*))
{
    t_nodo* actual, *auxSig, *auxAnt;

    if(*lista)
    {
        actual = *lista;
        while(actual->sig)
        {
            actual = actual->sig;
            if(filtro(info, actual->info))
            {
                auxSig = actual->sig;
                auxAnt = actual->ant;
                free(actual->info);
                free(actual);
                auxAnt->sig = auxSig;
                if(auxSig)
                {
                    auxSig->ant = auxAnt;
                }
                actual = auxAnt;
            }
        }

        actual = *lista;
        while(actual->ant)
        {
            actual = actual->sig;
            if(filtro(info, actual->info))
            {
                auxSig = actual->sig;
                auxAnt = actual->ant;
                free(actual->info);
                free(actual);
                auxSig->ant = auxAnt;
                if(auxAnt)
                {
                    auxAnt->sig = auxSig;
                }
                actual = auxSig;
            }
        }

        if(filtro(info, (*lista)->info))
        {
            actual = *lista;

            if(actual->sig && actual->ant)
            {
                auxSig = actual->sig;
                auxAnt = actual->ant;
                auxSig->ant = auxAnt;
                auxAnt->sig = auxSig;
                *lista = auxAnt;
            }
            else if(actual->sig)
            {
                *lista = actual->sig;
                (*lista)->ant = NULL;
            }
            else
            {
                *lista = actual->ant;
                (*lista)->sig = NULL;
            }

            free(actual->info);
            free(actual);
        }


    }

}

void recorrerListaIzq(t_lista* lista, void(*accion)(const void*))
{
    while(*lista && (*lista)->ant)
    {
        lista = &(*lista)->ant;
    }
    while(*lista)
    {
        accion((*lista)->info);
        lista = &(*lista)->sig;
    }
}

void recorrerListaDer(t_lista* lista, void(*accion)(const void*))
{
    while(*lista && (*lista)->sig)
    {
        lista = &(*lista)->sig;
    }
    while(*lista)
    {
        accion((*lista)->info);
        lista = &(*lista)->ant;
    }
}
