#include <Additional/request.h>
#include <locale>
#include <codecvt>
#include <vector>

#pragma camment winhttp
#pragma comment(lib, "winhttp.lib")
[[maybe_unused]] std::string Request::get_query_param(const Request& request, const std::string& param_name) const {
    std::wstring urlWide = std::wstring(Request::path.begin(), Request::path.end());
    urlWide += L"?";
    urlWide += std::wstring(Request::query_params.begin(), Request::query_params.end());

    HINTERNET hSession = WinHttpOpen(L"User-Agent", WINHTTP_ACCESS_TYPE_DEFAULT_PROXY, WINHTTP_NO_PROXY_NAME, WINHTTP_NO_PROXY_BYPASS, 0);
    if (hSession) {
        HINTERNET hConnect = WinHttpOpenRequest(hSession, L"GET", urlWide.c_str(), nullptr, WINHTTP_NO_REFERER, WINHTTP_DEFAULT_ACCEPT_TYPES, 0);
        if (hConnect) {

            if (WinHttpSendRequest(hConnect, WINHTTP_NO_ADDITIONAL_HEADERS, 0, WINHTTP_NO_REQUEST_DATA, 0, 0, 0)) {
                if (WinHttpReceiveResponse(hConnect, nullptr)) {
                    DWORD bytesRead = 0;
                    std::vector<char> buffer(4096, '\0');
                    std::string response;

                    while (WinHttpReadData(hConnect, &buffer[0], buffer.size(), &bytesRead) && bytesRead > 0) {
                        response.append(buffer.begin(), buffer.begin() + bytesRead);
                    }

                    std::unordered_map<std::string, std::string> params = parse_query_params(response);
                    auto it = params.find(param_name);
                    if (it != params.end()) {
                        return it->second;
                    }
                }
            }


            WinHttpCloseHandle(hConnect);
        }


        WinHttpCloseHandle(hSession);
    }

    return "";
}

[[maybe_unused]] std::string Request::get_path_param(const std::string& param_name) {
    std::wstring urlWide = std::wstring(path.begin(), path.end());
    HINTERNET hSession = WinHttpOpen(L"User-Agent", WINHTTP_ACCESS_TYPE_DEFAULT_PROXY, WINHTTP_NO_PROXY_NAME, WINHTTP_NO_PROXY_BYPASS, 0);
    if (hSession) {
        HINTERNET hConnect = WinHttpOpenRequest(hSession, L"GET", urlWide.c_str(), nullptr, WINHTTP_NO_REFERER, WINHTTP_DEFAULT_ACCEPT_TYPES, 0);
        if (hConnect) {
            if (WinHttpSendRequest(hConnect, WINHTTP_NO_ADDITIONAL_HEADERS, 0, WINHTTP_NO_REQUEST_DATA, 0, 0, 0)) {
                if (WinHttpReceiveResponse(hConnect, nullptr)) {
                    DWORD bytesRead = 0;
                    std::vector<char> buffer(4096, '\0');
                    std::string response;
                    while (WinHttpReadData(hConnect, &buffer[0], buffer.size(), &bytesRead) && bytesRead > 0) {
                        response.append(buffer.begin(), buffer.begin() + bytesRead);
                    }
                    std::unordered_map<std::string, std::string> params = parse_path_params(response);
                    auto it = params.find(param_name);
                    if (it != params.end()) {
                        return it->second;
                    }
                }
            }
            WinHttpCloseHandle(hConnect);
        }
        WinHttpCloseHandle(hSession);
    }
    return "";
}

