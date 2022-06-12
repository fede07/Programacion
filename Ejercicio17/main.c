#include <stdio.h>
#include <stdlib.h>

#define ALUMARCH alumnos.txt

int main()
{
    FILE* empleados;
    FILE* alumnos;

    alumnos = fopen(ALUMARCH, "rt");

    return 0;
}
