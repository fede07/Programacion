#include "arbol.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void crearArbol (t_arbol * arbol)
{
    *arbol = NULL;
}
///inserta recursivamente
///(la llama el main)
int insertarArbolRec (t_arbol * arbol, void * dato, unsigned tamBy, int (*compar)(const void *, const void *))
{
    t_nodo* nuevo;
    int comp;
    if(*arbol)
    {

        if((comp=compar((*arbol)->info,dato))>0)
        {
            return insertarArbolRec(&(*arbol)->izq,dato,tamBy,compar);
        }
        else if(comp<0)
        {
            return insertarArbolRec(&(*arbol)->der,dato,tamBy,compar);
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
    nuevo->tam=tamBy;
    nuevo->izq=NULL;
    nuevo->der=NULL;
    *arbol=nuevo;

    return 1;
}
///inserta iterativamente
///(la llama el main)
int insertarArbol(t_arbol * arbol, void * dato, unsigned tam, int (*compar)(const void *, const void *))
{
    t_nodo *nue = malloc(sizeof(t_nodo));
    int comp;
    if(!nue)
        return 0;
    nue->info = malloc(tam);
    if(!nue->info)
    {
        free(nue);
        return 0;
    }

    memcpy(nue->info,dato,tam);
    memcpy(&(nue->tam),&tam,sizeof(unsigned));
    nue->der = NULL;
    nue->izq = NULL;

    if(!*arbol)
    {
        *arbol = nue;
        return 1;
    }

    comp = compar(nue->info,(*arbol)->info);

    while( (comp<0 && (*arbol)->izq) || (comp>0 && (*arbol)->der) )
    {///el while busca donde hay que insertarlo (o no si son iguales)
        if(comp<0)
            arbol = &(*arbol)->izq;
        else
            arbol = &(*arbol)->der;

        comp = compar(nue->info,(*arbol)->info);
    }

    if(comp==0)
    {
        free(nue->info);
        free(nue);
        return 0;
    }
    else if(comp<0)
        (*arbol)->izq = nue;
    else
        (*arbol)->der = nue;

    return 1;
}

void preOrden (t_arbol * arbol, void (*accion)(const void *))///RID
{
    if(!*arbol)
        return;

    accion((*arbol)->info);
    preOrden(&(*arbol)->izq,accion);
    preOrden(&(*arbol)->der,accion);
}

void inOrden (t_arbol * arbol, void (*accion)(const void *))///IRD
{
    if(!*arbol)
        return;

    inOrden(&(*arbol)->izq,accion);
    accion((*arbol)->info);
    inOrden(&(*arbol)->der,accion);
}

void posOrden (t_arbol * arbol, void (*accion)(const void *))///IDR
{
    if(!*arbol)
        return;

    posOrden(&(*arbol)->izq,accion);
    posOrden(&(*arbol)->der,accion);
    accion((*arbol)->info);
}
///muestra el arbol acostado
///(la llama el main)
void rotar90g_i(t_arbol* arbol, void(*accion)(const void*))
{
    if(!*arbol)
        return;

    rotar90Rec(&(*arbol)->der,1,accion);
    accion((*arbol)->info);
    rotar90Rec(&(*arbol)->izq,1,accion);
}
///complementa a otar90g_i
void rotar90Rec(t_arbol * arbol,int nivel,void(*accion)(const void*))
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
///complementa a otar90g_i
void tabRec(int nivel,int cont)
{
  if((nivel)>cont)
  {
      printf("\t");
      tabRec(nivel,cont+1);
  }
  return;
}
///devuelve 1 si el arbol esta completo y balanceado en el nivel indicado por el usuario
///(la llama el main)
int nivelXCompyBalan (t_arbol * arbol, unsigned nivel)
{
    if(!*arbol)
        return 0;

    return nivelXCompRecyBalan(arbol,nivel);
}
///complementa a nivelXCompyBalan
int nivelXCompRecyBalan (t_arbol * arbol, unsigned nivel)
{
    int der, izq;

    if( ((*arbol)->der && (*arbol)->izq) && nivel)
    {///entra si tiene nodo derecho e izquierdo, y todavia no se llego al nivel pedido
        izq = nivelXCompRecyBalan (&(*arbol)->izq,nivel-1);
        der = nivelXCompRecyBalan (&(*arbol)->der,nivel-1);
        if(izq && der)
            return 1;
    }
    else if(nivel == 0)///se llego hasta el nivel pedido
    {
        return 1;
    }

    return 0;
}
///devuelve el nivel mas alto donde el arbol esta completo y balanceado
///(la llama el main)
unsigned nivelComp (t_arbol * arbol)
{
    unsigned nivelMin, nivelActual;
    if(!*arbol)
        return 0;

    nivelMin = 0;
    nivelActual = 0;

    return nivelCompRec (arbol,&nivelMin,nivelActual);
}
///complementa a nivelComp
unsigned nivelCompRec (t_arbol * arbol, unsigned * nivelMin, unsigned nivelActual)
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

        ///nivelMin lo recibe der/izq
        return *nivelMin;
    }
    if(*nivelMin==0)///setea el nivelMin en la primera recorrida completa
        *nivelMin = nivelActual;

    return nivelActual;
}
///elimina COMPLETAMENTE todo lo que este abajo del nivel indicado por el usuario
///(la llama el main)
void podarDesdeXNivel (t_arbol * arbol, unsigned nivel)
{
    int nivelActual;
    if(!*arbol)
        return;

    nivelActual = 0;

    talarXNivel(arbol,nivel,nivelActual);
}
///complementa a podarDesdeXNivel
void talarXNivel (t_arbol * arbol, unsigned nivel, unsigned nivelActual)
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
///vacia el arbol
///(la llama el main)
void talar (t_arbol * arbol)
{
    talarRec (arbol);
    *arbol = NULL;
}
///complementa a talar y a su vez a talarXNivel
void talarRec (t_arbol * arbol)
{
    if(!*arbol)
        return;

    talarRec (&(*arbol)->izq);
    talarRec (&(*arbol)->der);

    free((*arbol)->info);
    free((*arbol));
}
///elimina los nodos que no tengan izquierdo ni derecha
void podar_hojas(t_arbol *arbol)
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
        podar_hojas(&(*arbol)->izq);
        podar_hojas(&(*arbol)->der);
    }
}
///devuelve la altura del arbol
///(la llama el main)
int altura (t_arbol * arbol)
{
    int izq, der;
    if(!*arbol)
    {
        return 0;
    }

    izq = altura(&(*arbol)->izq);
    der = altura(&(*arbol)->der);

    return der>izq?der+1:izq+1;
}
///devuelve 1 si tiene los nodos correspondientes a su altura (el ultimo nivel todos terminan en NULL)
///(la llama el main)
int esCompleto (t_arbol * arbol)
{
    return esCompletoAniv(arbol,altura(arbol)-1);
}
///devuelve 1 si el arbol esta completo hasta un nivel menos de su maximo
///(la llama el main)
int esBalanceado(t_arbol * arbol)
{
    return esCompletoAniv(arbol,altura(arbol)-2);
}

