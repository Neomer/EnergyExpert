#ifndef POSTGRESQLPATCHER_H
#define POSTGRESQLPATCHER_H

#include <Sdk/Database/IDatabasePatcher.h>

namespace energy::database {

class PostgreSqlPatcher : public IDatabasePatcher
{
public:
    PostgreSqlPatcher(const IDatabaseConnectionSettings *settings);
    virtual ~PostgreSqlPatcher() override = default;

    // IDatabasePatcher interface
protected:
    virtual void fillPatchList(std::vector<std::shared_ptr<IDatabasePatch> > &patches) override;
    virtual IDatabaseConnection *createConnection(const IDatabaseConnectionSettings *settings) override;
};

}


#endif // POSTGRESQLPATCHER_H
