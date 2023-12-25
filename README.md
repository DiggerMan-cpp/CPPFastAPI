# CPPFastAPI
[![Windows](https://github.com/DiggerMan-cpp/CPPFastAPI/actions/workflows/windows.yml/badge.svg)](https://github.com/DiggerMan-cpp/CPPFastAPI/actions/workflows/windows.yml)

## Form Class

The `Form` class provides functionality for working with form data, including fields with multiple values and file attachments.

### Methods:

1. **`add_multi_value_field`**
    - **Description:** Add a form field with multiple values.
    - **Parameters:**
        - `field_name` (const std::string&): The name of the form field.
        - `field_values` (const std::vector<std::string>&): The values associated with the field.

2. **`get_multi_value_field`**
    - **Description:** Get all values of a form field with multiple values by its name.
    - **Parameters:**
        - `field_name` (const std::string&): The name of the form field.
    - **Returns:**
        - A vector containing all values of the specified field.

3. **`remove_multi_value_field`**
    - **Description:** Remove all values of a form field with multiple values by its name.
    - **Parameters:**
        - `field_name` (const std::string&): The name of the form field.

4. **`get_all_multi_value_fields`**
    - **Description:** Get all form fields with multiple values as an associative container.
    - **Returns:**
        - An unordered map with field names as keys and associated values as vectors.

5. **`serialize_multi_value_fields`**
    - **Description:** Serialize all form fields with multiple values into a string for inclusion in the request body.
    - **Returns:**
        - A string representing the serialized form data.

6. **`add_file`**
    - **Description:** Add a file to the form.
    - **Parameters:**
        - `field_name` (const std::string&): The name of the form field representing the file.
        - `file_path` (const std::string&): The path to the file to be added.

7. **`get_file_path`**
    - **Description:** Get the file path associated with a form field by its name.
    - **Parameters:**
        - `field_name` (const std::string&): The name of the form field.
    - **Returns:**
        - The path to the file associated with the specified field.

8. **`has_file`**
    - **Description:** Check if a file exists for a given form field name.
    - **Parameters:**
        - `field_name` (const std::string&): The name of the form field.
    - **Returns:**
        - True if a file is associated with the specified field, false otherwise.

9. **`remove_file`**
    - **Description:** Remove the file associated with a form field by its name.
    - **Parameters:**
        - `field_name` (const std::string&): The name of the form field.

10. **`get_all_files`**
    - **Description:** Get all form fields with files as an associative container.
    - **Returns:**
        - An unordered map with field names as keys and file paths as values.

11. **`serialize_files`**
    - **Description:** Serialize all form fields with files into a string for inclusion in the request body.
    - **Returns:**
        - A string representing the serialized form data with files.

12. **`parse_with_files`**
    - **Description:** Parse form data with files from a query string.
    - **Parameters:**
        - `query_string` (const std::string&): The query string containing form data.
    - **Returns:**
        - A `Form` instance with parsed data, including files.

## Request Class

The `Request` class represents an HTTP request.

### Attributes:

1. **`path`**
    - **Type:** `std::string`
    - **Description:** The path of the HTTP request.

2. **`method`**
    - **Type:** `std::string`
    - **Description:** The HTTP method of the request.

3. **`query_params`**
    - **Type:** `std::string`
    - **Description:** The query parameters of the request.

4. **`body`**
    - **Type:** `std::string`
    - **Description:** The body of the request.

### Methods:

1. **`get_query_param`**
    - **Description:** Get the value of a query parameter by its name.
    - **Parameters:**
        - `request` (const Request&): The request object.
        - `param_name` (const std::string&): The name of the query parameter.
    - **Returns:**
        - The value of the query parameter.

2. **`get_path_param`**
    - **Description:** Get the value of a path parameter by its name.
    - **Parameters:**
        - `param_name` (const std::string&): The name of the path parameter.
    - **Returns:**
        - The value of the path parameter.

3. **`get_header`**
    - **Description:** Get the value of a header by its name.
    - **Parameters:**
        - `header_name` (const std::string&): The name of the header.
    - **Returns:**
        - The value of the header.

4. **`get_query_params`**
    - **Description:** Get all request parameters as an associative container.
    - **Returns:**
        - An unordered map containing all query parameters.

5. **`get_path_params`**
    - **Description:** Get all path parameters as an associative container.
    - **Returns:**
        - An unordered map containing all path parameters.

6. **`get_headers`**
    - **Description:** Get all request headers as an associative container.
    - **Returns:**
        - An unordered map containing all request headers.

7. **`has_query_param`**
    - **Description:** Check the presence of a query parameter by its name.
    - **Parameters:**
        - `param_name` (const std::string&): The name of the query parameter.
    - **Returns:**
        - True if the query parameter exists, false otherwise.

8. **`has_path_param`**
    - **Description:** Check the presence of a path parameter by its name.
    - **Parameters:**
        - `param_name` (const std::string&): The name of the path parameter.
    - **Returns:**
        - True if the path parameter exists, false otherwise.

9. **`has_header`**
    - **Description:** Check the presence of a header by its name.
    - **Parameters:**
        - `header_name` (const std::string&): The name of the header.
    - **Returns:**
        - True if the header exists, false otherwise.

10. **`get_body`**
    - **Description:** Retrieve the body of the request.
    - **Returns:**
        - The body of the request.

11. **`get_cookies`**
    - **Description:** Get cookie parameters as an associative container.
    - **Returns:**
        - An unordered map containing all cookie parameters.

12. **`has_cookie`**
    - **Description:** Check the presence of a cookie by its name.
    - **Parameters:**
        - `cookie_name` (const wchar_t*): The name of the cookie.
    - **Returns:**
        - True if the cookie exists, false otherwise.

### Private Methods:

1. **`parse_query_params`**
    - **Description:** Parse query parameters from a string.
    - **Parameters:**
        - `params` (const std::string&): The string containing query parameters.
    - **Returns:**
        - An unordered map containing parsed query parameters.

2. **`parse_path_params`**
    - **Description:** Parse path parameters from a string.
    - **Parameters:**
        - `path1` (const std::string&): The string containing the path.
    - **Returns:**
        - An unordered map containing parsed path parameters.

3. **`parse_headers`**
    - **Description:** Parse headers from a string.
    - **Parameters:**
        - `headers` (const std::string&): The string containing headers.
    - **Returns:**
        - An unordered map containing parsed headers.

4. **`parse_cookies`**
    - **Description:** Parse cookies from a string.
    - **Parameters:**
        - `cookiesStr` (const std::string&): The string containing cookies.
        - `cookies` (std::unordered_map<std::string, std::string>&): Reference to store parsed cookies.

## Response Class

The `Response` class represents an HTTP response.

### Attributes:

1. **`status_code`**
    - **Type:** `int`
    - **Description:** The HTTP status code of the response.

2. **`content`**
    - **Type:** `std::string`
    - **Description:** The content of the response.

### Methods:

1. **`set_header`**
    - **Description:** Set the value of a response header.
    - **Parameters:**
        - `header_name` (const std::string&): The name of the response header.
        - `header_value` (const std::string&): The value to set for the header.

2. **`set_status_code`**
    - **Description:** Set the status code for the response.
    - **Parameters:**
        - `code` (int): The status code to set.

3. **`get_header`**
    - **Description:** Get the value of a response header by its name.
    - **Parameters:**
        - `header_name` (const std::string&): The name of the response header.
    - **Returns:**
        - The value of the specified header.

4. **`get_headers`**
    - **Description:** Get all response headers as an associative container.
    - **Returns:**
        - An unordered map with header names as keys and values as values.

5. **`set_content`**
    - **Description:** Set the content for the response.
    - **Parameters:**
        - `new_content` (const std::string&): The new content to set for the response.

6. **`clear_content`**
    - **Description:** Clear the content of the response.

7. **`append_content`**
    - **Description:** Append additional content to the existing content.
    - **Parameters:**
        - `additional_content` (const std::string&): The content to append.

8. **`set_content_from_file`**
    - **Description:** Set the content of the response from a file.
    - **Parameters:**
        - `file_path` (const std::string&): The path to the file providing the content.

9. **`set_cors_headers`**
    - **Description:** Set CORS headers for cross-origin requests.
    - **Parameters:**
        - `allowed_origin` (const std::string&): The allowed origin for CORS.
        - `allowed_methods` (const std::string&): The allowed HTTP methods for CORS.

10. **`set_content_type`**
    - **Description:** Set the Content-Type header.
    - **Parameters:**
        - `content_type` (const std::string&): The value to set for the Content-Type header.

### Additional Methods (Uncomment and Implement Based on Your Specific Needs):

- `send()`: Send the response (e.g., to the network).
- `set_json_content(const json& json_data)`: Set the content of the response as JSON data.
- `set_cookie(const std::string& cookie_name, const std::string& cookie_value)`: Set a cookie in the response.
- `set_redirect(const std::string& redirect_url)`: Set a redirection in the response.
- `set_security_headers()`: Set security-related headers in the response.
- `set_content_disposition_attachment(const std::string& file_name)`: Set the Content-Disposition header for attachment.
- `send_compressed()`: Send a compressed response.
- `send_partial_content(const std::vector<std::pair<size_t, size_t>>& ranges)`: Send partial content based on ranges.

## Header Class

The `Header` class provides functionality for managing HTTP headers.

### Methods:

1. **`set_value`**
    - **Description:** Set the value of a header.
    - **Parameters:**
        - `header_name` (const std::string&): The name of the header.
        - `header_value` (const std::string&): The value to set for the header.

2. **`get_value`**
    - **Description:** Get the value of a header by its name.
    - **Parameters:**
        - `header_name` (const std::string&): The name of the header.
    - **Returns:**
        - The value of the specified header.

3. **`has_header`**
    - **Description:** Check if a header exists by its name.
    - **Parameters:**
        - `header_name` (const std::string&): The name of the header.
    - **Returns:**
        - True if the header exists, false otherwise.

4. **`remove_header`**
    - **Description:** Remove a header by its name.
    - **Parameters:**
        - `header_name` (const std::string&): The name of the header to remove.

5. **`get_all_headers`**
    - **Description:** Get all headers as an associative container.
    - **Returns:**
        - An unordered map with header names as keys and values as values.

6. **`serialize`**
    - **Description:** Serialize all headers into a string for inclusion in the request body.
    - **Returns:**
        - A string representing the serialized headers.

7. **`parse`**
    - **Description:** Parse headers from a headers string.
    - **Parameters:**
        - `headers_string` (const std::string&): The string containing header data.
    - **Returns:**
        - A `Header` instance with parsed header data.


## Router Class

The `Router` class is responsible for routing incoming requests to appropriate handlers and applying middleware functions.

### Methods:

1. **`add_route`**
    - **Description:** Add a route with a specified handler and request method.
    - **Parameters:**
        - `path` (const std::string&): The path of the route.
        - `method` (const std::string&): The HTTP method associated with the route.
        - `handler` (App::RequestHandler): The handler function for the route.

2. **`add_middleware`**
    - **Description:** Add middleware to process requests before the main handler.
    - **Parameters:**
        - `middleware` (App::RequestHandler): The middleware function.

3. **`route_request`**
    - **Description:** Route an incoming request.
    - **Parameters:**
        - `request` (const Request&): The incoming request.
    - **Returns:**
        - The response generated for the request.

4. **`set_error_handler`**
    - **Description:** Set the error handler for the entire router.
    - **Parameters:**
        - `error_handler` (App::RequestHandler): The handler function for errors.

5. **`get_error_handler`**
    - **Description:** Get the error handler for the router.
    - **Returns:**
        - The error handler function.

6. **`clear_routes_and_middlewares`**
    - **Description:** Clear all routes and middlewares.

7. **`get_routes`**
    - **Description:** Get a list of routes as an associative container.
    - **Returns:**
        - A map containing path and method information for each route.

8. **`get_middlewares`**
    - **Description:** Get middleware as a vector.
    - **Returns:**
        - A vector containing middleware information.

9. **`set_not_found_handler`**
    - **Description:** Set the handler for 404 Not Found errors.
    - **Parameters:**
        - `not_found_handler` (App::RequestHandler): The handler function for 404 errors.

10. **`get_not_found_handler`**
    - **Description:** Get the handler for 404 Not Found errors.
    - **Returns:**
        - The handler function for 404 errors.

11. **`add_request_logger_middleware`**
    - **Description:** Add middleware for logging incoming requests.

12. **`add_authentication_middleware`**
    - **Description:** Add middleware for authentication checks.

13. **`add_response_compression_middleware`**
    - **Description:** Add middleware for response compression.

14. **`add_cors_middleware`**
    - **Description:** Add middleware for CORS (Cross-Origin Resource Sharing) control.

15. **`add_error_handling_middleware`**
    - **Description:** Add middleware for general error handling.

### Private Members:

- **`routes_`**
    - **Type:** `std::map<std::string, App::RequestHandler>`
    - **Description:** Map to store routes and their corresponding handlers.

- **`middlewares_`**
    - **Type:** `std::vector<App::RequestHandler>`
    - **Description:** Vector to store middleware functions.

- **`error_handler_`**
    - **Type:** `App::RequestHandler`
    - **Description:** Handler for general errors.

- **`not_found_handler_`**
    - **Type:** `App::RequestHandler`
    - **Description:** Handler for 404 Not Found errors.


## [UNRELEASED!] JSONResponse Class

The `JSONResponse` class represents an HTTP JSON response.

### Attributes:

1. **`status_code`**
    - **Type:** `int`
    - **Description:** The HTTP status code of the response.

2. **`content`**
    - **Type:** `std::string`
    - **Description:** The content of the response, typically containing JSON data.
## CookieParams Class

The `CookieParams` class, derived from `App`, represents a collection of cookie parameters.

### Methods:

1. **`set_value`**
    - **Description:** Set the value of a cookie.
    - **Parameters:**
        - `cookie_name` (const std::string&): The name of the cookie.
        - `cookie_value` (const std::string&): The value to set for the cookie.

2. **`get_value`**
    - **Description:** Get the value of a cookie by its name.
    - **Parameters:**
        - `cookie_name` (const std::string&): The name of the cookie.
    - **Returns:**
        - The value of the specified cookie.

3. **`has_cookie`**
    - **Description:** Check the presence of a cookie by its name.
    - **Parameters:**
        - `cookie_name` (const std::string&): The name of the cookie.
    - **Returns:**
        - True if the cookie exists, false otherwise.

4. **`remove_cookie`**
    - **Description:** Remove a cookie by its name.
    - **Parameters:**
        - `cookie_name` (const std::string&): The name of the cookie.

5. **`get_all_cookies`**
    - **Description:** Get all cookies as an associative container.
    - **Returns:**
        - An unordered map with cookie names as keys and values as values.

6. **`serialize`**
    - **Description:** Serialize all cookies into a string for inclusion in the request.
    - **Returns:**
        - A string representing the serialized cookies.

7. **`parse`**
    - **Description:** Parse cookies from a string.
    - **Parameters:**
        - `cookies_string` (const std::string&): The string containing cookie data.
    - **Returns:**
        - A `CookieParams` instance with parsed data.

### Inherits from:

- **`App`**
    - **Description:** The `CookieParams` class inherits from the `App` class.

## PathParams Class

The `PathParams` class represents a collection of path parameters.

### Methods:

1. **`set_value`**
    - **Description:** Set the value of a path parameter.
    - **Parameters:**
        - `param_name` (const std::string&): The name of the path parameter.
        - `param_value` (const std::string&): The value to set for the path parameter.

2. **`get_value`**
    - **Description:** Get the value of a path parameter by its name.
    - **Parameters:**
        - `param_name` (const std::string&): The name of the path parameter.
    - **Returns:**
        - The value of the specified path parameter.

3. **`has_param`**
    - **Description:** Check the presence of a path parameter by its name.
    - **Parameters:**
        - `param_name` (const std::string&): The name of the path parameter.
    - **Returns:**
        - True if the path parameter exists, false otherwise.

4. **`remove_param`**
    - **Description:** Remove a path parameter by its name.
    - **Parameters:**
        - `param_name` (const std::string&): The name of the path parameter.

5. **`get_all_params`**
    - **Description:** Get all path parameters as an associative container.
    - **Returns:**
        - An unordered map with path parameter names as keys and values as values.

6. **`serialize`**
    - **Description:** Serialize all path parameters into a string for inclusion in the request.
    - **Returns:**
        - A string representing the serialized path parameters.

7. **`parse`**
    - **Description:** Parse path parameters from a string.
    - **Parameters:**
        - `path_params_string` (const std::string&): The string containing path parameter data.
    - **Returns:**
        - A `PathParams` instance with parsed data.
## QueryParams Class

The `QueryParams` class represents a collection of query parameters.

### Methods:

1. **`set_value`**
    - **Description:** Set the value of a query parameter.
    - **Parameters:**
        - `param_name` (const std::string&): The name of the query parameter.
        - `param_value` (const std::string&): The value to set for the query parameter.

2. **`get_value`**
    - **Description:** Get the value of a query parameter by its name.
    - **Parameters:**
        - `param_name` (const std::string&): The name of the query parameter.
    - **Returns:**
        - The value of the specified query parameter.

3. **`has_param`**
    - **Description:** Check the presence of a query parameter by its name.
    - **Parameters:**
        - `param_name` (const std::string&): The name of the query parameter.
    - **Returns:**
        - True if the query parameter exists, false otherwise.

4. **`remove_param`**
    - **Description:** Remove a query parameter by its name.
    - **Parameters:**
        - `param_name` (const std::string&): The name of the query parameter.

5. **`get_all_params`**
    - **Description:** Get all query parameters as an associative container.
    - **Returns:**
        - An unordered map with query parameter names as keys and values as values.

6. **`serialize`**
    - **Description:** Serialize all query parameters into a string for inclusion in the request.
    - **Returns:**
        - A string representing the serialized query parameters.

7. **`parse`**
    - **Description:** Parse query parameters from a string.
    - **Parameters:**
        - `query_params_string` (const std::string&): The string containing query parameter data.
    - **Returns:**
        - A `QueryParams` instance with parsed data.
## BackgroundTasks Class

The `BackgroundTasks` class manages a collection of background tasks that can be executed asynchronously.

### Methods:

1. **`add_task`**
    - **Description:** Add a background task.
    - **Parameters:**
        - `task` (const std::function<void()>&): The function representing the background task.

2. **`get_all_tasks`**
    - **Description:** Get all background tasks as a vector of functions.
    - **Returns:**
        - A vector containing all background tasks.

3. **`clear_tasks`**
    - **Description:** Clear the list of background tasks.

4. **`execute_all_tasks`**
    - **Description:** Execute all background tasks.


## DependencyContainer Class

The `DependencyContainer` class manages dependencies and provides a mechanism for dependency injection.

### Methods:

1. **`register_dependency`**
    - **Description:** Register a type as a dependency.

2. **`register_dependency_instance`**
    - **Description:** Register an instance of a type as a dependency.

3. **`register_dependency_factory`**
    - **Description:** Register a factory function for creating instances of a type as a dependency.

4. **`resolve_dependency`**
    - **Description:** Resolve and retrieve an instance of a registered dependency.

5. **`has_dependency`**
    - **Description:** Check if a dependency of a specific type is registered.

6. **`clear_dependencies`**
    - **Description:** Clear all registered dependencies.
## UploadFile Class

The `UploadFile` class represents an uploaded file and provides methods to interact with its properties.

### Methods:

1. **`get_filename`**
    - **Description:** Get the filename of the uploaded file.
    - **Returns:**
        - A string containing the filename.

2. **`read_content`**
    - **Description:** Read the content of the uploaded file.
    - **Returns:**
        - A string containing the file content.

3. **`save_to`**
    - **Description:** Save the uploaded file to a specified destination path.
    - **Parameters:**
        - `destination_path` (const std::string&): The path where the file should be saved.

4. **`get_size`**
    - **Description:** Get the size of the uploaded file.
    - **Returns:**
        - The size of the file in bytes.

5. **`get_mime_type`**
    - **Description:** Get the MIME type of the uploaded file.
    - **Returns:**
        - A string containing the MIME type.

6. **`get_additional_params`**
    - **Description:** Get additional parameters associated with the uploaded file.
    - **Returns:**
        - An unordered map with parameter names as keys and values as values.
      ## WebSocket Class

The `WebSocket` class represents a WebSocket connection and provides methods to interact with the WebSocket.

### Methods:

1. **`set_message_handler`**
    - **Description:** Set a handler function for incoming messages.
    - **Parameters:**
        - `handler` (const std::function<void(const std::string&)>&): The function to handle incoming messages.

2. **`set_connection_handler`**
    - **Description:** Set a handler function for the WebSocket connection event.
    - **Parameters:**
        - `handler` (const std::function<void()>&): The function to handle the connection event.

3. **`set_disconnection_handler`**
    - **Description:** Set a handler function for the WebSocket disconnection event.
    - **Parameters:**
        - `handler` (const std::function<void()>&): The function to handle the disconnection event.

4. **`send_message`**
    - **Description:** Send a message through the WebSocket.
    - **Parameters:**
        - `message` (const std::string&): The message to send.

5. **`close`**
    - **Description:** Close the WebSocket connection.

6. **`get_client_ip`**
    - **Description:** Get the IP address of the WebSocket client.
    - **Returns:**
        - A string containing the client's IP address.

7. **`get_client_port`**
    - **Description:** Get the port number of the WebSocket client.
    - **Returns:**
        - A uint16_t representing the client's port number.
        - ## App Class

The `App` class represents the core of a web application and provides methods to handle incoming requests, define routes, set middleware, and manage various application settings.

### Methods:

1. **`Initialize`**
    - **Description:** Initialize Winsock for the application.
    - **Returns:**
        - 0 on success, -1 on failure.

2. **`Uninitialize`**
    - **Description:** Cleanup resources allocated by Winsock.

3. **`route`**
    - **Description:** Add a route with a specified handler and request method.
    - **Parameters:**
        - `path` (const std::string&): The path of the route.
        - `method` (const std::string&): The HTTP method associated with the route.
        - `handler` (RequestHandler): The handler function for the route.

4. **`handle_request`**
    - **Description:** Handle an incoming request and return the generated response.
    - **Parameters:**
        - `request` (const Request&): The incoming request.
    - **Returns:**
        - Response: The response generated for the request.

5. **`handle_request_with_defaults`**
    - **Description:** Handle an incoming request using default handlers (e.g., for 404).
    - **Parameters:**
        - `request` (const Request&): The incoming request.

6. **`add_default_not_found_handler`**
    - **Description:** Add a default handler for 404 Not Found errors.
    - **Parameters:**
        - `handler` (RequestHandler): The handler function for 404 errors.

7. **`add_middleware`**
    - **Description:** Add middleware to process requests before the main handler.
    - **Parameters:**
        - `middleware` (RequestHandler): The middleware function.

8. **`include`**
    - **Description:** Include routes and handlers from another `App` instance.
    - **Parameters:**
        - `other_app` (const App&): The `App` instance to include.

9. **`get_routes`**
    - **Description:** Get a list of routes as an associative container.
    - **Returns:**
        - std::map<std::string, std::string>: A map containing path and method information for each route.

10. **`has_route`**
    - **Description:** Check if a route with the specified path and method exists.
    - **Parameters:**
        - `path` (const std::string&): The path of the route.
        - `method` (const std::string&): The HTTP method associated with the route.
    - **Returns:**
        - bool: True if the route exists, false otherwise.

11. **`get_middlewares`**
    - **Description:** Get middleware as a vector.
    - **Returns:**
        - std::vector<std::string>: A vector containing middleware information.

12. **`set_error_handler`**
    - **Description:** Set an error handler for the entire application.
    - **Parameters:**
        - `error_handler` (RequestHandler): The handler function for errors.

13. **`get_error_handler`**
    - **Description:** Get the error handler for the application.
    - **Returns:**
        - RequestHandler: The error handler function.

14. **`add_static_file_handler`**
    - **Description:** Add support for serving static files.
    - **Parameters:**
        - `path_prefix` (const std::string&): The prefix for static file paths.
        - `directory_path` (const std::string&): The directory containing static files.

15. **`enable_response_compression`**
    - **Description:** Enable response compression (e.g., gzip).

16. **`set_max_request_body_size`**
    - **Description:** Set the maximum size of the request body.
    - **Parameters:**
        - `max_size` (size_t): The maximum size of the request body.

17. **`set_max_concurrent_connections`**
    - **Description:** Set the maximum number of concurrent connections.
    - **Parameters:**
        - `max_connections` (size_t): The maximum number of concurrent connections.

18. **`enable_sessions`**
    - **Description:** Enable session support.
    - **Parameters:**
        - `session_secret_key` (const std::string&): The secret key for session encryption and decryption.

19. **`add_request_logger_middleware`**
    - **Description:** Add middleware for logging incoming requests.

20. **`add_authentication_middleware`**
    - **Description:** Add middleware for authentication checks.