///1 AVL / 2 balanceado / 3 completo / 0 ninguno / -1 no existe
int tipoArbol (t_arbol * arbol)
{
    if(*arbol)
    {
        if(esAVL(arbol))
        {
            if(esBalanceado(arbol))
            {
                if(esCompleto(arbol))
                    return 3;
                return 2;
            }
            return 1;
        }
        return 0;
    }
    return -1;
}

///complementa a esCompleto y esCompletoAniv
int esCompletoAniv (t_arbol * arbol, int nivel)
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
///busca el nodo a eliminar
///(la llama el main)
int eliminar (t_arbol * arbol, void * dato, int(*comparar)(const void *, const void *))
{
    t_arbol * elim;
    if(!*arbol)
        return 0;

    if( (elim = buscarNodo((arbol),dato,comparar)) )
    {
        memcpy(dato,(*elim)->info,(*elim)->tam);
        return eliminarNodo(elim);
    }
    else
        return 0;
    ///si fueran iguales directamente va a eliminar
}
///complementa a eliminar (devuelve la direccion del dato o NULL si no lo encuentra)
t_arbol * buscarNodo (t_arbol * arbol, void * dato, int(*comparar)(const void *, const void *))
{
    if(!*arbol)
        return NULL;

    if( comparar((*arbol)->info,dato)<0 )
        return buscarNodo(&(*arbol)->der,dato,comparar);
    else if ( comparar((*arbol)->info,dato)>0 )
        return buscarNodo(&(*arbol)->izq,dato,comparar);

    return (arbol);///encontro el valor
}
///esta funcion no elimina el nodo, solo reemplaza sus valores y elimina otro nodo del final
///complementa a eliminar
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
    (*arbol)->tam = (*remp)->tam;

    elim = *remp;
    (*remp) = (*remp)->izq?(*remp)->izq:(*remp)->der;

    free(elim);
    return 1;
}
///complementa a eliminarRaiz / busca el minimo
t_nodo ** buscarMenor (const t_arbol * arbol)
{
    if(!(*arbol))
    {
        return NULL;
    }
    if(!(*arbol)->izq)
    {///este if es necesario para no devolver un NULL si es que existe el arbol
        return (t_arbol*)arbol;
    }
    return buscarMenor(&(*arbol)->izq);
}
///complementa a eliminarRaiz / busca el maximo
t_nodo ** buscarMayor (const t_arbol * arbol)
{
    if(!(*arbol))
    {
        return NULL;
    }
    if(!(*arbol)->der)
    {///este if es necesario para no devolver un NULL si es que existe el arbol
        return (t_arbol*)arbol;
    }
    return buscarMayor(&(*arbol)->der);
}
///cuenta todos los nodos de un arbol
///(la llama el main) y complementa a contarNodosDesdeN
int contarNodos (t_arbol * arbol)
{
    if(!*arbol)
    {
        return 0;
    }
    else
    {
        return (contarNodos(&(*arbol)->der)+contarNodos(&(*arbol)->izq)+1);
    }
}
///cuenta cuantos nodos hay hasta el nivel N incluido
///(la llama el main)
int contarNodosHastaN (const t_arbol *pa, int n)
{
    if(!*pa || n<0)
        return 0;
    return contarNodosHastaN(&(*pa)->izq,n-1) + contarNodosHastaN(&(*pa)->der,n-1) + 1;
}
///cuenta cuantos nodos hay desde el nivel N incluido
///(la llama el main)
int contarNodosDesdeN(const t_arbol *pa, int n)
{
    if(!*pa)
        return 0;
    if(n==0)
    {
        return contarNodos(&(*pa)->izq) + contarNodos(&(*pa)->der) + 1;
    }
    return contarNodosDesdeN(&(*pa)->izq,n-1) + contarNodosDesdeN(&(*pa)->der,n-1);
}

