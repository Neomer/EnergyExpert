#include "DatabaseExecutionFailed.h"

using namespace energy::exceptions;

DatabaseExecutionFailed::DatabaseExecutionFailed() :
    IOException ()
{

}

DatabaseExecutionFailed::DatabaseExecutionFailed(const char *message) :
    IOException (message)
{

}
