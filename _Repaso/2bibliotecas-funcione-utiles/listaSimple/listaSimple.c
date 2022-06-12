#include <stdlib.h>
#include <string.h>
#include "listaSimple.h"

void crearLista(t_lista*lista)
{
    *lista=NULL;
}

int insertarAlFinal(t_lista * lista, const void*dato,unsigned cantBy)
{
    t_nodo*nue=(t_nodo*)malloc(sizeof(t_nodo));
    if(!nue)
        return 0;
    while(*lista)
        lista=&(*lista)->sig;
    nue->dato=malloc(cantBy);
    if(!nue->dato)
    {
        free(nue);
        return 0;
    }
    memcpy(nue->dato,dato,cantBy);
    nue->tam=cantBy;
    nue->sig=*lista;
    *lista=nue;
    return 1;
}

int insertarAlInicio (t_lista * lista, const void* dato, unsigned cantBy)
{
    t_nodo * nue = malloc(sizeof(t_nodo));
    if(!nue)
    {
        return 0;
    }
    nue->dato = malloc(cantBy);
    if(!nue->dato)
    {
        free(nue);
        return 0;
    }

    memcpy(nue->dato,dato,cantBy);
    memcpy(&(nue->tam),&cantBy,sizeof(unsigned));

    if(!(*lista))
    {
        nue->sig=NULL;
    }
    else
    {
        nue->sig= *lista;
    }

    *lista = nue;

    return 1;
}

int insertarOrdenado(t_lista *lista, const void *info, unsigned cantBy, int(*comp)(const void*,const void*),int duplicado)
{
    t_nodo *nue;
    int valor_comparacion = 1;

    while(*lista && (valor_comparacion = comp(info,(*lista)->dato)) < 0)
    {
        lista = &(*lista)->sig;
    }

    if(valor_comparacion == 0 && !duplicado)
    {
        return 1;
    }

    nue = (t_nodo *)malloc(sizeof(t_nodo));
    if(!nue)
    {
        return 0;
    }

    nue->dato = malloc(cantBy);
    if(!nue->dato)
    {
        free(nue);
        return 0;
    }

    memcpy(nue->dato,info,cantBy);
    nue->tam = cantBy;
    nue->sig = *lista;
    *lista = nue;

    return 1;
}

int insertarEnPosicion(t_lista *lista, void *info, unsigned tamBy, unsigned pos)
{
    t_nodo* nuevo = (t_nodo*)malloc(sizeof(t_nodo));

    if(!nuevo)
    {
        return 0;
    }

    while(*lista && pos--)
    {
        lista = &(*lista)->sig;
    }

    if(!(*lista) && pos>0)
    {
        return 0;
    }

    nuevo->dato= malloc(tamBy);

    if(!(nuevo->dato))
    {
        free(nuevo);
        return 0;
    }

    memcpy(nuevo->dato, info, tamBy);

    nuevo->tam = tamBy;

    nuevo->sig = *lista;

    *lista = nuevo;

    return 1;

}

void recorrer(t_lista*lista,void(*accion)(const void*))
{
    while(*lista)
    {
        accion((*lista)->dato);
        lista=&(*lista)->sig;
    }
}

void filtrar(t_lista*lista,int(*fFiltro)(const void*))
{
    t_nodo*elim;
    while(*lista)
    {
        if(fFiltro((*lista)->dato))
        {
            elim=*lista;
            *lista=elim->sig;
            free(elim->dato);
            free(elim);
        }
        else
            lista=&(*lista)->sig;
    }
}

void* acumularLista(t_lista*lista,void*acumulador,void*(*acumulacion)(void*,void*))
{
    while(*lista)
    {
        acumulacion(acumulador,(*lista)->dato);
        lista=&(*lista)->sig;
    }
    return acumulador;
}

int buscarEnListaOrd(t_lista * lista, void * info, int(*comparar)(const void *, const void *))
{
    t_nodo * elim;
    int cmp = 1;

    cmp = comparar((*lista)->dato,info);
    while(*lista && cmp<0)
    {
        lista = &(*lista)->sig;
        cmp = comparar((*lista)->dato,info);
    }

    if(cmp)///no encontro el elemento
    {
        return 0;
    }

    elim = *lista;
    memcpy(info,elim->dato,sizeof(elim->tam));
    *lista = elim->sig;
    free(elim->dato);
    free(elim);

    return 1;
}

