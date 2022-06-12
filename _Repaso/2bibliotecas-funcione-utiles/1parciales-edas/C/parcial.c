#include "parcial.h"
#include <stdlib.h>
#include <string.h>

//void * memmove2 (void *s1, const void *s2, size_t n)
//{
//    int i;
//    for(i=0;i<5;i++)
//        printf("el buen pepito %c\n",1);
//
//
//}

int fusionArchivos ()
{

    FILE * bin;
    FILE * txt;
    FILE * fusion;

    tProducto prodTxt;
    tProducto prodBin;
    int chequeoTxt;
    int chequeoBin;

    ///ABRIENDO LOS TRES ARCHIVOS
    bin = fopen("maestro1.dat","rb");
    if(!bin)
    {
        printf("Error al abrir maestro1.dat");
        return 1;
    }

    txt = fopen("maestro2.txt","rt");
    if(!txt)
    {
        printf("Error al abrir maestro1.txt");
        fclose(bin);
        return 2;
    }

    fusion = fopen("p2MergeMaestro.dat","wb");
    if(!fusion)
    {
        printf("Error al abrir p2MergeMaestro.dat");
        fclose(bin);
        fclose(txt);
        return 3;
    }

    chequeoTxt = fscanf(txt,"%ld;%[^;];%d/%d/%d;%d;%f",&prodTxt.idProducto,prodTxt.descripcion,
                                                &(prodTxt.fecUltAct.dia),&(prodTxt.fecUltAct.mes),
                                                &(prodTxt.fecUltAct.anio),&prodTxt.cantidad,
                                                &prodTxt.precioUnitario);
    chequeoBin = fread(&prodBin,sizeof(tProducto),1,bin);
    while(chequeoBin!=0 && chequeoTxt != EOF )
    {
        ///se puede optimizar haciendo que si son iguales escriba ambos registros, y vuelva
        ///a leer de ambos
        if(prodBin.idProducto>=prodTxt.idProducto)
        {
            normalizar(prodTxt.descripcion);
            fwrite(&prodTxt,sizeof(tProducto),1,fusion);
            chequeoTxt = fscanf(txt,"%ld;%[^;];%d/%d/%d;%d;%f",&prodTxt.idProducto,prodTxt.descripcion,
                                                &(prodTxt.fecUltAct.dia),&(prodTxt.fecUltAct.mes),
                                                &(prodTxt.fecUltAct.anio),&prodTxt.cantidad,
                                                &prodTxt.precioUnitario);
        }
        else
        {
            normalizar(prodBin.descripcion);
            fwrite(&prodBin,sizeof(tProducto),1,fusion);
            chequeoBin = fread(&prodBin,sizeof(tProducto),1,bin);
        }
    }

    while(!feof(bin))
    {
        normalizar(prodTxt.descripcion);
        fwrite(&prodBin,sizeof(tProducto),1,fusion);
        fread(&prodBin,sizeof(tProducto),1,bin);
    }

    while( chequeoTxt != EOF )
    {
    normalizar(prodTxt.descripcion);
    fwrite(&prodTxt,sizeof(tProducto),1,fusion);
    chequeoTxt = fscanf(txt,"%ld;%[^;];%d/%d/%d;%d;%f",&prodTxt.idProducto,prodTxt.descripcion,
                                                &(prodTxt.fecUltAct.dia),&(prodTxt.fecUltAct.mes),
                                                &(prodTxt.fecUltAct.anio),&prodTxt.cantidad,
                                                &prodTxt.precioUnitario);
    }

    fclose(bin);
    fclose(txt);
    fclose(fusion);

    return 0;
}

