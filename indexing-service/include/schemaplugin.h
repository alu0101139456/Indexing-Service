#ifndef SCHEMAPLUGIN_H
#define SCHEMAPLUGIN_H

#include <cstring>
#include <optional>
#include <vector>

class SchemaPlugin {
public:
    struct FetchInfo {
        std::string content;
        std::string contentType;
    };

    SchemaPlugin() = default;
    virtual ~SchemaPlugin() = default;

    virtual std::optional<FetchInfo> fetchUrl(const std::string& url) {
        return{};
    }

    virtual std::vector<std::string> schemaSupported () {
        return {};
    }

};

extern "C" SchemaPlugin* loadPlugin();

#endif // SCHEMAPLUGIN_H
