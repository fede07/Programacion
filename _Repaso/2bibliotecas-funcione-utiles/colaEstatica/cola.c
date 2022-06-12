#include <string.h>
#include "cola.h"

void crearCola (t_cola *c)
{
    c->pri = 0;
    c->ult = 0;
    c->tamDisponible = TAM_COLA;
}

int colaVacia(const t_cola *c)
{
    return c->tamDisponible == TAM_COLA;
}

int colaLlena(const t_cola *c, unsigned tamBy)
{
    ///Si no tengo espacio para poner mi dato (tamBy) y el tamaño decimos que la cola esta llena
    return c->tamDisponible < (tamBy+sizeof(unsigned));
}

void vaciarCola(t_cola *c)
{
    c->pri = 0;
    c->ult = 0;
    c->tamDisponible = TAM_COLA;
}

int ponerEnCola(t_cola *c, void *info, unsigned cantBy)
{
    unsigned iniInfo, finInfo;
    if( c->tamDisponible < (cantBy+sizeof(unsigned)) )
        return 0;

    ///4BYTES DEL DATO
    c->tamDisponible -= sizeof(unsigned) + cantBy;
    ///veo si el tamaño del dato entra completo o no
    iniInfo = MIN(sizeof(unsigned),TAM_COLA - c->ult);///4bytes - tam disponible

    ///si vale 0 quiere decir que el dato se tiene que escribir en c->vec (al inicio)
    if(iniInfo !=0)///el dato podria estar partido
    {       ///posiciono en el vector,
        memcpy(c->vec + c->ult,&cantBy,iniInfo);///copio los primeros bytes del dato
    }

    finInfo = sizeof(unsigned) - iniInfo;

    ///solo va a entrar si iniInfo no vale 4, osea que el dato estaba partido y hay que terminarlo
    if(finInfo != 0)///si quedaron datos del tamaño por escribir
    {                   ///acomodo en los bytes que faltan escribir
        memcpy(c->vec,((char*)&cantBy)+iniInfo, finInfo);
    }

    c->ult = finInfo? finInfo:(c->ult + iniInfo);///si es distinto de 0

    ///INFO
    iniInfo = MIN(TAM_COLA - c->ult, cantBy);
    if (iniInfo !=0)
    {
        memcpy(c->vec + c->ult, info, iniInfo);
    }
    finInfo = cantBy - iniInfo;
    if(finInfo!=0)
    {
        memcpy(c->vec, ((char*)info)+iniInfo, finInfo);
    }

    c->ult = finInfo? finInfo:(c->ult + iniInfo);

    return 1;
}

int sacarDeCola(t_cola *cola, void *info, unsigned tamBy)
{
    unsigned iniInfo, finInfo, tamRecu, tamCola;
    if( cola->tamDisponible == TAM_COLA )
        return 0;

    ///recupero el tamaño del dato
    iniInfo = MIN(TAM_COLA - cola->pri,sizeof(unsigned));
    if(iniInfo)
        memcpy(&tamCola,cola->vec + cola->pri, iniInfo);
    finInfo = sizeof(unsigned) - iniInfo;
    if(finInfo)
        memcpy(((char*)&tamCola)+iniInfo,cola->vec,finInfo);
    cola->pri = finInfo?finInfo:cola->pri+iniInfo;

    cola->tamDisponible += sizeof(unsigned) + tamCola;


    ///recupero el la informacion
    tamRecu = MIN(tamCola,cola->tamBy);
    iniInfo = MIN(TAM_COLA - cola->pri, tamRecu);

    if(iniInfo)
        memcpy(info,cola->vec + cola->pri,iniInfo);
    finInfo = tamRecu - iniInfo;
    if(finInfo)
        memcpy((char*)info+iniInfo,cola->vec,finInfo);

    cola->pri = (cola->pri + tamCola)%TAM_COLA;

    return 1;
}

int verPriCola(const t_cola *cola, void *info, unsigned tamBy)
{
    unsigned iniInfo, finInfo, tamRecu;
    if(cola->tamDisponible == TAM_COLA)
        return 0;

    ///tamaño del dato a recuperar
    iniInfo = MIN(TAM_COLA - cola->pri, sizeof(unsigned));
    if(iniInfo)
        memcpy(&tamRecu,cola->vec + cola->pri,iniInfo);
    finInfo = sizeof(unsigned) - iniInfo;
    if(finInfo)///aca estaria al inicio del vec
        memcpy(((char*)&tamRecu)+iniInfo,cola->vec,finInfo);

    tamRecu = MIN(tamBy,tamRecu);
    iniInfo = MIN(TAM_COLA - cola->pri + sizeof(unsigned),tamRecu);
    if(iniInfo)
        memcpy(info,cola->vec + cola->pri + sizeof(unsigned),iniInfo);
    finInfo = tamRecu - iniInfo;
    if(finInfo)
        memcpy(((char *)info)+ iniInfo,cola->vec,finInfo);

    return 1;
}
