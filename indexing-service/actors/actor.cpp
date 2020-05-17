#include "actor.h"

Actor::Actor(Actor* parent) : QObject(parent)
{
}

bool Actor::delivery_from(Actor *sender /*, const Message& msg */)
{
    sender_ = sender;
    // TODO: Entregar el mensaje al mailbox
}

bool Actor::send(Actor *receiver /*, const Message& msg */)
{
    return receiver->delivery_from(this /*, msg */);
}

bool Actor::reply(/* const Message& msg */)
{
    if (sender_) {
        return send(sender_ /*, msg */);
    }
    return false;
}
