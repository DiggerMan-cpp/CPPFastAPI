#include <string>
#include <unordered_map>
#include <sstream>
#include <algorithm>
#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>
#include <winhttp.h>

#pragma comment(lib, "winhttp.lib")
class Request {
public:
    static std::string path;
    std::string method;
    static std::string query_params;
    std::string body;
    /**
  * @brief Get the value of a query parameter by its name.
  *
  * @param request The request object.
  * @param param_name The name of the query parameter.
  * @return The value of the query parameter.
  */
    [[maybe_unused]] [[nodiscard]] virtual std::string get_query_param(const Request& request, const std::string& param_name) const;

/**
 * @brief Get the value of a path parameter by its name.
 *
 * @param param_name The name of the path parameter.
 * @return The value of the path parameter.
 */
    [[maybe_unused]] [[nodiscard]] static std::string get_path_param(const std::string& param_name) ;

/**
 * @brief Get the value of a header by its name.
 *
 * @param header_name The name of the header.
 * @return The value of the header.
 */
    [[maybe_unused]] [[nodiscard]] static std::string get_header(const std::string& header_name);

/**
 * @brief Get all request parameters as an associative container.
 *
 * @return An unordered map containing all query parameters.
 */
    [[maybe_unused]] [[nodiscard]] static std::unordered_map<std::string, std::string> get_query_params() ;

/**
 * @brief Get all path parameters as an associative container.
 *
 * @return An unordered map containing all path parameters.
 */
    [[maybe_unused]] [[nodiscard]] static std::unordered_map<std::string, std::string> get_path_params() ;

/**
 * @brief Get all request headers as an associative container.
 *
 * @return An unordered map containing all request headers.
 */
    [[maybe_unused]] [[maybe_unused]] [[nodiscard]] static std::unordered_map<std::string, std::string> get_headers() ;

/**
 * @brief Check the presence of a query parameter by its name.
 *
 * @param param_name The name of the query parameter.
 * @return True if the query parameter exists, false otherwise.
 */
    [[maybe_unused]] [[nodiscard]] static bool has_query_param(const std::string& param_name) ;

/**
 * @brief Check the presence of a path parameter by its name.
 *
 * @param param_name The name of the path parameter.
 * @return True if the path parameter exists, false otherwise.
 */
    [[maybe_unused]] [[nodiscard]] static bool has_path_param(const std::string& param_name) ;

/**
 * @brief Check the presence of a header by its name.
 *
 * @param header_name The name of the header.
 * @return True if the header exists, false otherwise.
 */
    [[maybe_unused]] [[nodiscard]] static bool has_header(const std::string& header_name) ;

/**
 * @brief Retrieve the body of the request.
 *
 * @return The body of the request.
 */
    [[maybe_unused]] [[nodiscard]] static std::string get_body() ;

// Uncomment the following when a JSON library is used.
// /**
//  * @brief Retrieve the JSON representation of the request body.
//  *
//  * @return JSON representation of the request body.
//  */
// json get_json_body() const;

/**
 * @brief Get cookie parameters as an associative container.
 *
 * @return An unordered map containing all cookie parameters.
 */
    [[maybe_unused]] [[nodiscard]] std::unordered_map<std::string, std::string> get_cookies() const ;

/**
 * @brief Check the presence of a cookie by its name.
 *
 * @param cookie_name The name of the cookie.
 * @return True if the cookie exists, false otherwise.
 */
    [[maybe_unused]] [[maybe_unused]] [[nodiscard]] static bool has_cookie(const wchar_t *cookie_name) ;

/**
 * @brief Get the uploaded file object from the request.
 *
 * @param file_name The name of the uploaded file.
 * @return The uploaded file object.
 */
// Uncomment the following when file uploads are used.
// UploadFile get_uploaded_file(const std::string& file_name) const;

private:
    [[nodiscard]] static std::unordered_map<std::string, std::string> parse_query_params(const std::string& params) {
        std::unordered_map<std::string, std::string> result;
        std::istringstream iss(params);
        std::string param;
        while (std::getline(iss, param, '&')) {
            size_t equalsPos = param.find('=');
            if (equalsPos != std::string::npos) {
                std::string key = param.substr(0, equalsPos);
                std::string value = param.substr(equalsPos + 1);
                result[key] = value;
            }
        }

        return result;
    }

    static std::unordered_map<std::string, std::string> parse_path_params(const std::string& path1) {
        std::unordered_map<std::string, std::string> result;

        size_t questionMarkPos = path1.find('?');

        if (questionMarkPos != std::string::npos) {
            std::string pathParams = path1.substr(questionMarkPos + 1);

            std::istringstream iss(pathParams);

            std::string param;
            while (std::getline(iss, param, '&')) {
                size_t equalsPos = param.find('=');
                if (equalsPos != std::string::npos) {
                    std::string key = param.substr(0, equalsPos);
                    std::string value = param.substr(equalsPos + 1);
                    result[key] = value;
                }
            }
        }

        return result;
    }



    [[nodiscard]] static std::unordered_map<std::string, std::string> parse_headers(
            const std::basic_string<char, std::char_traits<char>, std::allocator<char>>& headers) {
        std::unordered_map<std::string, std::string> result;

        std::istringstream iss(headers);
        std::string line;
        while (std::getline(iss, line)) {
            size_t colonPos = line.find(':');
            if (colonPos != std::string::npos) {
                std::string key = line.substr(0, colonPos);

                key.erase(std::remove_if(key.begin(), key.end(), ::isspace), key.end());
                std::string value = line.substr(colonPos + 1);

                value.erase(value.begin(), std::find_if(value.begin(), value.end(), [](int ch) {
                    return !std::isspace(ch);
                }));

                result[key] = value;
            }
        }

        return result;
    }

    [[maybe_unused]] static void parse_cookies(const std::string& cookiesStr, std::unordered_map<std::string, std::string>& cookies) {
        std::istringstream iss(cookiesStr);
        std::string cookie;
        while (std::getline(iss, cookie, ';')) {
            size_t equalsPos = cookie.find('=');
            if (equalsPos != std::string::npos) {
                std::string key = cookie.substr(0, equalsPos);
                std::string value = cookie.substr(equalsPos + 1);

                key.erase(0, key.find_first_not_of(' '));
                key.erase(key.find_last_not_of(' ') + 1);
                value.erase(0, value.find_first_not_of(' '));
                value.erase(value.find_last_not_of(' ') + 1);
                cookies[key] = value;
            }
        }
    }

};
