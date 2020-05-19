#include <actor.h>
#include <actormanager.h>

ActorManager* ActorManager::instance_ = nullptr;

ActorManager::ActorManager(QObject *parent)
    : QObject(parent), rootActor_(new Actor(nullptr))
{

}

ActorManager::~ActorManager() = default;

ActorManager *ActorManager::instance()
{
    if (!instance_) {
        instance_ = new ActorManager();
    }
    return instance_;
}

bool ActorManager::send(Actor *receiver, const QString &message, const QVariant &arg0,
                        const QVariant &arg1, const QVariant &arg2, const QVariant &arg3,
                        const QVariant &arg4, const QVariant &arg5, const QVariant &arg6,
                        const QVariant &arg7, const QVariant &arg8, const QVariant &arg9)
{
    return receiver->delivery_from(nullptr, message, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
}
