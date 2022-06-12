#include "listaSimple.h"
#include <stdlib.h>
#include <string.h>

void crearLista(t_lista *lista)
{
    *lista=NULL;
}

int insertarAlFinal(t_lista *lista, const void *info, unsigned tamBy)
{
    t_nodo* nuevo = (t_nodo*)malloc(sizeof(t_nodo));
    if(!nuevo)
    {
        return 0;
    }
    while(*lista)
    {
        lista = &(*lista)->sig;
    }
    nuevo->info = malloc(tamBy);

    if(!(nuevo->info))
    {
        free(nuevo);
        return 0;
    }
    memcpy(nuevo->info,info,tamBy);
    nuevo->tamBy = tamBy;
    nuevo->sig = *lista;
    *lista = nuevo;
    return 1;
}

int insertarAlInicio (t_lista * lista, const void* info, unsigned tamBy)
{
    t_nodo * nue = malloc(sizeof(t_nodo));
    if(!nue)
    {
        return 0;
    }
    nue->info = malloc(tamBy);
    if(!nue->info)
    {
        free(nue);
        return 0;
    }

    memcpy(nue->info,info,tamBy);
    memcpy(&(nue->tamBy),&tamBy,sizeof(unsigned));

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

    nuevo->info = malloc(tamBy);

    if(!(nuevo->info))
    {
        free(nuevo);
        return 0;
    }

    memcpy(nuevo->info, info, tamBy);

    nuevo->tamBy = tamBy;

    nuevo->sig = *lista;

    *lista = nuevo;

    return 1;

}

int insertarOrdenado(t_lista* lista, void* info, unsigned tamBy, int duplic, int(*comparar)(const void*, const void*))
{
    t_nodo* nue = (t_nodo*)malloc(sizeof(t_nodo));
    int comp = 1;

    if(!nue)
        return 0;

    while((*lista) && ((comp = comparar(((*lista)->info),info)) < 0))
    {
        lista = &(*lista)->sig;
    }

    if(comp == 0 && !duplic)
    {
        return 1;
    }

    nue->info = malloc(tamBy);

    if(!(nue->info))
    {
        free(nue);
        return 0;
    }

    memcpy(nue->info, info, tamBy);
    nue->tamBy = tamBy;
    nue->sig = *lista;
    *lista = nue;

    return 1;
}

//int insertarOrdenadoRec(t_lista* lista, void* info, unsigned tamBy, int duplic, int(*comparar)(const void*, const void*))
//{
//    t_nodo* nue;
//    int comp = 1;
//
//    if((*lista) && ((comp = comparar(((*lista)->info),info)) < 0))
//    {
//        return insertarOrdenadoRec(&(*lista)->sig,info, tamBy, duplic, comparar);
//    }
//
//    if(comp == 0 && !duplic)
//    {
//        return 1;
//    }
//    else if(comp > 0   || !*lista)
//    {
//        nue =(t_nodo*)malloc(sizeof(t_nodo));
//        if(!nue)
//            return 0;
//        nue->info = malloc(tamBy);
//
//        if(!(nue->info))
//        {
//            free(nue);
//            return 0;
//        }
//
//        memcpy(nue->info, info, tamBy);
//        nue->tamBy = tamBy;
//        nue->sig = *lista;
//        *lista = nue;
//    }
//
//    return 1;
//}

void recorrerLista(t_lista* lista, void (*accion) (const void*)) /// Recorre la lista mientras realiza una accion;
{
    while(*lista)
    {
        accion((*lista)->info);
        lista = &(*lista)->sig;
    }
}

void filtrarLista(t_lista* lista, int(*fFiltro) (const void*)) /// Elimina nodos en los que el dato no cumple la condicion dada segun una funcion enviada
{
    t_nodo* elim;
    while(*lista)
    {
        if(!fFiltro((*lista)->info))
        {
            elim = *lista;
            *lista = elim->sig;
            free(elim->info);
            free(elim);
        }
        else
            lista = &(*lista)->sig;
    }
}

void* acumularDeLista(t_lista* lista, void* acumulador, void* (*acumulacion)(void*, void*)) /// Acumula los datos de la lista segun la funcion enviada
{
    while(*lista)
    {
        acumulacion(acumulador,(*lista)->info);
        lista = &(*lista)->sig;
    }

    return acumulador;
}

