#ifndef LISTADOBLEMENTEENLAZADA_H_INCLUDED
#define LISTADOBLEMENTEENLAZADA_H_INCLUDED

#define MIN(x,y)    ((x)<(y)?(x):(y))

typedef struct s_nodo{
    void* info;
    unsigned tamBy;
    struct s_nodo* sig;
    struct s_nodo* ant;
}t_nodo;

typedef t_nodo* t_lista;

void crearLista(t_lista* lista);
int insertarListaOrd(t_lista* lista, void* info, unsigned tamBy, int (*comparar)(const void*, const void*));
int insertarEnLista(t_lista *lista, void *info, unsigned tamBy);
int insertarAcumListaOrd(t_lista* lista, void* info, unsigned tamBy, int(*comparar)(const void*, const void*), void(*acumular)(void*, const void*));
int insertarAlFinal(t_lista *lista, void *info, unsigned tamBy);
int insertarAlInicio(t_lista *, void * dato, unsigned tam);

t_nodo* buscarMenor (t_nodo *actual, int(*comparar)(const void *, const void *));
void ordenarLista(t_lista *lista, int(*comparar)(const void *, const void *));
void intercambiarDatos (t_nodo *menor, t_nodo *actual);
void ordenarDatos(t_lista *lista ,int(*comparar)(const void *, const void *));

int eliminarPorClave(t_lista* lista, void* info, unsigned tamBy, int (*comparar)(const void*, const void*));
int eliminarActual(t_lista *lista, void *info, unsigned tamBy);
int elimDup (t_lista * lista,int(*comparar)(const void *, const void *));

t_nodo * buscarNodo (t_lista * lista, void * dato, int(*comparar)(const void *, const void *));
void * buscarDato (t_lista * lista, void * dato, int(*comparar)(const void *, const void *));
void * buscarDatoOrd (t_lista * lista, void * dato, int(*comparar)(const void *, const void *));
void filtrarListaOrd(t_lista* lista, void* info, int(*filtrar)(const void*, const void*));

void recorrerListaIzq(t_lista* lista, void(*accion)(const void*));
void recorrerListaDer(t_lista* lista, void(*accion)(const void*));

///RECURSIVAS

t_nodo* insertarOrdenadoR(t_nodo* actual,const void* info,int(*comparar)(const void*, const void*));
int insertarOrdenadoR_W(t_lista *lista, const void *info, unsigned tamBy, int(*comparar)(const void*, const void*),void(*acumular)(void *, const void *) );
void recorrerListaRecIzq(t_lista* lista, void(*accion)(const void*));
void recorrerListaRecDer(t_lista* lista, void(*accion)(const void*));
void recorrerListaRec(t_lista* lista, void(*accion)(const void*));
void recorrerListaRInv_I(t_lista* lista, void(*accion)(const void*));
void recorrerListaRInv_D(t_lista* lista, void(*accion)(const void*));
void recorrerListaRInv_W(t_lista* lista, void(*accion)(const void*));
t_nodo* insertarAlPrincipioR(t_nodo* actual);
int insertarAlPrincipioR_W(t_lista* lista, const void* info, unsigned tam);
t_nodo* buscarMenorR(t_lista* lista,t_nodo* menor, int(*comparar)(const void*, const void*));
t_nodo* buscarMenorR_W(t_lista* lista, int(*comparar)(const void*, const void*));
void ordenarListaR(t_lista* lista, int(*comparar)(const void*, const void*));
void ordenarListaR_W(t_lista* lista, int(*comparar)(const void*, const void*));

#endif // LISTADOBLEMENTEENLAZADA_H_INCLUDED
