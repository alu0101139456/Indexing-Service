#include <curl/curl.h>
#include "curlfetcher.h"
#include <optional>

std::atomic_int CurlFetcher::instanceCounter_ = 0;

CurlFetcher::CurlFetcher()
{
    if(instanceCounter_.fetch_add(1, std::memory_order_acquire) == 0) {
        curl_global_init(CURL_GLOBAL_ALL);
    }
}

CurlFetcher::~CurlFetcher()
{
    if(instanceCounter_.fetch_sub(1, std::memory_order_acquire) == 1) {
        curl_global_cleanup();
    }
}

std::optional<CurlFetcher::FetchInfo>  CurlFetcher::fetchUrl(const std::string &url)
{
    FetchInfo info;
    CURL* curl_handle = curl_easy_init();

    curl_easy_setopt(curl_handle, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl_handle, CURLOPT_VERBOSE, 1L);
    curl_easy_setopt(curl_handle, CURLOPT_NOPROGRESS, 1L);
    curl_easy_setopt(curl_handle, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, curlWriteCallback);
    curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, &info);

    auto result = curl_easy_perform(curl_handle);
    if( result != CURLE_OK || result != CURLE_WRITE_ERROR ) {
        return {};
    }
        // TODO: Manejar error

    char* contentType = nullptr;
    curl_easy_getinfo(curl_handle, CURLINFO_CONTENT_TYPE, &contentType);
    info.contentType = contentType;

    curl_easy_cleanup(curl_handle);

    return info;
}

size_t CurlFetcher::curlWriteCallback(char *ptr, size_t, size_t nmemb, void *userdata)
{
    auto info = static_cast<FetchInfo*>(userdata);
    if(nmemb != 0) {
        info->content.insert(info->content.end(), ptr, ptr + nmemb);
    }
    return nmemb;
}
