#include <stdio.h>
#include <stdlib.h>

#include "arbol.h"

#define S printf("\n******************\n");

typedef struct
{
    int cod;
    int cant;
} tmovimiento;

typedef struct
{
    int edad;
    int plata;
    int hijos;
} tpersona;

typedef struct
{
    float edad;
    float plata;
    float hijos;
}tprom;

int compararInt (const void * a, const void * b)
{
    return *((int*)a) - *((int*)b);
}

void mostrarInt (const void * a)
{
    printf("%d\n",*((int*)a));
}

int filtrarProd(const void*n)
{
    return (((tmovimiento*)n)->cod) > 10;
}

void mostrarProd (const void * a)
{
    printf("%d %d\n",((tmovimiento*)(a))->cod,((tmovimiento*)(a))->cant);
}

void* acumulacionProd(void * acum, void *n)
{
    *(int*)acum += ((tmovimiento*)n)->cant;
    return acum;
}

int compararProd (const void * dato1, const void * dato2)
{
    return ((tmovimiento*)(dato1))->cod - ((tmovimiento*)(dato2))->cod;
}

int compararPersona (const void * dato1, const void * dato2)
{
    return ((tpersona*)dato1)->edad - ((tpersona*)dato2)->edad;
}

int filtrarPersona(const void * n)
{
    if( ((tpersona*)n)->edad > 25 )
    {
        if( ((tpersona*)n)->hijos > 1)
            return 1;
    }
    return 0;
}

void* acumulacionPersona (void * acum, void *n)
{
    ((tpersona*)acum)->edad += ((tpersona*)n)->edad;
    ((tpersona*)acum)->plata += ((tpersona*)n)->plata;
    ((tpersona*)acum)->hijos += ((tpersona*)n)->hijos;
    return acum;
}

void mostrarPersona (const void * a)
{
    printf("%d %d %d\n",((tpersona*)(a))->edad,((tpersona*)(a))->plata,((tpersona*)(a))->hijos);
}

void promedioProd (void * prom, const void * acum, const void * cant)
{
    int a, b;
    a = *((int*)(acum));
    b = *((int*)cant);

    *((float*)prom) = ( (float)a / b );
    ///lo mismo pero sin variables
 ///   *((float*)prom) = ( (float)(*((int*)(acum))) / *((int*)cant) );

}

void promedioPersona (void * prom, const void * acum, const void * cant)
{
    int plata, edad, hijos;
    plata = ((tpersona*)acum)->plata;
    hijos = ((tpersona*)acum)->hijos;
    edad= ((tpersona*)acum)->edad;

    ((tprom*)prom)->edad =  ((float)edad / *(int*)cant);
    ((tprom*)prom)->hijos =  ((float)hijos / *(int*)cant);
    ((tprom*)prom)->plata =  ((float)plata / *(int*)cant);
}

int main()
{
///arbol dibujado en paint 9 nodos, h=3
//int vec[]={100,120,135,110,100,140,130,75,80,50};

///arbol balanceado h=4
//int vec[]={20, 0, 40, 10, -10, 30, 50, -15, -5, 5 ,15, 25, 35, 45, 55,-17, -12, -7, -2, 2 ,7 ,12, 17,22,27, 32, 37, 42, 47, 52, 57};

///arbol balanceado, 7 nodos, h = 2
//int vec[]={10,20, 0 ,15, 25, -5, 5};

///amongus / tiene nodos extra en las puntas
//int vec[]={10,20, 0 ,15, 24, -4, 5,-6,-7,-5,-3,4,6,14,16,23,26,27,25};

///13 nodos, h=6
//int vec[]={1,2,3,4,5,6,7,0,-1,-2,-3,-4,-5};

    tpersona persona[] =
    {
    ///edad, plata, hijos
        {29,10,3},
        {10,-50,0},
        {15,500,-5},
        {2,10,0},
        {70,1000,3},
        {20,10,15},
        {65,-100,1},
        {30,-900,0},
        {19,11,0}
    };
    tprom prom = {0,0,0};
    tpersona acum = {0,0,0};

    int i;
  ///  int nivel = 999;
    t_arbol arbolito;
    crearArbol(&arbolito);
//    for(i=0;i<sizeof(vec)/sizeof(int);i++)
//    {
//        insertarArbol(&arbolito,&vec[i],sizeof(int),compararInt);
//    }

    for(i=0;i<sizeof(persona)/sizeof(tpersona);i++)
    {
        insertarArbol(&arbolito,&persona[i],sizeof(tpersona),compararPersona);
    }

    rotar90g_i(&arbolito,mostrarPersona);

    promCondicionado(&arbolito,&acum,&prom,filtrarPersona,acumulacionPersona,promedioPersona);
    printf("a");
    printf("%f %f %f",prom.edad,prom.plata,prom.hijos);

    S

    return 0;
}
