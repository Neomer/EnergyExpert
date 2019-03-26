#ifndef DATABASECOMMITFAILEDEXCEPTION_H
#define DATABASECOMMITFAILEDEXCEPTION_H

#include <Sdk/Core/Exceptions/IOException.h>

namespace energy::exceptions {

/**
 * @brief Произошла ошибка при выполнении коммита транзакции
 */
class SDKSHARED_EXPORT DatabaseCommitFailedException : public IOException
{
public:
    explicit DatabaseCommitFailedException();
    explicit DatabaseCommitFailedException(const char *message);
    virtual ~DatabaseCommitFailedException() override = default;
};

}


#endif // DATABASECOMMITFAILEDEXCEPTION_H