int buscarEnLista(t_lista * lista, void * info, int(*comparar)(const void *, const void *))
{
    t_nodo * elim;
    int cmp = 1;

    cmp = comparar((*lista)->dato,info);
    while(*lista && cmp!=0)
    {
        lista = &(*lista)->sig;
        cmp = comparar((*lista)->dato,info);
    }

    if(cmp)///no encontro el elemento
    {
        return 0;
    }

    elim = *lista;
    memcpy(info,elim->dato,sizeof(elim->tam));
    *lista = elim->sig;
    free(elim->dato);
    free(elim);

    return 1;
}

int eliminar (t_lista * lista, void * dato, unsigned tamBy)
{
    t_nodo * elim;
    if(!*lista)
        return 0;

    elim = *lista;
    memcpy(dato, (*lista)->dato,MIN(tamBy,(*lista)->tam));
    *lista=elim->sig;

    free(elim->dato);
    free(elim);

    return 1;
}

t_lista * buscarMenor (t_lista * lista, int(*comparar)(const void *, const void *))
{
    t_lista * menor = lista;
    lista = &(*lista)->sig;

    while(*lista)
    {
        if(comparar((*lista)->dato, (*menor)->dato) < 0)
        {
            menor = lista;
        }
        lista = &(*lista)->sig;
    }

    return menor;
}

void ordenarMenMayNodo (t_lista * lista, int(*comparar)(const void *, const void *))
{
    t_lista * menor;
    t_nodo * temp;

    while(*lista && (*lista)->sig)
    {
        menor = buscarMenor (lista,comparar);
        if( *menor != *lista )///por si el menor es el primero que no se haga el cambio
        {
            temp = *menor;
            (*menor) = temp->sig;
            temp->sig = *lista;
            *lista = temp;
        }
        lista = &(*lista)->sig;
    }

}

void intercambiarMenor(t_lista * lista, t_lista * min)
{
    void * tempDato;///va a apuntar al dato/info de lista
    unsigned tempTam;

    tempDato = (*lista)->dato;
    tempTam = (*lista)->tam;

    (*lista)->dato = (*min)->dato;
    (*lista)->tam = (*min)->tam;

    (*min)->dato = tempDato;
    (*min)->tam = tempTam;

}

void ordenarMenMayDato(t_lista * lista, int(*comparar)(const void *, const void *))
{
    t_lista * min;

    while(*lista)
    {
        min = buscarMenor(lista,comparar);
        if(*min != *lista)
        {
            intercambiarMenor(lista,min);
        }
        lista = &(*lista)->sig;
    }
}

void vaciarLista (t_lista * lista)
{
    t_nodo * elim;
    while((*lista) && (*lista)->sig)
    {
        elim = *lista;
        *lista = (*lista)->sig;
        free(elim->dato);
        free(elim);
    }
    if(*lista)
    {
        elim = *lista;
        ///*lista = (*lista)->sig;
        free(elim->dato);
        free(elim);
    }

    *lista = NULL;
}

int elimNult (t_lista * lista, unsigned cant)
{
    t_nodo * elim;
    if(*lista && cant>0)
    {
        elim = *lista;
        while( elim->sig && (cant-1) )
        {
            elim = elim->sig;
            cant--;
        }
        if(elim->sig == NULL)///si esto pasa hay que vaciar toda
        {
            elim = *lista;
            while(*lista)
            {
                *lista = elim->sig;
                free(elim->dato);
                free(elim);
                elim = *lista;
            }
        }
        else
        {
            while( ((elim->sig))->sig )
            {
                elim = elim->sig;
                lista = &(*lista)->sig;
            }
            if(elim == *lista)
            {
                elim = elim->sig;
                free(elim->dato);
                free(elim);
                (*lista)->sig = NULL;
            }
            else
            {
                while(elim->sig)
                {
                    (*lista)->sig = elim->sig;
                    free(elim->dato);
                    free(elim);
                    elim = (*lista)->sig;
                }
                (*lista)->sig = elim->sig;
                free(elim->dato);
                free(elim);
            }
        }
    }
    else
        return 0;
    return 1;
}

