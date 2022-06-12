#ifndef MATRICES_H_INCLUDED
#define MATRICES_H_INCLUDED
#define FIL 5
#define COL 5

void mostrarMatriz(int[][COL],int,int);
void mostrarDiagonal(int[][COL],int);
void mostrarTrianguloSupSinDiagPrin(int[][COL],int);
void mostrarMatrizTranspuesta(int[][COL],int);
void mostrarDiagonalSecundaria(int[][COL],int);
void mostrarTrianguloSupConDiagPrin(int[][COL],int);
void mostrarTrianguloInfSinDiagPrin(int[][COL],int);
void mostrarTrianguloInfConDiagPrin(int[][COL],int);
void mostrarTrianguloSupSinDiagSec(int[][COL],int);
void mostrarTrianguloSupConDiagSec(int[][COL],int);
void mostrarTrianguloInfSinDiagSec(int[][COL],int);
void mostrarTrianguloInfConDiagSec(int[][COL],int);
int buscarElemento (int*, int, int, int);

#endif // MATRICES_H_INCLUDED
