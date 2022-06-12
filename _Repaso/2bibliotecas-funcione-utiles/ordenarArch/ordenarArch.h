#ifndef ORDENARARCH_H_INCLUDED
#define ORDENARARCH_H_INCLUDED

#define TAM 10

typedef struct
{
    int id;
    char cadena[20];
    float algo;
}t_struct;

typedef struct
{
    int id;
    int posArch;
}t_orden;


int cmpStruct (const void * n, const void *n2);
int ordenar ();

#endif // ORDENARARCH_H_INCLUDED
