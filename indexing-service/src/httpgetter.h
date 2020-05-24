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


};

#endif // HTTPGETTER_H
