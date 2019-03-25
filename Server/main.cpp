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
#include <Logs/ConsoleLogger.h>
#include <Logs/FileLogger.h>
#include <Logs/DefaultLogMessageFormatter.h>

#include <Core/Data/Exceptions/DataStreamNotOpenException.h>
#include <Core/Exceptions/IOException.h>
#include <Core/Types/DateTime.h>
#include <Sdk/os.h>
#include <Sdk/Core/Net/Ip4Address.h>

using namespace energy::exceptions;
using namespace energy::core::serialization::json;
using namespace energy::core::serialization::xml;
using namespace energy::model::network;
using namespace energy::core::types;
using namespace energy::core::serialization;
using namespace energy::logs;
using namespace energy::core::net;

#ifdef _OS_WIN_
    #include <winsock2.h>
#endif

int main()
{
    DefaultLogMessageFormatter formatter;
    ConsoleLogger consoleLogger(&formatter);
    consoleLogger.info("test to info");
    consoleLogger.debug("test to debug");
    consoleLogger.error("test to error");
    consoleLogger.trace("test to trace");
    consoleLogger.warning("test to warning");

    try {
        FileLogger fileLogger("c:\\test.log", 10, &formatter);
        fileLogger.info("test to info");
        fileLogger.debug("test to debug");
        fileLogger.error("test to error");
        fileLogger.trace("test to trace");
        fileLogger.warning("test to warning");

#ifdef _OS_WIN_
        fileLogger.debug("Инициализируем систему сокетов");
        WSADATA wsaData;
        if (WSAStartup(MAKEWORD(2,2), &wsaData)) {
            throw IOException("Не удалось инициализировать сокеты!");
        }
#endif

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
        DateTime dt(306723825);
        std::cout << "Date time: " << dt.toString() << std::endl;


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

        Ip4Address ip = Ip4Address::FromString("127.0.0.1");
        fileLogger.info(ip.toString().c_str());

    } catch (std::exception &e) {
        consoleLogger.error(e.what());
    }

#ifdef _OS_WIN_
    consoleLogger.debug("Закрываем работу с сокетами");
    WSACleanup();
#endif

    return 0;
}
