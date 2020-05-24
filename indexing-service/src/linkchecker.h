#ifndef LINKCHECKER_H
#define LINKCHECKER_H

#include <actor.h>

class LinkChecker : public Actor
{
    Q_OBJECT
public:
    explicit LinkChecker(Actor* actor);

public Q_SLOTS:
    void request(const QUrl& url, int depth); //Desde el servidor

    void checkUrl(const QUrl& url, int depth); //Desde HttpGetter

    void done(); //Desde HttpGetter

};

#endif // LINKCHECKER_H
