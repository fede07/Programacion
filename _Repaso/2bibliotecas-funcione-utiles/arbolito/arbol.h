#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

#define MIN(x,y) ( ((x)>(y))?(y):(x) )
#define ABS(x)    ( ((x))<0?((x)*(-1)):(x) )

typedef struct snodo{
    void * info;
    unsigned tam;
    struct snodo * der;
    struct snodo * izq;
}t_nodo;

typedef t_nodo * t_arbol;

void crearArbol (t_arbol *);
int insertarArbolRec (t_arbol * arbol, void * dato, unsigned tam, int (*compar)(const void *, const void *));
int insertarArbol(t_arbol * arbol, void * dato, unsigned tam, int (*compar)(const void *, const void *));

///muestra el arbol en columna
void preOrden (t_arbol * arbol, void (*accion)(const void *));///RID
void inOrden (t_arbol * arbol, void (*accion)(const void *));///IRD
void posOrden (t_arbol * arbol, void (*accion)(const void *));///IDR

///muestra el arbol acostado
void rotar90g_i(t_arbol* arbol, void(*accion)(const void*));
void rotar90Rec(t_arbol* arbol, int nivel, void(*accion)(const void*));
void tabRec(int nivel,int cont);

///el usuario pregunta por el nivel que quiere y le responde si esta completo Y balanceado
int nivelXCompyBalan (t_arbol *, unsigned nivel);
int nivelXCompRecyBalan (t_arbol *, unsigned nivel);
///devuelve el maximo nivel completo
unsigned nivelComp (t_arbol *);
unsigned nivelComp1erRama (t_arbol * arbol, unsigned * nivelMin, unsigned nivelActual);
unsigned nivelCompRec (t_arbol * arbol, unsigned * nivelMin, unsigned nivelActual);

///en clase
int esCompleto (t_arbol * arbol);
int esCompletoAniv (t_arbol * arbol, int nivel);
int esBalanceado(t_arbol * arbol);
int altura (t_arbol * arbol);
int tipoArbol (t_arbol *);

t_arbol * buscarNodo (t_arbol * arbol, void * dato, int(*comparar)(const void *, const void *));
int eliminar (t_arbol * arbol, void * dato, int(*comparar)(const void *, const void *));
int eliminarNodo(t_arbol * arbol);
t_nodo ** buscarMenor (const t_arbol * arbol);
t_nodo ** buscarMayor (const t_arbol * arbol);

void podarDesdeXNivel (t_arbol * arbol, unsigned nivel);
void talarXNivel(t_arbol * arbol, unsigned nivel, unsigned nivelActual);
void talar (t_arbol * arbol);
void talarRec (t_arbol *);
void podar_hojas(t_arbol *arbol);

int contarNodos (t_arbol * arbol);
int contarNodosHastaN (const t_arbol *pa, int n);
int contarNodosDesdeN(const t_arbol *pa, int n);
int contarNodosEnN(const t_arbol *pa,int n);

int cantMenQue (t_arbol * arbol, const void *, int(*comparar)(const void *, const void *));
int cantMenComp (t_arbol * arbol, void * dato, int(*comparar)(const void *, const void *));
int cantMayQue (t_arbol * arbol, const void * dato, int(*comparar)(const void *, const void *));
int cantMayComp (t_arbol * arbol, const void *, int(*comparar)(const void *, const void *));
int esAVL (t_arbol * arbol);
int buscarDato (t_arbol * arbol, void * dato, unsigned tamBy, int(*comparar)(const void *, const void *));

int balancearArbol (t_arbol * arbol);

int guardarOrdenadoGen (t_arbol * arbol, void (*accion)(const void *dato, void*contexto));
void inOrdenArchivos (t_arbol * arbol, void (*accion)(const void *dato, void*contexto), void * parametros);






/**
TIPOS DE ARBOL

COMPLETO: Es un arbol que tiene la cantidad maxima de nodos para la altura que tiene osea
que todos los nodos tiene dos hijos hasta su maxima altura
--(2^h) - 1 = cantidad de nodos
--completo_hasta_nivel(h-1)

BALANCEADO: Es un arbol que tiene completo el nivel anterior al ultimo
--completo_hasta_nivel(h-2)
--(2^(h-1)) - 1 = completo_hasta_nivel (h-2)

AVL: Es un arbol que la altura de la derecha y de la izquierda no se diferencia en mas de uno
--|hi-hd|<=1

**/


#endif // ARBOL_H_INCLUDED
