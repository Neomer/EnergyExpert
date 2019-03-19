#ifndef IMETADATA_H
#define IMETADATA_H

#include <export.h>
#include <vector>
#include <functional>
#include <Core/Types/Uuid.h>

namespace energy { namespace core { namespace metadata {

class MetaObject;

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
     * @brief Полное имя класса, включая namespace.
     * @return
     */
    virtual const char *getFullClassName() const = 0;
    /**
     * @brief Возвращает новый экземпляр объекта.
     * @return
     */
    virtual MetaObject *createInstance() const = 0;
    virtual std::vector<std::function<void(void)>> getMethods() = 0;
    /**
     * @brief Проверяет, что метаданные other принадлежат экземпляру того же класса.
     * Сравнение происходит по TypeUid.
     * @param other Метаданные сравниваемого класса
     * @return true, если метаданные other принадлежат экземпляру того же класса
     */
    bool isSame(const IMetadata &other) const;
    void invoke(MetaObject *object, const char *methodName) const;
};

} } }

#endif // IMETADATA_H
