#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include "cadena.h"
#include "C:\Users\fede0\Documents\Programacion\menuGenerico\menu.h"

#define FACTORIAL(X,Y)  for(i=1;i<=X;i++)\
                        {\
                            (Y)*=i;\
                        };\

#define TAM 5

int main()
{
    char destino[] = "OTRO PEPITO";
    char origen[]  = "HOLZ";
    char pepito[] = "PEPITO";

    char destino2[] = "OTRO PEPITO";
    char origen2[]  = "HOLZ";
    char pepito2[] = "PEPITO";


    printf("Antes de memcpy <%s>, src = <%s>\n", destino, origen);
    memcpy((origen+1), origen,TAM);
    printf("memcpy <%s>, src = <%s>\n", destino, origen);

    printf("\n SEPARACION\n\n");

    printf("Antes de memcpy_mi <%s>, src = <%s>\n", destino2, origen2);
    memcpy_MI((origen2+1), origen2,TAM);
    printf("memcpy_mi <%s>, src = <%s>\n", destino2, origen2);

    printf("\n SEPARACION\n\n");

    printf("%s\n", pepito);
    printf("%s\n", pepito2);

    printf("%d", (int)sizeof(origen));
    return(0);
}


//int main()
//{
////    int menu, opcion, salir = 1;
////    char cadena1[] = "y con lopez Obrador mucho dulce de leche";
//    char cadena2[] = "aaab564654";
//    char cadena3[] = "aab";
////    char cadena4[] = "";
////    char char1= '\0';
////    char char2= 'z';
//
////    printf( "\ns1=%s\n", cadena1 );
//    printf( "\nCadena 1: *%s*\n", cadena2 );
//    printf( "\nCadena 2: *%s*\n", cadena3 );
////
////    printf("\ncompararString devuelve: %d", compararString(cadena3, cadena2));
////    printf("\nSTRCMP devuelve: %d", strcmp(cadena3, cadena2));
////
////    printf("\ncompararStringIg devuelve: %d", compararStringIg(cadena3, cadena2));
////    printf("\nSTRCMPI devuelve: %d", strcmpi(cadena3, cadena2));
//
////    printf( "\nMIstrstr(s1,s2) = %s\n", primerAparicionDeStringEnString( cadena1, cadena2 ) );
////    printf( "\nstrstr(s1,s2) = %s\n", strstr( cadena1, cadena2 ) );
//
////    printf("\nLa letra buscada es: %p", primerAparicionDeStringEnString(cadena2, cadena3));
////    printf("\nLa letra buscada es: %s", primerAparicionDeStringEnString(cadena2, cadena3));
////    printf("\nLa letra buscada es: %p", strstr(cadena2, cadena3));
////    printf("\nLa letra buscada es: %s", strstr(cadena2, cadena3));
////
////    printf( "\ns1=%s\n", cadena1 );
////    printf( "\ns1=%s\n", cadena2 );
////    printf( "\ns2=%s\n", cadena3 );
//
////    printf("\nLa cadena buscada es: %p", primerAparicionDeStringEnString(cadena3, cadena2));
//    printf("\nMi strstr devuelve: *%s*\n", primerAparicionDeStringEnString(cadena2, cadena3));
////    printf("\nLa letra buscada es: %p", strstr(cadena3, cadena2));
//    printf("\nSTRSTR devuelve: *%s*\n", strstr(cadena2, cadena3));
//    printf("\nbuscarSubcadena devuelve: *%s*\n", strstr(cadena2, cadena3));
//
//    printf( "\nCadena 1: *%s*\n", cadena2 );
//    printf( "\nCadena 2: *%s*\n", cadena3 );
//
////    printf("\nLa letra buscada es: %p", ultimaAparicionEnString(cadena3, 'c'));
////    printf("\nLa letra buscada es: %s", ultimaAparicionEnString(cadena3, 'c'));
////    printf("\nLa letra buscada es: %p", strrchr(cadena3, 'c'));
////    printf("\nLa letra buscada es: %s", strrchr(cadena3, 'c'));
////
////    printf("\nLa letra buscada es: %p", ultimaAparicionEnString(cadena3, char1));
////    printf("\nLa letra buscada es: %s", ultimaAparicionEnString(cadena3, char1));
////    printf("\nLa letra buscada es: %p", strrchr(cadena3, char1));
////    printf("\nLa letra buscada es: %s", strrchr(cadena3, char1));
////
////    printf("\nLa letra buscada es: %p", ultimaAparicionEnString(cadena3, char2));
////    printf("\nLa letra buscada es: %s", ultimaAparicionEnString(cadena3, char2));
////    printf("\nLa letra buscada es: %p", strrchr(cadena3, char2));
////    printf("\nLa letra buscada es: %s", strrchr(cadena3, char2));
//
////    printf("\nLa letra buscada es: %p", primerAparicionEnString(cadena3, 'c'));
////    printf("\nLa letra buscada es: %s", primerAparicionEnString(cadena3, 'c'));
////    printf("\nLa letra buscada es: %p", strchr(cadena3, 'c'));
////    printf("\nLa letra buscada es: %s", strchr(cadena3, 'c'));
////
////    printf("\nLa letra buscada es: %p", primerAparicionEnString(cadena3, char1));
////    printf("\nLa letra buscada es: %s", primerAparicionEnString(cadena3, char1));
////    printf("\nLa letra buscada es: %p", strchr(cadena3, char1));
////    printf("\nLa letra buscada es: %s", strchr(cadena3, char1));
////
////    printf("\nLa letra buscada es: %p", primerAparicionEnString(cadena3, char2));
////    printf("\nLa letra buscada es: %s", primerAparicionEnString(cadena3, char2));
////    printf("\nLa letra buscada es: %p", strchr(cadena3, char2));
////    printf("\nLa letra buscada es: %s", strchr(cadena3, char2));
//
//
////    do
////    {
//        menu=menuCadena();
//        switch(menu)
//        {
//        case 1:
//            printf("\nElegir cadena a ingresar:");
//            scanf("%d", &opcion);
//            if(opcion == 1)
//            {
//                gets(cadena1);
//            }
//            else
//            {
//                gets(cadena2);
//            }
//            fflush(stdin);
//            system("cls");
//            break;
//        case 2:
//            printf("\nCadena1: %s", cadena1);
//            printf("\nCadena2: %s", cadena2);
//            getch();
//            fflush(stdin);
//            system("cls");
//            break;
//        case 3:
//            printf("\nCadena1: %s", cadena1);
//            printf("\nCadena2: %s", cadena2);
//            printf("\nElegir cadena a poner en mayuscula:");
//            scanf("%d", &opcion);
//            if(opcion == 1)
//            {
//                aMayusculaString(cadena1);
//            }
//            else
//            {
//                aMayusculaString(cadena2);
//            }
//            fflush(stdin);
//            printf("\nCadena1: %s", cadena1);
//            printf("\nCadena2: %s", cadena2);
//            getch();
//            fflush(stdin);
//            system("cls");
//            break;
//        case 4:
//            printf("\nCadena1: %s", cadena1);
//            printf("\nCadena2: %s", cadena2);
//            printf("\nElegir cadena a poner en minuscula:");
//            scanf("%d", &opcion);
//            if(opcion == 1)
//            {
//                aMinusculaString(cadena1);
//            }
//            else
//            {
//                aMinusculaString(cadena2);
//            }
//            fflush(stdin);
//            printf("\n\nCadena1: %s", cadena1);
//            printf("\nCadena2: %s", cadena2);
//            getch();
//            fflush(stdin);
//            system("cls");
//            break;
//        case 5:
//            printf("\nCadena1: %s", cadena1);
//            printf("\nCadena2: %s", cadena2);
//            copiarString(cadena2, cadena1);
//            printf("\nCadena2 modificado: %s", cadena2);
//            getch();
//            fflush(stdin);
//            system("cls");
//            break;
//        case 0:
//            salir=0;
//            break;
//        }
//    }
//    while(salir);
//    return 0;
//}




