#ifndef ACTOR_H
#define ACTOR_H

#include <QObject>
#include <QThread>

//#include "actorthread.h"
#include <actors_global.h>

class ActorThread;

class ACTORS_EXPORT Actor : public QObject
{
    Q_OBJECT

public:
    explicit Actor(Actor* parent);
    ~Actor();

    bool delivery_from (Actor* sender /*, const Message& msg */);

protected:

    bool send (Actor* receiver /*, const Message& msg */);
    bool reply(/* const Message& msg */);

private:
    // Mailbox<Message> mailbox_;
    Actor* sender_ = nullptr;
    ActorThread*  thread_;

    friend ActorThread;

    bool processMessage();

public Q_SLOTS:
};

#endif // ACTOR_H
