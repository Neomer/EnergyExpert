#ifndef BASEMETADATACLASSBUILDER_H
#define BASEMETADATACLASSBUILDER_H

#include <vector>
#include <Core/Metadata/IMetadata.h>

namespace energy { namespace core { namespace metadata {

/**
 * Абстрактный класс, реализующий базовый функционал паттерна Строитель (Builder).
 */
template<class T>
class BaseMetadataClassBuilder
{
public:
    BaseMetadataClassBuilder<T>()
    {

    }

    /**
     * @brief Создать элемент сети, основывясь на Uuid его типа.
     * @param uid Uuid типа элемента сети
     * @return Элемент сети, либо nullptr, если элемента с таким Uuid типа не зарегистрировано.
     */
    T *createElementByTypeUid(const energy::core::types::Uuid &uid) const
    {
        for (auto m : _metadataList) {
            if (m->getTypeUid().isEquals(uid)) {
                return static_cast<T *>(m->createInstance());
            }
        }
        return nullptr;
    }
    /**
     * @brief Возвращает список реализаций классов метаданных.
     * @return Константная ссылка на список реализаций классов метаданных
     */
    const std::vector<energy::core::metadata::IMetadata *> getElementTypeList() const
    {
        return _metadataList;
    }

protected:
    std::vector<IMetadata *> _metadataList;
};

} } }

#endif // BASEMETADATACLASSBUILDER_H
