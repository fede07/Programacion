#include <iostream>

using namespace std;

int main()
{
    float producto, iva = 1.27;

    cout<<"Ingrese precio de producto: ";
    cin>>producto;

    producto*=iva;

    cout<<"Precio con IVA: $"<<producto<<endl;

    return 0;
}
