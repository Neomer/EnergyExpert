#include "DataStreamNotOpenException.h"

using namespace energy::exceptions;

DataStreamNotOpenException::DataStreamNotOpenException() :
    _message{ "Поток ввода-вывода не открыт!" }
{

}

DataStreamNotOpenException::DataStreamNotOpenException(const char *message) :
    _message{ message }
{

}
