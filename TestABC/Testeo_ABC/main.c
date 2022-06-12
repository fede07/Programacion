#include <stdio.h>
#include <stdlib.h>

//int main()
//{
////    char carac = 'A';
////    printf("\n");
////    while (carac <='Z')
////    {
////        printf("%c \n", carac++);
////    }
////    char carac;
////    for(carac= 'A'; carac <='Z'; carac++)
////    {
////        printf("%c \n",carac);
////    }
////    return 0;
////}

int main ()
{
    char n1,n2;
    int suma;
    do
    {
        puts("Ingrese un digito:");
        fflush(stdin);
        scanf("%c", &n1);
    }
    while(n2 < '0' || n2>'9');

    do
    {
        puts("Ingrese un digito:");
        fflush(stdin);
        scanf("%c", &n2);
    }
    while(n2<'0' || n2>'9');
    suma = (int)n1 - '0' + (int)n2 - '0';
    printf("la suma de los numeros es: %i",suma);
    return 0;
}

//int main(){
//char n1,n2;
//int suma;
//do{
//puts("ingrese un digito:");
//fflush(stdin);
//scanf("%c",&n1);
//}while(n1<'0' || n1>'9');
//
//
//
//do{
//puts("ingrese un digito:");
//fflush(stdin);
//scanf("%c",&n2);
//}while(n2<'0' || n2>'9');
//
//
//
//suma = (int)n1 - '0' + (int)n2 - '0';
//
//
//
//printf("la suma de los numeros es: %i",suma);
//
//
//
//return 0;
//
//
//
//}
