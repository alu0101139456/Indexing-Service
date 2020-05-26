#include <QCoreApplication>
#include <QUrl>
#include <actormanager.h>
#include "httpgetter.h"
#include "indexingservice.h"

const auto REMOTE_OBJECT_NAME = QStringLiteral("local:indexing-service");
const auto REMOTE_OBJECT_REGISTRY = QStringLiteral("local:registry");

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QRemoteObjectRegistryHost registryNode (REMOTE_OBJECT_REGISTRY);
    QRemoteObjectHost indexingServiceNode (REMOTE_OBJECT_NAME, REMOTE_OBJECT_REGISTRY);

    ActorManager::makeActorManager();
    IndexingService indexingService;

    indexingServiceNode.enableRemoting(&indexingService);

    return a.exec();
}
