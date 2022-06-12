#include <iostream>
#include "Fecha.h"
#include "FechaException.h"

#define ERR_INGR_FECHA 1

using namespace std;

int main()
{
    Fecha hoy;

//     try {
//        hoy = Fecha(21702021);
//    }
//    catch(FechaException& fechaException) {
//        cout << "Hubo un error en el ingreso de la fecha: " << fechaException.getMensaje() << endl;
//		///return ERR_INGR_FECHA;
//    }
//    cout << "valida" << endl;

    hoy.setfecha(10,10,2021);
    cout << hoy << endl;
    hoy+=1;
    cout << hoy << endl;
    cout << hoy++ << endl;
    cout << hoy << endl;
    cout << ++hoy << endl;
    cin >> hoy;
    cout << hoy << endl;


    cout << "hola" << endl;


    return 0;
}
