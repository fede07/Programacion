#ifndef LISTACIRCULARPILA_H_INCLUDED
#define LISTACIRCULARPILA_H_INCLUDED

#define MIN(x,y) ((x)<(y)?(x):(y))

typedef struct s_nodo
{
    void* info;
    unsigned tamBy;
    struct s_nodo* sig;
}t_nodo;

typedef t_nodo* t_lista;

///Lista usada como pila.
void crearListaCircP(t_lista* lista);
int ponerEnListaP(t_lista* listaP, const void* info, unsigned tamBy);
int verTope(const t_lista* listaP, void* info, unsigned tamBy);
int sacarDeListaP(t_lista* listaP, void* info, unsigned tamBy);
int listaPVacia(const t_lista* listaP);
void vaciarListaP(t_lista* listaP);
int listaPLlena(const t_lista* listaP, unsigned tamBy);


#endif // LISTACIRCULARPILA_H_INCLUDED