///cuenta los nodos en el nivel N
///(la llama el main)
int contarNodosEnN(const t_arbol *pa,int n)
{
    if(!*pa || n<0)
        return 0;
    if(n == 0)
        return 1;
    return contarNodosEnN(&(*pa)->izq,n-1) + contarNodosEnN(&(*pa)->der,n-1);
}


///dice si es AVL (de cada nodo se desprende la misma cantidad +-1 para ambos lados)
///(la llama el main)
/**int esAVL(t_arbol *arbol)
{
    if(!*arbol)
        return 0;

    if(ABS(altura(&(*arbol)->izq)-altura(&(*arbol)->der)) > 1)
    {
        return 0;
    }
    else if((*arbol)->izq)
        return esAVL(&(*arbol)->izq);
    else if ((*arbol)->der)
         return esAVL(&(*arbol)->der);

    return 1;
}
**/
int esAVL(t_arbol *pa)
{
    int hi,hd;
    if(!*pa)
        return 1;
    hi=altura(&(*pa)->izq);
    hd=altura(&(*pa)->der);
    if(ABS(hi-hd)>1)
        return 0;
    return esAVL(&(*pa)->izq) && esAVL(&(*pa)->der);
}


///busca un dato pedido y devuelve la informacion
///(la llama el main)
int buscarDato (t_arbol * arbol, void * dato, unsigned tamBy, int(*comparar)(const void *, const void *))
{
    t_arbol * resBus;

    resBus = buscarNodo((arbol),dato,comparar);

    if(!resBus)
        return 0;

    memcpy(dato,(*resBus)->info,MIN(tamBy,(*resBus)->tam));

    return 1;
}
///busca los menores que un dato en el arbol
///(la llama el main)
int cantMenQue (t_arbol * arbol, const void * dato, int(*comparar)(const void *, const void *))
{
    int cant=0;
    int comp;
    if(!*arbol)
        return 0;

    comp = comparar((*arbol)->info,dato);

    if( comp<=0 )///la raiz es menor que el dato buscado
    {
        ///hay que contar cuantos nodos son menores que el dato buscado, desde el lado derecho
        ///de la raiz
        cant = cantMenComp(&(*arbol)->der,(void*)dato,comparar);
        cant+=1;
        cant += contarNodos(&(*arbol)->izq);
    }
    else if (comp>0)
    {
        cant = cantMenComp(&(*arbol)->izq,(void*)dato,comparar);
    }

    if(comp==0)
        cant-=1;

    return cant;
}
///busca los mayores que un dato en el arbol
///(la llama el main)
int cantMayQue (t_arbol * arbol, const void * dato, int(*comparar)(const void *, const void *))
{
    int cant=0;
    int comp;
    if(!*arbol)
        return 0;

    comp = comparar((*arbol)->info,dato);

    if( comp<0 )///la raiz es menor que el dato buscado
    {
        ///hay que contar cuantos nodos son menores que el dato buscado, desde el lado derecho
        ///de la raiz
        cant = cantMayComp(&(*arbol)->der,(void*)dato,comparar);
    }
    else if (comp>=0)
    {
        cant = cantMayComp(&(*arbol)->izq,(void*)dato,comparar);
        cant+=1;
        cant += contarNodos(&(*arbol)->der);
    }

    if(comp==0)
        cant-=1;

    return cant;
}
///busca cuantos nodos menores que el dato hay
///complementa a cantMayComp
int cantMayComp (t_arbol * arbol, const void * dato, int(*comparar)(const void *, const void *))
{
    int comp;
    if(!*arbol)
        return 0;

    comp = comparar((*arbol)->info,dato);

    if( comp>0 )///vamos a la derecha
        return cantMayComp(&(*arbol)->izq,dato,comparar)+contarNodos(&(*arbol)->der)+1;
    else if ( comp<0 )///vamos a la izquierda
        return cantMayComp(&(*arbol)->der,dato,comparar);

    return contarNodos(&(*arbol)->der);
}
///busca cuantos nodos menores que el dato hay
///complementa a cantMenQue
int cantMenComp (t_arbol * arbol, void * dato, int(*comparar)(const void *, const void *))
{
    int comp;
    if(!*arbol)
        return 0;

    comp = comparar((*arbol)->info,dato);

    if( comp<0 )///vamos a la derecha
        return cantMenComp(&(*arbol)->der,dato,comparar)+contarNodos(&(*arbol)->izq)+1;
    else if ( comp>0 )///vamos a la izquierda
        return cantMenComp(&(*arbol)->izq,dato,comparar);

    return contarNodos(&(*arbol)->izq);///encontro el dato entonces no lo cuenta
                            ///pero si hay que contar los que esten a su izquierda
}


