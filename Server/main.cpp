#include <iostream>
#include <Core/Serialization/Json/JsonObject.h>
#include <Model/Network/Wire.h>
#include <Model/Network/TransformerSubstation.h>
#include <Model/Network/NetworkElementBuilder.h>
#include <Core/Types/IObservable.h>

using namespace energy::core::serialization::json;
using namespace energy::model::network;
using namespace energy::core::types;

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wweak-vtables"

class A : public IObservable<int>
{
public:
    A() = default;
    virtual ~A() override = default;
};

class B : public IObserver<int>
{
public:
    B(IObservable<int> *observable) {
        observable->registerObserver(this);
    }
    virtual ~B() override = default;

    virtual bool onUpdate(const int &value, const IObservable<int> *observable) override
    {
        std::cout << "class B: update " << value << std::endl;
        return false;
    }
};

class C : public IObserver<int>
{
public:
    C(IObservable<int> *observable) {
        observable->registerObserver(this);
    }
    virtual ~C() override = default;

    virtual bool onUpdate(const int &value, const IObservable<int> *observable) override
    {
        std::cout << "class C: update " << value << std::endl;
        return false;
    }
};

int main()
{
    JsonObject json;
    std::cout << "Object type: " << json.objectType() << std::endl;
    json.value("Testtttet");
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

    A a;
    B b(&a);
    C c(&a);
    a.update(45);

    std::cout << std::endl << "Press any key" << std::endl;
    int g;
    std::cin >> g;

    return 0;
}
