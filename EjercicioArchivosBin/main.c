#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int dni;
    char nyap[50];
    char dpto;
    float promedio;
}t_alumno;

int main()
{
    t_alumno alu;
    char linea[] = "20127140|Maria Pia|I|7.9";
    sscanf(linea, "%d|%[^|]|%c|%f", &alu.dni, alu.nyap, &alu.dpto, &alu.promedio);
    //fscanf(stdin, "%d|%[^|]|%c|%f", &alu.dni, alu.nyap, &alu.dpto, &alu.promedio);
    fprintf(stdout, "%d %s %c %f", alu.dni, alu.nyap, alu.dpto, alu.promedio);
}
