#include "funciones.h"

#define TAM1 5
#define TAM2 7
#define LARGO 20
#define ARCHP1 "p1.txt"
#define ARCHP2 "p2.txt"
#define ARCHPR "pr.txt"

int generarLote()
{
    int i;
    FILE *p1;
    FILE *p2;
    char polinomio1[TAM1][LARGO] = {
                            "X(6)(-5)",
                            "X(+3)(6)",
                            "X(-5)(-7)",
                            "X(3)(9)",
                            "X(0)(-4)"
                            };
    char polinomio2[TAM2][LARGO] ={
                            "X(-8)(+6)",
                            "X(3)(9)",
                            "X(+4)(-3)",
                            "X(6)(5)",
                            "X(0)(0)",
                            "X(20000)(32000)",
                            "X(-20000)(-32000)"
                            };

    p1 = fopen(ARCHP1, "wt");
    if(!p1)
    {
        printf("No se pudo crear p1.txt");
        return 2;
    }
    p2 = fopen(ARCHP2, "wt");
    if(!p2)
    {
        fclose(p1);
        printf("No se pudo crear p2.txt");
        return 3;
    }

    for(i = 0; i<TAM1; i++)
    {
        fprintf(p1,"%s\n", polinomio1[i]);
    }

    for(i = 0; i<TAM2; i++)
    {
        fprintf(p2,"%s\n", polinomio2[i]);
    }

    fclose(p1);
    fclose(p2);

    return 1;
}

int sumarPolinomios()
{
    FILE *p1;
    FILE *p2;
    FILE *pRes;
    t_polinomio polinom;
    t_lista poliOrden;
    char cadena[LARGO];

    p1 = fopen(ARCHP1, "rt");

    if(!p1)
    {
        return 0;
    }
    p2 = fopen(ARCHP2, "rt");

    if(!p2)
    {
        fclose(p1);
        return 0;
    }

    pRes = fopen(ARCHPR,"wt");

    if(!pRes)
    {
        fclose(p1);
        fclose(p2);
        return 0;
    }

    crearLista(&poliOrden);

    while(fgets(cadena, LARGO, p1))
    {
        sscanf(cadena, "X(%d)(%d)", &(polinom.poten), &(polinom.coef));

        insertarOrdenadoAcum(&poliOrden,
                             &polinom,
                             sizeof(t_polinomio),
                             compararPolinomio,
                             acumularPolinomio);
    }

    fclose(p1);

    while(fgets(cadena, LARGO, p2))
    {
        sscanf(cadena, "X(%d)(%d)", &(polinom.poten), &(polinom.coef));

        insertarOrdenadoAcum(&poliOrden,
                             &polinom,
                             sizeof(t_polinomio),
                             compararPolinomio,
                             acumularPolinomio);
    }
    fclose(p2);

    recorrerListaGuardarArch(&poliOrden,pRes,filtroPolinomio, guardarPolinomioEnArch);

    fclose(pRes);

    vaciarLista(&poliOrden);

    return 1;
}

void crearLista(t_lista *lista)
{
    *lista=NULL;
}

int insertarOrdenadoAcum(t_lista* lista, void* info, unsigned tamBy,
                         int(*comparar)(const void*, const void*),
                         void* (*acumulacion)(void*, void*))
{
    t_nodo* nue = (t_nodo*)malloc(sizeof(t_nodo));
    int comp = 1;

    if(!nue)
        return 0;

    while((*lista) && ((comp = comparar(((*lista)->info),info)) < 0))
    {
        lista = &(*lista)->sig;
    }

    if(comp == 0)
    {
        acumulacion((*lista)->info, info);
        return 1;
    }

    nue->info = malloc(tamBy);

    if(!(nue->info))
    {
        free(nue);
        return 0;
    }

    memcpy(nue->info, info, tamBy);
    nue->tamBy = tamBy;
    nue->sig = *lista;
    *lista = nue;

    return 1;
}

int compararPolinomio(const void *poli1, const void *poli2)
{
    return  (((t_polinomio*)(poli2))->poten)-(((t_polinomio*)(poli1))->poten);
}

void* acumularPolinomio(void *acum, void *polinomio)
{
    ((t_polinomio*)(acum))->coef += ((t_polinomio*)polinomio)->coef;
    return acum;
}

void recorrerListaGuardarArch(t_lista *lista, FILE *arch, int(*filtro)(void*dato), void (*accion)(void* dato, FILE* arch))
{
    while(*lista)
    {
        if(filtro((*lista)->info))
            accion((*lista)->info,arch);
        lista = &(*lista)->sig;
    }
}

int filtroPolinomio(void *dato)
{
    return ((t_polinomio*)(dato))->coef;
}

void guardarPolinomioEnArch(void *dato, FILE* arch)
{
    fprintf(arch, "X(%d)(%d)\n",((t_polinomio*)dato)->poten,((t_polinomio*)dato)->coef);
}

void vaciarLista (t_lista* lista)
{
    t_nodo * elim;
    while((*lista) && (*lista)->sig)
    {
        elim = *lista;
        *lista = (*lista)->sig;
        free(elim->info);
        free(elim);
    }
    if(*lista)
    {
        elim = *lista;
        free(elim->info);
        free(elim);
    }

    *lista = NULL;
}
