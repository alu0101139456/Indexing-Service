#include <QUrl>
#include "httpgetter.h"
#include "curlfetcher.h"


HttpGetter::HttpGetter(Actor* parent)
    : Actor(parent)
{

}

HttpGetter::~HttpGetter() {

}

void HttpGetter::request(const QUrl &url, int depth)
{
    // TODO: Descargar la URL y buscar URL
    CurlFetcher fectcher;

    auto info = fectcher.fetchUrl(url.toString().toStdString());

    // Gumpo-parse
    // QGumpoParaser
}
