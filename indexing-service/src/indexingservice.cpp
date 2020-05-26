#include "indexingservice.h"

IndexingService::IndexingService()
{
    getter_ = ActorManager::spawn<HttpGetter>();
}

void IndexingService::request(const QUrl &url, int depth)
{
    ActorManager::send(getter_, "request", url, depth);
}
