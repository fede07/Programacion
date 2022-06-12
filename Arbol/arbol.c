#include "arbol.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void crearArbol(t_arbol *arbol)
{
    *arbol = NULL;
}

int insertarArbolRec(t_arbol *arbol, const void* dato, unsigned tamBy, int (*comparar)(const void*, const void*))
{
    t_nodo* nuevo;
    int comp;
    if(*arbol)
    {

        if((comp=comparar((*arbol)->info,dato))>0)
        {
            return insertarArbolRec(&(*arbol)->izq,dato,tamBy,comparar);
        }
        else if(comp<0)
        {
            return insertarArbolRec(&(*arbol)->der,dato,tamBy,comparar);
        }
        else
        {
            return 0;
        }
    }

    nuevo=malloc(sizeof(t_nodo));
    if(!nuevo)
    {
        return 0;
    }
    nuevo->info=malloc(tamBy);
    if(!(nuevo->info))
    {
        free(nuevo);
        return 0;
    }

    memcpy(nuevo->info,dato,tamBy);
    nuevo->tamBy=tamBy;
    nuevo->izq=NULL;
    nuevo->der=NULL;
    *arbol=nuevo;

    return 1;
}

int insertarArbol(t_arbol *arbol, void *dato, unsigned tam, int (*comparar)(const void *, const void *))
{
    t_nodo *nuevo = malloc(sizeof(t_nodo));
    int comp;
    if(!nuevo)
        return 0;
    nuevo->info = malloc(tam);
    if(!nuevo->info)
    {
        free(nuevo);
        return 0;
    }

    memcpy(nuevo->info,dato,tam);
    memcpy(&(nuevo->tamBy),&tam,sizeof(unsigned));
    nuevo->der = NULL;
    nuevo->izq = NULL;

    if(!*arbol)
    {
        *arbol = nuevo;
        return 1;
    }

    comp = comparar(nuevo->info,(*arbol)->info);

    while( (comp<0 && (*arbol)->izq) || (comp>0 && (*arbol)->der) )
    {///el while busca donde hay que insertarlo (o no si son iguales)
        if(comp<0)
            arbol = &(*arbol)->izq;
        else
            arbol = &(*arbol)->der;

        comp = comparar(nuevo->info,(*arbol)->info);
    }

    if(comp==0)
    {
        free(nuevo->info);
        free(nuevo);
        return 0;
    }
    else if(comp<0)
        (*arbol)->izq = nuevo;
    else
        (*arbol)->der = nuevo;

    return 1;
}

void preOrden(t_arbol *arbol, void(*accion)(const void*)) ///RID
{
    if(!(*arbol))
    {
        return;
    }

    accion((*arbol)->info);
    preOrden(&(*arbol)->izq,accion);
    preOrden(&(*arbol)->der,accion);
}

void inOrden(t_arbol *arbol, void(*accion)(const void*)) ///IRD
{
    if(!(*arbol))
    {
        return;
    }

    inOrden(&(*arbol)->izq,accion);
    accion((*arbol)->info);
    inOrden(&(*arbol)->der,accion);
}

void posOrden(t_arbol * arbol, void(*accion)(const void*)) ///IDR
{
    if(!(*arbol))
    {
        return;
    }

    posOrden(&(*arbol)->izq,accion);
    posOrden(&(*arbol)->der,accion);
    accion((*arbol)->info);
}

void rotar90g_i(t_arbol *arbol, void(*accion)(const void*))
{
    if(!*arbol)
        return;

    rotar90Rec(&(*arbol)->der,1,accion);
    accion((*arbol)->info);
    rotar90Rec(&(*arbol)->izq,1,accion);
}

void rotar90Rec(t_arbol *arbol,int nivel,void(*accion)(const void*))
{
    if(!*arbol)
        return;

    ///printf("\t");
    rotar90Rec(&(*arbol)->der,nivel+1,accion);
    tabRec(nivel,0);
    ///printf("\t");
    accion((*arbol)->info);
    ///printf("\t");
    rotar90Rec(&(*arbol)->izq,nivel+1,accion);
}

void tabRec(int nivel,int cont)
{
  if((nivel)>cont)
  {
      printf("\t");
      tabRec(nivel,cont+1);
  }
  return;
}

int nivelXCompYBal (t_arbol *arbol, unsigned nivel)
{
    if(!*arbol)
        return 0;

    return nivelXCompYBalRec(arbol,nivel);
}

int nivelXCompYBalRec (t_arbol *arbol, unsigned nivel)
{
    int der, izq;

    if( ((*arbol)->der && (*arbol)->izq) && nivel)
    {
        ///entra si tiene nodo derecho e izquierdo, y todavia no se llego al nivel pedido
        izq = nivelXCompYBalRec (&(*arbol)->izq,nivel-1);
        der = nivelXCompYBalRec (&(*arbol)->der,nivel-1);
        if(izq && der)
        {
            return 1;
        }
    }
    else if(nivel == 0)///se llego hasta el nivel pedido
    {
        return 1;
    }
    return 0;
}

