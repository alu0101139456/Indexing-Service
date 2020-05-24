#include <actormanager.h>
#include <actor.h>
#include "actorthread.h"
#include "mailbox.h"

#include <QDebug>


Actor::Actor(Actor* parent)
    : QObject(parent), done_(false)
{
    mailbox_ = std::make_unique<ActorMailBox>();
    thread_ = new ActorThread(this);
    thread_->start();
}

Actor::~Actor() { //para que el mailbox pueda ser opcaco
    if (!thread_->isFinished()) {
        qCritical() << "Se ha intentado destruir un actor no detenido: " << this;
    }
}

bool Actor::delivery_from(Actor *sender, const QString& message, const QVariant& arg0,
                          const QVariant& arg1, const QVariant& arg2, const QVariant& arg3,
                          const QVariant& arg4, const QVariant& arg5, const QVariant& arg6,
                          const QVariant& arg7, const QVariant& arg8, const QVariant& arg9)
{
    mailbox_->push([this, sender, message, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9]() {
        sender_ = sender;
        bool success = QMetaObject::invokeMethod(this, message.toLocal8Bit(), Qt::DirectConnection,
                                                  QGenericArgument(arg0.typeName(), arg0.data()),
                                                  QGenericArgument(arg1.typeName(), arg1.data()),
                                                  QGenericArgument(arg2.typeName(), arg2.data()),
                                                  QGenericArgument(arg3.typeName(), arg3.data()),
                                                  QGenericArgument(arg4.typeName(), arg4.data()),
                                                  QGenericArgument(arg5.typeName(), arg5.data()),
                                                  QGenericArgument(arg6.typeName(), arg6.data()),
                                                  QGenericArgument(arg7.typeName(), arg7.data()),
                                                  QGenericArgument(arg8.typeName(), arg8.data()),
                                                  QGenericArgument(arg9.typeName(), arg9.data()));
        sender_ = nullptr;
    });

    return true;
}

void Actor::kill()
{
    done_ = true;
}

bool Actor::send(Actor *receiver, const QString& message, const QVariant& arg0,
                 const QVariant& arg1, const QVariant& arg2, const QVariant& arg3,
                 const QVariant& arg4, const QVariant& arg5, const QVariant& arg6,
                 const QVariant& arg7, const QVariant& arg8, const QVariant& arg9)
{
    return receiver->delivery_from(this,message, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
}

bool Actor::reply(const QString& message, const QVariant& arg0,
                  const QVariant& arg1, const QVariant& arg2, const QVariant& arg3,
                  const QVariant& arg4, const QVariant& arg5, const QVariant& arg6,
                  const QVariant& arg7, const QVariant& arg8, const QVariant& arg9)
{
    if (sender_) {
        return send(sender_, message, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
    }
    return false;
}

bool Actor::processMessage()
{
    auto message = mailbox_->pop(std::chrono::milliseconds(100));
    if(!done_ && message) {
        std::invoke(message.value());
    }
    return !done_;
}


