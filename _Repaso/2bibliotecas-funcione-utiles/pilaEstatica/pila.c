#include <strings.h>
#include "pila.h"

void crearPila(t_pila* pila)
{
    pila->tope=TAM;
}

int ponerEnPila(t_pila* pila, const void* info, unsigned tambyte)
{
    if(pila->tope < (tambyte + sizeof(unsigned) ))
        return 0;

    pila->tope -= tambyte;
    memcpy(pila->iniPila + pila->tope, info, tambyte);
    pila->tope-=sizeof(unsigned);
    memcpy(pila->iniPila + pila->tope, &tambyte, sizeof(unsigned));

    return 1;
}

int sacarDePila(t_pila* pila, void* info, unsigned tambytes)
{
    unsigned tamTemp;
    if(pila->tope == TAM)
        return 0;

    memcpy(&tamTemp, (pila->iniPila + pila->tope), sizeof(unsigned));
    pila->tope += sizeof(unsigned);

    memcpy(info, (pila->iniPila + pila->tope), MIN(tamTemp, tambytes));
    pila->tope += tamTemp;

    return 1;
}

int verTope(const t_pila* pila, void* info, unsigned tambytes)
{
    unsigned tamTemp;

    if(pila->tope == TAM)
    {
        return 0;
    }

    memcpy(&tamTemp, (pila->iniPila + pila->tope), sizeof(unsigned));

    memcpy(info, (pila->iniPila + pila->tope + sizeof(unsigned)), MIN(tamTemp, tambytes));

    return 1;
}

int pilaVacia(const t_pila* pila)
{
    return (pila->tope == TAM);
}

void vaciarPila(t_pila* pila)
{
    pila->tope = TAM;
}

int pilaLlena(const t_pila* pila, unsigned tambytes)
{
    return ((pila->tope) < (tambytes+sizeof(unsigned)));
}
