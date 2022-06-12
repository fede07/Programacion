#include <iostream>
#include <iomanip>
#include "fecha.h"
using namespace std;

int main()
{
    Fecha hoy(17,4,2021);//
    Fecha pepito;
    pepito=hoy.sumarDias(10);
    int dia,mes,anio;
    pepito.getDMA(&dia,&mes,&anio);
    cout<<"La fecha suma es: "<<setw(2)<<dia<<fixed<<'/'<<setw(2)<<mes<<fixed<<'/'<<setw(2)<<anio<<fixed<<endl;

    return 0;
}
