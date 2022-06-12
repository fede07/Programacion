#ifndef PILAESTATICA_H_INCLUDED
#define PILAESTATICA_H_INCLUDED

#define TAM 500

typedef struct{
    char iniPila[TAM];
    unsigned tope;
}t_pila;

void crearPila(t_pila* pila);
int ponerEnPila(t_pila* pila, const void* info, unsigned tam);
int sacarDePila(t_pila* pila, void* info, unsigned tambytes);
int verTope(const t_pila* pila, void* info, unsigned tam);
int pilaVacia(const t_pila* pila);
void vaciarPila(t_pila* pila);
int pilaLlena(const t_pila* pila, unsigned tam);

#endif // PILAESTATICA_H_INCLUDED