int elimNprim (t_lista * lista, unsigned cant)
{
    t_nodo * elim;

    if(*lista && cant>0)
    {
        elim = (*lista);
        while(elim->sig && cant-1)
        {
            *lista = elim->sig;
            free(elim->dato);
            free(elim);
            cant--;
            elim = (*lista);
        }

        *lista = elim->sig;
        free(elim->dato);
        free(elim);

    }
    else
        return 0;

    return 1;
}

int elimXDup (t_lista * lista, void * dato,int(*comparar)(const void *, const void *))
{
    t_nodo * elim;
    int comp=0;
    if(*lista)
    {
        while((*lista)->sig && (comp=comparar((*lista)->dato,dato)) )
        {
            ///mientras no llegue a NULL y no encuentre el duplicado
            lista = &(*lista)->sig;
        }
        while((*lista)->sig)
        {
            if((comp=comparar(((*lista)->sig)->dato,dato))==0)
            {
                elim=(*lista)->sig;
                (*lista)->sig = (elim->sig);
                free(elim->dato);
                free(elim);
            }
            else
                lista = &(*lista)->sig;
        }
    }
    else
        return 0;

    return 1;
}

int elimDupOrd (t_lista * lista,int(*comparar)(const void *, const void *))
{
    t_nodo * elim;

    if(*lista)
    {
        while((*lista)->sig)
        {
            while((*lista)->sig && (comparar((*lista)->dato,((*lista)->sig)->dato))==0)
            {
                elim = (*lista)->sig;
                (*lista)->sig = elim->sig;
                free(elim->dato);
                free(elim);
            }

            if((*lista)->sig)
                lista = &(*lista)->sig;
        }
    }
    else
        return 0;

    return 1;

}

int elimDup (t_lista * lista,int(*comparar)(const void *, const void *))
{
    t_nodo * actual, * elim;
    if(!*lista)
        return 0;

    while((*lista)->sig)
    {
        actual = *lista;
        while(actual->sig)
        {
            if(actual->sig && comparar((*lista)->dato,(actual->sig)->dato)==0)
            {
                elim = actual->sig;
                actual->sig = elim->sig;
                free(elim->dato);
                free(elim);
            }
            else
                actual = actual->sig;
        }
        if((*lista)->sig)
            lista = &(*lista)->sig;
    }
    return 1;
}

int elimYAcumOrd (t_lista * lista,int(*comparar)(const void *, const void *),void*(*acumulacion)(void *, void *))
{
    t_nodo * actual;

    if(!*lista)
        return 0;

    while((*lista)->sig)
    {
        actual = (*lista)->sig;
        while(actual && comparar(actual->dato,(*lista)->dato)==0 )
        {
            acumulacion((*lista)->dato,actual->dato);
            (*lista)->sig = actual->sig;
            free(actual->dato);
            free(actual);
            actual = (*lista)->sig;
        }
        if((*lista)->sig)
            lista = &(*lista)->sig;
    }
    return 1;
}

int eliminarDuplicadosListaOrdenadaAcum (t_lista * lista,int(*comparar)(const void *, const void *), void*(*acumulacion)(void *, void *))
{
    t_nodo * elim;

    if(*lista)
    {
        while((*lista)->sig)
        {
            while((*lista)->sig && (comparar((*lista)->dato,((*lista)->sig)->dato))==0)
            {
                elim = (*lista)->sig;
                (*lista)->sig = elim->sig;
                acumulacion((*lista)->dato,elim->dato);
                free(elim->dato);
                free(elim);
            }
            if((*lista)->sig)
                lista = &(*lista)->sig;
        }
    }
    else
        return 0;

    return 1;
}

void recorrerFin(t_lista* lista, void(*accion)(const void *))
{
    t_lista listaPila;
    void * dato=malloc(1);
    if(!*lista)
        return;

    crearLista(&listaPila);///para apilar los valores que hay en la lista

    while((*lista))
    {
        insertarAlInicio(&listaPila,*lista,sizeof(t_lista));///apilo el puntero
        lista = &(*lista)->sig;
    }

    while(listaPila)
    {
        eliminar(&listaPila,dato,listaPila->tam);
        accion(dato);
    }

    free(dato);
}


///RECURSIVAS

