#ifndef TESTACTOR_H
#define TESTACTOR_H

#include <actor.h>

class TestActor : public Actor
{
    Q_OBJECT
    Q_PROPERTY(int intProperty MEMBER intProperty_);

public:
    TestActor(Actor* parent) : Actor(parent) {}

    bool testSend (Actor* receiver, const QString& message, const QVariant& arg) {
        return send(receiver, message, arg);
    }

public Q_SLOTS:
    void updateIntProperty(int arg) {
        intProperty_ = arg;
    }

private:
    int intProperty_;
};

#endif // TESTACTOR_H
