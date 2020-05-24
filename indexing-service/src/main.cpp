#include <QCoreApplication>

#include "curlfetcher.h"




int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    CurlFetcher fetcher;

    auto result = fetcher.fetchUrl("http://www.ull.es");
    return a.exec();
}
