#ifndef MATRICES2_H_INCLUDED
#define MATRICES2_H_INCLUDED

#define FILA 13
#define COLM 15

///formato
void ponerEspacios(int);

///categoria pendiente
void llenarMatrizConsecutiva(int [][COLM],int , int);
void mostrarMatriz(int matriz[][COLM], int fila, int colum);
int esMatrizIdentidad(int m[][COLM],int filas);

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

int rotarMatriz(int matriz[][COLM], int fila, int colum);

int esSimetrica(int matriz[][COLM], int fila, int colum);

int mostrarTriangInfConDSec_2(int matriz[][COLM], int fila, int columna);

#endif // MATRICES2_H_INCLUDED
