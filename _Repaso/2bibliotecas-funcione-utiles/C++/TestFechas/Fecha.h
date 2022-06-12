#ifndef FECHA_H
#define FECHA_H

#include <iostream>

using namespace std;

///LA FECHA TRABAJA RECIBIENDO DIA MES Y ANIO, Y PASA ESOS DATOS A UN DIA RELATIVO PARA
///TRABAJAR CON ESO Y FACILITAR LAS CUENTAS AL NO TENER QUE CONSIDERAR CONSTANTEMENTE
///CUANDO SE PASA DE UN MES A OTRO, O DE UN AÑO A OTRO
///SE TRABAJA EN DIA RELATIVO Y FINALMENTE SI SE TIENE QUE MOSTRAR SE TRANSFORMA EN DD/MM/AA



class Fecha///declaracion clase fecha
{
private:
    ///ATRIBUTOS PRIVADOS
	unsigned long diaRel;
	///static hace que no se pierda nunca el valor aunque se salga del metodo?
	///el valor declarado en estas variables afecta a TODOS los objetos y no se pueden modificar
	///funciona similar a una macro
	static const int acumuladoMesesNoBisiesto[13];
	static const int acumuladoMesesBisiesto[13];


	///METODOS PRIVADOS
	///static indica que solo se van a usar variables static propias de la clase
	///dia, mes y anio estan declaradas en el main asi que no afectan lo de static
	static int diaDelAnio(int dia, int mes, int anio);
	static bool esBisiesto(int anio);
	static void diaDelAnioADiaMes(int diaDelAnio, int anio, int& d, int& m);

	static bool esFechaValida(int dia, int mes, int anio);
	static int cantDiasMes(int mes, int anio);

public:
    ///CONSTRUCTORES
	Fecha();
	Fecha(int dia, int mes, int anio);

	///METODOS PUBLICOS
	Fecha sumarDias(int dias) const;///estos const finales aseguran que el atributo enviado
	Fecha sumarMeses(int cantmeses) const;///no va a ser modificado en ningun momento
	void getDMA(int& d, int& m, int& a) const;///durante la ejecucion del metodo
	void setDMA(int d, int m, int a);

	///SOBRECARGA OPERADORES
	Fecha operator +(int dias) const;
	Fecha& operator +=(int dias);
	Fecha& operator ++(); /// Pre
	Fecha operator ++(int); /// Pos
	Fecha& operator --();	/// Pre

	static Fecha hoy();

	friend Fecha operator +(int dias, const Fecha& f);
};


ostream& operator <<(ostream& sal, const Fecha& f);
istream& operator >>(istream& ent, Fecha& f);


#endif // FECHA_H
