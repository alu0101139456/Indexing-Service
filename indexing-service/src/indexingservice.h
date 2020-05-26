#ifndef INDEXINGSERVICE_H
#define INDEXINGSERVICE_H

#include <rep_indexing-service_source.h>
#include "httpgetter.h"

class IndexingService : public IndexingServiceSimpleSource
{
    Q_OBJECT

public:
    IndexingService();

    virtual void request (const QUrl& url, int depth) override;

private:
    HttpGetter* getter_;
};

#endif // INDEXINGSERVICE_H
