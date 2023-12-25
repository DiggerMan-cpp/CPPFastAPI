#include <Additional/Form.h>
#include <vector>
#include <string>


[[maybe_unused]] void Form::add_multi_value_field(const std::string& field_name, const std::vector<std::string>& field_values) {

    HINTERNET hSession = WinHttpOpen(L"User-Agent", WINHTTP_ACCESS_TYPE_DEFAULT_PROXY, WINHTTP_NO_PROXY_NAME, WINHTTP_NO_PROXY_BYPASS, 0);
    if (hSession) {

        HINTERNET hConnect = WinHttpOpenRequest(hSession, L"POST", L"/your/resource/path", nullptr, WINHTTP_NO_REFERER, WINHTTP_DEFAULT_ACCEPT_TYPES, 0);
        if (hConnect) {

            std::wstring content;
            for (const std::string& value : field_values) {
                content += L"\"";
                content += std::wstring(value.begin(), value.end());
                content += L"\" ";
            }

            std::wstring headers = L"Content-Type: application/x-www-form-urlencoded\r\n";

            std::wstring postData = std::wstring(field_name.begin(), field_name.end()) + L"=" + content;


            if (WinHttpSendRequest(hConnect, headers.c_str(), headers.length(), (LPVOID)postData.c_str(), postData.length(), postData.length(), 0)) {
                if (WinHttpReceiveResponse(hConnect, nullptr)) {

                }
            }

            WinHttpCloseHandle(hConnect);
        }
        WinHttpCloseHandle(hSession);
    }
}

[[maybe_unused]] std::vector<std::string> Form::get_multi_value_field([[maybe_unused]] const std::string& field_name) {
    std::vector<std::string> values;


    HINTERNET hSession = WinHttpOpen(L"User-Agent", WINHTTP_ACCESS_TYPE_DEFAULT_PROXY, WINHTTP_NO_PROXY_NAME, WINHTTP_NO_PROXY_BYPASS, 0);
    if (hSession) {

        HINTERNET hConnect = WinHttpOpenRequest(hSession, L"GET", L"/your/resource/path", nullptr, WINHTTP_NO_REFERER, WINHTTP_DEFAULT_ACCEPT_TYPES, 0);
        if (hConnect) {

            if (WinHttpSendRequest(hConnect, WINHTTP_NO_ADDITIONAL_HEADERS, 0, WINHTTP_NO_REQUEST_DATA, 0, 0, 0)) {
                if (WinHttpReceiveResponse(hConnect, nullptr)) {

                    std::vector<char> buffer(4096, '\0');
                    DWORD bytesRead = 0;


                    while (WinHttpReadData(hConnect, &buffer[0], buffer.size(), &bytesRead) && bytesRead > 0) {

                        std::string response(buffer.begin(), buffer.begin() + bytesRead);


                        size_t pos;
                        while ((pos = response.find(',')) != std::string::npos) {
                            std::string value = response.substr(0, pos);
                            values.push_back(value);
                            response.erase(0, pos + 1);
                        }

                        values.push_back(response);
                    }
                }
            }

            WinHttpCloseHandle(hConnect);
        }

        WinHttpCloseHandle(hSession);
    }

    return values;
}


[[maybe_unused]] void Form::remove_multi_value_field(const std::string& field_name) {
    HINTERNET hSession = WinHttpOpen(L"User-Agent", WINHTTP_ACCESS_TYPE_DEFAULT_PROXY, WINHTTP_NO_PROXY_NAME, WINHTTP_NO_PROXY_BYPASS, 0);
    if (hSession) {
        HINTERNET hConnect = WinHttpOpenRequest(hSession, L"DELETE", L"/your/resource/path", nullptr, WINHTTP_NO_REFERER, WINHTTP_DEFAULT_ACCEPT_TYPES, 0);
        if (hConnect) {
            std::wstring headers = L"Content-Type: application/x-www-form-urlencoded\r\n";
            std::wstring postData = std::wstring(field_name.begin(), field_name.end());

            if (WinHttpSendRequest(hConnect, headers.c_str(), headers.length(), (LPVOID)postData.c_str(), postData.length(), postData.length(), 0)) {
                if (WinHttpReceiveResponse(hConnect, nullptr)){
                }
            }
            std::cout << "Debug";
            WinHttpCloseHandle(hConnect);
        }

        WinHttpCloseHandle(hSession);
    }
}

