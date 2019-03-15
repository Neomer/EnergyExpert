#ifndef IMETADATA_H
#define IMETADATA_H

#include <export.h>
#include <Core/Types/Uuid.h>

namespace energy { namespace core { namespace metadata {

/**
 * @brief Абстрактный класс (интерфейс) предоставляющий доступ к метаданным класса-владельца.
 * Должен быть реализован для каждого класса, который наследуется от абстрактного класса MetaObject.
 */
class SDKSHARED_EXPORT IMetadata
{
public:
    IMetadata();
    virtual ~IMetadata() = default;
    /**
     * @brief Uid типа
     */
    virtual const energy::core::types::Uuid &getTypeUid() const = 0;
    /**
     * @brief Имя класса
     * @return
     */
    virtual const char *getClassName() const = 0;

    /**
     * @brief Проверяет, что метаданные other принадлежат экземпляру того же класса.
     * Сравнение происходит по TypeUid.
     * @param other Метаданные сравниваемого класса
     * @return true, если метаданные other принадлежат экземпляру того же класса
     */
    bool isSame(const IMetadata &other) const;
};

} } }

#endif // IMETADATA_H