int buscarEnListaOrd(t_lista* lista, void* info, int(*comparar)(const void*, const void*))
{
    int cmp = 1;
    t_nodo* elim;

    while(*lista && ((cmp = comparar(info, (*lista)->info))>0))
    {
        lista = &(*lista)->sig;
    }

    if(cmp)
    {
        return 0;
    }

    elim = *lista;
    memcpy(info, elim->info, elim->tamBy);

    *lista = elim->sig;
    free(elim->info);
    free(elim);

    return 1;
}

t_lista* buscarMenor(t_lista* lista, int(*comparar)(const void*, const void*))
{
    t_lista* menor = lista;

    lista = &(*lista)->sig;
    while(*lista)
    {

        if(comparar((*lista)->info, (*menor)->info)<0)
        {
            menor=lista;
        }
        lista = &(*lista)->sig;
    }

    return menor;
}

void ordenarLista(t_lista* lista, int(*comparar)(const void*, const void*))
{
    t_lista* menor;
    t_nodo* temp;

    while(*lista)
    {
        menor = buscarMenor(lista, comparar);

        if(*menor != *lista)
        {
            temp = *menor;
            (*menor)=temp->sig;
            temp->sig = *lista;
            *lista = temp;
        }
        lista = &(*lista)->sig;
    }
}

void intercambiarMenor(t_lista * lista, t_lista * minimo)
{
    void * tempInfo;
    unsigned tempTam;

    tempInfo = (*lista)->info;
    tempTam = (*lista)->tamBy;

    (*lista)->info = (*minimo)->info;
    (*lista)->tamBy = (*minimo)->tamBy;

    (*minimo)->info = tempInfo;
    (*minimo)->tamBy = tempTam;

}

void ordenarMenMayAlt(t_lista * lista, int(*comparar)(const void *, const void *))
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

void* buscarEnLista(t_lista* lista, void* info, void* (*comparar)(const void*, const void*))
{
    while(*lista && !comparar((*lista)->info, info))
    {
        lista = &(*lista)->sig;
    }
    return lista;
}

int eliminarDeLista(t_lista* lista, void* info, unsigned tamBy)
{
    t_nodo* elim;
    if(!(*lista))
    {
        return 0;
    }
    elim = *lista;
    memcpy(info, (*lista)->info, MIN(tamBy, (*lista)->tamBy));
    *lista = elim->sig;
    free(elim->info);
    free(elim);

    return 1;
}

int eliminarNUltimos (t_lista* lista, unsigned cant)
{
    t_nodo* elim;
    if(*lista && cant>0)
    {
        elim = *lista;
        while(elim->sig && (cant-1))
        {
            elim = elim->sig;
            cant--;
        }
        if(elim->sig == NULL)
        {
            elim = *lista;
            while(*lista)
            {
                *lista = elim->sig;
                free(elim->info);
                free(elim);
                elim = *lista;
            }
        }
        else
        {
            while((elim->sig)->sig )
            {
                elim = elim->sig;
                lista = &(*lista)->sig;
            }
            if(elim == *lista)
            {
                elim = elim->sig;
                free(elim->info);
                free(elim);
                (*lista)->sig = NULL;
            }
            else
            {
                while(elim->sig)
                {
                    (*lista)->sig = elim->sig;
                    free(elim->info);
                    free(elim);
                    elim = (*lista)->sig;
                }
                (*lista)->sig = elim->sig;
                free(elim->info);
                free(elim);
            }
        }
    }
    else
        return 0;
    return 1;
}

int eliminarNprimeros (t_lista* lista, unsigned cant)
{
    t_nodo * elim;

    if(*lista && cant>0)
    {
        elim = (*lista);
        while(elim->sig && cant-1)
        {
            *lista = elim->sig;
            free(elim->info);
            free(elim);
            cant--;
            elim = (*lista);
        }

        *lista = elim->sig;
        free(elim->info);
        free(elim);

    }
    else
        return 0;

    return 1;
}

