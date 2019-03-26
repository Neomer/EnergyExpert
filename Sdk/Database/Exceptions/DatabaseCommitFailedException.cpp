#include "DatabaseCommitFailedException.h"

using namespace energy::exceptions;

DatabaseCommitFailedException::DatabaseCommitFailedException() :
    IOException ()
{

}

DatabaseCommitFailedException::DatabaseCommitFailedException(const char *message) :
    IOException (message)
{

}
