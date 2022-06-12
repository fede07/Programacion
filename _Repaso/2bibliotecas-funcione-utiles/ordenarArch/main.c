#include <stdio.h>
#include <stdlib.h>
#include "ordenarArch.h"

int main()
{
    FILE * bin;
    t_struct a[TAM]={{2,"abc",2.2},
                   {6,"def",6.6},
                   {31,"ghi",31.31},
                   {8,"jkl",8.8},
                   {1,"mno",1.1},
                   {99,"PEPITO",99.99},
                   {97,"PEPITA",99.99},
                   {-5,"PEPITO RICA",99.99},
                   {1,"MARITO",99.99},
                   {7,"ILLIDIAN",99.99},
                   };
    bin = fopen("binario.dat","wb");
    fwrite(&a,sizeof(a),1,bin);

    fclose(bin);


    ordenar ();
    return 0;
}
