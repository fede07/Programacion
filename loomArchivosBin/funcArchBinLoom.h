#ifndef FUNCARCHBINLOOM_H_INCLUDED
#define FUNCARCHBINLOOM_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMALU 13
#define TAMEMP 10
#define AUMENTO 1.728

typedef struct
{
    int dni;
    char apellido[20];
    char nombre[20];
    float promedio;
} t_alumno;

typedef struct
{
    int dni;
    char apellido[20];
    char nombre[20];
    double sueldo;
} t_empleado;

///ordenados alfabéticamente por <apellido> / <nombre> /<dni>

void crearArchivos();
void actualizarArch(FILE* archAlum, FILE* archEmpl, FILE* archUpdate);

#endif // FUNCARCHBINLOOM_H_INCLUDED
