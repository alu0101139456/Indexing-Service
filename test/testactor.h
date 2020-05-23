#ifndef TESTACTOR_H
#define TESTACTOR_H

#include <actor.h>

class TestActor : public Actor
{
    Q_OBJECT
    Q_PROPERTY(int intProperty MEMBER intProperty_);
    Q_PROPERTY(int childHasFailed MEMBER childHasFailed_);

public:
    TestActor(Actor* parent) : Actor(parent) {}

    bool testSend (Actor* receiver, const QString& message, const QVariant& arg) {
        return send(receiver, message, arg);
    }

    bool testSend (Actor* receiver, const QString& message) {
        return send(receiver, message);
    }

    TestActor* spawnChildAndFail() {
        auto child = spawn<TestActor>();
        send(child, "failedTask");
        return child;
    }

public Q_SLOTS:
    void updateIntProperty(int arg) {
        intProperty_ = arg;
    }

    void die () {
        kill();
    }

    // PROPUESTA DE HIMAR
//    void failedTask () {
//        // Este metodo manda un mensaje al padre de que el hijo ha fallado
//        send(parent(), "childFailed");
//    }

private:
    int intProperty_;
    bool childHasFailed_;
};

#endif // TESTACTOR_H
