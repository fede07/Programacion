#ifndef FIGURA_H
#define FIGURA_H


class Figura
{
public:///polimorfismo, cada figura aplica estas funciones de distinta manera
    ///TIENE que tener el virtual
	virtual double perimetro() const = 0;
	virtual double area() const = 0;
};


#endif // FIGURA_H
