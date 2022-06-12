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

int insertarAlInicio(t_lista * lista, void * dato, unsigned tamBy)
{
    t_nodo * nue, * auxAnt;

    nue = malloc(sizeof(t_nodo));
    if(!nue)
        return 0;

    nue->info = malloc(tamBy);
    if(!nue->info)
    {
        free(nue);
        return 0;
    }

    memcpy(nue->info,dato,tamBy);
    memcpy(&(nue->tamBy),&tamBy,sizeof(unsigned));

    if(!*lista)
    {
        nue->ant = NULL;
        nue->sig = NULL;
        *lista = nue;
        return 1;
    }

    auxAnt = *lista;

    while(auxAnt->ant)
    {
        auxAnt = auxAnt->ant;
    }

    auxAnt->ant = nue;
    nue->sig = auxAnt;
    nue->ant = NULL;



    *lista = nue;

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

int elimDup (t_lista * lista,int(*comparar)(const void *, const void *))
{
    t_nodo * elim, * auxSig, * auxAnt;

    if(!*lista)
        return 0;

    while((*lista)->ant)
    {
        lista = &(*lista)->ant;
    }

    while((*lista)->sig)
    {
        elim = buscarNodo(&(*lista)->sig,(*lista)->info,comparar);
        if(elim)
        {
            auxAnt = elim->ant;
            auxSig = elim->sig;
            if(auxAnt)
                auxAnt->sig = auxSig;
            if(auxSig)
                auxSig->ant = auxAnt;
            free(elim->info);
            free(elim);
        }
        else
            lista = &(*lista)->sig;
    }

    return 1;
}

void * buscarDato (t_lista * lista, void * dato, int(*comparar)(const void *, const void *))
{
    t_nodo * temp;
    if(!*lista)
        return NULL;

    while((*lista)->ant)
    {
        lista = &(*lista)->ant;
    }

    temp = buscarNodo(&(*lista),dato,comparar);

    if(temp)
        return temp->info;

    return NULL;
}

t_nodo * buscarNodo (t_lista * lista, void * dato, int(*comparar)(const void *, const void *))
{
    int comp;
    comp = comparar((*lista)->info,dato);
    while((*lista)->sig && comp!=0)
    {
        lista = &(*lista)->sig;
        comp = comparar((*lista)->info,dato);
    }

    if(comp == 0)
        return *lista;

    return NULL;
}

void * buscarDatoOrd (t_lista * lista, void * dato, int(*comparar)(const void *, const void *))
{
    int comp;
    if(!*lista)
        return NULL;

    comp = comparar((*lista)->info,dato);

    while((*lista)->ant && comp>0)
    {
        lista = &(*lista)->ant;
        comp = comparar((*lista)->info,dato);
    }
    while((*lista)->sig && comp<0)
    {
        lista = &(*lista)->sig;
        comp = comparar((*lista)->info,dato);
    }

    if(comp==0)
        return (*lista)->info;

    return NULL;
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

///RECURSIVAS PUEDEN TENER ERRORES

t_nodo* insertarOrdenadoR(t_nodo* actual,const void* info,int(*comparar)(const void*, const void*))
{
    int comp;

    comp = comparar(info, actual->info);

    if(actual->sig &&(comp)>0)
    {
        return insertarOrdenadoR(actual->sig,info,comparar);
    }
    if(actual->ant &&(comp)<0)
    {
        return insertarOrdenadoR(actual->ant,info,comparar);
    }
    return actual;
}

int insertarOrdenadoR_W(t_lista *lista, const void *info, unsigned tamBy, int(*comparar)(const void*, const void*),void(*acumular)(void *, const void *) )
{
    t_nodo* auxAnt, *auxSig, *actual, *nuevo;
    int comp;

    if(*lista)
    {
        actual=insertarOrdenadoR(*lista,info,comparar);

        if((comp = comparar(info, actual->info)) == 0) ///Si tienen mismo codigo acumulamos
        {
            acumular(actual->info,info);
            *lista = actual;
            return 1;
        }
        else if(comp > 0)
        {
            auxAnt = actual;
            auxSig = actual->sig;
        }
        else
        {
            auxSig = actual;
            auxAnt = actual->ant;
        }

    }
    else
    {
        auxAnt = NULL;
        auxSig = NULL;
    }

    nuevo = (t_nodo*)malloc(sizeof(t_nodo));
    if(!nuevo)
        return 0;

    nuevo->info = malloc(tamBy);

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
        auxAnt->sig = nuevo;
    if(auxSig)
        auxSig->ant = nuevo;
    *lista = nuevo;
    return 1;
}

void recorrerListaRecIzq(t_lista* lista, void(*accion)(const void*))
{
    if(!(*lista))
    {
        return;
    }
    recorrerListaRecIzq(&(*lista)->ant,accion);
    accion((*lista)->info);
}

void recorrerListaRecDer(t_lista* lista, void(*accion)(const void*))
{
    if(!(*lista))
    {
        return;
    }
    accion((*lista)->info);
    recorrerListaRecDer(&(*lista)->sig,accion);
}

void recorrerListaRec(t_lista* lista, void(*accion)(const void*))
{
    if(!(*lista))
    {
        return;
    }
    recorrerListaRecIzq(&(*lista)->ant,accion);
    accion((*lista)->info);
    recorrerListaRecDer(&(*lista)->sig,accion);
}

void recorrerListaRInv_I(t_lista* lista, void(*accion)(const void*))
{
    if(!(*lista))
    {
        return;
    }
    accion((*lista)->info);
    recorrerListaRInv_I(&(*lista)->ant,accion);
}

void recorrerListaRInv_D(t_lista* lista, void(*accion)(const void*))
{
    if(!(*lista))
    {
        return;
    }
    recorrerListaRInv_D(&(*lista)->sig,accion);
    accion((*lista)->info);
}

void recorrerListaRInv_W(t_lista* lista, void(*accion)(const void*))
{
    if(!(*lista))
    {
        return;
    }
    recorrerListaRInv_D(&(*lista)->sig,accion);
    recorrerListaRInv_I(lista,accion);
}

t_nodo* insertarAlPrincipioR(t_nodo* actual)
{
    if(!(actual->ant))
    {
        return actual;
    }
    return insertarAlPrincipioR(actual->ant);
}

int insertarAlPrincipioR_W(t_lista* lista, const void* info, unsigned tam)
{
    t_nodo *actual, *nuevo;
    nuevo = (t_nodo*)malloc(sizeof(t_nodo));

    if(!nuevo)
        return 0;

    nuevo->info = malloc(tam);

    if(!(nuevo->info))
    {
        free(nuevo);
        return 0;
    }

    if(*lista)
    {
        actual = insertarAlPrincipioR(*lista);

        nuevo->sig=actual;
        actual->ant=nuevo;
    }
    else
    {
        nuevo->ant=NULL;
        nuevo->sig=NULL;
    }
    nuevo->ant=NULL;
    memcpy(nuevo->info,info,tam);
    nuevo->tamBy=tam;
    *lista = nuevo;

    return 1;
}

t_nodo* buscarMenorR(t_lista* lista,t_nodo* menor, int(*comparar)(const void*, const void*))
{
    if(!(*lista))
    {
        return menor;
    }

    if(comparar((*lista)->info, menor->info)<0)
    {
        menor=*lista;
    }
    return buscarMenorR(&(*lista)->sig,menor,comparar);
}

t_nodo* buscarMenorR_W(t_lista* lista, int(*comparar)(const void*, const void*))
{
    t_nodo* menor = *lista;

    if(!(*lista))
    {
        return NULL;
    }

    return buscarMenorR(&(*lista)->sig,menor,comparar);;
}

void ordenarListaR(t_lista* lista, int(*comparar)(const void*, const void*))
{
    t_nodo* menor, *auxAnt, *auxSig;
    if(!*lista)
    {
        return;
    }
    menor = buscarMenorR_W(lista,comparar);
    if(menor != *lista)
    {
        /// Desengancho el nodo
        auxAnt=menor->ant;
        auxSig=menor->sig;
        if(auxAnt)
        {
            auxAnt->sig=auxSig;
        }
        if(auxSig)
        {
            auxSig->ant=auxAnt;
        }
        /// Engancho al principio
        menor->ant=(*lista)->ant;
        (*lista)->ant=menor;
        menor->sig=(*lista);
        *lista=menor;
    }
    ordenarListaR(&(*lista)->sig,comparar);

}

void ordenarListaR_W(t_lista* lista, int(*comparar)(const void*, const void*)) ///Optimizar
{
    t_nodo* test;

   test=insertarAlPrincipioR(*lista);
   lista=&test;

  if(*lista)
  {
      ordenarListaR(lista,comparar);
  }
}
