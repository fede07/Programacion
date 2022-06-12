#include "memDinamica.h"
#include <stdlib.h>
#include <string.h>

char* mconcat(char* cad1, const char* cad2)
{
    char* tmp = realloc(cad1, strlen(cad1)+strlen(cad2)+1);

    if(tmp==NULL)
    {
        return NULL;
    }

    cad1=tmp;

    tmp+=(strlen(tmp));

    memcpy(tmp, cad2, strlen(cad2)+1);

    return cad1;
}
