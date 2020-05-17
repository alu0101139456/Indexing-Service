#ifndef ACTOR_H
#define ACTOR_H

#include <QObject>
#include <QThread>

#include "actors_global.h"

class ACTORS_EXPORT Actor : public QObject
{
    Q_OBJECT

public:
    explicit Actor(Actor* parent);

    bool delivery_from (Actor* sender /*, const Message& msg */);

protected:

    bool send (Actor* receiver /*, const Message& msg */);
    bool reply(/* const Message& msg */);

private:
    // Mailbox<Message> mailbox_;
    Actor* sender_ = nullptr;
    QThread* thread_;

public Q_SLOTS:
};

#endif // ACTOR_H
