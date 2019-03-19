#include <sstream>
#include <algorithm>

#include "XmlSerializerImpl.h"
#include <Core/Serialization/Xml/XmlObject.h>

using namespace energy::core::serialization::xml;

XmlSerializerImpl::XmlSerializerImpl(const IXmlDecorator *tagNameDecorator,
                                     const IXmlDecorator *attributeNameDecorator) :
    _tagNameDecorator{ tagNameDecorator },
    _attributeNameDecorator{ attributeNameDecorator }
{

}

std::string XmlSerializerImpl::serialize(const energy::core::serialization::ISerializable *object) const
{
    std::stringstream stream;
    try {
        auto xmlObject = const_cast<XmlObject *>(static_cast<const XmlObject *>(object));
        auto rootNode = xmlObject->getRootNode();

        stream << "<?xml version=\"1.0\"?>";
        serializeNode(stream, &rootNode);
    }
    catch (std::bad_alloc ex) {

    }

    return std::string(stream.str());
}

void XmlSerializerImpl::deserialize(energy::core::serialization::ISerializable *object, std::string &data)
{
    //TODO: реализовать

}

void XmlSerializerImpl::serializeAttributes(std::stringstream &stream, const XmlNode *node) const
{
    std::for_each(node->getAttributesBeginIterator(), node->getAttributesEndIterator(), [this, &stream](const XmlAttribute *item) {
        if (_attributeNameDecorator != nullptr) {
            _attributeNameDecorator->decorate(stream, item->getName());
        } else {
            stream << item->getName();
        }
        stream << "=\"" << item->getTextValue() << "\" ";
    });
}

void XmlSerializerImpl::serializeNode(std::stringstream &stream, const XmlNode *node) const
{

    stream << "<";
    if (_tagNameDecorator != nullptr) {
        _tagNameDecorator->decorate(stream, node->getName());
    } else {
        stream << node->getName();
    }
    if (node->hasAnyAttributes()) {
        stream << " ";
        serializeAttributes(stream, node);
    }
    if (node->isEmpty()) {
        stream << " />";
    } else {
        stream << ">";
        if (node->hasAnyChild()) {
            std::for_each(node->getChildrenBeginIterator(), node->getChildrenEndIterator(), [this, &stream](const XmlNode *item) {
                this->serializeNode(stream, item);
            });
        } else {
            stream << node->getText_const();
        }
        stream << "</";
        if (_tagNameDecorator != nullptr) {
            _tagNameDecorator->decorate(stream, node->getName());
        } else {
            stream << node->getName();
        }
        stream << ">";
    }
}
