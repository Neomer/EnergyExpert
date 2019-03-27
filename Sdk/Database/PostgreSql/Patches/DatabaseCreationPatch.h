#ifndef DATABASECREATIONPATCH_H
#define DATABASECREATIONPATCH_H

#include <Sdk/Database/IDatabasePatch.h>

namespace energy::database {

class DatabaseCreationPatch : public IDatabasePatch
{
public:
    DatabaseCreationPatch() = default;
    virtual ~DatabaseCreationPatch() override = default;

    // IDatabasePatch interface
public:
    virtual void execute(IDatabaseTransaction *transaction) override;

private:
    void createTableUsers(IDatabaseTransaction *transaction);
};

}


#endif // DATABASECREATIONPATCH_H
