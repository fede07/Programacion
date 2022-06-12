/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* 22.333.444-PEREZ_DEL_RIO,JuanManuel-(07-2299) *//**/
/**//**   DEBE MODIFICAR LA LÍNEA DE COMENTARIO ANTERIOR CON SUS DATOS   **//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//**   DESARROOLLE LAS "FUNCIONES MIEMBRO" DE LA CLASE    **//**//**//**/

#include "Prisma.h"

Prisma::Prisma ()
{
    this->alto = 1;
    this->ancho = 1;
    this->profundidad = 1;
    this->color = "Incoloro";
}

Prisma::Prisma (string color,int alto, int ancho)
{
    this->alto = alto;
    this->ancho = ancho;
    this->profundidad = 1;
    this->color = color;
}

Prisma::Prisma (string color,int alto, int ancho, int profundidad)
{
    this->alto = alto;
    this->ancho = ancho;
    this->profundidad = profundidad;
    this->color = color;
}

Prisma::Prisma (const Prisma& otro)
{
    this->alto = otro.alto;
    this->ancho = otro.ancho;
    this->profundidad = otro.profundidad;
    this->color = otro.color;
}

Prisma operator *(int numero, const Prisma& otro)
{
    Prisma tempPris;
    tempPris.alto = otro.alto * numero;
    tempPris.ancho = otro.ancho * numero;
    tempPris.profundidad = otro.profundidad * numero;
    tempPris.color = otro.color;
	return tempPris;
}

Prisma& Prisma::operator = (const Prisma& otro)
{
    this->alto = otro.alto;
    this->ancho = otro.ancho;
    this->profundidad = otro.profundidad;
    this->color = otro.color;
    return *this;
}

Prisma Prisma::operator ++(int) /// Pos
{
    Prisma temp(*this);
	this->alto ++;
	this->ancho ++;
	this->profundidad ++;
	return temp;
}

Prisma& Prisma::operator --()	/// Pre
{
    --this->alto;
	--this->ancho;
	--this->profundidad;
	return *this;
}

ostream& operator <<(ostream& sal, const Prisma& prisma)
{
    sal << prisma.alto << "x" << prisma.ancho << "x" << prisma.profundidad << " - " << prisma.color;
    return sal;
}
