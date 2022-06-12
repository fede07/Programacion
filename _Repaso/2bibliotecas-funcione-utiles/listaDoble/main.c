#include <stdio.h>
#include <stdlib.h>
#include "listaDoble.h"

#define S printf("\n**********\n");
#define N printf("\n");

typedef struct
{
    int cod;
    char desc;
    int cant;
}t_prod;

int compararProd(const void*, const void*);
int compararInt(const void*, const void*);
void accionProd(const void*);
void accionInt(const void * a);
void acumularProd (void * dato, const void * nodo);
int filtro (const void*, const void*);
void* acumulacionInt(void * acum, void *n);

int main()
{
    int vec[] = {9,90,99,99,99};///7
    ///int vec[TAM] = {-10,-50,5,-50};
    int i;
 ///   int dato = 99;
        t_prod prod[]={{-1,'v',1},
                    {-2,'b',100},
                    {-90,'a',-70},
                    {-5,'c',-5},
                    {0,'w',7},
                    {-5,'z',5},
                    {0,'z',-7}
                    };
    t_lista lista;
    crearLista(&lista);
    for(i=0;i<sizeof(prod)/sizeof(t_prod);i++)
        insertarOrdenadoR_W(&lista,&prod[i],sizeof(t_prod),compararProd,acumularProd);

    recorrerListaR_W(&lista,accionProd);
    S

    recorrerListaRInv_W(&lista,accionProd);

//    S
//    recorrerListaDer(&lista,accion);




}


int compararProd(const void* cmp1, const void* cmp2)
{
    return (((t_prod*)(cmp1))->cod) - (((t_prod*)(cmp2))->cod);
}

int compararInt(const void* a, const void* b)
{
    return (*((int*)a) - *((int*)b));
}

void* acumulacionInt(void * acum, void *n)
{
    *(int*)acum+=*(int*)n;
    return acum;
}

void accionProd(const void * a)
{
    printf("%d %c %d\n",((t_prod*)(a))->cod,((t_prod*)(a))->desc,(((t_prod*)(a))->cant));
}

void accionInt(const void * a)
{
    printf("%d\n",*(int*)a);
}

void acumularProd (void * nodoInfo, const void * dato)
{
    ((t_prod*)nodoInfo)->cant += ((t_prod*)dato)->cant;
}

int filtro (const void* a, const void* b)
{
    return (((t_prod*)b)->cod % *(int*)a)==0;
}









