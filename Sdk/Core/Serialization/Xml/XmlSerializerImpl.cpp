#include <sstream>
#include <algorithm>

#include "XmlSerializerImpl.h"
#include <Core/Serialization/Xml/XmlObject.h>

using namespace energy::core::serialization::xml;

XmlSerializerImpl::XmlSerializerImpl()
{

}

std::string XmlSerializerImpl::serialize(const energy::core::serialization::ISerializable *object) const
{
    auto node = static_cast<const XmlNode *>(object);

    std::stringstream stream;
    if (node->isEmpty()) {
        stream << "<" << node->getName() << " />";
    } else {
        stream << "<" << node->getName() << ">";
        if (node->hasChildren()) {
            std::for_each(node->getChildrenBeginIterator(), node->getChildrenEndIterator(), [this, &stream](const XmlNode *item) {
                stream << serialize(item);
            });
        } else {
            stream << node->getText_const();
        }
        stream << "</" << node->getName() << ">";
    }

    return std::string(stream.str());
}

void XmlSerializerImpl::deserialize(energy::core::serialization::ISerializable *object, std::string &data)
{
    //TODO: реализовать

}
