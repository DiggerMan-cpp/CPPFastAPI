#include <app.h>
#include <string>
#include <functional>
#include <map>
#include <vector>

class Router {
public:
    /**
     * @brief Add a route with a specified handler and request method.
     *
     * @param path The path of the route.
     * @param method The HTTP method associated with the route.
     * @param handler The handler function for the route.
     */
    void add_route(const std::string& path, const std::string& method, App::RequestHandler handler);

    /**
     * @brief Add middleware to process requests before the main handler.
     *
     * @param middleware The middleware function.
     */
    void add_middleware(App::RequestHandler middleware);

    /**
     * @brief Route an incoming request.
     *
     * @param request The incoming request.
     * @return The response generated for the request.
     */
    Response route_request(const Request& request);

    /**
     * @brief Set the error handler for the entire router.
     *
     * @param error_handler The handler function for errors.
     */
    void set_error_handler(App::RequestHandler error_handler);

    /**
     * @brief Get the error handler for the router.
     *
     * @return The error handler function.
     */
    App::RequestHandler get_error_handler() const;

    /**
     * @brief Clear all routes and middlewares.
     */
    void clear_routes_and_middlewares();

    /**
     * @brief Get a list of routes as an associative container.
     *
     * @return A map containing path and method information for each route.
     */
    std::map<std::string, std::string> get_routes() const;

    /**
     * @brief Get middleware as a vector.
     *
     * @return A vector containing middleware information.
     */
    std::vector<std::string> get_middlewares() const;

    /**
     * @brief Set the handler for 404 Not Found errors.
     *
     * @param not_found_handler The handler function for 404 errors.
     */
    void set_not_found_handler(App::RequestHandler not_found_handler);

    /**
     * @brief Get the handler for 404 Not Found errors.
     *
     * @return The handler function for 404 errors.
     */
    App::RequestHandler get_not_found_handler() const;

    /**
     * @brief Add middleware for logging incoming requests.
     */
    void add_request_logger_middleware();

    /**
     * @brief Add middleware for authentication checks.
     */
    void add_authentication_middleware();

    /**
     * @brief Add middleware for response compression.
     */
    void add_response_compression_middleware();

    /**
     * @brief Add middleware for CORS (Cross-Origin Resource Sharing) control.
     */
    void add_cors_middleware();

    /**
     * @brief Add middleware for error handling.
     */
    void add_error_handling_middleware();

private:
    // Map to store routes and their corresponding handlers.
    std::map<std::string, App::RequestHandler> routes_;

    // Vector to store middleware functions.
    std::vector<App::RequestHandler> middlewares_;

    // Handler for general errors.
    App::RequestHandler error_handler_;

    // Handler for 404 Not Found errors.
    App::RequestHandler not_found_handler_;
};
