#ifndef LOTES_H_INCLUDED
#define LOTES_H_INCLUDED

#define TAM 8
#define LARGO 38
#define ERROR_ARCH 100
#define TODO_OK 1
#define NOMBREARCHLOTE "lotePrueba.txt"

typedef struct{
    int dni;
    char nyap[50];
    char dpto;
    float promedio;
}t_alumno;

int crearLoteVar();
int abrirArchivo(FILE** archivo, char* nombre, char* modo);
int parseo(char*, t_alumno*);
#endif // LOTES_H_INCLUDED
