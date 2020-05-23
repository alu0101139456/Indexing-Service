#include <QtTest>
#include <QCoreApplication>

#include "testactor.h"
#include <actormanager.h>


class actortest : public QObject
{
    Q_OBJECT

public:
    actortest();
    ~actortest();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void slotIsCalledWhenMessageIsSend();
    void actorKillItSelfWhenIsRequest();
    void actorIsNotifiedWhenChildFails();
    /* TODO:                                            CREAR CLASES TESTEO POR CLASES A TESTEAR
    void senderIsNullWhenNoMessage();
    void senderIsSetWhenMessageArrives();
    void slotCanReplyToSenderActor();

    //Actor::unknownMessage(c const QString& message);
    void slotIsCalledWhenUnkownMessage();

    Actor::kill(); ActorManager::kill(Actor* actor);



    OPCIONAL --> Testing del ActorManager
    */


private:
    TestActor* actorA_;
    TestActor* actorB_;

};

actortest::actortest()
{

}

actortest::~actortest()
{

}

void actortest::initTestCase()
{
    ActorManager::makeActorManager(this);
    actorA_ = ActorManager::instance()->spawn<TestActor>();
    actorB_ = ActorManager::instance()->spawn<TestActor>();
}

void actortest::cleanupTestCase()
{
    QPointer<TestActor> p = actorA_;

    ActorManager::instance()->kill(actorA_);
    ActorManager::instance()->kill(actorB_);

    while(!p.isNull());
}

void actortest::slotIsCalledWhenMessageIsSend()
{
    int arg = 10;
    QVERIFY(actorA_->testSend(actorB_, "updateIntProperty", arg));
    QTest::qWait(100); //hay que tener siempre en cuenta el tiempo porque son hilos y estan vivos
    QVERIFY(actorB_->property("intProperty").canConvert<int>());
    QCOMPARE(actorB_->property("intProperty").toInt(), arg);
}

void actortest::actorKillItSelfWhenIsRequest() {
    QPointer<TestActor> actor = ActorManager::instance()->spawn<TestActor>();

    QVERIFY(actor->testSend(actor, "die"));
    QTest::qWait(100);
    QVERIFY(actor.isNull());
}

void actortest::actorIsNotifiedWhenChildFails()
{
    auto child = actorA_->spawnChildAndFail();
    auto cleanup = qScopeGuard([child]() {
        ActorManager::instance()->kill(child);
    });
    // Comprobar si actorA_ recibio el mensaje de fail del hijo

// <<--- se destruye cleanup
}

QTEST_MAIN(actortest)

#include "tst_actortest.moc"