[[maybe_unused]] std::unordered_map<std::string, std::vector<std::string>> Form::get_all_multi_value_fields() {
    std::unordered_map<std::string, std::vector<std::string>> multiValueFields;


    HINTERNET hSession = WinHttpOpen(L"User-Agent", WINHTTP_ACCESS_TYPE_DEFAULT_PROXY, WINHTTP_NO_PROXY_NAME, WINHTTP_NO_PROXY_BYPASS, 0);
    if (hSession) {

        HINTERNET hConnect = WinHttpOpenRequest(hSession, L"GET", L"/your/resource/path", nullptr, WINHTTP_NO_REFERER, WINHTTP_DEFAULT_ACCEPT_TYPES, 0);
        /* *
         * * ----->      @For User Change ! "/your/resource/path"
         * * ----->      @For User Change ! "/your/resource/path"
         * * ----->      @For User Change ! "/your/resource/path"
         * */
        if (hConnect) {

            if (WinHttpSendRequest(hConnect, WINHTTP_NO_ADDITIONAL_HEADERS, 0, WINHTTP_NO_REQUEST_DATA, 0, 0, 0)) {
                if (WinHttpReceiveResponse(hConnect, nullptr)) {

                    std::vector<char> buffer(4096, '\0');
                    DWORD bytesRead = 0;


                    while (WinHttpReadData(hConnect, &buffer[0], buffer.size(), &bytesRead) && bytesRead > 0) {

                        std::string response(buffer.begin(), buffer.begin() + bytesRead);


                        size_t pos = response.find("{\"");
                        while (pos != std::string::npos) {
                            size_t endPos = response.find('}', pos);
                            if (endPos != std::string::npos) {
                                std::string jsonField = response.substr(pos, endPos - pos + 1);


                                std::string fieldName = "example";
                                std::vector<std::string> fieldValues = {"value1", "value2"};

                                multiValueFields[fieldName] = fieldValues;

                                pos = response.find("{\"", endPos);
                            } else {

                                pos = std::string::npos;
                            }
                        }
                    }
                }
            }


            WinHttpCloseHandle(hConnect);
        }


        WinHttpCloseHandle(hSession);
    }

    return multiValueFields;
}

[[maybe_unused]] std::string Form::serialize_multi_value_fields() {
    std::ostringstream serializedData;
    for (const auto& entry : get_all_multi_value_fields()) {
        const std::string& fieldName = entry.first;
        const std::vector<std::string>& fieldValues = entry.second;
        serializedData << fieldName << "=";
        for (size_t i = 0; i < fieldValues.size(); ++i) {
            serializedData << fieldValues[i];
            if (i < fieldValues.size() - 1) {
                serializedData << ",";
            }
        }
        serializedData << "\n";
    }
    return serializedData.str();
}

[[maybe_unused]]void Form::add_file(const std::string& field_name, const std::string& file_path) {

    HINTERNET hSession = WinHttpOpen(L"User-Agent", WINHTTP_ACCESS_TYPE_DEFAULT_PROXY, WINHTTP_NO_PROXY_NAME,
                                     WINHTTP_NO_PROXY_BYPASS, 0);
    if (hSession) {

        HINTERNET hConnect = WinHttpOpenRequest(hSession, L"POST", L"/your/resource/path", nullptr, WINHTTP_NO_REFERER,
                                                WINHTTP_DEFAULT_ACCEPT_TYPES, 0);
        if (hConnect) {

            std::wstring headers = L"Content-Type: multipart/form-data\r\n";

            std::wstring postData = L"--boundary\r\n";
            postData +=
                    L"Content-Disposition: form-data; name=\"" + std::wstring(field_name.begin(), field_name.end()) +
                    L"\"; filename=\"" + std::wstring(file_path.begin(), file_path.end()) + L"\"\r\n";
            postData += L"Content-Type: application/octet-stream\r\n\r\n";

            HANDLE hFile = CreateFile(file_path.c_str(), GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING,
                                      FILE_ATTRIBUTE_NORMAL, nullptr);
            if (hFile != INVALID_HANDLE_VALUE) {
                DWORD bytesRead = 0;
                std::vector<char> buffer(4096, '\0');


                while (ReadFile(hFile, &buffer[0], buffer.size(), &bytesRead, nullptr) && bytesRead > 0) {
                    postData += std::wstring(buffer.begin(), buffer.begin() + bytesRead);
                }


                CloseHandle(hFile);


                postData += L"\r\n";
            }
            postData += L"--boundary--\r\n";
            if (WinHttpSendRequest(hConnect, headers.c_str(), headers.length(), (LPVOID) postData.c_str(),
                                   postData.length(), postData.length(), 0)) {
                if (WinHttpReceiveResponse(hConnect, nullptr)) {

                }
            }
            WinHttpCloseHandle(hConnect);
        }


        WinHttpCloseHandle(hSession);
    }
}

