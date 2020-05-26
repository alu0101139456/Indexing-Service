#ifndef HTTPSCHEMAPLUGIN_H
#define HTTPSCHEMAPLUGIN_H

#include <schemaplugin.h>
#include <atomic>

class HttpSchemaPlugin : public SchemaPlugin
{
public:
    HttpSchemaPlugin();
    virtual ~HttpSchemaPlugin();

    virtual std::optional<FetchInfo> fetchUrl(const std::string& url) override;

    virtual std::vector<std::string> schemaSupported () override;

private:
    static std::atomic_int instanceCounter_;

    static size_t curlWriteCallback(char* ptr, size_t size, size_t nmemb, void *userdata);
};

#endif // HTTPSCHEMAPLUGIN_H
