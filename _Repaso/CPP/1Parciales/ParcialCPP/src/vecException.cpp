#include "vecException.h"

vecException::vecException(const string& msj)
{
	this->mensaje = msj;
}

const string& vecException::getMensaje() const
{
	return this->mensaje;
}
