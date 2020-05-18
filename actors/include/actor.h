#ifndef ACTOR_H
#define ACTOR_H

#include <memory>
#include <QObject>
#include <QThread>
#include <QVariant>
#include <functional>
//#include "actorthread.h"
#include <actors_global.h>

class ActorThread;

template <typename Message>
class MailBox;

class ACTORS_EXPORT Actor : public QObject
{
    Q_OBJECT

public:
    using ActorMessage = std::function<void ()>;
    using ActorMailBox = MailBox<ActorMessage>;

    explicit Actor(Actor* parent);
    ~Actor();

    bool delivery_from (Actor* sender , const QString& message, const QVariant& arg0 = QVariant(),
                        const QVariant& arg1 = QVariant(), const QVariant& arg2 = QVariant(), const QVariant& arg3 = QVariant(),
                        const QVariant& arg4 = QVariant(), const QVariant& arg5 = QVariant(), const QVariant& arg6 = QVariant(),
                        const QVariant& arg7 = QVariant(), const QVariant& arg8 = QVariant(), const QVariant& arg9 = QVariant());

protected:

    bool send (Actor* receiver, const QString& message, const QVariant& arg0 = QVariant(),
               const QVariant& arg1 = QVariant(), const QVariant& arg2 = QVariant(), const QVariant& arg3 = QVariant(),
               const QVariant& arg4 = QVariant(), const QVariant& arg5 = QVariant(), const QVariant& arg6 = QVariant(),
               const QVariant& arg7 = QVariant(), const QVariant& arg8 = QVariant(), const QVariant& arg9 = QVariant());

    bool reply(const QString& message, const QVariant& arg0 = QVariant(),
               const QVariant& arg1 = QVariant(), const QVariant& arg2 = QVariant(), const QVariant& arg3 = QVariant(),
               const QVariant& arg4 = QVariant(), const QVariant& arg5 = QVariant(), const QVariant& arg6 = QVariant(),
               const QVariant& arg7 = QVariant(), const QVariant& arg8 = QVariant(), const QVariant& arg9 = QVariant());

private:

    Actor* sender_ = nullptr;
    ActorThread*  thread_;

    std::unique_ptr<ActorMailBox> mailbox_;

    friend ActorThread;

    bool processMessage();

public Q_SLOTS:
};

#endif // ACTOR_H
