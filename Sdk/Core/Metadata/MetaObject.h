#ifndef METAOBJECT_H
#define METAOBJECT_H

#include <export.h>
#include <Core/Metadata/IMetadata.h>

namespace energy { namespace core { namespace metadata {

/**
 * @brief Абстрактный класс для предоставления доступа к метаданным класса.
 * Класс, предоставляющий метаданные, должен быть унаследован от класса MetaObject и реализовать виртуальный метод MetaObject::getMetadata(), возвращающий
 * метаданные объекта.
 */
class SDKSHARED_EXPORT MetaObject
{
public:
    MetaObject();
    virtual ~MetaObject() = default;

    /**
     * @brief Возвращает метаданные класса
     */
    virtual const energy::core::metadata::IMetadata &getMetadata() const = 0;
};

} } }

#endif // METAOBJECT_H
