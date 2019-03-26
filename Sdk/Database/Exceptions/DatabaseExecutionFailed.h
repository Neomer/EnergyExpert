#ifndef DATABASEEXECUTIONFAILED_H
#define DATABASEEXECUTIONFAILED_H

#include <Sdk/Core/Exceptions/IOException.h>

namespace energy::exceptions {

/**
 * @brief Произошла ошибка во время выполнения SQL-запроса.
 */
class DatabaseExecutionFailed : public IOException
{
public:
    explicit DatabaseExecutionFailed();
    explicit DatabaseExecutionFailed(const char *message);
    virtual ~DatabaseExecutionFailed() override = default;
};

}

#endif // DATABASEEXECUTIONFAILED_H
