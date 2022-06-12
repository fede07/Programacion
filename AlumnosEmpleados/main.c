#include <stdio.h>
#include <stdlib.h>
#include "alumEmpl.h"

#define LARGO 30
#define TAM 10

int loteDePruebas();

int main()
{
    loteDePruebas();
    return 0;
}

int loteDePruebas()
{
    char empleado[10][LARGO]={    "123333/Fernandez/Juana/250\n",
                                        "456666/Garcia/Jose/200\n",
                                        "456798/Gonzalez/Maria/100\n",
                                        "789999/Gonzalez/Maria/300\n",
                                        "000000/Lopez/Francisco/500\n",
                                        "111222/Rodriguez/Luis/800\n",
                                        "321321/Rodriguez/Martin/1100\n",
                                        "654789/Tortuga/Pepito/1300\n",
                                        "889648/Werez/Martin/0\n",
                                        "999854/Zar/Pepita/1200\n"
                                    };

    char alumno[14][LARGO]= {       "123333/Fernandez/Juana/2.50\n",
                                        "456666/Garcia/Jose/2\n",
                                        "123365/Garcia/Jose/1.5\n",///este no es empleado
                                        "456798/Gonzalez/Maria/9\n",
                                        "789999/Gonzalez/Maria/3\n",
                                        "666548/Hernandez/Pepe/8.5\n",///este no es empleado
                                        "998775/Hernandez/Pepe/3\n",///este no es empleado
                                        "000000/Lopez/Francisco/5.\n",
                                        "111222/Rodriguez/Luis/8\n",
                                        "321321/Rodriguez/Martin/9\n",
                                        "654789/Tortuga/Pepito/10\n",
                                        "889648/Werez/Martin/8\n",
                                        "999854/Zar/Pepita/7\n"
                                };
    FILE *pEmpl, *pAlum;
    int i;

    pEmpl=fopen("Empleados.bin","wb");
    if(!pEmpl)
    {
        printf("NO SE PUDO CREAR EMPLEADOS");
        return 0;
    }
    pAlum=fopen("Alumnos.bin", "wb");
    if(!pAlum)
    {
        printf("NO SE PUDO CREAR ALUMNOS");
        fclose(pEmpl);
        return 0;
    }
    for(i=0;i<10;i++)
    {
        fprintf(pEmpl, "%s", empleado[i]);
    }

    for(i=0;i<13;i++)
    {
        fprintf(pAlum, "%s", alumno[i]);
    }
    fclose(pEmpl);
    fclose(pAlum);
    return 1;
}
