#include <actor.h>
#include "actorthread.h"

Actor::Actor(Actor* parent) : QObject(parent)
{
    thread_ = new ActorThread(this);
    thread_->start();
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

bool Actor::processMessage()
{
//    auto message = mailbox_->pop();
//    TODO: hacer algo con el mensaje

}

Actor::~Actor() {}
