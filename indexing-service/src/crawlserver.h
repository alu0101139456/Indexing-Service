#ifndef CRALWSERVER_H
#define CRALWSERVER_H

#include <actor.h>

class CrawlServer : public Actor
{
    Q_OBJECT
public:
    explicit CrawlServer(Actor* parent);

public Q_SLOTS:
    void crawlRequest(const QUrl& url, int depth); //Desde cliente

    void result(const QUrl& url, const QList<QVariant>& links); //Desde el LinkChecker.

};

#endif // CRALWSERVER_H
