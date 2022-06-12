#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED



#define MIN(x,y) ((x)<(y)?(x):(y))

typedef struct s_nodo{
void * dato;
unsigned tam;
struct s_nodo * sig;
}t_nodo;

typedef t_nodo * t_pila;

void crearPila(t_pila* pila);
int ponerEnPila(t_pila* pila, const void* info, unsigned tam);
int sacarDePila(t_pila* pila, void* info, unsigned tambytes);
int verTope(const t_pila* pila, void* info, unsigned tam);
int pilaVacia(const t_pila* pila);
void vaciarPila(t_pila* pila);
int pilaLlena(const t_pila* pila, unsigned tam);

#endif // PILA_H_INCLUDED
