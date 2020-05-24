#include <QCoreApplication>
#include <QUrl>
#include <actormanager.h>
#include "curlfetcher.h"
#include "httpgetter.h"
#include "httpfecthplugin.h"
#include <dlfcn.h>

class FindPlugins {
 public:
    FindPlugins();

    void find("./extensions");
    void load(std::string path) {
        void* handle = dlopen(path.c_str(), RTLD_LAZY );

        typedef HttpFetchPlugin (*Function)(int);
        Function fn = reinterpret_cast<Function>(dlsym(handle, "makeHttpFetchPlugin"));
        if (fn != nullptr)
            HttpFetchPlugin(10);
    }


 private:
    std::vector<std::string> pluginsPath;
};

// ------------------
char** suppertedSchema(); //http, https, ftp

const char* fetch(const char* url);
// ------------------

class httpSchemaPlugin {
 public:
    httpSchemaPlugin();
    std::vector<std::string> supportedSchema();

    std::vector<uint8_t> fecthUrl(const std::string& url);

};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ActorManager::makeActorManager();

    auto getter = ActorManager::spawn<HttpGetter>();
    ActorManager::send(getter, "request", QUrl("http://www.ull.es"), 1);

    return a.exec();
}
