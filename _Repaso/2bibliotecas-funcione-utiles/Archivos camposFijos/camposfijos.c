#include <stdio.h>
#include <string.h>
#include "camposfijos.h"


int crearLote ()
{
    int i;
    t_alumno alumno [] = {{12345678,"Pepito Feliz","Cisneros",12345},
                         {41111111,"Marito Gomez","Don Bosco",7890},
                         {99444444,"Juancito Perez","Libertador",855}
                         };

    FILE * pf = fopen("alumnos.txt","wt");

    if(!pf)
        return 0;


    ///esta parte respeta el limite de caracteres de las cadenas declaradas en el struct (33)
    for(i=0; i<3; i++)
    { ///ver por que se rompe con otros numeros
        fprintf(pf,"%8d%33s%33s%5d\n",alumno[i].dni,alumno[i].nyap,alumno[i].direccion,alumno[i].altura);
    }


    ///con esto es que pudimos "solucionar" el error bajando de 33 a 30
    ///parece que el error es que despues de la direccion hay \0 y por eso toma la altura como una cadena separada
//    for(i=0;i<3;i++)
//    {///por que tengo que poner 3 elementos menos en el %ns (cuando pongo debugger marca como fin de cadena
//    ///\000)
//        fprintf(pf,"%8d%-30s%-30s%5d\n",alumno[i].dni,alumno[i].nyap,alumno[i].direccion,alumno[i].altura);
//    }

    fclose(pf);

    return 1;
}

char * borrarBlancosExtras (char* cadena)
{
    char * inicioCadena = cadena,
           * lector = cadena;

    while (*lector)///si la cadena no llego al \0 entra
    {
        while(ESBLANCO(*lector))///si esta en un espacio va al siguiente lugar
            lector++;

        while (/* *lector!=' ' && */*lector && !ESBLANCO(*lector))///mientras no haya un espacio, y el lector no llegue a \0 guarda los caracteres en cadena
        {
            *cadena = *lector;
            lector++;
            cadena++;
        }

        if(!ESBLANCO(*(cadena-1)))///si el lector no llego al fin de la cadena quiere decir que hay un espacio, entonces pongo solo uno en el caso de que no lo haya puesto antes
        {
            *cadena = ' ';
            cadena++;
        }

    }
    *(cadena-1) = '\0';
    return inicioCadena;
}

int abrirArh(FILE ** pf, char nombre[], char modo[])
{
    *pf = fopen(nombre,modo);
    return (*pf)?1:0;
}

///esta funcion recibe la cadena, la desgloza y la muestra
int dezglozamiento (char * cadena, t_alumno * alumno)
{
    ///cadena+=sizeof(t_alumno);///pongo la cadena en el \0

    cadena+=(strlen(cadena)-1);
    *cadena='\0';

    cadena-=5;///vuelvo la cantidad de elementos que tiene ese campo?
                ///tiene que ser 8 porque el int ocupa 8 bytes, son los 5 que tiene que leer + 3 de relleno
    sscanf(cadena,"%5d",&(alumno->altura));
    *cadena='\0';///pongo al inicio de ese campo un \0 para marcar el nuevo final de la cadena

    ///sin blancos extras
    cadena-=33;
    strcpy(alumno->direccion,borrarBlancosExtras(cadena));
    *cadena='\0';
    cadena-=33;
    strcpy(alumno->nyap,borrarBlancosExtras(cadena));
    *cadena='\0';

    ///como viene del archivo
//    cadena-=30;
//    strcpy(alumno->direccion,cadena);
//    *cadena='\0';
//    cadena-=30;
//    strcpy(alumno->nyap,cadena);
//    *cadena='\0';

    cadena-=8;
    sscanf(cadena,"%8d",&(alumno->dni));

    return 1;
}







