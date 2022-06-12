#ifndef LISTAPILACIRC_H_INCLUDED
#define LISTAPILACIRC_H_INCLUDED

#define MIN(x,y) ((x)<(y)?(x):(y))

typedef struct s_nodo
{
    void * dato;
    unsigned tam;
    struct s_nodo* sig;
}t_nodo;

typedef t_nodo* t_listaP;

///lista usada como pila
void crearlistaP(t_listaP* listaP);
int ponerEnlistaP(t_listaP* listaP, const void* info, unsigned tam);
int verTope(const t_listaP* listaP, void* info, unsigned tam);
int sacarDelistaP(t_listaP* listaP, void* info, unsigned tambytes);
int listaPVacia(const t_listaP* listaP);
void vaciarlistaP(t_listaP* listaP);
int listaPLlena(const t_listaP* listaP, unsigned tam);


#endif // LISTAPILACIRC_H_INCLUDED
