#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED
#include <stdio.h>

#define MIN(x,y) ((x)<(y)?(x):(y))
#define TAM 100

typedef struct{
char iniPila[TAM];
unsigned tope;
}t_pila;

void crearPila (t_pila *);
int ponerEnPila (t_pila *, const  void * dato, unsigned tam);
int sacarDePila (t_pila *, void *, size_t);
int verTope (const t_pila * p, void * dato, size_t tam);
int pilaVacia (const t_pila *);
int pilaLlena (const t_pila *, unsigned);
void vaciarPila (t_pila *);


#endif // PILA_H_INCLUDED
