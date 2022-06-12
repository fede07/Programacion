#ifndef ARCHIVOS2_H_INCLUDED
#define ARCHIVOS2_H_INCLUDED

#include <stdio.h>

#define TODO_OK 1
#define ERROR_ARCH 0
#define TAM 10
#define LARGO 80
#define ESLETRA(x) (((x)>='a' && (x)<='z')||((x)>='A' && (x)<='Z'))

int crearLote();
int abrirArchivo(FILE** archivo, char* nombre, char* modo);
void invPalDeArch(FILE *);
char * invertirPalabras(char *);
int proximaPalabra(char *, char **, char **);
void intercambio (char*,char*);

#endif // ARCHIVOS2_H_INCLUDED

