#include <string>
#include <functional>
#include <map>
#include <Additional/response.h>
#include <Additional/request.h>
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>
#include <iostream>
#include <winhttp.h>

#pragma comment(lib, "winhttp.lib")
class App {
public:
    using RequestHandler = std::function<Response(const Request&)>;
      WSADATA wsaData;
    /**
    * @brief Initialize Winsock.
    *
    * @return 0 on success, -1 on failure.
    */
    int Initialize(){
        if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0){
            std::cout << "Error when WSAStartup, app.h, 16 line";
            return -1;
        }
    }
    /**
   * @brief Cleanup resources allocated by Winsock.
   */

    void Uninitilize(){
        WSACleanup();
    }
    void Uninitialize(){
        WSACleanup();
        // Additional cleanup logic can be added here.
    }

    /**
     * @brief Add a route with a specified handler and request method.
     *
     * @param path The path of the route.
     * @param method The HTTP method associated with the route.
     * @param handler The handler function for the route.
     */
    void route(const std::string& path, const std::string& method, RequestHandler handler);

    /**
     * @brief Handle an incoming request.
     *
     * @param request The incoming request.
     * @return The response generated for the request.
     */
    Response handle_request(const Request& request);

    /**
     * @brief Handle an incoming request using default handlers (e.g., for 404).
     *
     * @param request The incoming request.
     */
    void handle_request_with_defaults(const Request& request);

    /**
     * @brief Add a default handler for 404 Not Found.
     *
     * @param handler The handler function for 404 errors.
     */
    void add_default_not_found_handler(RequestHandler handler);

    /**
     * @brief Add middleware to process requests before the main handler.
     *
     * @param middleware The middleware function.
     */
    void add_middleware(RequestHandler middleware);

    /**
     * @brief Include routes and handlers from another App instance.
     *
     * @param other_app The App instance to include.
     */
    void include(const App& other_app);

    /**
     * @brief Get a list of routes as an associative container.
     *
     * @return A map containing path and method information for each route.
     */
    std::map<std::string, std::string> get_routes() const;

    /**
     * @brief Check if a route with the specified path and method exists.
     *
     * @param path The path of the route.
     * @param method The HTTP method associated with the route.
     * @return True if the route exists, false otherwise.
     */
    bool has_route(const std::string& path, const std::string& method) const;

    /**
     * @brief Get middleware as a vector.
     *
     * @return A vector containing middleware information.
     */
    std::vector<std::string> get_middlewares() const;

    /**
     * @brief Set an error handler for the entire application.
     *
     * @param error_handler The handler function for errors.
     */
    void set_error_handler(RequestHandler error_handler);

    /**
     * @brief Get the error handler for the application.
     *
     * @return The error handler function.
     */
    RequestHandler get_error_handler() const;

    /**
     * @brief Add support for serving static files.
     *
     * @param path_prefix The prefix for static file paths.
     * @param directory_path The directory containing static files.
     */
    void add_static_file_handler(const std::string& path_prefix, const std::string& directory_path);

    /**
     * @brief Enable response compression (e.g., gzip).
     */
    void enable_response_compression();

    /**
     * @brief Set the maximum size of the request body.
     *
     * @param max_size The maximum size of the request body.
     */
    void set_max_request_body_size(size_t max_size);

    /**
     * @brief Set the maximum number of concurrent connections.
     *
     * @param max_connections The maximum number of concurrent connections.
     */
    void set_max_concurrent_connections(size_t max_connections);

/**
 * @brief Enable session support.
 *
 * @param session_secret_key The secret key for session encryption
 * and decryption.
 */

    void enable_sessions(const std::string& session_secret_key);

/**
 * @brief Add middleware for logging incoming requests.
 */
    void add_request_logger_middleware();

/**
 * @brief Add middleware for authentication checks.
 */
    void add_authentication_middleware();
private:
std::map<std::string, RequestHandler> routes_;
};
