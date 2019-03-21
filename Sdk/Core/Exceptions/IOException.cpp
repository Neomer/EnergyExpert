#include "IOException.h"

using namespace energy::exceptions;

IOException::IOException() :
    _message{ "" }
{

}

IOException::IOException(const char *message) :
    _message{ message }
{

}
