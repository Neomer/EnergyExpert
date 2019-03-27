#ifndef ISTRINGABLE_H
#define ISTRINGABLE_H

#include <Sdk/export.h>
#include <Sdk/singleton.h>
#include <string>

namespace energy { namespace core { namespace types {

/**
 * @brief IStringable интерфейс, реализации которого должны уметь предоставлять свое значение в виде строки
 */
class IStringable {

    INTERFACE(IStringable);

public:
    /**
     * @brief toString преобразовать значение в строку
     * @return Строка со значением
     */
    virtual std::string toString() const = 0;
    /**
     * @brief toString записать значение в переданную строку
     * @param buffer Строка, в которую необходимо записать значение
     */
    virtual void toString(std::string &buffer) const = 0;
};


} } }

#endif // ISTRINGABLE_H
