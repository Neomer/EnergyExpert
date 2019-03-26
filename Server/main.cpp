#include <iostream>
#include <Sdk/Core/Serialization/Json/JsonObject.h>
#include <Sdk/Model/Network/Wire.h>
#include <Sdk/Model/Network/TransformerSubstation.h>
#include <Sdk/Model/Network/NetworkElementBuilder.h>
#include <Sdk/Core/Types/IObservable.h>
#include <Sdk/Core/Serialization/Xml/XmlObject.h>
#include <Sdk/Core/Serialization/Xml/XmlSerializerImpl.h>
#include <Sdk/Core/Serialization/Xml/XmlTagNameDecorator.h>
#include <Sdk/Core/Serialization/Xml/XmlAttributeNameDecorator.h>
#include <Sdk/Logs/ConsoleLogger.h>
#include <Sdk/Logs/FileLogger.h>
#include <Sdk/Logs/DefaultLogMessageFormatter.h>

#include <Sdk/Core/Data/Exceptions/DataStreamNotOpenException.h>
#include <Sdk/Core/Exceptions/IOException.h>
#include <Sdk/Core/Types/DateTime.h>

#include <Sdk/Database/PostgreSql/PostgreSqlConnection.h>
#include <Sdk/Database/PostgreSql/PostgreSqlConnectionSettings.h>

#include <Sdk/Database/Exceptions/DatabaseNotOpenException.h>
#include <Sdk/Database/Exceptions/DatabaseCommitFailedException.h>

using namespace energy::exceptions;
using namespace energy::core::serialization::json;
using namespace energy::core::serialization::xml;
using namespace energy::model::network;
using namespace energy::core::types;
using namespace energy::core::serialization;
using namespace energy::logs;
using namespace energy::database;

int main()
{
    DefaultLogMessageFormatter formatter;
    ConsoleLogger consoleLogger(&formatter);
    try {
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
        } catch (energy::exceptions::IOException &) {
            consoleLogger.error("Не удалось создать файл для логирования!");
        }


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
        DateTime dt(306723825);
        std::cout << "Date time: " << dt.toString() << std::endl;

        XmlNode xmlNode(static_cast<const char *>("test me"));
        xmlNode.appendAttribute(new XmlAttribute("attribute name", "value of attribute"));
        xmlNode.appendChild(new XmlNode(static_cast<const char *>("sub_item1"), static_cast<const char *>("sub_item1_value")));
        xmlNode.appendChild(new XmlNode(static_cast<const char *>("sub_item2")));
        xmlNode.appendChild(new XmlNode(static_cast<const char *>("sub_item3")));

        std::cout << "Has attribute " << xmlNode.hasAttribute("attribute name") << std::endl;

        std::cout << "XML node: " << xmlNode.getName() << std::endl;
        auto attr = xmlNode.getAttribute("attribute name");
        if (attr != nullptr) {
            std::cout << "Attribute: " << attr->getTextValue() << std::endl;
        } else {
            std::cout << "Attribute not found!" << std::endl;
        }

        XmlTagNameDecorator tagNameDecorator;
        XmlAttributeNameDecorator attributeNameDecorator;
        ISerializer *serializer = new XmlSerializerImpl(&tagNameDecorator,
                                                        &attributeNameDecorator);

        XmlObject xml(&xmlNode);
        std::cout << "XML document: " << serializer->serialize(&xml) << std::endl;

        consoleLogger.debug("Initialize PostgreSql connection settings.");
        PostgreSqlConnectionSettings connectionSettings;
        connectionSettings.setHost("localhost");
        connectionSettings.setDatabase("EnergyExpert");
        connectionSettings.setUsername("postgres");
        connectionSettings.setPassword("123456");
        consoleLogger.debug(connectionSettings.toString().c_str());

        IDatabaseConnection *connection = new PostgreSqlConnection();
        connection->setConnectionSettings(&connectionSettings);
        try {
            consoleLogger.debug("Open database connection");
            connection->open();
            consoleLogger.debug("Connection READY!");

            consoleLogger.debug("Open transaction");
            auto tr = connection->createTransaction();
            try {
                consoleLogger.debug("Create table `public.temp_table`");
                tr->exec("CREATE TABLE public.temp_table (i integer);");
                consoleLogger.debug("Commit transaction");
                tr->commit();
            } catch (DatabaseCommitFailedException &) {
                consoleLogger.debug("Commit failed! Rollback...");
                tr->rollback();
            }
            consoleLogger.debug("Close database connection");
            connection->close();
        } catch (DatabaseNotOpenException &) {
            consoleLogger.error("Database connection FAILED!");
        }
    } catch (std::exception &e) {
        consoleLogger.error(e.what());
    }

    std::cout << std::endl << "Press any key" << std::endl;
    int g;
    std::cin >> g;

    return 0;
}
