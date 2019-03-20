#include "DatabaseNotOpenException.h"

using namespace energy::core::exceptions;

DatabaseNotOpenException::DatabaseNotOpenException() :
    _message{ "Не удалось подключиться к базе данных!" }
{

}

DatabaseNotOpenException::DatabaseNotOpenException(const char *message) :
    _message{ message }
{

}
