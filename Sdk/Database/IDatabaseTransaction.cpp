#include "IDatabaseTransaction.h"

using namespace energy::database;

IDatabaseTransaction::IDatabaseTransaction() :
    _transactionState{ Active }
{

}

IDatabaseTransaction::TransactionState IDatabaseTransaction::getState() const
{
    return _transactionState;
}
