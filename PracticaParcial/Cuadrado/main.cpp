#include <iostream>

#include "cuadrado.h"

using namespace std;

int main()
{
    double lado;
    Cuadrado cuad1;
    cout << "Ingrese el lado del cuadrado: ";
    cin >> lado;

    Cuadrado cuad3;
    Cuadrado cuad2(cuad1);
    cuad1 = lado;
    cuad2 = cuad1++;

    cout << "El perimetro del cuadrado es: " << cuad1.perimetro() << endl;
    cout << "El area del cuadrado es: " << cuad1.area() << endl;

    cout << cuad1 << endl;
    cuad2.mostrar();

    cout << "Ingrese un cuadrado: " << endl;
    cin >> cuad3;
    cout << cuad3;

    return 0;
}
