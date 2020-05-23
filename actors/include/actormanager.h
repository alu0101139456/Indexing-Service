#ifndef ACTORMANAGER_H
#define ACTORMANAGER_H

#include <QVariant>

#include "actors_global.h"

class Actor;

class ACTORS_EXPORT ActorManager : public QObject
{
    Q_OBJECT
public:

    static ActorManager* instance();
    ~ActorManager();

    template <typename ActorClass>
    ActorClass* spawn (Actor* parent = nullptr);

//    void kill (Actor* actor);

    bool send (Actor* receiver, const QString& message, const QVariant& arg0 = QVariant(),
               const QVariant& arg1 = QVariant(), const QVariant& arg2 = QVariant(), const QVariant& arg3 = QVariant(),
               const QVariant& arg4 = QVariant(), const QVariant& arg5 = QVariant(), const QVariant& arg6 = QVariant(),
               const QVariant& arg7 = QVariant(), const QVariant& arg8 = QVariant(), const QVariant& arg9 = QVariant());

private:
    //Ocultamos el constructor para obligar a usar instance
    explicit ActorManager(QObject *parent = nullptr);

    static ActorManager* instance_;
    QScopedPointer<Actor, QScopedPointerDeleteLater> rootActor_;
};

template <typename ActorClass>
ActorClass *ActorManager::spawn(Actor *parent)
{
    static_assert(std::is_base_of<Actor, ActorClass>::value);

    return new ActorClass(parent == nullptr ? rootActor_.get() : parent);
}

#endif // ACTORMANAGER_H
