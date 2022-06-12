#include <stdlib.h>
#include <stdio.h>

int menuDinamicoDiezOps()
{
    return 0;
}

int menuCadena()
{
    int opcion, i;
    do
    {
        i=1;
        printf("\t*******************************************\n");
        printf("\t*          FUNCIONES DE CADENAS           *\n");
        printf("\t*******************************************\n\n\n");
        printf("\t\t%d.Cargar Cadenas\n",i);
        i++;
        printf("\t\t%d.Mostrar Cadenas\n",i);
        i++;
        printf("\t\t%d.Cadena a mayusculas\n",i);
        i++;
        printf("\t\t%d.Cadena a minusculas\n",i);
        i++;
        printf("\t\t%d.Copiar Cadena\n",i);
        i++;
        printf("\t\t%d.Concatenar Cadenas\n",i);
        i++;
        printf("\t\t%d.Comparar Cadenas\n",i);
        i++;
        printf("\t\t%d.Longitud de cadenas\n",i);
        i++;
        printf("\t\t%d.Primera aparicion de un caracter\n",i);
        i++;
        printf("\t\t%d.Primera aparicion de un string\n",i);
        i++;
        printf("\t\t0.Salir\n");
        i++;
        scanf("%d", &opcion);
        system("cls");
    }
    while(opcion<0 || opcion>i);
    return opcion;
}
