#include <stdio.h>
#include <stdlib.h>
#include "cadenas.h"

int main()
{
    char cadena1[20]="zzza",
         cadena2[10]="zz",
         caracter='\0';
    int resultado;

    ///strcmp
//    resultado = mi_strcmp(cadena1,cadena2);
//    printf("La cadena1 <%s> es ",cadena1);
//    if(resultado>0)
//        printf("mayor que <%s>",cadena2);
//    else if (resultado==0)
//        printf("igual que <%s>",cadena2);
//    else
//        printf("menor que <%s>",cadena2);
//
   ///strcpy
//    printf("Copiando cadena2: <%s> donde esta cadena1: <%s>\n",cadena2,cadena1);
//    printf("Resultado cadena1: <%s>",mi_strcpy(cadena1,cadena2));
//
    ///strcat solucionar problema con la capacidad de cadena1, permite mas valores de los que deberia
//    printf("Agregando <%s> a <%s>\n",cadena2,cadena1);
//    printf("Resultado cadena1: <%s>",mi_strcat(cadena1,cadena2));
//
    ///strlen
//    printf("Contando caracteres de <%s>\n",cadena1);
//    printf("Cantidad = %d",mi_strlen(cadena1));

    ///mi_toupper
//    printf("Viendo si es necesario pasar <%c> a mayuscula\n",caracter);
//    printf("Resultado <%c>",mi_toupper(caracter));

    ///tolower
//    printf("Viendo si es necesario pasar <%c> a minuscula\n",caracter);
//    printf("Resultado <%c>",mi_tolower(caracter));

    ///mi_strupr
//    printf("Pasando <%s> a mayuscula\n",cadena1);
//    printf("Resultado <%s>",mi_strupr(cadena1));

    ///mi_strlwr
//    printf("Pasando <%s> a minuscula\n",cadena1);
//    printf("Resultado <%s>",mi_strlwr(cadena1));

    ///mi_strchr
//    printf("Buscando si <%c> esta en <%s>\n",caracter,cadena1);
//    printf("Resultado: <%s>",mi_strchr(cadena1,caracter));

    ///
    printf("Cadena1 <%s> cadena2 <%s>\n",cadena1,cadena2);
    printf("resultado <%s>\n",mi_strstr(cadena1,cadena2));


    return 0;
}