char * normalizar (char * cadena)
{
    char * iniCad = cadena;
    char * escritura = cadena;
    int primera = 0;
    while(*cadena)///mientras no llegue a \0
    {
        while(ESLETRA(*cadena))///mientras sea letra
        {
            if(primera == 0)///solo pasa a mayuscula la primer letra de cada palabra
            {
                *escritura = AMAYUS(*cadena);
                primera = 1;
            }
            else
            {
                *escritura = AMINUS(*cadena);
            }
            cadena++;
            escritura++;
        }
        if((!ESLETRA(*cadena)) && (ESLETRA(*(cadena-1))) )
            {
                *escritura = ' ';
                escritura++;
            }
        if(*cadena)
            cadena++;
        primera = 0;
    }
    *(escritura-1) = '\0';
    return iniCad;
}

void crearCola(t_cola *cola)
{
    cola->pri=NULL;
    cola->ult=NULL;
}

int colaVacia(const t_cola *cola)
{
    return cola->pri == NULL;
}

int colaLlena(const t_cola *cola, unsigned tamBy)
{
    t_nodo * temp = malloc (sizeof(t_nodo));
    if(!temp)
        return 1;

    temp->dato = malloc(tamBy);
    if(!temp->dato)
    {
        free(temp);
        return 1;
    }

    free(temp->dato);
    free(temp);

    return 0;
}

int agregarEnCola(t_cola *cola, void *info, unsigned tamBy)
{
    t_nodo * nuevo = malloc(sizeof(t_nodo));
    if(!nuevo)
        return 0;

    nuevo->dato = malloc (tamBy);
    if(!nuevo->dato)
    {
        free(nuevo);
        return 0;
    }
    if(cola->pri == NULL)
        cola->pri = nuevo;
    else
        cola->ult->sig = nuevo;

    memcpy(&nuevo->tam,&tamBy,sizeof(unsigned));
    memcpy(nuevo->dato,info,tamBy);

    cola->ult = nuevo;
    nuevo->sig = NULL;

    return 1;
}

int sacarDeCola(t_cola *cola, void *info, unsigned tamBy)
{
    t_nodo * elim;
    if(cola->pri == NULL)
        return 0;

    elim = cola->pri;
    memcpy(info,elim->dato,MIN(tamBy,elim->tam));

    cola->pri = elim->sig;
    if(cola->pri == NULL)
        cola->ult = NULL;


    free(elim->dato);
    free(elim);

    return 1;
}

int verPriCola(const t_cola *cola, void *info, unsigned tamBy)
{
    if(cola->pri == NULL)
        return 0;

    memcpy(info,cola->pri->dato,MIN(tamBy,cola->pri->tam));

    return 1;
}

void vaciarCola(t_cola *cola)
{
    t_nodo * elim;

    while(cola->pri)
    {
        elim = cola->pri;
        cola->pri = elim->sig;
        free(elim->dato);
        free(elim);
    }
    cola->ult=NULL;
}

int elimDupl ()
{
    FILE * arch;
    FILE * sinDupl;
    t_cola cola;
    tProducto prodTemporal;
    tProducto prod;

    arch = fopen("p2MergeMaestro.dat","rb");
    if(!arch)
    {
        printf("Error al abrir p2MergeMaestro.dat");
        return 1;
    }

    sinDupl = fopen("p3MergeSinDuplicados.dat","wb");
    if(!sinDupl)
    {
        fclose(arch);
        return 1;
    }

    crearCola(&cola);

    fread(&prod,sizeof(tProducto),1,arch);
    fread(&prodTemporal,sizeof(tProducto),1,arch);
    while(!feof(arch))
    {
        if(prod.idProducto == prodTemporal.idProducto)
        {
            prod.cantidad += prodTemporal.cantidad;
        }
        else
        {
            agregarEnCola(&cola,&prod,sizeof(tProducto));
            prod = prodTemporal;
        }
        fread(&prodTemporal,sizeof(tProducto),1,arch);
    }
    agregarEnCola(&cola,&prod,sizeof(tProducto));

    while(!colaVacia(&cola))
    {
        sacarDeCola(&cola,&prod,sizeof(tProducto));
        fwrite(&prod,sizeof(tProducto),1,sinDupl);
    }

    fclose(arch);
    fclose(sinDupl);
    return 0;
}


