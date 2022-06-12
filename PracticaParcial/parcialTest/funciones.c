#include "funciones.h"
#include <string.h>

void crearCola(t_cola* cola)
{
    cola->pri = NULL;
    cola->ult = NULL;
}

int colaVacia(t_cola* cola)
{
    return cola->pri == NULL;
}
int colaLlena(t_cola* cola, unsigned cantBytes)
{
    t_nodo* temp = malloc(sizeof(t_nodo));
    if(temp == NULL)
    {
        return 1;
    }
    temp->info  = malloc(cantBytes);
    if(temp->info == NULL)
    {
        free(temp);
        return 1;
    }

    free(temp->info);
    free(temp);
    return 0;
}
int ponerEnCola(t_cola* cola, void* info, unsigned cantBytes)
{
    t_nodo* nuevoNodo = malloc(sizeof(t_nodo));

    if(nuevoNodo == NULL)
    {
        return 0;
    }

    nuevoNodo->info = malloc(cantBytes);

    if(nuevoNodo->info == NULL)
    {
        free(nuevoNodo);
        return 0;
    }
    memcpy(nuevoNodo->info, info, cantBytes);

    nuevoNodo->cantBytes = cantBytes;

    nuevoNodo->sig = NULL;

    if(cola->pri == NULL)
    {
        cola->pri = nuevoNodo;
    }
    else
    {
        cola->ult->sig = nuevoNodo;
    }

    cola->ult = nuevoNodo;

    return 1;

}
int sacarDeCola(t_cola* cola, void* info, unsigned cantBytes)
{
    t_nodo *elim;

    if(cola->pri == NULL)
    {
        return 0;
    }

    elim = cola->pri;

    memcpy(info, elim->info, MINIMO(elim->cantBytes,cantBytes));

    cola->pri = elim->sig;

    if(cola->pri == NULL)
    {
        cola->ult = NULL;
    }

    free(elim->info);

    free(elim);

    return 1;

}
int verPrim(t_cola* cola, void* info, unsigned cantBytes)
{
    t_nodo *temp = cola->pri;

    if(temp == NULL)
    {
        return 0;
    }

    memcpy(info, temp->info, MINIMO(temp->cantBytes,cantBytes));

    return 1;

}

void *memmove_MIO(void *destino, const void *origen, size_t cant)
{
    void* iniDest = destino;
    void* temporal;
    void* iniTemp;
    int i;

    temporal = malloc(cant);
    iniTemp = temporal;

    for(i=0; i<cant; i++)
    {
        *(char*)temporal = *(char*)origen;
        temporal++;
        origen++;
    }

    for(i=0; i<cant; i++)
    {
        *(char*)destino = *(char*)iniTemp;
        destino++;
        iniTemp++;
    }

    return iniDest;
}

char* normalizar(char* cadena)
{
    char* iniCad = cadena;
    char* escribirCad = cadena;
    while(ESBLANCO(*cadena))
    {
        cadena++;
    }
    while(*cadena)
    {
        *escribirCad = AMAYUS(*cadena);
        cadena++;
        escribirCad++;
        while(ESLETRA(*cadena))
        {
            *escribirCad = AMINUS(*cadena);
            cadena++;
            escribirCad++;
        }
        *escribirCad = *cadena;
        cadena++;
        escribirCad++;
        while(ESBLANCO(*cadena))
        {
            cadena++;
        }
    }
    *escribirCad = '\0';
    if(ESBLANCO(*(escribirCad-1)))
    {
        *(escribirCad-1)='\0';
    }
    else
    {
        *escribirCad = '\0';
    }
    return iniCad;
}


