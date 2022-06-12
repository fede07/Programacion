#include "cola.h"
#include <string.h>
#include <stdlib.h>
#define MIN(x,y) ((x)<(y)?(x):(y))
void crearCola(t_cola *cola)
{
    cola->pri = NULL;
    cola->ult = NULL;
}
int colaVacia(const t_cola *cola)
{
    return (cola->pri == NULL);
}
int colaLlena(const t_cola *cola, unsigned tamBy)
{
    t_nodo *temp = malloc(sizeof(t_nodo));
    if(temp == NULL)
        return 1;

    temp->dato = malloc(tamBy);
    if((temp->dato)== NULL)
    {
        free(temp);
        return 1;
    }

    free(temp->dato);
    free(temp);

    return 0;
}

int agregarEnCola(t_cola *cola, void *info, unsigned tamBy)
{
    t_nodo *nue = malloc(sizeof(t_nodo));
    if(!nue)
        return 0;
    nue->dato = malloc(tamBy);
    if(!(nue->dato))
    {
        free(nue);
        return 0;
    }
    if(cola->pri == NULL)
        cola->pri = nue;
    else
        cola->ult->sig = nue;

    nue->sig = NULL;
    memcpy(nue->dato,info,tamBy);
    nue->tam = tamBy; /// o con memcpy?

    cola->ult = nue;

    return 1;

}
int sacarDeCola(t_cola *cola, void *info, unsigned tamBy)
{
    t_nodo *elim;
    if((cola->pri)==NULL)
        return 0;

    elim=cola->pri;
    memcpy(info,elim->dato,MIN(tamBy,elim->tam));

    cola->pri=elim->sig;
    ///Opcional. Porque me deja la cola cuando se vacia en su situacion inicial
    if(cola->pri == NULL)
        cola->ult = NULL;

    free(elim->dato);
    free(elim);

    return 1;
}
void vaciarCola(t_cola *cola)
{
    t_nodo *elim;
    while(cola->pri)
    {
        elim=cola->pri;
        cola->pri=elim->sig;
        free(elim->dato);
        free(elim);
    }
    cola->ult=NULL; ///opcional
}

int verPriCola(const t_cola *cola, void *info, unsigned tamBy)
{
    if(cola->pri == NULL)
        return 0;

    memcpy(info, cola->pri->dato, MIN(tamBy, cola->pri->tam));

    return 1;
}

