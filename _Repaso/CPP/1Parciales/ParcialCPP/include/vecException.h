#ifndef VECEXCEPTION_H
#define VECEXCEPTION_H

#include <string>

using namespace std;

class vecException
{
    private:
        string mensaje;

    public:
        vecException(const string& msj);
        const string& getMensaje() const;
};

#endif // VECEXCEPTION_H
