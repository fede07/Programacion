#ifndef TRIANGULO_H
#define TRIANGULO_H


class Triangulo
{
    public:
        Triangulo();
        Triangulo(double _lado1, double _lado2, double _lado3);
        bool esTriangulo(Triangulo triangulo);
        int tipoTriangulo(Triangulo pepito);
    private:
        double lado1;
        double lado2;
        double lado3;
};

#endif // TRIANGULO_H
