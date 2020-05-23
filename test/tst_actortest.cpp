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
    /* TODO:                                            CREAR CLASES TESTEO POR CLASES A TESTEAR
    void senderIsNullWhenNoMessage();
    void senderIsSetWhenMessageArrives();
    void slotCanReplyToSenderActor();

    //Actor::unknownMessage(c const QString& message);
    void slotIsCalledWhenUnkownMessage();

    Actor::kill(); ActorManager::kill(Actor* actor);
    void actorKillItSelfWhenIsRequest();

    void actorIsNotifiedWhenChildFailds();

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
    actorA_ = ActorManager::instance()->spawn<TestActor>();
    actorB_ = ActorManager::instance()->spawn<TestActor>();
}

void actortest::cleanupTestCase()
{
    // ActorManager::kill(actorA_);
    // ActorManager::kill(actorB_);
}

void actortest::slotIsCalledWhenMessageIsSend()
{
    int arg = 10;
    QVERIFY(actorA_->testSend(actorB_, "updateIntProperty", arg));
    QTest::qWait(100); //hay que tener siempre en cuenta el tiempo porque son hilos y estan vivos
    QVERIFY(actorB_->property("intProperty").canConvert<int>());
    QCOMPARE(actorB_->property("intProperty").toInt(), arg);
}

QTEST_MAIN(actortest)

#include "tst_actortest.moc"
