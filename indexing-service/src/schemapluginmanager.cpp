#include "schemapluginmanager.h"

using namespace std::literals;

const auto LOADPLUGIN_SYMBOL_NAME = "loadPlugin"s;

const SchemaPluginManager &SchemaPluginManager::instance()
{
    static SchemaPluginManager instance;
    return instance;
}

std::unique_ptr<SchemaPlugin> SchemaPluginManager::getSchemaPlugin(const std::string &schema) const
{
    auto iter = schemas_.find(schema);
    if (iter == schemas_.end()) {
        return nullptr;
    }
    return std::unique_ptr<SchemaPlugin>((iter->second)());
}

SchemaPluginManager::SchemaPluginManager()
{
    // TODO: Buscar en un directorio y iterar sobre los *.so
    // encontrados para:
    try {
        libraries_.emplace_back("../httpschemaplugin/libhttpschemaplugin.so");
    } catch (std::runtime_error& e) {
        return;
    }

    auto loadPlugin = libraries_.back().resolve<LoadPluginFunctionPointer>(LOADPLUGIN_SYMBOL_NAME);
    if (!loadPlugin) {
        libraries_.pop_back();
        return;
    }

    auto schemaPlugin = (loadPlugin.value())();
    for (auto schema : schemaPlugin->schemaSupported()) {
        schemas_.emplace(schema, loadPlugin.value());
    }
}
