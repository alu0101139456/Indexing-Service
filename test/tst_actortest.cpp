#include <QtTest>
#include <QCoreApplication>

// add necessary includes here

class actortest : public QObject
{
    Q_OBJECT

public:
    actortest();
    ~actortest();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();

};

actortest::actortest()
{

}

actortest::~actortest()
{

}

void actortest::initTestCase()
{

}

void actortest::cleanupTestCase()
{

}

void actortest::test_case1()
{

}

QTEST_MAIN(actortest)

#include "tst_actortest.moc"
