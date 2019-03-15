#ifndef BASEMETADATACLASSBUILDER_H
#define BASEMETADATACLASSBUILDER_H

#include <vector>
#include <mutex>
#include <Core/Metadata/IMetadata.h>
#include <string.h>

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

    virtual ~BaseMetadataClassBuilder<T>()
    {
        for (auto m : _metadataList) {
            delete m;
        }
    }

    /**
     * @brief Создать элемент сети, основываясь на Uuid его типа.
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
     * @brief  Создать элемент сети, основываясь на имени класса.
     * Не рекомендуется использовать, лучше выбрать из методов
     * BaseMetadataClassBuilder::createElementByTypeUid(const energy::core::types::Uuid &) и
     * BaseMetadataClassBuilder::createElementByFullName(const char *).
     * @param name Искомое имя
     * @return Элемент сети, либо nullptr, если элемента с таким именем не зарегистрировано.
     */
    T *createElementByName(const char *name) const
    {
        for(auto m : _metadataList) {
            if (!strcmp(m->getClassName(), name)) {
                return static_cast<T *>(m->createInstance());
            }
        }
        return nullptr;
    }

    /**
     * @brief  Создать элемент сети, основываясь на полном имени класса с namespace.
     * @param name Искомое имя
     * @return Элемент сети, либо nullptr, если элемента с таким именем не зарегистрировано.
     */
    T *createElementByFullName(const char *name) const
    {
        for(auto m : _metadataList) {
            if (!strcmp(m->getFullClassName(), name)) {
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
    /**
     * @brief Потокобезопасный метод для инициализации списка реализаций метаданных.
     */
    void safeLoad()
    {
        std::lock_guard<std::mutex> lock(_loadMtx);
        if (!_loaded) {
            loadComponents();
            _loaded = true;
        }
    }

protected:
    /**
     * @brief Создает список всех реализаций класса метаданных
     */
    virtual void loadComponents() = 0;

    bool _loaded;
    std::mutex _loadMtx;

    std::vector<IMetadata *> _metadataList;
};

} } }

#endif // BASEMETADATACLASSBUILDER_H
