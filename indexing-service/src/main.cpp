#include <QCoreApplication>
#include <QUrl>
#include <actormanager.h>
#include "httpgetter.h"
#include "indexingservice.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QUrl UrlRegistry = QUrl(QStringLiteral("local:registry"));
    QUrl UrlIndexingServiceNode = QUrl(QStringLiteral("local:indexing-service"));

    QRemoteObjectRegistryHost registryNode (UrlRegistry);
    QRemoteObjectHost indexingServiceNode (UrlIndexingServiceNode, UrlRegistry);

    ActorManager::makeActorManager();
    IndexingService indexingService;

    indexingServiceNode.enableRemoting(&indexingService);

    return a.exec();
}
