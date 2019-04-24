#include <iostream>
#include <Sdk/Core/Serialization/Json/JsonObject.h>
#include <Sdk/Model/Network/Wire.h>
#include <Sdk/Model/Network/TransformerSubstation.h>
#include <Sdk/Model/Network/NetworkElementBuilder.h>
#include <Sdk/Core/Types/IObservable.h>
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

#include <Sdk/Core/Configuration/XmlConfiguration.h>

using namespace energy::exceptions;
using namespace energy::core::serialization::json;
using namespace energy::model::network;
using namespace energy::core::types;
using namespace energy::core::serialization;
using namespace energy::logs;
using namespace energy::database;

static DefaultLogMessageFormatter formatter;
static ConsoleLogger consoleLogger(&formatter);

void pugiTest() {
    consoleLogger.info("pugixml test");
    pugi::xml_document doc;
    auto res = doc.load_file("C:/sites.xml");
    if (res.status != pugi::status_ok) {
        consoleLogger.error(res.description());
        return;
    }
    auto child = doc.root().child("appcmd");
    std::cout << "First child node: " << child.name() << std::endl;
    std::cout << "Print attributes\n";
    for (auto at : child.attributes()) {
        std::cout << "Attribute " << at.name() << " = '" << at.value() << "'" << std::endl;
    }
    doc.reset();
}


int main()
{
    try {

        try {
            FileLogger fileLogger("c:\\test.log", 10, &formatter);
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



        pugiTest();

        consoleLogger.debug("Initialize PostgreSql connection settings.");
        PostgreSqlConnectionSettings connectionSettings;
        connectionSettings.setHost("localhost");
        connectionSettings.setDatabase("EnergyExpert");
        connectionSettings.setUsername("postgres");
        connectionSettings.setPassword("123456");
        consoleLogger.ILogger::debug(connectionSettings);

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
