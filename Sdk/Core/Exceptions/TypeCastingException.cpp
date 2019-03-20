#include "TypeCastingException.h"

using namespace energy::core::exceptions;

TypeCastingException::TypeCastingException() :
    _message{ "Type casting failed!" }
{

}

TypeCastingException::TypeCastingException(const char *message) :
    _message{ message }
{

}
