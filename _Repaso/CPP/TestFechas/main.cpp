#include <iostream>
#include <fstream>
#include <iomanip>

#include "Fecha.h"
#include "FechaException.h"

#define ERR_INGR_FECHA 1
#define ARG_TXT_SAL 1
#define ARG_TXT_ENT 2

using namespace std;


int main(int argc, char* argv[])
{
	filebuf fbSal;
    fbSal.open(argv[ARG_TXT_SAL], ios::out);
    ostream salida(&fbSal);

    filebuf fbEnt;
    fbEnt.open(argv[ARG_TXT_ENT], ios::in);
    istream entrada(&fbEnt);


    Fecha hoy;

    try {
        hoy = Fecha(24, 4, 2021);
        ///al entrar al try llama al constructor (fecha.cpp linea 18)
    }
    catch(FechaException& fechaException) {
        ///como salio por el throw el catch agarra ese problema
        //cout << "Hubo un error en el ingreso de la fecha: " << fechaException.getMensaje() << endl;
        salida << "Hubo un error en el ingreso de la fecha: " << fechaException.getMensaje() << endl;
        ///salida es un puntero a archivo, escribe el mensaje ahi

		return ERR_INGR_FECHA;///y termina el programa por ese error
    }

    Fecha pepito;
    Fecha ayer = --Fecha::hoy();
    salida << "La fecha ayer es: " << ayer << endl;
    ///salida es un puntero a archivo, escribe el mensaje ahi

    //pepito = hoy.sumarDias(30);
    hoy += 1;
//    pepito = 60 + hoy;

    cout << ++hoy << endl;///suma uno y muestra la fecha
    cout << hoy++ << endl;///muestra la fecha y despues suma uno
    cout << hoy << endl;///muestra la fecha que recien se sumo uno

    salida << "La fecha hoy es: " << hoy << endl;
    ///salida es un puntero a archivo, escribe el mensaje ahi

    // hoy += 30;

    int dia, mes, anio;

    hoy.getDMA(dia, mes, anio);

//    cout << "anio: " << anio << (Fecha::esBisiesto(2020)?"":" NO ")<< "es bisiesto" << endl;

 //   cout << "La fecha suma es: " << setw(2) << fixed << dia << '/' << setw(2) << fixed << mes << '/' << setw(4) << fixed << anio << endl;


    hoy = Fecha::hoy();

    salida << "Hoy posta es: " << hoy << endl;

    /*
	cout << hoy << endl;
	cout << hoy++ << endl;
	cout << ++hoy << endl;
*/
	// cout << 10 + hoy << endl;
	///suma 10 a la cantidad de dias, pero no las guarda, solo las muestra

	salida << "Mas 4 meses ==> " << hoy.sumarMeses(4) << endl;

    Fecha maniana = ++hoy;
    salida << "Mañana es: " << maniana << endl;

    Fecha fIngresada;

    while(entrada.peek() != EOF)
    {
        entrada >> fIngresada;///desde el archivo lee una fecha con el formato indicado en el metodo
                            /// >> de fecha
        entrada.ignore(1);///ignora un caracter despues de lo que se haya leido en fecha
                        ///sea el que sea pero parece que no le afecta el \n?

        cout << "La fecha ingresada del archivo es: " << fIngresada << endl;
    }


    return 0;
}
