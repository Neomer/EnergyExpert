#include "IDatabaseConnectionsProvider.h"

#include <algorithm>

using namespace energy::database;

IDatabaseConnectionsProvider::IDatabaseConnectionsProvider()
{

}

IDatabaseConnectionsProvider::~IDatabaseConnectionsProvider()
{
    for (auto context : _connectionVector) {
        if (context->Connection != nullptr && !context->Terminated) {
            context->Connection->close();
            delete context->Connection;
        }
    }
}

void IDatabaseConnectionsProvider::registerConnection(IDatabaseConnection *connection)
{
    // Ищем дропнутое подключение, чтобы записать новое подключение на его место
    auto terminated = std::find_if(_connectionVector.begin(), _connectionVector.end(), [](const DatabaseConnectionContext* context) -> bool {
        return context->Terminated;
    });
    if (terminated != _connectionVector.end()) {
        auto stored = *(terminated.base());
        delete stored->Connection;
        stored->Connection = connection;
        stored->Terminated = false;
    } else {
        auto context = new DatabaseConnectionContext();
        context->Connection = connection;
        context->Terminated = false;
        _connectionVector.push_back(context);
    }
}
