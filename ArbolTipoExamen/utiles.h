#ifndef UTILES_H_INCLUDED
#define UTILES_H_INCLUDED
#include "../Arbol/arbol.h"
#include "alumnos.h"


int cargarIndice(t_arbol *arbol, const char* nombre, int(*comparar)(const void*, const void*));

#endif // UTILES_H_INCLUDED
