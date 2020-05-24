#include "crawlserver.h"

CrawlServer::CrawlServer(Actor* parent)
    : Actor(parent)
{

}

void CrawlServer::crawlRequest(const QUrl &url, int depth)
{
    //TODO: Comprobar si la URL ya está siendo atendida. Si es así, apuntar al cliente para la respuesta.
    // Si no es así, crear LinkChecker y pedirle que procese la URL
}

void CrawlServer::result(const QUrl &url, const QList<QVariant> &links)
{
    //TODO: Responder a cada cliente pendiente de la petición con la lista de enlaces.
    // Message crawlResponse(url, links)
}
