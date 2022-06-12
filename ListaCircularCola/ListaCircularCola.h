#ifndef LISTACIRCULARCOLA_H_INCLUDED
#define LISTACIRCULARCOLA_H_INCLUDED

#define MIN(x,y)    (((x)<(y))?(x):(y))

typedef struct s_nodo
{
    void* info;
    unsigned tamBy;
    struct s_nodo* sig;
}t_nodo;

typedef t_nodo* t_lista;

void crearListaCC(t_lista* listaC);
int ponerEnListaCC(t_lista* listaC, void* info, unsigned tamBy);
int sacarDeListaCC(t_lista* listaC, void* info, unsigned tamBy);
int verPrimero(const t_lista* listaC, void* info, unsigned tamBy);
int listaCCVacia(const t_lista* listaC);
int listaCCLlena(const t_lista* listaC, unsigned tamBy);
void vaciarListaCC(t_lista* listaC);

#endif // LISTACIRCULARCOLA_H_INCLUDED