//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include "cadena.h"
//
//int main()
//{
////    char *cad99=    "uno";
//    char cad1[30]=   "Pato";
//    char cad2[30]=    "pATO";
//    char carac = 'a';
//    int i;
////    char cad3[10]=  "cuatro";
//////  char cad4[2]=   "cinco"; //Warning
////    char cad5[8]=   {'s','e','i','s'};
////    char cad6[]=    {'S','I'};
//////  char cad7[]; Necesita tamaño
////    char cad8[]=    {'n','o'};
////    char cad9[4];
//////  char cad10[4]=  0;
////    char cad101[4]= {0};
//////  char cad11[]=   0;
////    char cad21[]=   "tres\0";
////    char cad22[]=   "tres\0236589";
////
////    printf("\n%s", cad99);
////    printf("\n%s", cad1);
////    printf("\n%s", cad2);
////    printf("\n%s", cad3);
////    printf("\n%s", cad5);
////    printf("\n%s", cad6);
////    printf("\n%s", cad8);
////    printf("\n%s", cad9);
////    printf("\n%s", cad101);
////    printf("\n%s", cad21);
////    printf("\n%s", cad22);
//
////    aMayuscula(cad1);
////    printf("\n%s", cad1);
////    aMinuscula(cad1);
////    printf("\n%s", cad1);
////    copiarString(cad2, cad1);
////    printf("\n%s", cad2);
//    printf("\nOriginal: %s",cad2);
//    printf("\nConcatenado: %s", concatenarString(cad2, cad1));
//    printf("\n%s", cad2);
//    printf("\n%s", cad1);
////    printf("\n%s", cad2);
//    printf("\ncompararString devuelve: %d",compararString(cad1, cad2));
//    printf("\nstrcmp devuelve: %d",strcmp(cad1, cad2));
//    printf("\nLongitud: %d",longitudString(cad1));
//    i=strlen(cad1);
//    printf("\nStrlen: %d",i );
////    //printf("\nCaracter %c, toUpper: %c", carac, aMayuscula(carac));
////    printf("\nCaracter %c, toLower: %c", carac, aMinuscula(carac));
//    printf("\nPrimera aparicion de %c es %s",carac, primerAparicionEnString(cad1, carac));
//    printf("\nstrchr de %c es %s: ",carac, strchr(cad1, carac));
//    return 0;
//}