int eliminarXDuplicados (t_lista* lista, void* info, int(*comparar)(const void *, const void *))
{
    t_nodo * elim;
    int comp=0;
    if(*lista)
    {
        while((*lista)->sig && (comp=comparar((*lista)->info,info)) )
        {
            lista = &(*lista)->sig;
        }
        while((*lista)->sig)
        {
            if((comp=comparar(((*lista)->sig)->info,info))==0)
            {
                elim=(*lista)->sig;
                (*lista)->sig = (elim->sig);
                free(elim->info);
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

int eliminarDupOrd (t_lista* lista, int(*comparar)(const void*, const void*))
{
    t_nodo * elim;

    if(*lista)
    {
        while((*lista)->sig)
        {
            while((*lista)->sig && (comparar((*lista)->info,((*lista)->sig)->info))==0)
            {
                elim = (*lista)->sig;
                (*lista)->sig = elim->sig;
                free(elim->info);
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

int elimDup (t_lista* lista, int(*comparar)(const void*, const void*))
{
    t_nodo *actual, *elim;
    if(!*lista)
        return 0;

    while((*lista)->sig)
    {
        actual = *lista;
        while(actual->sig)
        {
            if(actual->sig && comparar((*lista)->info,(actual->sig)->info)==0)
            {
                elim = actual->sig;
                actual->sig = elim->sig;
                free(elim->info);
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
        while(actual && comparar(actual->info,(*lista)->info)==0 )
        {
            acumulacion((*lista)->info,actual->info);
            (*lista)->sig = actual->sig;
            free(actual->info);
            free(actual);
            actual = (*lista)->sig;
        }
        if((*lista)->sig)
            lista = &(*lista)->sig;
    }
    return 1;
}

void vaciarLista (t_lista* lista)
{
    t_nodo * elim;
    while((*lista) && (*lista)->sig)
    {
        elim = *lista;
        *lista = (*lista)->sig;
        free(elim->info);
        free(elim);
    }
    if(*lista)
    {
        elim = *lista;
        ///*lista = (*lista)->sig;
        free(elim->info);
        free(elim);
    }

    *lista = NULL;
}

void recorrerFin(t_lista* lista, void(*accion)(const void *))
{
    t_lista listaPila;
    void * info=malloc(1);
    if(!*lista)
        return;

    crearLista(&listaPila);///para apilar los valores que hay en la lista

    while((*lista))
    {
        insertarAlInicio(&listaPila,(*lista)->info,(*lista)->tamBy);///apilo los datos
        lista = &(*lista)->sig;
    }

    while(listaPila)
    {
        eliminarDeLista(&listaPila,info,listaPila->tamBy);
        accion(info);
    }

    free(info);
}

//void recorrerFinRec(t_lista* lista, void(*accion)(const void *))
//{
//    if(!*lista)
//        return;
//
//    recorrerFinRec(&(*lista)->sig,accion);
//    accion((*lista)->info);
//}
//
//void recorrerIniRec(t_lista* lista, void(*accion)(const void *))
//{
//    if(!*lista)
//        return;
//
//    accion((*lista)->info);
//    recorrerIniRec(&(*lista)->sig,accion);
//
//}

///RECURSIVAS

///ordena la lista de menor a mayor
int insertarOrdenadoRec(t_lista* lista, void* info, unsigned tamBy, int(*comparar)(const void*, const void*))
{
    t_nodo* nue;
    int comp = 1;

    if((*lista) && ((comp = comparar(info, (*lista)->info)) > 0))
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
        nue->info = malloc(tamBy);

        if(!(nue->info))
        {
            free(nue);
            return 0;
        }

        memcpy(nue->info, info, tamBy);
        nue->tamBy = tamBy;
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
    nue->info = malloc(cantBy);

    if(!(nue->info))
    {
        free(nue);
        return 0;
    }

    memcpy(nue->info, info, cantBy);
    nue->tamBy = cantBy;
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
    nue->info = malloc(cantBy);

    if(!(nue->info))
    {
        free(nue);
        return 0;
    }

    memcpy(nue->info, info, cantBy);
    nue->tamBy = cantBy;
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
        free(elim->info);
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
        free(elim->info);
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
        free(elim->info);
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

    res+=elimDupRec((*lista)->info,lista,comparar);
    res+=elimDupEnv(&(*lista)->sig,comparar);
    return res;
}

int elimDupRec (void * actual, t_lista * lista, int(*comparar)(const void *, const void *))
{
    t_nodo * elim;
    if(!(*lista)->sig)
        return 0;

    if( comparar(actual,((*lista)->sig)->info)==0 )
    {
        elim = (*lista)->sig;
        (*lista)->sig = elim->sig;
        free(elim->info);
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

    res+=elimDupOrdRec((*lista)->info,lista,comparar);
    res+=elimDupOrdEnv(&(*lista)->sig,comparar);
    return res;
}

int elimDupOrdRec(void * actual, t_lista * lista, int(*comparar)(const void *, const void *))
{
    t_nodo * elim;
    int comp;
    if(!(*lista)->sig)
        return 0;

    comp = comparar(actual,((*lista)->sig)->info);
    if( comp==0 )
    {
        elim = (*lista)->sig;
        (*lista)->sig = elim->sig;
        free(elim->info);
        free(elim);
        return elimDupOrdRec(actual,lista,comparar)+1;
    }
    else if( comp<0 )
        return 0;

    return elimDupOrdRec(actual,&(*lista)->sig,comparar);
}

void recorrerFinRec(t_lista* lista, void(*accion)(const void *))
{
    if(!*lista)
        return;

   /// if((*lista)->sig)
   /// {
        recorrerFinRec(&(*lista)->sig,accion);
   /// }
    accion((*lista)->info);
}

void recorrerIniRec(t_lista* lista, void(*accion)(const void *))
{
    if(!*lista)
        return;

    accion((*lista)->info);

    recorrerIniRec(&(*lista)->sig,accion);
}

///actualiza los datos ya escritos en la lista, a partir de nueva informacion
int actualizarDatosRec (t_lista * lista , void * info,int(*comparar)(const void *, const void *),void*(*acumulacion)(void *, void *))
{
    int comp;
    comp = comparar((*lista)->info,info);///ver que pasa en cada caso
    if( (*lista)->sig && comp<0)
    {
        lista = &((*lista)->sig);
        return actualizarDatosRec(lista,info,comparar,acumulacion);
    }

    if(comp == 0)
    {///solo acumula si encuentra el valor, cualquier otra cosa es un error
        acumulacion((*lista)->info,info);
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
        datoTemp = (*men)->info;
        (*men)->info = (*lista)->info;
        (*lista)->info = datoTemp;
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
        datoTemp = (*may)->info;
        (*may)->info = (*lista)->info;
        (*lista)->info = datoTemp;
    }
    ordenarMayMenDatoRec(&(*lista)->sig,comparar);
}

int buscarEnListaRec(t_lista * lista, void * info, int(*comparar)(const void *, const void *))
{
    int comp=1;
    if(!*lista)
        return 0;

    comp = comparar((*lista)->info,info);
    if(comp)
    {
        return buscarEnListaRec(&(*lista)->sig,info,comparar);
    }
    else///encontro el dato
    {
        memcpy(info,(*lista)->info,(*lista)->tamBy);
        return 1;
    }
}

int buscarEnListaOrdRec(t_lista * lista, void * info, int(*comparar)(const void *, const void *))
{
    int comp=1;
    if(!*lista)
        return 0;

    comp = comparar((*lista)->info,info);
    if(comp<0)
    {
        return buscarEnListaOrdRec(&(*lista)->sig,info,comparar);
    }
    else if(comp==0)///encontro el info
    {
        memcpy(info,(*lista)->info,(*lista)->tamBy);
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

    comp = comparar((*mayor)->info,(*siguiente)->info);
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

    comp = comparar((*menor)->info,(*siguiente)->info);
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

    acumulacion(acumulador,(*lista)->info);
    return acumularListaRec(&(*lista)->sig,acumulador,acumulacion);
}

void filtrarRec (t_lista* lista,int(*fFiltro)(const void*))
{
    t_nodo * elim;
    if(!*lista)
        return;

    if(fFiltro((*lista)->info))
    {
        elim=*lista;
        *lista=elim->sig;
        free(elim->info);
        free(elim);
        filtrarRec(lista,fFiltro);
    }
    else
    {
        filtrarRec(&(*lista)->sig,fFiltro);
    }

}
