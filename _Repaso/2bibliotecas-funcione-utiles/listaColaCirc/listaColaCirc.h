#ifndef LISTACOLACIRC_H_INCLUDED
#define LISTACOLACIRC_H_INCLUDED

#define MIN(x,y) ((x)<(y)?(x):(y))

typedef struct s_nodo
{
    void * dato;
    unsigned tam;
    struct s_nodo* sig;
}t_nodo;

typedef t_nodo* t_lista;

void crearLista(t_lista *listaC);
int listaVacia(const t_lista *listaC);
int listaLlena(const t_lista *listaC, unsigned tamBy); ///es por el tamaño que ocupa la variable, como es una estructura paso la direccion para copiar la menor cantidad posible. el unsigned ocupa la misma cant q un puntero por eso lo paso por copia
int agregarEnLista(t_lista *listaC, void *info, unsigned tamBy);
int sacarDeLista(t_lista *listaC, void *info, unsigned tamBy);
void vaciarLista(t_lista *listaC);
int verPriLista(const t_lista *listaC, void *info, unsigned tamBy);

#endif // LISTACOLACIRC_H_INCLUDED
