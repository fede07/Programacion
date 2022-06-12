#include <iostream>
#include "fecha.h"
#include "fechaexception.h"

#define ERR_INGR_FECHA 1

using namespace std;

int main()
{
    Fecha hoy;

    try {
        hoy = Fecha(42, 4, 2021);
    }
    catch(FechaException& fechaException) {
        cout << "Hubo un error en el ingreso de la fecha: " << fechaException.getMensaje() << endl;
        return ERR_INGR_FECHA;///y termina el programa por ese error
    }


    return 0;
}
