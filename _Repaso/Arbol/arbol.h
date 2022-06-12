#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

#define MIN(x,y)    (((x)<(y))?(x):(y))
#define ABS(x)    ((x)<0?((x)*(-1)):(x))

typedef struct s_nodo{
    void* info;
    unsigned tamBy;
    struct s_nodo *izq;
    struct s_nodo *der;
}t_nodo;

typedef t_nodo* t_arbol;

void crearArbol(t_arbol *arbol);
int insertarArbolRec(t_arbol *arbol, const void* dato, unsigned tamBy, int (*comparar)(const void*, const void*));
int insertarArbol(t_arbol *arbol, void *dato, unsigned tam, int (*comparar)(const void *, const void *));

///Mostrar en una columna
void posOrden(t_arbol *arbol, void(*accion)(const void*)); ///IDR
void inOrden(t_arbol *arbol, void(*accion)(const void*)); ///IRD
void preOrden(t_arbol *arbol, void(*accion)(const void*)); ///RID

///Mostrar Arbol 90g
void rotar90g_i(t_arbol *arbol, void(*accion)(const void*));
void rotar90Rec(t_arbol *arbol,int nivel,void(*accion)(const void*));
void tabRec(int nivel,int cont);

///el usuario pregunta por el nivel que quiere
int nivelXCompYBal (t_arbol *arbol, unsigned nivel);
int nivelXCompYBalRec (t_arbol *arbol, unsigned nivel);

unsigned nivelComp (t_arbol *arbol);
unsigned nivelCompRec (t_arbol *arbol, unsigned * nivelMin, unsigned nivelActual);
unsigned nivelComp1erRama (t_arbol *arbol, unsigned * nivelMin, unsigned nivelActual);

///Podar
void podarDesdeXNivel(t_arbol *arbol, unsigned nivel);
void talarXNivel(t_arbol *arbol, unsigned nivel, unsigned nivelActual);
void talar(t_arbol *arbol);
void talarRec(t_arbol *arbol);
void podarHojas(t_arbol *arbol);
int eliminarNodo(t_arbol * arbol);
int eliminar (t_arbol *arbol, void *dato, int(*comparar)(const void *, const void *));
int buscarDato (t_arbol *arbol, void *dato, unsigned tamBy, int(*comparar)(const void*, const void*));


///Otras
unsigned altura(t_arbol *arbol);
int alturaRec(t_arbol *arbol, unsigned altura);
int esCompleto (t_arbol *arbol);
int esBalanceado(t_arbol *arbol);
//void balanceadoRec(t_arbol *arbol, int *nivelMax, int nivelActual);
int esCompletoAniv (t_arbol *arbol, int nivel);
int esAVL(t_arbol *arbol);

int contarNodos(t_arbol *arbol);
int contarNodosHastaN (const t_arbol *arbol, int nivel);
int contarNodosDesdeN(const t_arbol *arbol, int nivel);
int contarNodosEnN(const t_arbol *arbol,int nivel);

t_arbol* buscarNodo(t_arbol *arbol, void *dato, int(*comparar)(const void*, const void*));
t_nodo** buscarMenor (const t_arbol *arbol);
t_nodo** buscarMayor (const t_arbol *arbol);

int cantMenQue (t_arbol *arbol, const void *dato, int(*comparar)(const void *, const void *));
int cantMenComp (t_arbol *arbol, void *dato, int(*comparar)(const void *, const void *));
int cantMayQue (t_arbol *arbol, const void *dato, int(*comparar)(const void*, const void*));
int cantMayComp (t_arbol *arbol, const void *dato, int(*comparar)(const void *, const void *));

int balancearArbol (t_arbol * arbol);

int guardarOrdenadoGen (t_arbol * arbol, void (*accion)(const void *dato, void*contexto));
void inOrdenArchivos (t_arbol * arbol, void (*accion)(const void *dato, void*contexto), void * parametros);

#endif // ARBOL_H_INCLUDED
