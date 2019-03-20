#include "TypeCastingException.h"

using namespace energy::exceptions;

TypeCastingException::TypeCastingException() :
    _message{ "Type casting failed!" }
{

}

TypeCastingException::TypeCastingException(const char *message) :
    _message{ message }
{

}
