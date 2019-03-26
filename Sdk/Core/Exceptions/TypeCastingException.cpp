#include "TypeCastingException.h"

using namespace energy::exceptions;

TypeCastingException::TypeCastingException() :
    _message{ "Приведение типов не удалось!" }
{

}

TypeCastingException::TypeCastingException(const char *message) :
    _message{ message }
{

}
