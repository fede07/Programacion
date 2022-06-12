#ifndef UTILES_H_INCLUDED
#define UTILES_H_INCLUDED
#include <stdio.h>
#include "../Arbol/arbol.h"
#include "alumnos.h"


int cargarIndice(const char *nombre, t_arbol *arbol, int (*compar)(const void*, const void*));
int cargar_Idx_ArchivoInord(t_arbol *arbol, int (*comparar)(const void*, const void*));
int cargar_Idx_ArchivoInord_i(t_arbol *arbol, int ini, int fin, FILE *archivo, int (*comparar)(const void*, const void*));

#endif // UTILES_H_INCLUDED
