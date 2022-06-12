#include "Carta.h"

Carta::Carta ()
{
    this->destinario = "";
    this->provincia = "";
    this->precio = 0;
}

Carta::Carta(const string destinatario, const string provincia, float precio)
{
    this->destinario = destinatario;
    this->provincia = provincia;
    this->precio = precio;
}

Carta::Carta (Carta& otra)
{
    this->destinario = otra.getDest();
    this->provincia = otra.getProv();
    this->precio = otra.getPrecio();
}

string Carta::getDest()
{
    return this->destinario;
}

string Carta::getProv()
{
    return this->provincia;
}

float Carta::getPrecio()
{
    return this->precio;
}

void Carta::actualizarPrecio(float precio)
{
    this->setPrecio(precio);
}

void Carta::setPrecio(float precio)
{
    this->precio = precio;
}

Carta& Carta::operator += (const float precio)
{
    float tempPrecio;
    tempPrecio = this->getPrecio();
    tempPrecio+=precio;
    this->setPrecio(tempPrecio);
    return *this;
}

Carta& Carta::operator = (const Carta& otra)
{
    this->precio = otra.precio;
    this->provincia = otra.provincia;
    this->destinario = otra.destinario;
    return *this;
}

Carta& Carta::operator ++ ()
{
    ++this->precio;
    return *this;
}

Carta Carta::operator ++ (int)
{
    Carta tempCarta(*this);
    this->precio++;
    return tempCarta;
}

ostream& operator << (ostream& sal, const Carta& otra)
{
    return sal << "Destinatario " << otra.destinario << " Provincia " << otra.provincia << " Precio " << otra.precio;
}

istream& operator >> (istream& ent, Carta& otra)
{
    string destTemp, provTemp;
    float precioTemp;
    cout << "holi" << endl;
    getline(ent,destTemp);
//    ent >> destTemp >> provTemp >> precioTemp;
    ent >> provTemp >> precioTemp;
    otra.destinario = destTemp;
    otra.provincia = provTemp;
    otra.precio = precioTemp;

    return ent;
}