///ordena la lista de menor a mayor
int insertarOrdenadoRec(t_lista* lista, void* info, unsigned tamBy, int(*comparar)(const void*, const void*))
{
    t_nodo* nue;
    int comp = 1;

    if((*lista) && ((comp = comparar(info, (*lista)->dato)) > 0))
    {
        return insertarOrdenadoRec(&(*lista)->sig,info, tamBy, comparar);
    }

    if(comp == 0 )
    {
        return 1;
    }
    else if(comp < 0   || !*lista)
    {
        nue =(t_nodo*)malloc(sizeof(t_nodo));
        if(!nue)
            return 0;
        nue->dato = malloc(tamBy);

        if(!(nue->dato))
        {
            free(nue);
            return 0;
        }

        memcpy(nue->dato, info, tamBy);
        nue->tam = tamBy;
        nue->sig = *lista;
        *lista = nue;
    }

    return 1;
}

int insertarAlFinalRec(t_lista * lista, const void*info,unsigned cantBy)
{
    t_nodo * nue;
    if(*lista)
        return insertarAlFinalRec(&(*lista)->sig,info,cantBy);

    nue =(t_nodo*)malloc(sizeof(t_nodo));
    if(!nue)
        return 0;
    nue->dato = malloc(cantBy);

    if(!(nue->dato))
    {
        free(nue);
        return 0;
    }

    memcpy(nue->dato, info, cantBy);
    nue->tam = cantBy;
    nue->sig = NULL;
    (*lista) = nue;

    return 1;
}

int insertarEnPosRec(t_lista * lista, const void*info,unsigned cantBy, unsigned pos)
{
    t_nodo * nue;
    if(*lista && pos)
        return insertarEnPosRec(&(*lista)->sig,info,cantBy,pos-1);

    nue =(t_nodo*)malloc(sizeof(t_nodo));
    if(!nue)
        return 0;
    nue->dato = malloc(cantBy);

    if(!(nue->dato))
    {
        free(nue);
        return 0;
    }

    memcpy(nue->dato, info, cantBy);
    nue->tam = cantBy;
    nue->sig = (*lista);
    (*lista) = nue;

    return 1;
}

void vaciarListaRec (t_lista * lista)
{
    t_nodo * elim;

    if(*lista)
    {
        vaciarListaRec(&(*lista)->sig);
        elim = *lista;
        free(elim->dato);
        free(elim);
        *lista = NULL;
    }
}

int elimNultRec (t_lista * lista, unsigned cant)
{
    t_nodo * elim;
    int res=cant;
    if(!*lista)
        return 0;

    if(cant)
    {
        res = elimNultRec (&(*lista)->sig,cant);
    }

    if(res<cant)
    {
        elim = *lista;
        free(elim->dato);
        free(elim);
        *lista = NULL;
        return res+1;
    }

    return res;
}

int elimNprimRec (t_lista * lista, unsigned cant)
{
    t_nodo * elim;
    if(!*lista)
        return 0;

    if(cant)
    {
        elim = *lista;
        *lista = elim->sig;
        free(elim->dato);
        free(elim);
        cant-=1;
    }

    if(*lista && cant)
    {
        return elimNprimRec ((lista),cant);
    }

    return 1;
}

///tambien dice cuantos nodos duplicados borro
int elimDupEnv (t_lista * lista,int(*comparar)(const void *, const void *))
{
    int res=0;
    if(!*lista)
        return res;

    res+=elimDupRec((*lista)->dato,lista,comparar);
    res+=elimDupEnv(&(*lista)->sig,comparar);
    return res;
}

int elimDupRec (void * actual, t_lista * lista, int(*comparar)(const void *, const void *))
{
    t_nodo * elim;
    if(!(*lista)->sig)
        return 0;

    if( comparar(actual,((*lista)->sig)->dato)==0 )
    {
        elim = (*lista)->sig;
        (*lista)->sig = elim->sig;
        free(elim->dato);
        free(elim);
        return elimDupRec(actual,lista,comparar)+1;
    }
    return elimDupRec(actual,&(*lista)->sig,comparar);
}

int elimDupOrdEnv (t_lista * lista,int(*comparar)(const void *, const void *))
{
    int res=0;
    if(!*lista)
        return res;

    res+=elimDupOrdRec((*lista)->dato,lista,comparar);
    res+=elimDupOrdEnv(&(*lista)->sig,comparar);
    return res;
}

