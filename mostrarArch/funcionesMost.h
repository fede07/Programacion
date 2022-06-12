#ifndef FUNCIONESMOST_H_INCLUDED
#define FUNCIONESMOST_H_INCLUDED
#include <stdio.h>


typedef struct
{
    int dni;
    char apellido[20];
    char nombre[20];
    float sueldo;
} t_empleado;

typedef struct
{
    t_empleado empleado;
    char codigo;
} t_novedad;

void mostrarArchivo(const char* nombreArch, void *info, size_t tam, void accion(void*));
void mostrarEmpleado(void *info);

#endif // FUNCIONESMOST_H_INCLUDED
