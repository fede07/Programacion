/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* 22.333.444-PEREZ_DEL_RIO,JuanManuel-(07-2299) *//**/
/**//**   DEBE MODIFICAR LA LÍNEA DE COMENTARIO ANTERIOR CON SUS DATOS   **//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//**         COMPLETE LA DECLARACIÓN DE LA CLASE          **//**//**//**/

#ifndef PRISMA_H_
#define PRISMA_H_

#include <iostream>
#include <string>

using namespace std;

class Prisma
{
private:
    int alto;
    int ancho;
    int profundidad;
    string color;     /// <--preferentemente, de lo contrario:  char *color;

public:
    Prisma ();
    Prisma (string,int,int);
    Prisma (string, int, int, int);
    Prisma (const Prisma&);

    friend Prisma operator *(int,const Prisma& otro);
	friend ostream& operator <<(ostream& sal, const Prisma&);
	Prisma& operator = (const Prisma&);
	Prisma operator ++(int); /// Pos
	Prisma& operator --();	/// Pre

};
#endif // PRISMA_H_





















