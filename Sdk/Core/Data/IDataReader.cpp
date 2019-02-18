#include "IDataReader.h"

#include <iostream>
#include <vector>

#include <Core/Collections/Array.h>
#include <Core/Collections/CollectionExtensions.h>

using namespace energy::core::data;
using namespace energy::core::collections;

IDataReader::IDataReader()
{
    std::vector<int> v{0, 1, 2, 3, 4};
    each<int, std::vector<int>>(v, [=](const int &item) {
        std::cout << item;
    });
}

IDataReader::~IDataReader()
{

}
