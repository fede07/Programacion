#ifndef VECTORES_H_INCLUDED
#define VECTORES_H_INCLUDED

int menu();
void cargarVectorInt(int*, int);
void mostrarVectorInt(int*, int);
int insertarIntComp(int*, int, int, int*);
int insertarIntOrdenado(int *vect, int elemento, int tam, int *cant);
int eliminarElementoInt(int *vect, int posicion, int *cantidad);
int eliminarPrimeraAparicionInt(int *vect, int elemento, int *cantidad);
int eliminarTodaAparicionInt(int *vect,int elemElim,int *cant);

int cargarVectorIntFull(int*, int, int);

int esMayor(int, int);
int* esMenor(int*, int*);
int* buscarMenor (int *, int, int);
void intercambiar(int*, int*);
void ordenarSelecc(int*, int);

#endif // VECTORES_H_INCLUDED
