#include <iostream>

#include <Sdk/Core/ApplicationContext.h>

using namespace energy::core;

int main()
{
    ApplicationContext::getInstance().init();

    return 0;
}
