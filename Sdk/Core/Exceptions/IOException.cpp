#include "IOException.h"

using namespace energy::core::exceptions;

IOException::IOException() :
    _message{ "" }
{

}

IOException::IOException(const char *message) :
    _message{ message }
{

}
