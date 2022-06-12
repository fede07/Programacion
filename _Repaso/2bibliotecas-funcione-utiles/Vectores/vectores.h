#ifndef VECTORES_H_INCLUDED
#define VECTORES_H_INCLUDED

void mostrarVec (int * vec, int * cantElem);


///valida una opcion dentro de un rango dado devolviendo 1 si es correcto, o 0 si no lo es
int valida (int opcion, int rangoMin, int rangoMax);
///inserta un valor en una posicion pedida
void insertaPos (int * vec, int numero, int posicion, int * cantElem, int tam);
///funciones para ordenar
void ordenar_seleccion(int * vec,int TAM, int ce);
int * buscarMenor (int * vec, int ce);
void intercambiar (int * vec, int * posicionMenor);
///dada una posicion se elimina ese elemento
void eliminarPosicion (int * vec, int pos, int * ce);
void insertarEnOrden (int * vec, int numero, int tam, int * cantElem);
void eliminarPrimeraAparicion(int *vect, int elemento, int * cantidad);
void eliminarTodaAparicion(int *vec, int elemento, int * cantidad);

#endif // VECTORES_H_INCLUDED
