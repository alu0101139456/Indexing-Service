#include "linkchecker.h"

LinkChecker::LinkChecker(Actor* parent)
    :Actor(parent)
{
}

void LinkChecker::request(const QUrl &url, int depth)
{
    //TODO: Crear un HttpGetter y pedirle que procese la URL.
}

void LinkChecker::checkUrl(const QUrl &url, int depth)
{
    //TODO: Comprobar si la URL ya a sido procesada por un Getter. En caso afirmativo, lo ignoramos.
    //En caso negativo, crear un HttpGetter y pedirle que procese la URL con depth -1.
    //Si depth == 0, guarda la URL pero no procesarla
}

void LinkChecker::done()
{
    //TODO: Comprobar si es el último HttpGetter. Si es así, mandar la lista de URL al CrawlServer.
    //la respuesta es Result
}
