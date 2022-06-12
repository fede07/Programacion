#ifndef RECURSIVIDAD_H_INCLUDED
#define RECURSIVIDAD_H_INCLUDED
#include <stdio.h>

#define ESLETRA(x) ( ((x)>'a' && (x)<'z')||((x)>'A' && (x)<'Z') )

unsigned long factorialRec (unsigned numero);
unsigned strlenRec(const char *cad);
int esPalindromoRec(char *cad, char *fin);
int esPalindromo(const char *cad);
//void recorrerFinRec(t_lista*,void(*accion)(const void *));

void *miBsearch (const void * clave, const void * base, unsigned nitems, unsigned , int(*compar)(const void *, const void *));
void *rSearch (const void * clave, const void * iniVec, const void * finVec, unsigned tam, int(*compar)(const void *, const void *));

#endif // RECURSIVIDAD_H_INCLUDED
