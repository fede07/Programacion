#include "recursividad.h"

unsigned long factorialRec(unsigned numero)
{
    return (numero>1)?(numero*factorialRec(numero-1)):1;
}

unsigned strlenRec(const char *cad)
{
    if(*cad)
    {
        return strlenRec(cad+1)+1;
    }
    return 0;
}

int esPalindromoRec(char *cad, char *fin)
{
    if(cad>=fin)
    {
        return 1;
    }

    if(!ESLETRA(*cad))
    {
        return esPalindromoRec(cad+1,fin);
    }

    if(!ESLETRA(*fin))
    {
        return esPalindromoRec(cad,fin+1);
    }

    if(*cad==*fin)
    {
        return esPalindromoRec(cad+1,fin-1);
    }
    else
        return 0;
}

int esPalindromo (const char *cad)
{
    char * fin = (char*)cad + strlenRec(cad)-1;

    return esPalindromoRec ((char*)cad, fin);
}

//void recorrerFinRec(t_lista* lista, void(*accion)(const void *))
//{
//    if(!*lista)
//        return;
//
//    if((*lista)->sig)
//    {
//        recorrerFinRec(&(*lista)->sig,accion);
//    }
//    accion((*lista)->dato);
//}

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

