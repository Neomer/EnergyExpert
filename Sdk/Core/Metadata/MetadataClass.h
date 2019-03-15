#ifndef METADATACLASS_H
#define METADATACLASS_H

#include "MetaObject.h"

namespace energy { namespace core { namespace metadata {

/**
 * Шаблонный класс, реализующий абстрактный класс MetaObject.
 * Создает в конструкторе экземпляр класса метаданных объекта. Тип класса метаданных передается через аргумент шаблона.
 * Тип T - класс метаданных объекта.
 */
template<class T>
class SDKSHARED_EXPORT MetadataClass : public MetaObject
{
public:
    MetadataClass() : _metadata{ } {}
    ~MetadataClass() override = default;

    // MetaObject interface
public:
    virtual const IMetadata &getMetadata() const override { return _metadata; }

private:
    const T &_metadata;
};

} } }

#endif // METADATACLASS_H
