#include <iostream>
#include <Core/Serialization/Json/JsonObject.h>
#include <Model/Network/Wire.h>
#include <Model/Network/TransformerSubstation.h>

using namespace energy::core::serialization::json;
using namespace energy::model::network;
using namespace energy::core::types;

int main()
{
    JsonObject json;
    std::cout << "Object type: " << json.objectType() << std::endl;
    json.value("Testtttet");
    std::cout << "Value: " << json.asString() << std::endl;

    auto wire = new Wire();
    std::cout << "Class [" << wire->getMetadata().getClassName() << "] Type Uuid [" << wire->getMetadata().getTypeUid().toString() << "]\n";

    auto ts = new TransformerSubstation(wire);
    std::cout << "Class [" << ts->getMetadata().getClassName() << "] Type Uuid [" << ts->getMetadata().getTypeUid().toString() << "]\n";

    std::cout << std::endl << "Press any key" << std::endl;
    int g;
    std::cin >> g;

    return 0;
}
