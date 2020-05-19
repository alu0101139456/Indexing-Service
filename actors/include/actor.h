#ifndef ACTOR_H
#define ACTOR_H

#include <memory>
#include <QObject>
#include <QThread>
#include <QVariant>
#include <functional>
//#include "actorthread.h"
#include <actors_global.h>
#include <actormanager.h>

class ActorThread;
class ActorManager;

template <typename Message>
class MailBox;

class ACTORS_EXPORT Actor : public QObject
{
    Q_OBJECT

public:
    using ActorMessage = std::function<void ()>;
    using ActorMailBox = MailBox<ActorMessage>;

    ~Actor();

    bool delivery_from (Actor* sender , const QString& message, const QVariant& arg0 = QVariant(),
                        const QVariant& arg1 = QVariant(), const QVariant& arg2 = QVariant(), const QVariant& arg3 = QVariant(),
                        const QVariant& arg4 = QVariant(), const QVariant& arg5 = QVariant(), const QVariant& arg6 = QVariant(),
                        const QVariant& arg7 = QVariant(), const QVariant& arg8 = QVariant(), const QVariant& arg9 = QVariant());

protected:

    explicit Actor(Actor* parent);

    bool send (Actor* receiver, const QString& message, const QVariant& arg0 = QVariant(),
               const QVariant& arg1 = QVariant(), const QVariant& arg2 = QVariant(), const QVariant& arg3 = QVariant(),
               const QVariant& arg4 = QVariant(), const QVariant& arg5 = QVariant(), const QVariant& arg6 = QVariant(),
               const QVariant& arg7 = QVariant(), const QVariant& arg8 = QVariant(), const QVariant& arg9 = QVariant());

    bool reply(const QString& message, const QVariant& arg0 = QVariant(),
               const QVariant& arg1 = QVariant(), const QVariant& arg2 = QVariant(), const QVariant& arg3 = QVariant(),
               const QVariant& arg4 = QVariant(), const QVariant& arg5 = QVariant(), const QVariant& arg6 = QVariant(),
               const QVariant& arg7 = QVariant(), const QVariant& arg8 = QVariant(), const QVariant& arg9 = QVariant());

    template <typename ActorClass>
    ActorClass* spawn();

private:

    Actor* sender_ = nullptr;
    ActorThread*  thread_;

    std::unique_ptr<ActorMailBox> mailbox_;

    friend ActorThread;
    friend ActorManager;

    bool processMessage();
};

template <typename ActorClass>
ActorClass *Actor::spawn()
{
    return ActorManager::instance()->spawn<ActorClass>(this);
}

#endif // ACTOR_H
