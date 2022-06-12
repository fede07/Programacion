#ifndef ALUMEMPL_H_INCLUDED
#define ALUMEMPL_H_INCLUDED

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
    float sueldo;
} t_empleado;

typedef struct
{
    t_empleado empleado;
    char codigo;
} t_novedad;

#endif // ALUMEMPL_H_INCLUDED
