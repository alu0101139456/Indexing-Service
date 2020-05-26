#include "indexingservice.h"

IndexingService::IndexingService()
{
    getter_ = ActorManager::spawn<HttpGetter>();
    connect(getter_, &HttpGetter::checkUrl, this, &IndexingService::results, Qt::QueuedConnection);
}

void IndexingService::request(const QUrl &url, int depth)
{
    ActorManager::send(getter_, "request", url, depth);
}

void IndexingService::results (const QUrl& url, int depth) {
    Q_EMIT response(url);
}
