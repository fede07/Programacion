#include <stdio.h>
#include <stdlib.h>
#include "Carta.h"

using namespace std;

int main()
{
    Carta c1,c2("Lopez Luis","Jujuy",320),c3(c2), c4;
    c2 += 1.2;
    c4 = c1;
    cin >> c1;
    c3.actualizarPrecio(30);
    c2 = c2++;
/***esta linea de arriba parece que no funciona porque se pisa c2 con la informacion anterior al incremento
    FALTA DECLARAR C5
    cout << c2 << endl;
    c5 = c2++;
    cout << c2 << endl;
    cout << c5 << endl;
    **/
    ++c4;
    cout <<endl;
    cout << "CARTA 1"<< endl  << c1 <<endl <<"CARTA 2" << endl << c2 <<endl << "CARTA 3" << endl  << c3<<endl << "CARTA 4" << endl  << c4<<endl;
}
