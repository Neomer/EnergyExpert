#include "DataStreamAlreadyOpenException.h"

using namespace energy::exceptions;

DataStreamAlreadyOpenException::DataStreamAlreadyOpenException() :
    _message{ "Поток ввода-вывода уже открыт!" }
{

}

DataStreamAlreadyOpenException::DataStreamAlreadyOpenException(const char *message) :
    _message{ message }
{

}