[[maybe_unused]] std::string Form::get_file_path(const std::string &field_name) {

        HINTERNET hSession = WinHttpOpen(L"User-Agent", WINHTTP_ACCESS_TYPE_DEFAULT_PROXY, WINHTTP_NO_PROXY_NAME, WINHTTP_NO_PROXY_BYPASS, 0);
        std::string filePath;

        if (hSession) {

            HINTERNET hConnect = WinHttpOpenRequest(hSession, L"GET", L"/your/resource/path", nullptr, WINHTTP_NO_REFERER, WINHTTP_DEFAULT_ACCEPT_TYPES, 0);
            /* *
            * * ----->      @For User Change ! "/your/resource/path"
            * * ----->      @For User Change ! "/your/resource/path"
            * * ----->      @For User Change ! "/your/resource/path"
            * */

            if (hConnect) {

                if (WinHttpSendRequest(hConnect, WINHTTP_NO_ADDITIONAL_HEADERS, 0, WINHTTP_NO_REQUEST_DATA, 0, 0, 0)) {
                    if (WinHttpReceiveResponse(hConnect, nullptr)) {

                        std::vector<char> buffer(4096, '\0');
                        DWORD bytesRead = 0;

                        while (WinHttpReadData(hConnect, &buffer[0], buffer.size(), &bytesRead) && bytesRead > 0) {

                            std::string response(buffer.begin(), buffer.begin() + bytesRead);


                            size_t pos = response.find("\"" + field_name + "\":\"");
                            if (pos != std::string::npos) {
                                pos += field_name.length() + 4;
                                size_t endPos = response.find('\"', pos);
                                if (endPos != std::string::npos) {
                                    filePath = response.substr(pos, endPos - pos);
                                }
                            }
                        }
                    }
                }

                WinHttpCloseHandle(hConnect);
            }


            WinHttpCloseHandle(hSession);
        }
        return filePath;
}


[[maybe_unused]] bool Form::has_file(const std::string& field_name) {

    HINTERNET hSession = WinHttpOpen(L"User-Agent", WINHTTP_ACCESS_TYPE_DEFAULT_PROXY, WINHTTP_NO_PROXY_NAME, WINHTTP_NO_PROXY_BYPASS, 0);
    bool fileExists = false;

    if (hSession) {

        HINTERNET hConnect = WinHttpOpenRequest(hSession, L"GET", L"/your/resource/path", nullptr, WINHTTP_NO_REFERER, WINHTTP_DEFAULT_ACCEPT_TYPES, 0);
        /* *
        * * ----->      @For User Change ! "/your/resource/path"
        * * ----->      @For User Change ! "/your/resource/path"
        * * ----->      @For User Change ! "/your/resource/path"
        * */
        if (hConnect) {
            // Send the request
            if (WinHttpSendRequest(hConnect, WINHTTP_NO_ADDITIONAL_HEADERS, 0, WINHTTP_NO_REQUEST_DATA, 0, 0, 0)) {
                if (WinHttpReceiveResponse(hConnect, nullptr)) {

                    std::vector<char> buffer(4096, '\0');
                    DWORD bytesRead = 0;


                    while (WinHttpReadData(hConnect, &buffer[0], buffer.size(), &bytesRead) && bytesRead > 0) {

                        std::string response(buffer.begin(), buffer.begin() + bytesRead);


                        size_t pos = response.find("\"" + field_name + "\":\"");
                        if (pos != std::string::npos) {

                            fileExists = true;
                            break;
                        }
                    }
                }
            }


            WinHttpCloseHandle(hConnect);
        }

        WinHttpCloseHandle(hSession);
    }

    return fileExists;
}