[[maybe_unused]] std::string Request::get_header(const std::string& header_name) {

    std::wstring urlWide = std::wstring(path.begin(), path.end());
    urlWide += L"?";
    urlWide += std::wstring(query_params.begin(), query_params.end());


    HINTERNET hSession = WinHttpOpen(L"User-Agent", WINHTTP_ACCESS_TYPE_DEFAULT_PROXY, WINHTTP_NO_PROXY_NAME, WINHTTP_NO_PROXY_BYPASS, 0);
    if (hSession) {
        HINTERNET hConnect = WinHttpOpenRequest(hSession, L"GET", urlWide.c_str(), nullptr, WINHTTP_NO_REFERER, WINHTTP_DEFAULT_ACCEPT_TYPES, 0);
        if (hConnect) {

            if (WinHttpSendRequest(hConnect, WINHTTP_NO_ADDITIONAL_HEADERS, 0, WINHTTP_NO_REQUEST_DATA, 0, 0, 0)) {
                if (WinHttpReceiveResponse(hConnect, nullptr)) {
                    DWORD bytesRead = 0;
                    std::vector<char> buffer(4096, '\0');
                    std::string response;


                    while (WinHttpReadData(hConnect, &buffer[0], buffer.size(), &bytesRead) && bytesRead > 0) {
                        response.append(buffer.begin(), buffer.begin() + bytesRead);
                    }


                    std::unordered_map<std::string, std::string> headersMap = parse_headers(response);
                    auto it = headersMap.find(header_name);
                    if (it != headersMap.end()) {
                        return it->second;
                    }
                }
            }


            WinHttpCloseHandle(hConnect);
        }


        WinHttpCloseHandle(hSession);
    }

    return "";
}

[[maybe_unused]] std::unordered_map<std::string, std::string> Request::get_query_params() {
    return parse_query_params(query_params);
}

[[maybe_unused]] std::unordered_map<std::string, std::string> Request::get_path_params() {
    return parse_path_params(path);
}

[[maybe_unused]] std::unordered_map<std::string, std::string> Request::get_headers() {
    return parse_headers(query_params);
}

[[maybe_unused]] bool Request::has_query_param(const std::string& param_name) {
    std::unordered_map<std::string, std::string> params = parse_query_params(query_params);
    return params.find(param_name) != params.end();
}

[[maybe_unused]] bool Request::has_path_param(const std::string& param_name) {
    std::unordered_map<std::string, std::string> params = parse_path_params(path);

    return params.find(param_name) != params.end();
}

[[maybe_unused]] bool Request::has_header(const std::string& header_name) {
    std::unordered_map<std::string, std::string> headers = parse_headers(query_params);

    return headers.find(header_name) != headers.end();
}

[[maybe_unused]] std::string Request::get_body() const {
    return body;
}

[[maybe_unused]]  std::unordered_map<std::string, std::string> Request::get_cookies() const {
    std::unordered_map<std::string, std::string> cookies;


    std::unordered_map<std::string, std::string> requestHeaders = parse_headers(query_params);


    auto it = requestHeaders.find("Cookie");
    if (it != requestHeaders.end()) {
        std::wstring cookieHeader = std::wstring(it->second.begin(), it->second.end());


        HINTERNET hSession = WinHttpOpen(L"User-Agent", WINHTTP_ACCESS_TYPE_DEFAULT_PROXY, WINHTTP_NO_PROXY_NAME, WINHTTP_NO_PROXY_BYPASS, 0);
        if (hSession) {
            HINTERNET hConnect = WinHttpOpenRequest(hSession, L"GET", L"/", nullptr, WINHTTP_NO_REFERER, WINHTTP_DEFAULT_ACCEPT_TYPES, 0);
            if (hConnect) {

                if (WinHttpSendRequest(hConnect, cookieHeader.c_str(), 0, WINHTTP_NO_REQUEST_DATA, 0, 0, 0)) {
                    if (WinHttpReceiveResponse(hConnect, nullptr)) {
                        DWORD bufferSize = 0;
                        WinHttpQueryHeaders(hConnect, WINHTTP_QUERY_SET_COOKIE, WINHTTP_HEADER_NAME_BY_INDEX, nullptr, &bufferSize, WINHTTP_NO_HEADER_INDEX);
                        if (GetLastError() == ERROR_INSUFFICIENT_BUFFER) {
                            std::wstring cookieBuffer(bufferSize / sizeof(wchar_t), L'\0');
                            if (WinHttpQueryHeaders(hConnect, WINHTTP_QUERY_SET_COOKIE, WINHTTP_HEADER_NAME_BY_INDEX, &cookieBuffer[0], &bufferSize, WINHTTP_NO_HEADER_INDEX)) {
                                std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
                                std::string cookieStr = converter.to_bytes(cookieBuffer);

                                parse_cookies(cookieStr, cookies);
                            }
                        }
                    }
                }
                WinHttpCloseHandle(hConnect);
            }
            WinHttpCloseHandle(hSession);
        }
    }

    return cookies;
}