///levantar registros en una cola de n espacios e ir pasando los datos al archivo hasta que
///el archivo este vacio
int eliminarNult(unsigned cantidad)
{
    FILE * arch;
    FILE * fin;

    t_cola cola;
    t_cola colaTemp;

    int i, regArch = 0, cantFinal;

    tProducto producto;

    arch = fopen("p3MergeSinDuplicados.dat","rb");
    if(!arch)
    {
        return 0;
    }
    fin = fopen("nEliminados.txt","wt");
    if(!fin)
    {
        fclose(arch);
        return 0;
    }

    crearCola(&cola);
    crearCola(&colaTemp);

    fread(&producto,sizeof(tProducto),1,arch);

    while(!feof(arch))
    {
        regArch++;
        ///pongo TODO el archivo en la cola
        agregarEnCola(&cola,&producto,sizeof(tProducto));
        fread(&producto,sizeof(tProducto),1,arch);
    }

    fclose(arch);

    ///for(i=0;i<regArch-cantidad;i++) no sirve porque capaz se piden borrar mas
    i=0;
    cantFinal = ABS(regArch-cantidad);
    while(i<cantFinal && !colaVacia(&cola) /*colaLlena(&colaTemp)?*/)
    {
        sacarDeCola(&cola,&producto,sizeof(tProducto));
        agregarEnCola(&colaTemp,&producto,sizeof(tProducto));
        fprintf(fin,"%ld %s %d/%d/%d %d %f\n",producto.idProducto,producto.descripcion,
                                                (producto.fecUltAct.dia),(producto.fecUltAct.mes),
                                                (producto.fecUltAct.anio),producto.cantidad,
                                                producto.precioUnitario);
        i++;
    }

    vaciarCola(&cola);
    vaciarCola(&colaTemp);

    fclose(arch);
    fclose(fin);

    return 1;
}
int actualizar()
{
    FILE * prod;
    FILE * nov;

    int chequeoNov;

    tNovedad novedad;
    tProducto producto;

    prod = fopen("p3MergeSinDuplicados.dat","r+b");
    if(!prod)
    {
        return 0;
    }
    nov = fopen("novedades.txt","rt");
    if(!nov)
    {
        fclose(prod);
        return 0;
    }

    chequeoNov = fscanf(nov,"%ld %c %d",&novedad.idProducto,&novedad.tipoMovimiento,&novedad.cantidad);

    fread(&producto,sizeof(tProducto),1,prod);

    while(chequeoNov!=EOF && !feof(prod))
    {
        if(novedad.idProducto==producto.idProducto)///si son iguales actualizo
        {
            if(novedad.tipoMovimiento=='I')
                producto.cantidad+=novedad.cantidad;
            else
                producto.cantidad-=novedad.cantidad;

            chequeoNov = fscanf(nov,"%ld %c %d",&novedad.idProducto,&novedad.tipoMovimiento,&novedad.cantidad);
        }
        else if(novedad.idProducto>producto.idProducto)
        {
            fseek(prod,(long int)-sizeof(tProducto),SEEK_CUR);
            fwrite(&producto,sizeof(tProducto),1,prod);
            fseek(prod,0,SEEK_CUR);
            fread(&producto,sizeof(tProducto),1,prod);///leo siguiente producto
        }
        else
        {
            chequeoNov = fscanf(nov,"%ld %c %d",&novedad.idProducto,&novedad.tipoMovimiento,&novedad.cantidad);
        }
    }

    while(!feof(prod))
    {
        fseek(prod,(long int)-sizeof(tProducto),SEEK_CUR);
        fwrite(&producto,sizeof(tProducto),1,prod);
        fseek(prod,0,SEEK_CUR);
        fread(&producto,sizeof(tProducto),1,prod);
    }

    fclose(prod);
    fclose(nov);
    return 1;
}
















