#include <Additional/Header.h>

void Header::set_value(std::basic_string<wchar_t> header_name, std::basic_string<wchar_t> header_value) {
}

std::string Header::get_value(const std::string& header_name) const {

    const char *it;
    it = reinterpret_cast<const char *>(headers.find(header_name));
    return reinterpret_cast<const char *>(&it);
}

[[maybe_unused]] bool Header::has_header(const std::string& header_name) const {
    HINTERNET hSession = WinHttpOpen(L"WinHTTP Example/1.0", WINHTTP_ACCESS_TYPE_DEFAULT_PROXY, WINHTTP_NO_PROXY_NAME, WINHTTP_NO_PROXY_BYPASS, 0);

    if (hSession) {
        HINTERNET hConnect = WinHttpOpenRequest(hSession, L"HEAD", L"http://www.example.com", nullptr, WINHTTP_NO_REFERER, WINHTTP_DEFAULT_ACCEPT_TYPES, 0);

        if (hConnect) {
            std::wstring headersString;




            if (WinHttpAddRequestHeaders(hConnect, headersString.c_str(), headersString.length(), WINHTTP_ADDREQ_FLAG_REPLACE)) {

                if (WinHttpSendRequest(hConnect, WINHTTP_NO_ADDITIONAL_HEADERS, 0, WINHTTP_NO_REQUEST_DATA, 0, 0, 0)) {
                    if (WinHttpReceiveResponse(hConnect, nullptr)) {
                        DWORD statusCode = 0;
                        DWORD statusCodeSize = sizeof(DWORD);


                        if (WinHttpQueryHeaders(hConnect, WINHTTP_QUERY_STATUS_CODE | WINHTTP_QUERY_FLAG_NUMBER, NULL, &statusCode, &statusCodeSize, NULL)) {

                            return statusCode == HTTP_STATUS_OK;
                        }
                    }
                }
            }


            WinHttpCloseHandle(hConnect);
        }

        WinHttpCloseHandle(hSession);
    }

    return false;
}

void Header::remove_header(
        __gnu_cxx::__normal_iterator<std::basic_string<char, std::char_traits<char>, std::allocator<char>>::const_pointer, std::basic_string<char, std::char_traits<char>, std::allocator<char>>> header_name) {
    headers.erase(header_name);
}

[[maybe_unused]] const std::basic_string<char> Header::get_all_headers() const {
    return headers;
}

std::string Header::serialize() const {
    std::ostringstream serializedHeaders;

    for (const auto &entry: headers)


    return serializedHeaders.str();
}

[[maybe_unused]] Header Header::parse(const std::string& headers_string) {
    Header parsedHeaders;


    HINTERNET hSession = WinHttpOpen(L"WinHTTP Example/1.0", WINHTTP_ACCESS_TYPE_DEFAULT_PROXY, WINHTTP_NO_PROXY_NAME, WINHTTP_NO_PROXY_BYPASS, 0);

    if (hSession) {
        HINTERNET hRequest = WinHttpOpenRequest(hSession, L"GET", L"/", nullptr, WINHTTP_NO_REFERER, WINHTTP_DEFAULT_ACCEPT_TYPES, 0);

        if (hRequest) {
            if (WinHttpAddRequestHeaders(hRequest, reinterpret_cast<LPCWSTR>(headers_string.c_str()), headers_string.length(), WINHTTP_ADDREQ_FLAG_ADD)) {
                if (WinHttpSendRequest(hRequest, WINHTTP_NO_ADDITIONAL_HEADERS, 0, WINHTTP_NO_REQUEST_DATA, 0, 0, 0)) {
                    if (WinHttpReceiveResponse(hRequest, NULL)) {
                        DWORD bufferSize = 0;
                        WinHttpQueryHeaders(hRequest, WINHTTP_QUERY_RAW_HEADERS_CRLF, WINHTTP_HEADER_NAME_BY_INDEX, nullptr, &bufferSize, WINHTTP_NO_HEADER_INDEX);

                        if (GetLastError() == ERROR_INSUFFICIENT_BUFFER) {
                            std::vector<wchar_t> buffer(bufferSize / sizeof(wchar_t), L'\0');

                            if (WinHttpQueryHeaders(hRequest, WINHTTP_QUERY_RAW_HEADERS_CRLF, WINHTTP_HEADER_NAME_BY_INDEX, &buffer[0], &bufferSize, WINHTTP_NO_HEADER_INDEX)) {
                                std::wistringstream iss(std::wstring(buffer.begin(), buffer.end()));
                                std::wstring line;

                                while (std::getline(iss, line)) {
                                    size_t separatorPos = line.find(L':');

                                    if (separatorPos != std::wstring::npos) {
                                        std::wstring headerName = line.substr(0, separatorPos);
                                        std::wstring headerValue = line.substr(separatorPos + 1);
                                        parsedHeaders.set_value(std::wstring(headerName), std::wstring(headerValue));
                                    }
                                }
                            }
                        }
                    }
                }
            }


            WinHttpCloseHandle(hRequest);
        }


        WinHttpCloseHandle(hSession);
    }

    return parsedHeaders;
}



