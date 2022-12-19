#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "curl.h"

int curl_ping(const char *domain_addr)
{
    CURLcode res;
    CURL *curl;

    curl = curl_easy_init();
    if (!curl) {
        LOGE(DEBUG_NETWORK, "curl_easy_init fail");
        return WIFI_PROC_ERR_CHECK;
    }

    curl_easy_setopt(curl, CURLOPT_URL, INTERNET_DOMAIN_NAME);
    curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);    //做下载请求，而不会得到正文
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 1L);   //设置超时时间s
    //curl_easy_setopt(curl, CURLOPT_TIMEOUT_MS, 500L);
    res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);
    if (res != 0) {
        LOGE(DEBUG_NETWORK, "curl %s fail, errcode:%d", domain_name, res);
        return -1;
    } else {
        LOGI(DEBUG_NETWORK, "curl %s success", domain_name);
        return 0;
    }
}

