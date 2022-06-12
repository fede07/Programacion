#include <stdio.h>
#include <stdlib.h>
#include "ListaSimple.h"

#define TAM 8

#define SEPARADOR printf("--------------------\n")

typedef struct
{
    unsigned codigo;
    int cant;
} t_producto;

/////////////

void mostrar (const void* a);
int fFiltro(const void* filtro);
void* acumulacion(void*acum, void* n);
int comparar(const void *dato1, const void *dato2);

/////////////
void sumaCant(const t_lista* listaOrigen, t_lista* );
void mostrarProd(const void * dato);
/////////////

///////

//int main()
//{
//    t_producto prod[TAM]={{1,10},
//                        {1,20},
//                        {1,-15},
//                        {2,5},
//                        {2,-3},
//                        {2,10},
//                        {4,10},
//                        {4,-5}
//                        };
//    t_lista lista;
//    t_lista listaAct;
//    int i;
//
//    crearLista(&lista);
//    crearLista(&listaAct);
//
//    for(i=0;i<8;i++)
//    {
//        insertarAlFinal(&lista, &prod[i], sizeof(t_producto));
//    }
//    recorrerLista(&lista, mostrarProd);
//    SEPARADOR;
//
//    sumaCant(&lista, &listaAct);
//
//    recorrerLista(&listaAct, mostrarProd);
//
//    return 0;
//}

/////////////////////////////////////////////////

int main()
{
//    int vec[5]={10,2,4,1,10};
//    int vec2[8]={3,2,4,1,5,4,3,6};

    ///arbol dibujado
//int vec[]={100,120,135,110,100,140,130,75,80,50};

///arbol balanceado h=4
//int vec[]={20, 0, 40, 10, -10, 30, 50, -15, -5, 5 ,15, 25, 35, 45, 55,-17, -12, -7, -2, 2 ,7 ,12, 17,22,27, 32, 37, 42, 47, 52, 57};

///arbol balanceado
//int vec[]={10,20, 0 ,15, 25, -5, 5};

///tiene nodos extra en las puntas
int vec[]={10,20, 0 ,15, 24, -4, 5,-6,-7,-5,-3,4,6,14,16,23,26,27,25};

    int i, acumulador=0;
    t_lista lista, listaTest;

    crearLista(&lista);
    crearLista(&listaTest);

    for(i=0;i<(sizeof(vec)/sizeof(int));i++)
    {
//         insertarAlFinal(&lista,&vec[i],sizeof(int));
        insertarOrdenado(&lista, &vec[i], sizeof(int), 0, comparar);
    }

    recorrerLista(&lista,mostrar);
    puts("///");
//
//    filtrarLista(&lista,fFiltro);
//    recorrerLista(&lista,mostrar);
//    puts("////");
//
//    printf("%d\n",*(int*)acumularDeLista(&lista,&acumulador,acumulacion));
//
//    puts("////");
//
//    for(i=0;i<8;i++)
//    {
//        insertarOrdenado(&listaTest, &vec2[i],sizeof(int), 0, comparar);
//    }
//
//    recorrerLista(&listaTest, mostrar);
//    puts("////Recursivo:");
//    recorrerFinRec(&listaTest, mostrar);
//    puts("////Normal:");
//    recorrerFin(&listaTest, mostrar);
//    puts("////");
    return 0;
}

/////////////////////////////////////////////////



void mostrar (const void * dato)
{
    printf("%d\n",*((int*)dato));
}

int fFiltro(const void* filtro)
{
    return (*(int*)filtro)< 3;
}

void* acumulacion(void*acum, void* dato)
{
    (*(int*)acum) += (*(int*)dato);
    return acum;
}

int comparar(const void *dato1, const void *dato2)
{
    return ((*(int*)dato1) - (*(int*)dato2));
}

void sumaCant(const t_lista* lista, t_lista* listaAcum)
{
    int acum;
    t_producto prod;
    unsigned codigo;

    while(*lista)
    {
        acum=0;
        codigo = ((t_producto*)(*lista)->info)->codigo;
        while(*lista && codigo == ((t_producto*)(*lista)->info)->codigo)
        {
            acum += ((t_producto*)(*lista)->info)->cant;
            lista = &(*lista)->sig;
        }
        prod.cant = acum;
        prod.codigo = codigo;
        insertarAlFinal(listaAcum,&prod,sizeof(t_producto));
    }
}

void mostrarProd(const void * dato)
{
    printf("%u, %d\n",((t_producto*)dato)->codigo, ((t_producto*)dato)->cant);
}
