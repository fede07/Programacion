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

t_nodo* buscarMenor (t_nodo *actual, int(*comparar)(const void *, const void *));
void ordenarLista(t_lista *lista, int(*comparar)(const void *, const void *));
void intercambiarDatos (t_nodo *menor, t_nodo *actual);
void ordenarDatos(t_lista *lista ,int(*comparar)(const void *, const void *));

int eliminarPorClave(t_lista* lista, void* info, unsigned tamBy, int (*comparar)(const void*, const void*));
int eliminarActual(t_lista *lista, void *info, unsigned tamBy);
void filtrarListaOrd(t_lista* lista, void* info, int(*filtrar)(const void*, const void*));

void recorrerListaIzq(t_lista* lista, void(*accion)(const void*));
void recorrerListaDer(t_lista* lista, void(*accion)(const void*));

#endif // LISTADOBLEMENTEENLAZADA_H_INCLUDED
