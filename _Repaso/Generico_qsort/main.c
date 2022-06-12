#include <stdio.h>
#include <stdlib.h>
#include "Generico_qsort.h"

///hacer que qsort2 devuelva el vector ordenado en vez de void

int main()
{
    int vector[5] = {1,0,-5,27,999};
    char cadena[6]="edcba";
    t_emp emp[16]= {{123333,"Fernandez Juana",250},
                    {458922,"Fernandez Juana",300},
                    {2,"Gonzalez Maria",100},
                    {1,"Gonzalez Maria",300},
                    {1,"Rodriguez Martin",800},
                    {2,"Rodriguez Martin",1100},
                    {3,"Tortuga Pepito",1300},
                    {4,"Tortuga Pepito",10},
                    {889648,"Werez Nicolas",0},
                    {9,"Zar Pepito",1200},
                    {6,"Zar Pepito",750}
                    };
    int i;

    printf("***** comparInt *****\n");
    printf("Ordenando: ");
    for(i=0;i<5;i++)
        printf("%d ", vector[i]);
    qsort2(vector, 5, sizeof(int), comparInt);
    printf("\nResultado: ");
    for(i=0;i<5;i++)
        printf("%d ", vector[i]);

    printf("\n\n***** comparInt *****\n");
    printf("Ordenando: ");
    puts(cadena);
    qsort2(cadena, 5, sizeof(char), comparChar);
    printf("Resultado: ");
    puts(cadena);

    printf("\n\n***** comparEmp *****\n");
    printf("Ordenando:\n");
    for(i=0;i<11;i++)
    {
        printf("%d %s\n",emp[i].dni,emp[i].apyn);
    }
    qsort2(emp, 11, sizeof(t_emp), comparEmp);
    printf("\nResultado:\n");
    for(i=0;i<11;i++)
    {
        printf("%d %s\n",emp[i].dni,emp[i].apyn);
    }

    return 0;
}
