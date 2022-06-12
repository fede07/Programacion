#include <stdio.h>
#include <stdlib.h>

#include "macros.h"
int main()
{
    int entero=-99;
    float flotante=5.123, red;


    ///ABS
//    printf("Numero %d, numero en ABS %d\n",entero,ABS(entero));

    ///PARTE_ENTERA
//    printf("Numero %f, parte entera %d\n",flotante,PARTE_ENTERA(flotante,entero));

    ///PARTE_DECIMAL
//    printf("Numero %f, parte flotante %f\n",flotante,PARTE_DECIMAL(flotante));

    printf("\n\nNumero a redondear: 4.5673");
    REDONDEO(4.5673, 3, red);
    printf("\n\nEl redondeo de 4.5673 a 3 decimales es: %.3f", red);


    return 0;
}
