#include "DatabaseCreationPatch.h"

#include <Sdk/Database/PostgreSql/PostgreSqlConnection.h>

using namespace energy::database;

void DatabaseCreationPatch::execute(IDatabaseTransaction *transaction)
{
    createTableUsers(transaction);
}

void DatabaseCreationPatch::createTableUsers(IDatabaseTransaction *transaction)
{
    transaction->exec("CREATE TABLE public.SecurityUsers " \
                      "(" \
                      "    \"Id\" uuid NOT NULL, " \
                      "    \"Username\" character varying(256) NOT NULL, " \
                      "    PRIMARY KEY (\"Id\") " \
                      ") " \
                      "WITH (" \
                      "    OIDS = FALSE " \
                      ");");

    transaction->exec("ALTER TABLE public.users OWNER to postgres;");

} // createTableUsers