unsigned nivelComp (t_arbol *arbol)
{
    unsigned nivelMin, nivelActual;
    if(!*arbol)
        return 0;

    nivelMin = 0;
    nivelActual = 0;

    return nivelCompRec (arbol,&nivelMin,nivelActual);
}

unsigned nivelCompRec (t_arbol *arbol, unsigned * nivelMin, unsigned nivelActual)
{
    unsigned izq, der;

    ///entra mientras el nodo no tenga algun nulo
    ///Y
    ///sea la primera vez lo recorre (nivelMin == 0)
    ///O
    ///ya haya llegado al tope encontrado en una rama previa (*nivelMin)>=nivelActual
    ///si una rama encontro tope 2 no tiene sentido que las demas vean mas que el 2

    if( ((*arbol)->der && (*arbol)->izq) && (*nivelMin == 0 || (*nivelMin)>=nivelActual) )
    {
        der = nivelCompRec(&(*arbol)->der,nivelMin,nivelActual+1);
        izq = nivelCompRec(&(*arbol)->izq,nivelMin,nivelActual+1);

        if(*nivelMin>izq || *nivelMin>der)
        ///cuando se llega a un nodo sin hijos, si el nivel encontrado es menor
        ///que el nivelMin de antes hay que actualizarlo
            *nivelMin = MIN(izq,der);

        return *nivelMin;
    }
    if(*nivelMin==0)///setea el nivelMin en la primera recorrida completa
        *nivelMin = nivelActual;

    return nivelActual;
}

void podarDesdeXNivel (t_arbol *arbol, unsigned nivel)
{
    int nivelActual;
    if(!*arbol)
        return;

    nivelActual = 0;

    talarXNivel(arbol,nivel,nivelActual);
}

void talarXNivel(t_arbol *arbol, unsigned nivel, unsigned nivelActual)
{
    if(!*arbol)
        return;

    if(nivelActual<nivel)
    {
        talarXNivel(&(*arbol)->izq,nivel,nivelActual+1);
        talarXNivel(&(*arbol)->der,nivel,nivelActual+1);
    }
    else
    {
        talarRec (&(*arbol)->izq);
        talarRec (&(*arbol)->der);
        (*arbol)->der = NULL;
        (*arbol)->izq = NULL;
    }
}

void talar (t_arbol *arbol)
{
    talarRec (arbol);
    *arbol = NULL;
}

void talarRec (t_arbol *arbol)
{
    if(!*arbol)
        return;

    talarRec (&(*arbol)->izq);
    talarRec (&(*arbol)->der);

    free((*arbol)->info);
    free((*arbol));
}

void podarHojas(t_arbol *arbol)
{
    if(!*arbol)
        return;
    if(!(*arbol)->der && !(*arbol)->izq)
    {
        free((*arbol)->info);
        free(*arbol);
        *arbol = NULL;
    }
    else
    {
        podarHojas(&(*arbol)->izq);
        podarHojas(&(*arbol)->der);
    }
}

int eliminarNodo(t_arbol * arbol)
{
    t_nodo * elim;
    t_arbol * remp;
    int hIzq, hDer;
    if(!*arbol)
        return 0;
    free((*arbol)->info);
    ///por si
    if(!(*arbol)->izq && !(*arbol)->der)
    {
        free(*arbol);
        *arbol = NULL;
        return 1;
    }

    hDer = altura(&(*arbol)->der);
    hIzq = altura(&(*arbol)->izq);

    ///guardo el nodo necesario perteneciente al subarbol de mayor altura
    if(hIzq<hDer)
        remp = buscarMenor(&(*arbol)->der);
    else
        remp = buscarMenor(&(*arbol)->izq);

    (*arbol)->info = (*remp)->info;
    (*arbol)->tamBy = (*remp)->tamBy;

    elim = *remp;
    (*remp) = (*remp)->izq?(*remp)->izq:(*remp)->der;

    free(elim);
    return 1;
}

unsigned altura(t_arbol *arbol)
{
    int altura = 0;
    if(!*arbol)
        return altura;

    return alturaRec(arbol,altura);
}

int alturaRec(t_arbol *arbol, unsigned altura)
{
    int altDer = 0, altIzq = 0;
    if(!*arbol)
        return altura;

    altIzq = alturaRec(&(*arbol)->izq,altura+1);
    altDer = alturaRec(&(*arbol)->der,altura+1);

    return (altIzq>altDer)?altIzq:altDer;
}

