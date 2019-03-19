#include <iostream>
#include <Core/Serialization/Json/JsonObject.h>
#include <Model/Network/Wire.h>
#include <Model/Network/TransformerSubstation.h>
#include <Model/Network/NetworkElementBuilder.h>
#include <Core/Types/IObservable.h>
#include <Core/Serialization/Xml/XmlObject.h>
#include <Core/Serialization/Xml/XmlSerializerImpl.h>
#include <Core/Serialization/Xml/XmlTagNameDecorator.h>
#include <Core/Serialization/Xml/XmlAttributeNameDecorator.h>

using namespace energy::core::serialization::json;
using namespace energy::core::serialization::xml;
using namespace energy::model::network;
using namespace energy::core::types;
using namespace energy::core::serialization;

int main()
{
    JsonObject json;
    std::cout << "Object type: " << json.objectType() << std::endl;
    json.value("Statuette");
    std::cout << "Value: " << json.asString() << std::endl;

    auto wire = new Wire();
    auto newWire = static_cast<Wire *>(wire->getMetadata().createInstance());
    std::cout << "Class [" << wire->getMetadata().getClassName() << "] Type Uuid {" << wire->getMetadata().getTypeUid().toString() << "}\n";
    std::cout << "Created class [" << newWire->getMetadata().getClassName() << "] Type Uuid {" << newWire->getMetadata().getTypeUid().toString() << "}\n";

    auto ts = new TransformerSubstation(wire);
    std::cout << "Class [" << ts->getMetadata().getClassName() << "] Type Uuid {" << ts->getMetadata().getTypeUid().toString() << "}\n";

    auto element = NetworkElementBuilder::getInstance().createElementByTypeUid(Uuid(10, 00, 00, 03));
    if (element != nullptr) {
        std::cout << "Class [" << element->getMetadata().getClassName() << "] Type Uuid {" << element->getMetadata().getTypeUid().toString() << "}\n";
    } else {
        std::cout << "Element creation failed!\n";
    }

    XmlObject xml;
    XmlNode xmlNode(static_cast<const char *>("test me"));
    xmlNode.addAttribute(new XmlAttribute("attribute name", "value of attribute"));
    xmlNode.getChildren().push_back(new XmlNode(static_cast<const char *>("sub_item1"), static_cast<const char *>("sub_item1_value")));
    xmlNode.getChildren().push_back(new XmlNode(static_cast<const char *>("sub_item2")));
    xmlNode.getChildren().push_back(new XmlNode(static_cast<const char *>("sub_item3")));

    std::cout << "Has attribute " << xmlNode.hasAttribute("attribute name") << std::endl;

    std::cout << "XML node: " << xmlNode.getName() << std::endl;
    auto attr = xmlNode.getAttribute("attribute name");
    if (attr != nullptr) {
        std::cout << "Attribute: " << attr->getTextValue() << std::endl;
    } else {
        std::cout << "Attribute not found!" << std::endl;
    }
    xml.getRootNode() = xmlNode;

    XmlTagNameDecorator tagNameDecorator;
    XmlAttributeNameDecorator attributeNameDecorator;
    ISerializer *serializer = new XmlSerializerImpl(&tagNameDecorator,
                                                    &attributeNameDecorator);
    std::cout << "XML document: " << serializer->serialize(&xml) << std::endl;

    std::cout << std::endl << "Press any key" << std::endl;
    int g;
    std::cin >> g;

    return 0;
}
