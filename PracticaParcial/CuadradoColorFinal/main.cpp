#include <iostream>
#include "cuadradoColor.h"

using namespace std;

int main()
{
    float lado;
    Cuadrado cuad1;
    cout << "Ingrese un lado del cuadrado:" << endl;
    cin >> lado;

    Cuadrado cuad3;
    Cuadrado cuad2(cuad1);
    cuad1 = lado;
    cuad2 = cuad1++;

    cout << "El perimetro del cuadrado es: " << cuad1.perimetro() << endl;

    cout << cuad1 << endl;
    cuad2.mostrar();
    cin >> cuad3;
    cout << cuad3;

    return 0;
}