//int esBalanceado(t_arbol *arbol)
//{
//    int nivelMax, nivelActual;
//    if(!*arbol)
//        return 0;
//
//    nivelMax = 0;
//    nivelActual = 0;
//    balanceadoRec(arbol,&nivelMax,nivelActual);
//    return nivelMax==-1?0:1;
//}
//
//void balanceadoRec(t_arbol *arbol, int *nivelMax, int nivelActual)
//{
//    if(*nivelMax!=(-1) && ((*arbol)->der && (*arbol)->izq) && (*nivelMax == 0 || (*nivelMax)>=nivelActual))
//    {
//        balanceadoRec(&(*arbol)->izq,nivelMax,nivelActual+1);
//        balanceadoRec(&(*arbol)->der,nivelMax,nivelActual+1);///3
//
//        return;
//    }
//    if(*nivelMax==0)///setea el nivelMin en la primera recorrida completa
//        *nivelMax = nivelActual;
//    else if( !( (*arbol)->der && (*arbol)->izq ) && *nivelMax!=nivelActual)
//        *nivelMax = -1;
//
//    return;
//}

int esCompleto (t_arbol *arbol)
{
    return esCompletoAniv(arbol,altura(arbol)-1);
}

int esBalanceado(t_arbol *arbol)
{
    return esCompletoAniv(arbol,altura(arbol)-2);
}

int esCompletoAniv (t_arbol *arbol, int nivel)
{
    if(!*arbol)
    {
        return nivel<0;
    }

    if(!nivel)
    {
        return 1;
    }

    return ( esCompletoAniv(&(*arbol)->izq,nivel-1) && esCompletoAniv(&(*arbol)->der,nivel-1) );
}

int esAVL(t_arbol *arbol)
{
    int altIzq,altDer;
    if(!*arbol)
        return 1;
    altIzq=altura(&(*arbol)->izq);
    altDer=altura(&(*arbol)->der);
    if(ABS(altIzq-altDer)>1)
        return 0;
    return esAVL(&(*arbol)->izq) && esAVL(&(*arbol)->der);
}

int contarNodos(t_arbol *arbol)
{
    if(!(*arbol))
    {
        return 0;
    }
    else{
        return contarNodos(&(*arbol)->der) + contarNodos(&(*arbol)->izq) +1;
    }
}

int contarNodosHastaN (const t_arbol *arbol, int nivel)
{
    if(!*arbol || nivel<0)
        return 0;
    return contarNodosHastaN(&(*arbol)->izq,nivel-1) + contarNodosHastaN(&(*arbol)->der,nivel-1) + 1;
}

int contarNodosDesdeN(const t_arbol *arbol, int nivel)
{
    if(!(*arbol))
        return 0;
    if(nivel==0)
    {
        return contarNodos(&(*arbol)->izq) + contarNodos(&(*arbol)->der) + 1;
    }

    return contarNodosDesdeN(&(*arbol)->izq,nivel-1) + contarNodosDesdeN(&(*arbol)->der,nivel-1);
}

int contarNodosEnN(const t_arbol *arbol,int nivel)
{
    if(!*arbol || nivel<0)
        return 0;
    if(nivel == 0)
        return 1;
    return contarNodosEnN(&(*arbol)->izq,nivel-1) + contarNodosEnN(&(*arbol)->der,nivel-1);
}

t_arbol* buscarNodo(t_arbol *arbol, void *dato, int(*comparar)(const void*, const void*))
{
    if(!*arbol)
        return NULL;

    if( comparar((*arbol)->info,dato)<0 )
        return buscarNodo(&(*arbol)->der,dato,comparar);
    else if ( comparar((*arbol)->info,dato)>0 )
        return buscarNodo(&(*arbol)->izq,dato,comparar);

    return (arbol);
}

int buscarDato (t_arbol * arbol, void * dato, unsigned tamBy, int(*comparar)(const void *, const void *))
{
    t_arbol * resBus;

    resBus = buscarNodo((arbol),dato,comparar);

    if(!resBus)
        return 0;

    memcpy(dato,(*resBus)->info,MIN(tamBy,(*resBus)->tamBy));

    return 1;
}

///complementa a eliminarRaiz / busca el minimo
t_nodo** buscarMenor (const t_arbol * arbol)
{
    if(!(*arbol))
    {
        return NULL;
    }
    if(!(*arbol)->izq)
    {
        return (t_arbol*)arbol;
    }
    return buscarMenor(&(*arbol)->izq);
}
///complementa a eliminarRaiz / busca el maximo
t_nodo** buscarMayor (const t_arbol * arbol)
{
    if(!(*arbol))
    {
        return NULL;
    }
    if(!(*arbol)->der)
    {
        return (t_arbol*)arbol;
    }
    return buscarMayor(&(*arbol)->der);
}

