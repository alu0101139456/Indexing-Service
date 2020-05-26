#ifndef INDEXINGSERVICE_H
#define INDEXINGSERVICE_H

#include <rep_indexingservice_source.h>
#include "httpgetter.h"

class IndexingService : public IndexingServiceSimpleSource
{
    Q_OBJECT

public:
    IndexingService();

    virtual void request (const QUrl& url, int depth) override;

public Q_SLOTS:
    void results(const QUrl &url, int depth);

private:
    HttpGetter* getter_;
};

#endif // INDEXINGSERVICE_H
