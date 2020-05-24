#include <QUrl>
#include <QDebug>
#include "httpgetter.h"
#include "curlfetcher.h"

#include "Document.h"
#include "Node.h"

HttpGetter::HttpGetter(Actor* parent)
    : Actor(parent)
{

}

HttpGetter::~HttpGetter() {

}

void HttpGetter::request(const QUrl &url, int depth)
{

    CurlFetcher fectcher;

    auto info = fectcher.fetchUrl(url.toString().toStdString());

    if( !info || info.value().contentType.find("text/html",0) == std::string::npos) {
        reply("done");
        kill();
        return;
    }
    auto content = std::string(reinterpret_cast<char*>(info.value().content.data()), info.value().content.size());
    info.value().content.clear();

    CDocument doc;
    doc.parse(content);
    CSelection elements = doc.find("[href], [src]");
    for(size_t i =0; i < elements.nodeNum(); ++i) {
        auto node = elements.nodeAt(i);
        auto hrefAttribute = node.attribute("href");
        auto srcAttribute =node.attribute("stc");
        if( !hrefAttribute.empty()) {
            reply("checkUrl", url.resolved(QString::fromStdString(hrefAttribute)), depth);
            qDebug() << "HttpGetter: URL encontrada " << url.resolved(QString::fromStdString(hrefAttribute));
        }
        if( !srcAttribute.empty()) {
            reply("checkUrl", url.resolved(QString::fromStdString(srcAttribute)), depth);
            qDebug() << "HttpGetter: URL encontrada " << url.resolved(QString::fromStdString(srcAttribute));
        }

    }

    reply("done");
    kill();

}