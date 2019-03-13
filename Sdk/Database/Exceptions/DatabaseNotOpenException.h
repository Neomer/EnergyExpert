#ifndef DATABASENOTOPENEXCEPTION_H
#define DATABASENOTOPENEXCEPTION_H

#include <exception>

namespace energy { namespace exceptions {

class DatabaseNotOpenException : public std::exception
{
public:
    virtual const char* what() const throw ()
    {
        return "Не удалось создать подключение к базе данных!";
    }
};

} }


#endif // DATABASENOTOPENEXCEPTION_H
