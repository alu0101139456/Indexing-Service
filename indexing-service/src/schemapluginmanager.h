#ifndef SCHEMAPLUGINMANAGER_H
#define SCHEMAPLUGINMANAGER_H

#include <memory>
#include <vector>
#include <map>
#include <schemaplugin.h>
#include "dynamiclibrary.h"
#include <string>

class SchemaPluginManager
{
public:
    using LoadPluginFunctionPointer = decltype (&loadPlugin);

    static const SchemaPluginManager& instance();

    std::unique_ptr<SchemaPlugin> getSchemaPlugin(const std::string& schema) const;

private:
    std::map<std::string, LoadPluginFunctionPointer> schemas_;
    std::vector<DynamicLibrary> libraries_;

    SchemaPluginManager();
    SchemaPluginManager (const SchemaPluginManager&) = delete;
    SchemaPluginManager& operator= (const SchemaPluginManager&) = delete;
};

#endif // SCHEMAPLUGINMANAGER_H
