#ifndef LISTADOBLE_H_INCLUDED
#define LISTADOBLE_H_INCLUDED

#define MIN(x,y) ((x)<(y))?(x):(y)

typedef struct s_nodo
{
    void * dato;
    unsigned tam;
    struct s_nodo* sig;
    struct s_nodo* ant;
}t_nodo;

typedef t_nodo* t_lista;

void crearLista(t_lista *);

int insertarOrd (t_lista *, void * dato, unsigned tam, int(*comparar)(const void *, const void *));
int insertar (t_lista *, void * dato, unsigned tam);///inserta a la derecha del actual
int insertarAlFinal(t_lista *, void * dato, unsigned tam);
int insertarAlInicio(t_lista *, void * dato, unsigned tam);

int vaciarLista(t_lista *listaD);
int eliminarPorClave(t_lista *listaD, void *info, unsigned cantBy, int (*comparar)(const void*, const void*));
int eliminarActual(t_lista *listaD, void *info, unsigned cantBy);
int elimDup (t_lista * lista,int(*comparar)(const void *, const void *));
int elimYAcum (t_lista * lista,int(*comparar)(const void *, const void *),void*(*acumulacion)(void *, void *));
t_nodo * buscarNodo (t_lista * lista, void * dato, int(*comparar)(const void *, const void *));
void * buscarDato (t_lista * lista, void * dato, int(*comparar)(const void *, const void *));
void * buscarDatoOrd (t_lista * lista, void * dato, int(*comparar)(const void *, const void *));

void recorrerListaIzq(t_lista* lista, void(*accion)(const void*));
void recorrerListaDer(t_lista* lista, void(*accion)(const void*));

int insertarOrdAcum (t_lista * lista, void * info, unsigned tamBy, int(*comparar)(const void *, const void *),void(*acumular)(void *, const void *));
void filtrar (t_lista * lista, void * dato, int(*filtro)(const void*, const void*));

void ordenar (t_lista * ,int(*comparar)(const void *, const void *));
void ordenarDatos (t_lista * ,int(*comparar)(const void *, const void *));

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

#endif // LISTADOBLE_H_INCLUDED
