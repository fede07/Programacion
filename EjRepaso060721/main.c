///Se dispone de una archivo de stock y otro de movimientos, el de stock esta formado
///por codigo de producto y cantidad en stock, el de movimientos por codigo de
///producto y cantidad del movimiento.
///Ninguno de ambos archivos esta ordenado. Utilizando un solo TDA
///recorriendo ambos archivos una unica vez, genere un archivo "stock_ordenado.dat"
///donde figure el stock disponible despues de procesar los movimientos.
///No utilize bucles en las primitivas de su TDA y procure que sean genericas.
///Informe en un archivo de texto los movimientos sobre productos
///inexistentes en stock.
///
///
///Recomendacion: TDA lista simplemente enlazada

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int cod;
    int cant;
} tstock;

typedef struct
{
    int cod;
    int cant;
} tmovimiento;

int main()
{
    return 0;
}

int crearStockYMovimientos()
{
    tstock stock[] =
    {
        {1, 100},{2,500},{10,100},{3,1000}
    };

    tmovimiento movs[] =
    {
        {10,-50},
        {2,-50},
        {1,10},
        {3,-100},
        {9,11}
    };

    FILE* fstock = fopen("stock.dat", "wb");
    FILE* fmov = fopen("movimientos.dat", "wb");

    if(!fstock)
    {
        return 0;
    }
    if(!fmov)
    {
        return 0;
    }

    fwrite(stock, sizeof(stock),1, fstock);
    fwrite(movs, sizeof(movs),1, fmov);

    fclose(fstock);
    fclose(fmov);
    return 1;
}
