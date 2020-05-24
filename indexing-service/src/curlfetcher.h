#ifndef CURLFETCHER_H
#define CURLFETCHER_H

#include <string>
#include <atomic>
#include <vector>
#include <optional>

class CurlFetcher
{
public:
    struct FetchInfo {
        std::vector<uint8_t> content;
        std::string contentType;
    };

    CurlFetcher();
    ~CurlFetcher();

    std::optional<FetchInfo> fetchUrl(const std::string& url);

private:
    static std::atomic_int instanceCounter_;

    static size_t curlWriteCallback(char* ptr, size_t size, size_t nmemb, void *userdata);

};

#endif // CURLFETCHER_H
