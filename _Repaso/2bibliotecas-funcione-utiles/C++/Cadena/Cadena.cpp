#include <string.h>

#include <stdio.h>
#include <queue>

#include "Cadena.h"


Cadena::Cadena()
{
	this->cad = new char[1];///new = malloc, hay que indicar tipo de dato y tamaño
	this->cad[0] = '\0';///inicializa el caracer en \0
}


Cadena::Cadena(const char* cad)
{
	this->cad = new char[strlen(cad) + 1];///malloc pidiendo el espacio de la cadena del main +1 (\0)
	strcpy(this->cad, cad);///copia la cadena recibida por parametro en la creada recien
}


Cadena::Cadena(char c)
{
	this->cad = new char[2];
	this->cad[0] = c;
	this->cad[1] = '\0';
}


Cadena::Cadena(int n)
{
	this->cad = new char[cantDigitos(n) + 1];
	sprintf(this->cad, "%d", n);///como un strcpy, copia n en cad
}


Cadena::Cadena(char* cad)///constructor privado
                ///lo llama el metodo de la linea 96
{
	this->cad = cad;
}


Cadena::~Cadena()
{
	delete [] this->cad;///por el malloc, equivalente a free
}


Cadena::Cadena(const Cadena& otra)
{
	this->cad = new char[strlen(otra.cad) + 1];///otra es un objeto tipo cadena
	strcpy(this->cad, otra.cad);
}


Cadena& Cadena::operator =(const Cadena& otra)
{
	size_t nuevoTam = strlen(otra.cad);

	///si la cadena privada no tiene el mismo espacio que la enviada
	if(strlen(this->cad) != nuevoTam)
	{
	    ///libera la memoria de la privada
		delete [] this->cad;
		///y reasigna la memoria necesaria
		this->cad = new char[nuevoTam + 1];
	}

	///finalmente copia la cadena
	strcpy(this->cad, otra.cad);

	return *this;
}


Cadena& Cadena::operator +=(const Cadena& otra)
{
	char* vConcat = new char[strlen(this->cad) + strlen(otra.cad) + 1];
        ///crea una nueva cadena con el espacio de ambas cadenas+1

    ///copia ambas cadenas en el espacio nuevo
	strcpy(vConcat, this->cad);
	strcat(vConcat, otra.cad);

	///libera el espacio de la cadena que esta como privada en la clase
	delete [] this->cad;
	///cad apunta al mismo lugar que vConcat
	this->cad = vConcat;

	return *this;
}


Cadena operator +(const Cadena& cad1, const Cadena& cad2)
{
	char* vConcat = new char[strlen(cad1.cad) + strlen(cad2.cad) + 1];

	strcpy(vConcat, cad1.cad);
	strcat(vConcat, cad2.cad);

	return Cadena(vConcat); ///Llama al constructor privado que no copia la cadena.
}


bool Cadena::vacia() const
{
	return *this->cad == '\0';
}


vector<Cadena> Cadena::split(char separador)
{
	vector<Cadena> campos;///campos es un array que puede cambiar de tamaño dinamicamente

	char* origen = this->cad;
	char* posSeparador;
	char* subcad;
	char* destino;

	while(*origen)
	{
		posSeparador = proximoSeparador(origen, separador);///busca primer aparicion del separador

		subcad = new char[posSeparador - origen + 1];///+1 es necesario?
		///guarda en subcad todos los caracteres que hayan hasta el separador
		destino = subcad;

		for(; origen < posSeparador; origen++, destino++)
			*destino = *origen;///copia caracter a caracter desde origen a destino

		*destino = '\0';

		if(*origen)
			++origen;

		campos.push_back(subcad);///agrega lo que este en subcad al final (o inicio la primera vez)
                                ///de campos
	}

	return campos;
}


char* Cadena::proximoSeparador(const char* origen, char separador)
{
	char* posSeparador;

	if((posSeparador = strchr((char*)origen, separador)))
                    ///busca la primer aparicion del separador
		return posSeparador;
	else
		return strchr((char*)origen, '\0');
                    ///si no lo encuentra busca el \0
}


ostream& operator <<(ostream& sal, const Cadena& cadena)
{
	return sal << cadena.cad;///muestra en pantalla la cadena
}


istream& operator >>(istream& ent, Cadena& cadena)
{
	size_t cantCar = 0;
	char c;
	queue<char> colaChars;///crearCola

    c = ent.get();///ent es un archivo, pone en c el primer caracter
	while(( c != EOF && c != '\n')
	{
	    ///escribe el archivo en la cola, pero al reves
		cantCar++;
		colaChars.push(c); /// ponerEnCola
        c = ent.get();
	}

	///si la cantidad de caracteres del archivo supera el espacio asignado al
    ///atributo privado le reasigna el espacio necesario
	if(strlen(cadena.cad) != cantCar)
	{
		delete [] cadena.cad;
		cadena.cad = new char[cantCar + 1];
	}

	char* pc = cadena.cad;
	///puntero a la cadena

	while(!colaChars.empty()) /// colaVacia
	{
		*pc = colaChars.front(); /// verTope
		colaChars.pop(); /// sacarDeCola, solo lo elimina pero no lo devuelve
		++pc;
	}

	*pc = '\0';

	///es necesario porque en el while de linea 172 no se pregunta por el puntero, solo por el caracter
	ent.peek(); /// Para prender el flag EOF, si estoy al final del archivo, pero no intenté leer.

	return ent;
}


int Cadena::cantDigitos(int n)
{
	int cantDig = 1;

	while((n /= 10) > 0)///cada division por 10 indica que hay un numero mas
			cantDig++;

	return cantDig;
}








