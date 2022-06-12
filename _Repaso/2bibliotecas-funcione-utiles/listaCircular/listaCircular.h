#ifndef LISTACIRCULAR_H_INCLUDED
#define LISTACIRCULAR_H_INCLUDED

#define MIN(x,y) ((x)<(y))?(x):(y)

typedef struct s_nodo
{
    void * dato;
    unsigned tam;
    struct s_nodo* sig;
}t_nodo;

typedef t_nodo* t_lista;

void crearLista (t_lista *);
int insertar (t_lista *, const void*, unsigned);
int insertarAlFinal (t_lista * lista, const void * dato, unsigned tamBy);
void recorrerCirc(t_lista*lista,void(*accion)(const void*));
int eliminar (t_lista *, void * dato, unsigned);


#endif // LISTACIRCULAR_H_INCLUDED
