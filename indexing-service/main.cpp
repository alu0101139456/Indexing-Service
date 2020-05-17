#include <QCoreApplication>

#include <actor.h>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Actor actor(nullptr);


    return a.exec();
}
