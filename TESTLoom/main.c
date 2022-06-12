#include <stdio.h>

#define FIL_EST 3
#define COL_EST 2

#define FIL_COMP 2
#define COL_COMP 2

#define FIL_GASTO 6
#define COL_GASTO 2

void mostrarCantComponentes(const int *comps, const char *tipos, int filas, int columnas);
void calcularComp(int *matrizALlenar, const int *matrizComponentes, const int *matrizDatos, int filas, int columnas);
void mostrarTipo(const char *tipos, int pos);
int devolverCantEstanterias(const int *matrizDatos, int tipoDeCol, int colMia);
int devolverCantcomponentes(const int *matrizComponentes, int i, int j);
void mostrarComponentesTotales(const int *cantDeComp, int filas, int cols);


int main( void )
{

    const char tiposDeEstanterias[FIL_EST] = {'A', 'B', 'C'};
    const int matrizDatos[FIL_EST][COL_EST] = { {1000, 8000}, {8000, 6000}, {4000, 6000} };
    const int matrizComp[FIL_COMP][COL_COMP] = { {16, 6}, {12, 4} };
    int cantDeComp[FIL_GASTO][COL_GASTO] = {0};


    calcularComp(*cantDeComp, *matrizComp, *matrizDatos, FIL_EST, COL_EST);
    mostrarCantComponentes(*cantDeComp, tiposDeEstanterias, FIL_GASTO, COL_GASTO);
    mostrarComponentesTotales(*cantDeComp, FIL_GASTO, COL_GASTO);

    return 0;
}


void mostrarCantComponentes(const int *comps, const char *tipos, int fil, int cols)
{


    for(int i = 0 ; i < fil; i++)
    {
        mostrarTipo(tipos, i);
        printf(i % 2 == 0 ? "\tPara estanterias grandes: \n" :  "\tPara estanterias pequenias: \n");
        for(int j = 0 ; j < cols; j++){

            printf(!j ? "Tornillos : %d\t" : "Soportes : %d\n\n", *(comps + (i * cols)+ j));
        }
    }
}

void calcularComp(int *matrizALlenar, const int *matrizComponentes, const int *matrizDatos, int fil, int cols)
{
    int desplazarMatriz = 0;

    for(int i = 0 ; i < fil; i++)
    {
        for(int j = 0 ; j < cols; j++)
        {
            for(int k = 0 ; k < cols; k++)
            {
                *(matrizALlenar + desplazarMatriz) =  devolverCantEstanterias(matrizDatos,  i,  j) *
                  devolverCantcomponentes(matrizComponentes, j, k);

                desplazarMatriz++;
            }
        }
    }

}

int devolverCantcomponentes(const int *matrizComponentes, int fila, int col)
{

    return *(matrizComponentes + (fila * 2) + col);

}

int devolverCantEstanterias(const int *matrizDatos, int fila, int col)
{

    return *(matrizDatos + (fila * 2) + col);

}

void mostrarTipo(const char *tipos, int pos){

    int aDesplazar;
    if(pos <= 1)
        aDesplazar = 0;
    else if (pos > 1 && pos <= 3)
        aDesplazar = 1;
    else
        aDesplazar = 2;

    printf("Estanterias de tipo: %c\n", *(tipos + aDesplazar));
}

void mostrarComponentesTotales(const int *matrizCargada, int filas, int cols){


    int componentesDiarios[2] = {0};

    for(int i = 0 ; i < filas; i++){
        for(int j = 0 ; j < cols; j++){
            componentesDiarios[j] += *(matrizCargada + (i * cols) + j);
        }
    }
    printf("Total de Tornillos gastados: %d\tTotal de Soportes gastados: %d\n",
           *(componentesDiarios + 0), *(componentesDiarios + 1));

}