int mergeArchs()
{
    FILE *archBin, *archTxt, *archMaster;
    tProducto producto1, producto2;
    char texto;
    int bin;

    archBin = fopen("maestro1.dat", "rb");
    if(!archBin)
    {
        printf("NO SE PUEDE ABRIR MAESTRO1.DAT");
        return 1;
    }

    archTxt = fopen("maestro2.txt", "rt");
    if(!archTxt)
    {
        printf("NO SE PUEDE ABRIR MAESTRO2.DAT");
        fclose(archBin);
        return 2;
    }

    archMaster= fopen("MaestroFinal.dat", "wb");
    if(!archMaster)
    {
        printf("NO SE PUEDE ABRIR MAESTRO FINAL");
        fclose(archBin);
        fclose(archTxt);
        return 3;
    }


    texto= fscanf(archTxt, "%ld;%[^;];%d/%d/%d;%d;%f",  &producto1.idProducto, producto1.descripcion,
                  &producto1.fecUltAct.dia, &producto1.fecUltAct.mes,
                  &producto1.fecUltAct.anio, &producto1.cantidad,
                  &producto1.precioUnitario);
    bin = fread(&producto2, sizeof(tProducto), 1, archBin);
    while(texto!=EOF || bin)
    {
        if(producto1.idProducto<=producto2.idProducto)
        {
            while(producto1.idProducto<producto2.idProducto && texto!=EOF)
            {
                normalizar(producto1.descripcion);
                MOSTRAR_PROD(producto1);
                fwrite(&producto1, sizeof(tProducto), 1, archMaster);
                texto= fscanf(archTxt, "%ld;%[^;];%d/%d/%d;%d;%f",  &producto1.idProducto, producto1.descripcion,
                              &producto1.fecUltAct.dia, &producto1.fecUltAct.mes,
                              &producto1.fecUltAct.anio, &producto1.cantidad,
                              &producto1.precioUnitario);
            }
            normalizar(producto2.descripcion);
            MOSTRAR_PROD(producto2);
            fwrite(&producto2, sizeof(tProducto), 1, archMaster);
            bin = fread(&producto2, sizeof(tProducto), 1, archBin);

        }
        else
        {
            while(producto1.idProducto>producto2.idProducto && bin)
            {
                normalizar(producto2.descripcion);
                MOSTRAR_PROD(producto2);
                fwrite(&producto2, sizeof(tProducto), 1, archMaster);
                bin = fread(&producto2, sizeof(tProducto), 1, archBin);
            }
            normalizar(producto1.descripcion);
            MOSTRAR_PROD(producto1);
            fwrite(&producto1, sizeof(tProducto), 1, archMaster);

            texto = fscanf(archTxt, "%ld;%[^;];%d/%d/%d;%d;%f", &producto1.idProducto, producto1.descripcion,
                           &producto1.fecUltAct.dia, &producto1.fecUltAct.mes,
                           &producto1.fecUltAct.anio, &producto1.cantidad,
                           &producto1.precioUnitario);
        }
    }

    fclose(archBin);
    fclose(archTxt);
    fclose(archMaster);

    return 1;
}

int eliminarDupes()
{
    FILE* archBin, *archTemp;
    t_cola cola;
    tProducto producto, productoSig;

    crearCola(&cola);

    archBin = fopen("MaestroFinal.dat", "rb");
    if(!archBin)
    {
        return 0;
    }

    archTemp = fopen("MaestroTemp.dat", "wb");
    if(!archTemp)
    {
        fclose(archBin);
        return 0;
    }

    fread(&producto, sizeof(tProducto),1,archBin);
    fread(&productoSig, sizeof(tProducto), 1, archBin);

    MOSTRAR_PROD(producto);
    MOSTRAR_PROD(productoSig);

    while(!feof(archBin))
    {
        if(producto.idProducto == productoSig.idProducto)
        {
            while(producto.cantidad == productoSig.cantidad && !feof(archBin))
            {
                producto.cantidad += productoSig.cantidad;
                fread(&productoSig, sizeof(tProducto), 1, archBin);
            }
        }
        MOSTRAR_PROD(producto);
        fwrite(&producto, sizeof(tProducto), 1, archTemp);
        memcpy(&producto, &productoSig, sizeof(tProducto));
        fread(&productoSig, sizeof(tProducto),1,archBin);
    }

    fclose(archBin);
    fclose(archTemp);

    return 1;
}

int eliminarUlt(unsigned cantidad)
{
    FILE *arch;
    FILE *fin;

    t_cola cola;
    t_cola colaTemp;

    tProducto producto;

    arch = fopen("MergeSinDups.dat", "rb");
    fin = fopen("nEliminados.txt","wb");

    crearCola(&cola);
    crearCola(&colaTemp);

    fread(&producto, sizeof(tProducto),1,arch)
}


