#ifndef HTTPGETTER_H
#define HTTPGETTER_H

#include <actor.h>

class HttpGetter : public Actor
{
    Q_OBJECT
public:
    explicit HttpGetter(Actor* parent);
    ~HttpGetter();

public Q_SLOTS:
    void request(const QUrl& url, int depth); //Desde el Linkcheker

Q_SIGNALS:
    void checkUrl (const QUrl& url, int depth);

};

#endif // HTTPGETTER_H