[[maybe_unused]] void Form::remove_file(const std::string& field_name) {

    HINTERNET hSession = WinHttpOpen(L"User-Agent", WINHTTP_ACCESS_TYPE_DEFAULT_PROXY, WINHTTP_NO_PROXY_NAME, WINHTTP_NO_PROXY_BYPASS, 0);

    if (hSession) {

        HINTERNET hConnect = WinHttpOpenRequest(hSession, L"DELETE", L"/your/resource/path", nullptr, WINHTTP_NO_REFERER, WINHTTP_DEFAULT_ACCEPT_TYPES, 0);

        if (hConnect) {

            std::wstring headers = L"Content-Type: application/json\r\n";


            std::wstring jsonPayload = L"{\"" + std::wstring(field_name.begin(), field_name.end()) + L"\":null}";


            if (WinHttpSendRequest(hConnect, headers.c_str(), headers.length(), (LPVOID)jsonPayload.c_str(), jsonPayload.length(), jsonPayload.length(), 0)) {
                if (WinHttpReceiveResponse(hConnect, nullptr)) {

                }
            }


            WinHttpCloseHandle(hConnect);
        }


        WinHttpCloseHandle(hSession);
    }
}

[[maybe_unused]] std::unordered_map<std::string, std::string> Form::get_all_files() {
    std::unordered_map<std::string, std::string> files;

    HINTERNET hSession = WinHttpOpen(L"User-Agent", WINHTTP_ACCESS_TYPE_DEFAULT_PROXY, WINHTTP_NO_PROXY_NAME, WINHTTP_NO_PROXY_BYPASS, 0);

    if (hSession) {

        HINTERNET hConnect = WinHttpOpenRequest(hSession, L"GET", L"/your/resource/path", nullptr, WINHTTP_NO_REFERER, WINHTTP_DEFAULT_ACCEPT_TYPES, 0);

        if (hConnect) {

            if (WinHttpSendRequest(hConnect, WINHTTP_NO_ADDITIONAL_HEADERS, 0, WINHTTP_NO_REQUEST_DATA, 0, 0, 0)) {
                if (WinHttpReceiveResponse(hConnect, nullptr)) {

                    std::vector<char> buffer(4096, '\0');
                    DWORD bytesRead = 0;


                    while (WinHttpReadData(hConnect, &buffer[0], buffer.size(), &bytesRead) && bytesRead > 0) {

                        std::string response(buffer.begin(), buffer.begin() + bytesRead);


                        size_t pos = response.find('{');
                        while (pos != std::string::npos) {
                            size_t endPos = response.find('}', pos);
                            if (endPos != std::string::npos) {
                                std::string jsonField = response.substr(pos, endPos - pos + 1);


                                std::string fieldName = "example";
                                std::string filePath = "example.txt";

                                files[fieldName] = filePath;

                                pos = response.find('{', endPos);
                            } else {

                                pos = std::string::npos;
                            }
                        }
                    }
                }
            }


            WinHttpCloseHandle(hConnect);
        }


        WinHttpCloseHandle(hSession);
    }

    return files;
}

[[maybe_unused]] std::string Form::serialize_files() {
    std::ostringstream serializedData;
    for (const auto& entry : get_all_files()) {
        const std::string& fieldName = entry.first;
        const std::string& filePath = entry.second;
        serializedData << fieldName << "=";
        serializedData << filePath;
        serializedData << "\n";
    }
    return serializedData.str();
}

[[maybe_unused]] Form Form::parse_with_files(const std::string &query_string) {
    Form form;


    std::istringstream iss(query_string);
    std::string fieldValuePair;

    while (std::getline(iss, fieldValuePair, '&')) {

        size_t equalPos = fieldValuePair.find('=');

        if (equalPos != std::string::npos) {
            std::string fieldName = fieldValuePair.substr(0, equalPos);
            std::string filePath = fieldValuePair.substr(equalPos + 1);


            Form::add_file(fieldName, filePath);
        }
    }

}
