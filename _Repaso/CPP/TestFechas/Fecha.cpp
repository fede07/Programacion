#include "Fecha.h"
#include "FechaException.h"
#include "time.h"
#include <iomanip>

#define ANIO_BASE 1601

const int Fecha::acumuladoMesesNoBisiesto[] = {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
const int Fecha::acumuladoMesesBisiesto[] = {0, 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335};


Fecha::Fecha()
{
	this->diaRel = 1;
}


Fecha::Fecha(int dia, int mes, int anio)
{
    ///despues de ser invocado llama a setDMA (fecha.cpp linea 54)
	this->setDMA(dia, mes, anio);
}


Fecha Fecha::sumarDias(int dias) const
{
	Fecha fSuma(*this);///el objeto fSuma recibe un CLON del objeto que llamo al metodo
	fSuma.diaRel += dias;///le suma los dias enviados por parametro
	return fSuma;///devuelve ese resultado
}


void Fecha::getDMA(int& d, int& m, int& a) const
{///hace lo que tenga que hacer, y en la direccion de dia, mes y anio guarda esos valores
	int cantAniosComplCalc = this->diaRel / 365;///this-> seria el objeto llamador, invocando al metodo diaRel
	unsigned long diasAniosComplCalc = cantAniosComplCalc * 365 + cantAniosComplCalc / 4 - cantAniosComplCalc / 100 + cantAniosComplCalc / 400;

	while(diasAniosComplCalc >= this->diaRel)
	{
		cantAniosComplCalc--;
		diasAniosComplCalc = cantAniosComplCalc * 365 + cantAniosComplCalc / 4 - cantAniosComplCalc / 100 + cantAniosComplCalc / 400;
	}

	int anio = ANIO_BASE + cantAniosComplCalc;

	a = anio;

	int diaDelAnio = this->diaRel - diasAniosComplCalc;

	diaDelAnioADiaMes(diaDelAnio, anio, d, m);
}


void Fecha::setDMA(int d, int m, int a)
{
   if(!esFechaValida(d, m, a))
    ///si ese try resulta en un error hace un throw para mostrar un error (main.cpp linea 32)
		throw FechaException("La fecha es inválida");

	int cantAnios = a - ANIO_BASE;
	int diasAniosCompl = cantAnios * 365 + cantAnios / 4 - cantAnios / 100 + cantAnios / 400;
	this->diaRel = diasAniosCompl + diaDelAnio(d, m, a);
}


Fecha Fecha::operator +(int dias) const
{
	return sumarDias(dias);
}


Fecha& Fecha::operator +=(int dias)
{
    ///si bien c++ sabe como usar el += no sabe como usarlo en esta clase
    ///no sabe que parametro utilizar, eso es lo que hay que indicar
	this->diaRel += dias;

	return *this;
}


Fecha& Fecha::operator ++()	/// Pre
{
	++this->diaRel;///a diaRel le suma uno
	return *this;///devuelve la fecha sumada en uno
}


Fecha Fecha::operator ++(int) /// Pos
{
	Fecha temp(*this);
	this->diaRel++;///suma la fecha REAL, la del main
	return temp;///devuelve una COPIA de lo que era la fecha ANTES de sumarle uno
}


Fecha& Fecha::operator --()	/// Pre
{
	--this->diaRel;
	return *this;
}

///setea el dia actual o no se cual, no importa
Fecha Fecha::hoy()
{
	time_t segs = time(NULL);

	struct tm* timeMachine = localtime(&segs);

	int dia = timeMachine->tm_mday;
	int mes = timeMachine->tm_mon + 1;
	int anio = timeMachine->tm_year + 1900;

	return Fecha(dia, mes, anio);
}

///es friend, permite usar metodos/atributos privados?
///es porque hay dos metodos con el mismo nombre
///es necesario porque es posible escribir "10+fecha", y el otro operador (linea 66) hace "fecha+10"
Fecha operator +(int dias, const Fecha& f)
{
	Fecha fSuma(f);

	fSuma.diaRel += dias;

	return fSuma;
}

/********** Funciones miembro (métodos) privadas **********/

int Fecha::diaDelAnio(int dia, int mes, int anio)
{
	return (esBisiesto(anio)? acumuladoMesesBisiesto[mes] : acumuladoMesesNoBisiesto[mes]) + dia;
}


bool Fecha::esBisiesto(int anio)
{
	return (anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0;
}


void Fecha::diaDelAnioADiaMes(int diaDelAnio, int anio, int& d, int& m)
{
	const int* acumuladoMeses = esBisiesto(anio)? acumuladoMesesBisiesto : acumuladoMesesNoBisiesto;

	int mes = 2;

	while(mes <= 12 && diaDelAnio > acumuladoMeses[mes])
		mes++;

	mes--;
	m = mes;

	d = diaDelAnio - acumuladoMeses[mes];
}


bool Fecha::esFechaValida(int dia, int mes, int anio)
{
	return anio >= ANIO_BASE && mes >= 1 && mes <= 12 && dia >= 1 && dia <= cantDiasMes(mes, anio);
}


int Fecha::cantDiasMes(int mes, int anio)
{
	static const int vCantDias[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if(mes == 2 && esBisiesto(anio))
		return 29;

	return vCantDias[mes];
}


Fecha Fecha::sumarMeses(int cantmeses)const
{
    Fecha fsuma(*this);///copia de los valores del objeto llamador
    int dia,mes,anio;
    this->getDMA(dia, mes, anio);///toma los valores del objeto llamador del metodo
	///es necesario hacerlo asi para no perder el valor real entre las cuentas
	///sino el resultado seria incorrecto

	///lo ignoro porque es logica propia del programa
    if(esBisiesto(anio))
    {
        fsuma.diaRel-=acumuladoMesesBisiesto[mes+1];
        fsuma.diaRel+=acumuladoMesesBisiesto[mes+1+cantmeses];
    }
    else
    {
        fsuma.diaRel-=acumuladoMesesNoBisiesto[mes+1];
        fsuma.diaRel+=acumuladoMesesNoBisiesto[mes+1+cantmeses];
    }
    return(fsuma);
}


ostream& operator <<(ostream& sal, const Fecha& f)
{
	int dia, mes, anio;
	f.getDMA(dia, mes, anio);
    ///setfill('dato') pone la cantidad de "datos" indicada por setw(X)
    ///despues en esos X lugares muestra el dia y pone una / despues
	return sal << setfill('0') << setw(2) << dia << '/' << setfill('0') << setw(2) << mes << '/' << setfill('0') << setw(4) << anio;
}

///lee un archivo y lo setea con el formato indicado
istream& operator >>(istream& ent, Fecha& f)
{
	int d, m, a;
	char c;

	ent >> d >> c >> m >> c >> a;
	f.setDMA(d, m, a);

	return ent;
}

