#ifndef LISTASIMPLE_H_INCLUDED
#define LISTASIMPLE_H_INCLUDED

#define MIN(x,y)    ((x)<(y)?(x):(y))

typedef struct s_nodo{
    void* info;
    unsigned tamBy;
    struct s_nodo* sig;
}t_nodo;

typedef t_nodo* t_lista;

void crearLista(t_lista *lista);

int insertarAlFinal(t_lista* lista, const void* info, unsigned tamBy);
int insertarAlInicio (t_lista * lista, const void* info, unsigned tamBy);
int insertarOrdenado(t_lista* lista, void* info, unsigned tamBy, int duplic, int(*comparar)(const void*, const void*));
int instertarEnPos (t_lista *lista,void* dato, unsigned tam, unsigned pos);
int insertarOrdenadoRec(t_lista* lista, void* info, unsigned tamBy, int duplic, int(*comparar)(const void*, const void*));

void recorrerLista(t_lista* lista, void (*accion) (const void*));
void filtrarLista(t_lista* lista, int(*fFiltro) (const void*));
void* acumularDeLista(t_lista* lista, void* acumulador, void* (*acumulacion)(void* acum, void* info));

int buscarEnListaOrd(t_lista* lista, void* info, int(*comparar)(const void*, const void*));
t_lista* buscarMenor(t_lista* lista, int(*comparar)(const void*, const void*));
void ordenarLista(t_lista* lista, int(*comparar)(const void*, const void*));

void intercambiarMenor(t_lista* lista, t_lista* minimo);
void ordenarMenMayAlt(t_lista* lista, int(*comparar)(const void*, const void*));

void* buscarEnLista(t_lista* lista, void* info, void* (*comparar)(const void*, const void*));

int eliminarDeLista(t_lista *lista, void* dato, unsigned tamBy);
int eliminarNUltimos (t_lista* lista, unsigned cant);
int eliminarNprimeros (t_lista* lista, unsigned cant);
int eliminarXDuplicados (t_lista* lista, void* info, int(*comparar)(const void *, const void *));
int eliminarDupOrd (t_lista* lista, int(*comparar)(const void*, const void*));
int elimDup (t_lista* lista, int(*comparar)(const void*, const void*));
int elimYAcumOrd (t_lista * lista,int(*comparar)(const void *, const void *),void*(*acumulacion)(void *, void *));

void vaciarLista(t_lista* lista);

void recorrerFin(t_lista* lista, void(*accion)(const void *));
void recorrerFinRec(t_lista* lista, void(*accion)(const void *));
void recorrerIniRec(t_lista* lista, void(*accion)(const void *));

#endif // LISTASIMPLE_H_INCLUDED
