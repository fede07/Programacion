#include <stdio.h>
#include <stdlib.h>
#include "vectores.h"

int mostrarVectInt(int[], int);

int main()
{
    int x=1, *px;
    int vec1[4];
    int vec2[4]= {1,2,3,4};
    int vec3[4]= {11,21};
    int vec4[4]= {12,32,42};
//    int vec5[4]= {13,23,43,54,63};
    int vec6[]= {14,24,34,44};
    int vec7[4]= {0};
    int vec10[4]= {'a'};

//    mostrarVectInt(vec1,4);
//    puts("\n");
//    mostrarVectInt(vec2,4);
//    puts("\n");

//
//    printf("Tamaño de un entero %d",(int)sizeof(int));
//    printf("\n%x, %p, %d, %d", vec1, vec1, vec1, sizeof(vec1));
//    printf("\n%x, %p, %d, %d", vec2, vec2, vec2, sizeof(vec2));
//    printf("\n%x, %p, %d, %d", vec3, vec3, vec3, sizeof(vec3));
//    printf("\n%x, %p, %d, %d", vec4, vec4, vec4, sizeof(vec4));
//    printf("\n%x, %p, %d, %d", vec5, vec5, vec5, sizeof(vec5));
//    printf("\n%x, %p, %d, %d", vec6, vec6, vec6, sizeof(vec6));
//    printf("\n%x, %p, %d, %d", vec7, vec7, vec7, sizeof(vec7));
//    printf("\n%x, %p, %d, %d", vec10, vec10, vec10, sizeof(vec10));
//    printf("\n%d", vec10[10]);
//    printf("\n%d", vec2[2]);
//    printf("\n%d", vec2[4]);
//    printf("\n%d", vec2[8]);
//    printf("\n%d", vec7[-1]);
//    printf("\n%d", vec10[-1]);
//    printf("\n");
//    vec2[3]=54;
//    mostrarVectInt(vec2, 4);
    printf("\n%p, %p")

}

int mostrarVectInt(int vect[], int cant)
{
    int i;
    for(i=0; i<cant; i++)
    {
        printf("\t%d",vect[i]);
    }
    return 1;
}
