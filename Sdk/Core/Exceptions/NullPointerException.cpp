#include "NullPointerException.h"

using namespace energy::core::exceptions;


NullPointerException::NullPointerException() :
    _message{ "Unexpected null pointer!" }
{

}

NullPointerException::NullPointerException(const char *message) :
    _message{ message }
{

}
