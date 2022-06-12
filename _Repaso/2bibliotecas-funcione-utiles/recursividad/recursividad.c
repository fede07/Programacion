#include <stdlib.h>
#include "recursividad.h"

unsigned long Rfactorial (unsigned n)
{
    return n>1?n*Rfactorial(n-1):1;
}

unsigned strlen2(const char * cad)
{
    if(*cad)
    {
        return strlen2(cad+1)+1;
    }
    return 0;
}

int rEsPalindromo (char * cad, char * fin)
{
    if(cad>=fin)
    {
        return 1;
    }

    if(!ESLETRA(*cad))
    {
        return rEsPalindromo(cad+1,fin);
    }

    if(!ESLETRA(*fin))
    {
        return rEsPalindromo(cad,fin+1);
    }

    if(*cad==*fin)
    {
        return rEsPalindromo(cad+1,fin-1);
    }
    else
        return 0;
}

int esPalindromo (const char * cad)
{
    char * fin = (char*)cad + strlen2(cad)-1;

    return rEsPalindromo ((char*)cad, fin);
}

void *miBsearch (const void *clave, const void *iniVec, unsigned nitems, unsigned tam, int (*compar)(const void *, const void *))
{
    return rSearch(clave,iniVec,iniVec+(nitems-1)*tam,tam,compar);
}

void* rSearch(const void* clave, const void* iniVec,const void* finVec,unsigned tam,int (*compar)(const void *, const void *))
{
    const void* pm=iniVec+((((finVec-iniVec+tam)/tam)/2)*tam);

    if(iniVec>finVec)
    {
        return NULL;
    }

    if(compar(clave,pm)==0)
    {
        return (void*)pm;
    }
    else if(compar(clave,pm)>0)
    {
        return rSearch(clave,pm+tam,finVec,tam,compar);
    }
    else
    {
        return rSearch(clave,iniVec,pm-tam,tam,compar);
    }
}










