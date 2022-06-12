#include <stdlib.h>
#include <string.h>
#include "listaDoble.h"

void crearLista(t_lista * lista)
{
    *lista = NULL;
}

int insertarOrd (t_lista * lista, void * info, unsigned tamBy, int(*comparar)(const void *, const void *))
{
    t_nodo* auxAnt, *auxSig, *actual, *nuevo;
    int comp;

    nuevo = (t_nodo*)malloc(sizeof(t_nodo));
    if(!nuevo)
        return 0;

    nuevo->dato = malloc(tamBy);
    if(!(nuevo->dato))
    {
        free(nuevo);
        return 0;
    }

    if(*lista)
    {
        actual = *lista;
        while(actual->sig && (comparar(info, actual->dato) > 0))
        {
            actual = actual->sig;
        }
        while(actual->ant && (comparar(info, actual->dato) < 0))
        {
            actual = actual->ant;
        }

        if((comp = comparar(info, actual->dato)) == 0) ///Si tienen mismo codigo acumulamos
        {
            free(nuevo->dato);
            free(nuevo);
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

    memcpy(nuevo->dato, info, tamBy);
    nuevo->tam = tamBy;
    nuevo->ant = auxAnt;
    nuevo->sig = auxSig;

    if(auxAnt)
        auxAnt->sig = nuevo;
    if(auxSig)
        auxSig->ant = nuevo;
    *lista = nuevo;
    return 1;
}

int insertar (t_lista * lista, void * dato, unsigned tamBy)
{
    t_nodo* auxAnt, *auxSig, *nuevo;

    nuevo = (t_nodo*)malloc(sizeof(t_nodo));
    if(!nuevo)
        return 0;

    nuevo->dato = malloc(tamBy);
    if(!(nuevo->dato))
    {
        free(nuevo);
        return 0;
    }

    if(!*lista)
    {///inserto primer nodo de la lista
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

    memcpy(nuevo->dato, dato, tamBy);
    memcpy(&(nuevo->tam),&tamBy,sizeof(unsigned));
    nuevo->ant = auxAnt;
    nuevo->sig = auxSig;

    if(auxAnt)
        auxAnt->sig = nuevo;
    if(auxSig)
        auxSig->ant = nuevo;
    *lista = nuevo;

    return 1;
}

int insertarOrdAcum (t_lista * lista, void * info, unsigned tamBy, int(*comparar)(const void *, const void *), void(*acumular)(void *, const void *) )
{
    t_nodo* auxAnt, *auxSig, *actual, *nuevo;
    int comp;

    nuevo = (t_nodo*)malloc(sizeof(t_nodo));
    if(!nuevo)
        return 0;

    nuevo->dato = malloc(tamBy);
    if(!(nuevo->dato))
    {
        free(nuevo);
        return 0;
    }

    if(*lista)
    {
        actual = *lista;
        while(actual->sig && (comparar(info, actual->dato) > 0))
        {
            actual = actual->sig;
        }
        while(actual->ant && (comparar(info, actual->dato) < 0))
        {
            actual = actual->ant;
        }

        if((comp = comparar(info, actual->dato)) == 0) ///Si tienen mismo codigo acumulamos
        {
            free(nuevo->dato);
            free(nuevo);

            acumular(actual->dato,info);

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

    memcpy(nuevo->dato, info, tamBy);
    nuevo->tam = tamBy;
    nuevo->ant = auxAnt;
    nuevo->sig = auxSig;

    if(auxAnt)
        auxAnt->sig = nuevo;
    if(auxSig)
        auxSig->ant = nuevo;
    *lista = nuevo;
    return 1;
}

int insertarAlFinal(t_lista * lista, void * dato, unsigned tamBy)
{
    t_nodo * nue, * auxSig;

    nue = malloc(sizeof(t_nodo));
    if(!nue)
        return 0;

    nue->dato = malloc(tamBy);
    if(!nue->dato)
    {
        free(nue);
        return 0;
    }

    memcpy(nue->dato,dato,tamBy);
    memcpy(&(nue->tam),&tamBy,sizeof(unsigned));

    if(!*lista)
    {
        nue->ant = NULL;
        nue->sig = NULL;
        *lista = nue;
        return 1;
    }

    auxSig = *lista;

    while(auxSig->sig)
    {
        auxSig = auxSig->sig;
    }

    auxSig->sig = nue;
    nue->ant = auxSig;
    nue->sig = NULL;



    *lista = nue;

    return 1;
}

int insertarAlInicio(t_lista * lista, void * dato, unsigned tamBy)
{
    t_nodo * nue, * auxAnt;

    nue = malloc(sizeof(t_nodo));
    if(!nue)
        return 0;

    nue->dato = malloc(tamBy);
    if(!nue->dato)
    {
        free(nue);
        return 0;
    }

    memcpy(nue->dato,dato,tamBy);
    memcpy(&(nue->tam),&tamBy,sizeof(unsigned));

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

int eliminarPorClave(t_lista* lista, void* dato, unsigned cantBytes, int(*comparar)(const void*, const void*))
{
    t_nodo* act;
    t_nodo* auxSig;
    t_nodo* auxAnt;
    int cmp;

    if(!*lista)
        return 0;

    act = *lista;
    while(act->sig && (comparar(act->dato, dato)) > 0)
    {
        act = act->sig;
    }
    while(act->ant && (comparar(act->dato, dato)) < 0)
    {
        act = act->ant;
    }

    cmp = comparar(act->dato,dato);

    if(cmp != 0)///Sale por que NO encontro la clave
    {
        return 0;
    }
    auxAnt = act->ant;
    auxSig = act->sig;
    if(auxAnt)
    {
        auxAnt->sig = auxSig;
        *lista = auxAnt;
    }

    if(auxSig)
    {
        auxSig->ant = auxAnt;
        *lista = auxSig;
    }

    if(!auxAnt && !auxSig)
        *lista = NULL;

    memcpy(dato, act->dato, MIN(cantBytes, act->tam));

    free(act->dato);
    free(act);
    return 1;
}

int eliminarActual(t_lista *lista, void *info, unsigned cantBy)
{
    t_nodo * elim, * auxAnt, *auxSig;
    if(!*lista)
        return 0;

    elim = *lista;

    auxSig = elim->sig;
    auxAnt = elim->ant;

    if(!auxAnt && !auxSig)
    {///era el ultimo nodo y ahora esta vacia
        free(elim->dato);
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

    memcpy(info,elim->dato,MIN(elim->tam,cantBy));

    free(elim->dato);
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

void recorrerListaIzq(t_lista* lista, void(*accion)(const void*))///izq a der
{
    while(*lista && (*lista)->ant)
    {
        lista = &(*lista)->ant;
    }
    while(*lista)
    {
        accion((*lista)->dato);
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
        accion((*lista)->dato);
        lista = &(*lista)->ant;
    }
}

void filtrar (t_lista * lista, void * dato, int(*filtro)(const void*, const void*))
{
    t_nodo* act;
    t_nodo* auxSig;
    t_nodo* auxAnt;

    if(*lista)
    {
        act = *lista;
        while(act->sig)///va hacia la derecha hasta encontrar el final de la lista
        {
            act = act->sig;
            if(filtro(dato,act->dato))///entra si hay que filtrarlo
            {
                auxSig = act->sig;
                auxAnt = act->ant;
                free(act->dato);
                free(act);
                auxAnt->sig = auxSig;
                if(auxSig)
                    auxSig->ant = auxAnt;
                act = auxAnt;
            }
        }

        act = *lista;
        while(act->ant)
        {
            act = act->ant;
            if(filtro(dato,act->dato))///entra si hay que filtrarlo
            {
                auxSig = act->sig;
                auxAnt = act->ant;
                free(act->dato);
                free(act);

                auxSig->ant = auxAnt;
                if(auxAnt)
                    auxAnt->sig = auxSig;
                act = auxSig;
            }
        }

        ///ver que pasa si hay un unico nodo
        if(filtro(dato,(*lista)->dato))
        {
            act = *lista;

            if(act->sig && act->ant)///por lo menos un nodo a cada lado
            {
                auxSig = act->sig;
                auxAnt = act->ant;
                auxSig->ant = auxAnt;
                auxAnt->sig = auxSig;
                *lista = auxAnt;
            }
            else if(act->sig)///unicamente nodo a su derecha
            {
                *lista = act->sig;
                (*lista)->ant = NULL;
            }
            else///apunta al nodo izquierdo o a NULL si no habia nada a la izq ni derecha
            {
                *lista = act->ant;
                (*lista)->sig = NULL;
            }

            free(act->dato);
            free(act);
        }
    }
}

t_nodo * buscarMenor (t_nodo * actual, int(*comparar)(const void *, const void *))
{
    t_nodo * menor = actual;
    while(actual->sig)
    {
        actual = actual->sig;
        if(comparar(menor->dato,actual->dato)>0)
        {
            menor = actual;
        }
    }
    return menor;
}

void ordenar (t_lista * lista ,int(*comparar)(const void *, const void *))
{
    t_nodo * actual, * menor, *auxAnt, *auxSig;

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

void intercambiarDatos (t_nodo * menor, t_nodo * actual)
{
    unsigned tamAux;
    void * datoAux;

    datoAux = menor->dato;
    tamAux = menor->tam;
    menor->dato = actual->dato;
    menor->tam = actual->tam;
    actual->dato = datoAux;
    actual->tam = tamAux;
}

void ordenarDatos (t_lista * lista ,int(*comparar)(const void *, const void *))
{
    t_nodo * menor, * actual;

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
        elim = buscarNodo(&(*lista)->sig,(*lista)->dato,comparar);
        if(elim)
        {
            auxAnt = elim->ant;
            auxSig = elim->sig;
            if(auxAnt)
                auxAnt->sig = auxSig;
            if(auxSig)
                auxSig->ant = auxAnt;
            free(elim->dato);
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
        return temp->dato;

    return NULL;
}

t_nodo * buscarNodo (t_lista * lista, void * dato, int(*comparar)(const void *, const void *))
{
    int comp;
    comp = comparar((*lista)->dato,dato);
    while((*lista)->sig && comp!=0)
    {
        lista = &(*lista)->sig;
        comp = comparar((*lista)->dato,dato);
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

    comp = comparar((*lista)->dato,dato);

    while((*lista)->ant && comp>0)
    {
        lista = &(*lista)->ant;
        comp = comparar((*lista)->dato,dato);
    }
    while((*lista)->sig && comp<0)
    {
        lista = &(*lista)->sig;
        comp = comparar((*lista)->dato,dato);
    }

    if(comp==0)
        return (*lista)->dato;

    return NULL;
}

int elimYAcum (t_lista * lista,int(*comparar)(const void *, const void *),void*(*acumulacion)(void *, void *))
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
        elim = buscarNodo(&(*lista)->sig,(*lista)->dato,comparar);
        if(elim)
        {
            acumulacion((*lista)->dato,(elim)->dato);
            auxAnt = elim->ant;
            auxSig = elim->sig;
            if(auxAnt)
                auxAnt->sig = auxSig;
            if(auxSig)
                auxSig->ant = auxAnt;
            free(elim->dato);
            free(elim);
        }
        else
            lista = &(*lista)->sig;
    }

    return 1;
}

///RECURSIVAS PUEDEN TENER ERRORES

t_nodo* insertarOrdenadoR(t_nodo* actual,const void* info,int(*comparar)(const void*, const void*))
{
    int comp;

    comp = comparar(info, actual->dato);

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

        if((comp = comparar(info, actual->dato)) == 0) ///Si tienen mismo codigo acumulamos
        {
            acumular(actual->dato,info);
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

    nuevo->dato = malloc(tamBy);

    if(!(nuevo->dato))
    {
        free(nuevo);
        return 0;
    }

    memcpy(nuevo->dato, info, tamBy);
    nuevo->tam = tamBy;
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
    accion((*lista)->dato);
}

void recorrerListaRecDer(t_lista* lista, void(*accion)(const void*))
{
    if(!(*lista))
    {
        return;
    }
    accion((*lista)->dato);
    recorrerListaRecDer(&(*lista)->sig,accion);
}

void recorrerListaRec(t_lista* lista, void(*accion)(const void*))
{
    if(!(*lista))
    {
        return;
    }
    recorrerListaRecIzq(&(*lista)->ant,accion);
    accion((*lista)->dato);
    recorrerListaRecDer(&(*lista)->sig,accion);
}

void recorrerListaRInv_I(t_lista* lista, void(*accion)(const void*))
{
    if(!(*lista))
    {
        return;
    }
    accion((*lista)->dato);
    recorrerListaRInv_I(&(*lista)->ant,accion);
}

void recorrerListaRInv_D(t_lista* lista, void(*accion)(const void*))
{
    if(!(*lista))
    {
        return;
    }
    recorrerListaRInv_D(&(*lista)->sig,accion);
    accion((*lista)->dato);
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

    nuevo->dato = malloc(tam);

    if(!(nuevo->dato))
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
    memcpy(nuevo->dato,info,tam);
    nuevo->tam=tam;
    *lista = nuevo;

    return 1;
}

t_nodo* buscarMenorR(t_lista* lista,t_nodo* menor, int(*comparar)(const void*, const void*))
{
    if(!(*lista))
    {
        return menor;
    }

    if(comparar((*lista)->dato, menor->dato)<0)
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










