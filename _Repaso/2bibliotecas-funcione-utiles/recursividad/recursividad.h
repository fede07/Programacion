#ifndef RECURSIVIDAD_H_INCLUDED
#define RECURSIVIDAD_H_INCLUDED

#define ESLETRA(x) ( ((x)>'a' && (x)<'z')||((x)>'A' && (x)<'Z') )

unsigned long Rfactorial (unsigned);
unsigned strlen2(const char *);
int esPalindromo (const char *);
///void recorrerFinRec(t_lista*,void(*accion)(const void *));
///void recorrerIniRec(t_lista* lista, void(*accion)(const void *));
void *miBsearch (const void * clave, const void * base, unsigned nitems, unsigned , int(*compar)(const void *, const void *));
void *rSearch (const void * clave, const void * iniVec, const void * finVec, unsigned tam, int(*compar)(const void *, const void *));


#endif // RECURSIVIDAD_H_INCLUDED
