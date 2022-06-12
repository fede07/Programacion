#ifndef MATRICES_H_INCLUDED
#define MATRICES_H_INCLUDED

#define FILA 5
#define COLM 5

///formato
void ponerEspacios(int);

///categoria pendiente
void llenarMatrizConsecutiva(int [][COLM],int , int);
void mostrarMatriz(int matriz[][COLM], int fila, int colum);
int esMatrizIdentidad(int m[][COLM],int filas);
int rotarMatriz180(int matriz[][COLM], int fila, int colum);
int esSimetrica (int mat[][COLM], int fil, int colum);
int productoMatricial(int mat1[][COLM],int mat2[][COLM], int filasM1, int filasM2);
void matrizTranpuesta (int mat[][COLM],int fila, int colum);
void matricesDadoIJ (int mat[][COLM],int f,int x, int y);
void mostrarSubMatriz (int matriz[][COLM], int fila, int colum, int x, int y);

///diagonales
int mostrarDiagPrincipal (int [][COLM],int, int);
int mostrarDiagSecundaria(int [][COLM],int, int);

///triangulos respecto diagonal primaria
int mostrarTriangInfSinDPri(int [][COLM], int, int);
int mostrarTriangInfConDPri(int [][COLM], int , int);

int mostrarTriangSupSinDPri(int [][COLM], int, int);
int mostrarTriangSupConDPri(int [][COLM], int, int);

///triangulos diagonal secunaria
int mostrarTiangSupSinDSec(int [][COLM], int, int);
int mostrarTiangSupConDSec(int [][COLM], int, int);

///calzones
int triagT1topSinDiagPri(int [][COLM], int, int);
int triagT1topConDiags(int [][COLM], int, int);

int triagT2rightSinDiags(int matriz[][COLM], int fila, int colum);
int triagT2rightConDiags(int matriz[][COLM], int fila, int colum);

int triagT3bottomSinDiags(int matriz[][COLM], int fila, int colum);
int triagT3bottomConDiags(int matriz[][COLM], int fila, int colum);

int triagT4leftSinDiags(int matriz[][COLM], int fila, int colum);
int triagT4leftConDiags(int matriz[][COLM], int fila, int colum);

#endif // MATRICES_H_INCLUDED