///HECHAS EN CLASE
///guarda el arbol que tiene los registros del archivo, en un nuevo archivo temporal para despues tener
///un arbol balanceado
int guardarOrdenadoGen (t_arbol * arbol, void (*accion)(const void *dato, void*contexto))
{
    FILE * temp = fopen("temp.idx","wb");

    if(!temp)
        return 0;

    inOrdenArchivos(arbol,accion,temp);

    fclose(temp);

    return 1;
}

void inOrdenArchivos (t_arbol * arbol, void (*accion)(const void *dato, void*contexto), void * parametros)///el segundo parametro es void porque no siempre va a ser FILE
{
    if(!*arbol)
        return;

    inOrdenArchivos(&(*arbol)->izq,accion,parametros);
    accion((*arbol)->info,parametros);
    inOrdenArchivos(&(*arbol)->der,accion,parametros);
    /**ACCION
    void guardarRegIndice (const void * dato, void * contexto)
{
    fwrite(dato,sizeof(tidx),1,(FILE*)contexto);
}
**/
}



///despues de esto se pueden levantar los datos directamente de archivo y ya queda balanceado
                                ///Clientes.idx
int guardarIndice (t_arbol * arbol, const char * nombre, void (*accion)(const void *dato, void*contexto))
{
    FILE * temp = fopen(nombre,"wb");

    if(!temp)
        return 0;

    preOrdenArchivos(arbol,accion,temp);

    fclose(temp);

    return 1;
}

void preOrdenArchivos (t_arbol * arbol, void (*accion)(const void *dato, void*contexto), void * parametros)///el segundo parametro es void porque no siempre va a ser FILE
{
    if(!*arbol)
        return;

    accion((*arbol)->info,parametros);
    preOrdenArchivos(&(*arbol)->izq,accion,parametros);
    preOrdenArchivos(&(*arbol)->der,accion,parametros);
    /**ACCION
    void guardarRegIndice (const void * dato, void * contexto)
{
    fwrite(dato,sizeof(tidx),1,(FILE*)contexto);
}
**/
}