int elimDupOrdRec(void * actual, t_lista * lista, int(*comparar)(const void *, const void *))
{
    t_nodo * elim;
    int comp;
    if(!(*lista)->sig)
        return 0;

    comp = comparar(actual,((*lista)->sig)->dato);
    if( comp==0 )
    {
        elim = (*lista)->sig;
        (*lista)->sig = elim->sig;
        free(elim->dato);
        free(elim);
        return elimDupOrdRec(actual,lista,comparar)+1;
    }
    else if( comp<0 )
        return 0;

    return elimDupOrdRec(actual,&(*lista)->sig,comparar);
}


///buscarNodoEnListaRec
int elimXnodoEnv (t_lista * lista, void * dato, unsigned tamBy, int(*comparar)(const void *, const void *))
{
    t_lista * anterior;
    t_nodo * elim;
    if(!*lista)
        return 0;

    if( comparar((*lista)->dato,dato)==0 )
    {
        memcpy(dato, (*lista)->dato,MIN(tamBy,(*lista)->tam));
        elim = *lista;
        *lista = elim->sig;
        free(elim->dato);
        free(elim);
        return 1;
    }

    anterior = buscarNodoEnListaRec(lista,dato,comparar);

    if(anterior)
    {
        elim = (*anterior)->sig;
        memcpy(dato, elim->dato,MIN(tamBy,elim->tam));
        (*anterior)->sig = elim->sig;
        free(elim->dato);
        free(elim);
        return 1;
    }

    return 0;
}

void recorrerFinRec(t_lista* lista, void(*accion)(const void *))
{
    if(!*lista)
        return;

    /// if((*lista)->sig)
    /// {
    recorrerFinRec(&(*lista)->sig,accion);
    /// }
    accion((*lista)->dato);
}

void recorrerIniRec(t_lista* lista, void(*accion)(const void *))
{
    if(!*lista)
        return;

    accion((*lista)->dato);

    recorrerIniRec(&(*lista)->sig,accion);
}

///actualiza los datos ya escritos en la lista, a partir de nueva informacion
int actualizarDatosRec (t_lista * lista, void * dato,int(*comparar)(const void *, const void *),void*(*acumulacion)(void *, void *))
{
    int comp;
    comp = comparar((*lista)->dato,dato);///ver que pasa en cada caso
    if( (*lista)->sig && comp<0)
    {
        lista = &((*lista)->sig);
        return actualizarDatosRec(lista,dato,comparar,acumulacion);
    }

    if(comp == 0)
    {
        ///solo acumula si encuentra el valor, cualquier otra cosa es un error
        acumulacion((*lista)->dato,dato);
        return 1;///encontro y acumulo
    }

    return 0;///la funcion que la invoca se tiene que encargar de registrar el error
}

void ordenarMenMayDatoRec(t_lista * lista, int(*comparar)(const void *, const void *))
{
    t_lista * men;
    t_nodo * datoTemp;
    if(!*lista)
        return;

    men = buscarMenEnv(lista,comparar);
    if(men!=lista)
    {
        datoTemp = (*men)->dato;
        (*men)->dato = (*lista)->dato;
        (*lista)->dato = datoTemp;
    }
    ordenarMenMayDatoRec(&(*lista)->sig,comparar);
}

void ordenarMayMenDatoRec(t_lista * lista, int(*comparar)(const void *, const void *))
{
    t_lista * may;
    t_nodo * datoTemp;
    if(!*lista)
        return;

    may = buscarMayEnv(lista,comparar);
    if(may!=lista)
    {
        datoTemp = (*may)->dato;
        (*may)->dato = (*lista)->dato;
        (*lista)->dato = datoTemp;
    }
    ordenarMayMenDatoRec(&(*lista)->sig,comparar);
}

int buscarEnListaRec(t_lista * lista, void * info, int(*comparar)(const void *, const void *))
{
    int comp=1;
    if(!*lista)
        return 0;

    comp = comparar((*lista)->dato,info);
    if(comp)
    {
        return buscarEnListaRec(&(*lista)->sig,info,comparar);
    }
    else///encontro el dato
    {
        memcpy(info,(*lista)->dato,(*lista)->tam);
        return 1;
    }
}

