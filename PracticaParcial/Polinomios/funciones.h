#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct{
    int poten;
    int coef;
}t_polinomio;

typedef struct s_nodo{
    void *info;
    unsigned tamBy;
    struct s_nodo *sig;
}t_nodo;

typedef t_nodo *t_lista;


int generarLote();
int sumarPolinomios();

void crearLista(t_lista *lista);
int insertarOrdenadoAcum(t_lista* lista, void* info, unsigned tamBy,
                         int(*comparar)(const void*, const void*),
                         void* (*acumulacion)(void*, void*));

int compararPolinomio(const void *poli1, const void *poli2);
void* acumularPolinomio(void *acum, void *polinomio);
void recorrerListaGuardarArch(t_lista *lista, FILE *arch, int(*filtro)(void*dato), void (*accion)(void* dato, FILE* arch));
int filtroPolinomio(void *dato);
void guardarPolinomioEnArch(void *dato, FILE* arch);
void vaciarLista(t_lista* lista);

#endif // FUNCIONES_H_INCLUDED
