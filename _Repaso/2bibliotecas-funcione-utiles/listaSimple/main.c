#include <stdio.h>
#include <stdlib.h>
#include "listaSimple.h"

#define N printf("\n");
#define S printf("\n*****************\n");

#define TAM 9

typedef struct
{
    int cod;
    int cant;
} tstock;

typedef struct
{
    int cod;
    int cant;
} tmovimiento;

void mostrarInt (const void *);
int fFiltro(const void*);
int filtrarProd(const void*);
void* acumulacionInt(void * acum, void *n);
int compararInt(const void * a, const void * b);
void promedioProd (void * prom, const void * acum, const void * cant);

void mostrarProd (const void * a);

void sumaCant (const t_lista * lista, t_lista * listaAcum, int (*comparacion) (const t_lista * lista, const t_lista * sig),void (*acumular)(const t_lista * lista, int  * acum), void (*insertarAcum) (int acum, const t_lista * lista, t_lista * listaAcum));
int compararProd (const void * lista, const void * sigL);
void * actualizarProd(void * acum, void  * dato);
void insertarAcumProd (int acum, const t_lista * lista, t_lista * listaAcum);
void* acumulacionProd(void * acum, void *n);

int crearStockYMovimientos()
{    tstock stock[] =
    {
        {1, 100},{2,500},{10,100},{3,1000},{3,1},{3,5000},{11,900}
    };

    tmovimiento movs[] =
    {
        {29,11},
        {10,-50},
        {10,-55},
        {2,-50},
        {91,11},
        {1,10},
        {3,-100},
        {3,-900},
        {19,11}
    };

    FILE* fstock = fopen("stock.dat", "wb");
    FILE* fmov = fopen("movimientos.dat", "wb");

    if(!fstock)
    {
        return 0;
    }
    if(!fmov)
    {
        fclose(fstock);
        return 0;
    }

    fwrite(stock, sizeof(stock),1, fstock);
    fwrite(movs, sizeof(movs),1, fmov);

    fclose(fstock);
    fclose(fmov);
    return 1;
}

int main()
{
 ///   int vec[]={5,8,1,3,6,9,7,0,2,4};
    tmovimiento movs[] =
    {
        {29,11},
        {11,-50},
        {10,-55},
        {2,-50},
        {91,-11},
        {1,-10},
        {31,-100},
        {3,-900},
        {19,-11}
    };
    float prom = 0;
    tmovimiento acum = {0,0};
    t_lista lista;
    int i;
///    int resultado=0;
    crearLista(&lista);

    for(i=0;i<sizeof(movs)/sizeof(tmovimiento);i++)
        insertarAlFinal(&lista,&movs[i],sizeof(tmovimiento));

    ordenarMayMenDatoRec(&lista,compararProd);

    recorrerIniRec(&lista,mostrarProd);
    S

    promedioCond(&lista,&acum,&prom,filtrarProd,acumulacionProd,promedioProd);

    printf("%f",prom);

}



void mostrarInt (const void * a)
{
    printf("%d\n",*((int*)a));
}

void mostrarProd (const void * a)
{
    printf("%d %d\n",((tstock*)(a))->cod,((tstock*)(a))->cant);
}

int fFiltro(const void* a)
{
    return *(int*)a<3;
}

int filtrarProd(const void*n)
{
    return (((tmovimiento*)n)->cod) < 21;
}

void* acumulacionInt(void * acum, void *n)
{
    *(int*)acum+=*(int*)n;
    return acum;
}

void* acumulacionProd(void * acum, void *n)
{
    *(int*)acum += ((tmovimiento*)n)->cant;
    return acum;
}

int compararInt(const void *  a, const void * b)
{
    return *(int*)a-*(int*)b;
}

void promedioProd (void * prom, const void * acum, const void * cant)
{
    int a, b;
    a = *((int*)(acum));
    b = *((int*)cant);

    *((float*)prom) = ( (float)a / b );
}

///falta borrar nodos de la primer lista
void sumaCant (const t_lista * lista, t_lista * listaAcum, int (*comparacion) (const t_lista * lista, const t_lista * sig),void (*acumular)(const t_lista * lista, int  * acum), void (*insertarAcum) (int acum, const t_lista * lista, t_lista * listaAcum))
{
    int acum;
    int comp = 1;

    while(*lista)
    {
        acum = 0;
        comp = comparacion(lista,&(*lista)->sig);

        while((*lista)->sig && comp==0)
        {
            acumular(lista,&acum);
            lista = &(*lista)->sig;
            if((*lista)->sig)
                comp = comparacion(lista,&(*lista)->sig);
        }
        if(*lista)
        {
            acumular(lista,&acum);
            insertarAcum(acum,lista,listaAcum);///insertamos en la otra lista
            lista = &(*lista)->sig;
        }
    }
}

int compararProd (const void * dato1, const void * dato2)
{
    return ((tstock*)(dato1))->cod - ((tstock*)(dato2))->cod;
}

void * actualizarProd(void * acum, void  * dato)
{
    ((tstock*)(acum))->cant += ((tstock*)(dato))->cant;
    return acum;
}

void insertarAcumProd (int acum, const t_lista * lista, t_lista * listaAcum)
{
    t_prod temp;
    temp = *((t_prod*)((*lista)->dato));
    temp.cant = acum;
    insertarAlFinal (listaAcum,&temp, sizeof(t_prod));
}

