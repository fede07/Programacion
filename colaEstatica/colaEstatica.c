#include "colaEstatica.h"
#include <string.h>

void crearCola (t_cola *cola)
{
    cola->pri = 0;
    cola->ult = 0;
    cola->tamDisp = TAM_COLA;
}

int colaVacia(const t_cola *cola)
{
    return cola->tamDisp == TAM_COLA;
}

int colaLlena(const t_cola *cola, unsigned cantBytes)
{
    return cola->tamDisp < (sizeof(unsigned) + cantBytes);
}

void vaciarCola(t_cola* cola)
{
    cola->pri = cola->ult;
    cola->tamDisp = TAM_COLA;
}

int ponerEnCola(t_cola* cola, void* dato, unsigned cantBytes)
{
    unsigned iniDato, finDato;
    if(cola->tamDisp < (sizeof(unsigned) + cantBytes))
    {
        return 0;
    }
    cola->tamDisp -= sizeof(unsigned) + cantBytes;
    /// TAMAÑO del dato

    iniDato = MIN((TAM_COLA - cola->ult),sizeof(unsigned));

    if(iniDato != 0)
    {
        memcpy((cola->iniCola + cola->ult), &cantBytes, iniDato);
    }

    finDato = sizeof(unsigned) - iniDato;

    if(finDato != 0)
    {
        memcpy(cola->iniCola, ((char*) &cantBytes)+iniDato, finDato);
    }

    cola->ult = (finDato)?finDato:cola->ult+iniDato;
    ///Trabajar con el dato

    iniDato = MIN(TAM_COLA - cola->ult, cantBytes);

    if(iniDato != 0)
    {
        memcpy(cola->iniCola + cola->ult, dato, iniDato);
    }
    finDato = cantBytes - iniDato;
    if(finDato != 0)
    {
        memcpy(cola->iniCola, ((char*)dato)+iniDato, finDato);
    }

    cola->ult = (finDato)?finDato:cola->ult+iniDato;

    return 1;
}

int sacarDeCola(t_cola* cola, void* dato, unsigned cantBytes)
{
    unsigned iniDato, finDato, tamRecu, tamCola;
    if(TAM_COLA == cola->tamDisp)
    {
        return 0;
    }
    iniDato = MIN (TAM_COLA - cola->pri, sizeof(unsigned));
    if(iniDato)
    {
        memcpy(&tamCola, cola->iniCola + cola->pri, iniDato);
    }
    finDato = sizeof(unsigned) - iniDato;
    if(finDato)
    {
        memcpy(((char*)&tamCola) + iniDato, cola->iniCola, finDato);
    }

    cola->pri = finDato?finDato:(cola->pri+iniDato);

    cola->tamDisp+= sizeof(unsigned)+tamCola;

    tamRecu = MIN(tamCola, cantBytes);
    iniDato = MIN(TAM_COLA - cola->pri, tamRecu);
    if(iniDato)
    {
        memcpy(dato, cola->iniCola + cola->pri, iniDato);
    }
    finDato = tamRecu - iniDato;
    if(finDato)
    {
         memcpy((char*)dato + iniDato, cola->iniCola, finDato);
    }
    cola->pri = (cola->pri + tamCola) % TAM_COLA;

    return 1;
}

int verPrim(const t_cola* cola, void* dato, unsigned cantBytes)
{
    unsigned tamRecu, iniDato, finDato;
    if(cola->tamDisp == TAM_COLA)
        return 0;

    iniDato = MIN(TAM_COLA - cola->pri, sizeof(unsigned));
    if(iniDato)
    {
        memcpy(&tamRecu, cola->iniCola+cola->pri, iniDato);
    }
    finDato = sizeof(unsigned)-iniDato;
    if(finDato)
    {
        memcpy(((char*)&tamRecu)+iniDato, cola->iniCola, finDato);
    }

    tamRecu = MIN(cantBytes, tamRecu);
    iniDato = MIN(TAM_COLA - cola->pri + sizeof(unsigned), tamRecu);
    if(iniDato)
    {
        memcpy(dato, cola->iniCola + cola->pri + sizeof(unsigned), iniDato);
    }
    finDato = tamRecu - iniDato;
    if(finDato)
    {
        memcpy(((char*)dato) + iniDato, cola->iniCola, finDato);
    }
    return 1;
}