t_lista * buscarNodoEnListaRec(t_lista * lista, void * info, int(*comparar)(const void *, const void *))
{
    int comp=1;
    t_nodo * auxSig;
    if(!*lista)
        return NULL;

    auxSig = (*lista)->sig;

    comp = comparar(auxSig->dato,info);
    if(comp)
    {
        return buscarNodoEnListaRec(&(auxSig),info,comparar);
    }
    else///encontro el dato
    {
        return (lista);
    }
}

int buscarEnListaOrdRec(t_lista * lista, void * info, int(*comparar)(const void *, const void *))
{
    int comp=1;
    if(!*lista)
        return 0;

    comp = comparar((*lista)->dato,info);
    if(comp<0)
    {
        return buscarEnListaOrdRec(&(*lista)->sig,info,comparar);
    }
    else if(comp==0)///encontro el dato
    {
        memcpy(info,(*lista)->dato,(*lista)->tam);
        return 1;
    }

    return 0;
}

t_lista * buscarMayEnv(t_lista * lista, int(*comparar)(const void *, const void *))
{
    t_lista * mayor;
    if(!*lista)
        return NULL;
    mayor = lista;
    return buscarMayRec(mayor,&(*lista)->sig,comparar);
}

t_lista * buscarMayRec (t_lista * mayor, t_lista * siguiente, int(*comparar)(const void *, const void *))
{
    int comp;
    if(!*siguiente)
        return mayor;

    comp = comparar((*mayor)->dato,(*siguiente)->dato);
    if(comp>=0)
    {
        return buscarMayRec(mayor,&(*siguiente)->sig,comparar);
    }
    else
    {
        mayor = siguiente;
        return buscarMayRec(mayor,&(*siguiente)->sig,comparar);
    }
}

t_lista * buscarMenEnv(t_lista * lista, int(*comparar)(const void *, const void *))
{
    t_lista * menor;
    if(!*lista)
        return NULL;
    menor = lista;
    return buscarMenRec(menor,&(*lista)->sig,comparar);
}

t_lista * buscarMenRec (t_lista * menor, t_lista * siguiente, int(*comparar)(const void *, const void *))
{
    int comp;
    if(!*siguiente)
        return menor;

    comp = comparar((*menor)->dato,(*siguiente)->dato);
    if(comp<=0)
    {
        return buscarMenRec(menor,&(*siguiente)->sig,comparar);
    }
    else
    {
        menor = siguiente;
        return buscarMenRec(menor,&(*siguiente)->sig,comparar);
    }
}

void* acumularListaRec (t_lista*lista,void*acumulador,void*(*acumulacion)(void*,void*))
{
    if(!*lista)
        return acumulador;

    acumulacion(acumulador,(*lista)->dato);
    return acumularLista(&(*lista)->sig,acumulador,acumulacion);
}

void filtrarRec (t_lista* lista,int(*fFiltro)(const void*))
{
    t_nodo * elim;
    if(!*lista)
        return;

    if(fFiltro((*lista)->dato))
    {
        elim=*lista;
        *lista=elim->sig;
        free(elim->dato);
        free(elim);
        filtrarRec(lista,fFiltro);
    }
    else
    {
        filtrarRec(&(*lista)->sig,fFiltro);
    }


}

void promedioCond (t_lista * lista, void * acum, void * prom, int fFiltro(const void* a),void* (*acumular)(void * acum, void *n), void (*promedio)(void * prom, const void * acum, const void * cant))
{
    int cantNodos=0;
    if(!*lista)
        return;

    cantNodos = promedioCondRec(lista,acum,fFiltro,acumular);

    promedio(prom,acum,&cantNodos);
}

int promedioCondRec (t_lista * lista, void * acum, int fFiltro(const void* a),void* (*acumular)(void * acum, void *n))
{
    if(!*lista)
        return 0;

    if( fFiltro((*lista)->dato ) )
    {
        acumular((void*)acum,(*lista)->dato);
        return promedioCondRec(&(*lista)->sig,acum,fFiltro,acumular) + 1;
    }

    return promedioCondRec(&(*lista)->sig,acum,fFiltro,acumular);
}

















