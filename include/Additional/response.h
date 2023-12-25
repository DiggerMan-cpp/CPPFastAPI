#include <string>
#include <unordered_map>
#include <vector>

class Response {
public:
    int status_code;
    std::string content;
    // Additional response data, such as headers, can be added here.

    /**
     * @brief Set the value of a response header.
     *
     * @param header_name The name of the response header.
     * @param header_value The value to set for the header.
     */
    void set_header(const std::string& header_name, const std::string& header_value);

    /**
     * @brief Set the status code for the response.
     *
     * @param code The status code to set.
     */
    void set_status_code(int code);

    /**
     * @brief Get the value of a response header by its name.
     *
     * @param header_name The name of the response header.
     * @return The value of the specified header.
     */
    std::string get_header(const std::string& header_name) const;

    /**
     * @brief Get all response headers as an associative container.
     *
     * @return An unordered map with header names as keys and values as values.
     */
    std::unordered_map<std::string, std::string> get_headers() const;

    /**
     * @brief Set the content for the response.
     *
     * @param new_content The new content to set for the response.
     */
    void set_content(const std::string& new_content);

    /**
     * @brief Clear the content of the response.
     */
    void clear_content();

    /**
     * @brief Append additional content to the existing content.
     *
     * @param additional_content The content to append.
     */
    void append_content(const std::string& additional_content);

    /**
     * @brief Set the content of the response from a file.
     *
     * @param file_path The path to the file providing the content.
     */
    void set_content_from_file(const std::string& file_path);

    // Additional methods can be uncommented and implemented based on your specific needs.

    /**
     * @brief Send the response (e.g., to the network).
     * The implementation of this method will depend on your specific use case.
     * For example:
     * void send() const;
     */

    // void set_json_content(const json& json_data);

    /**
     * @brief Set CORS headers for cross-origin requests.
     *
     * @param allowed_origin The allowed origin for CORS.
     * @param allowed_methods The allowed HTTP methods for CORS.
     */
    void set_cors_headers(const std::string& allowed_origin, const std::string& allowed_methods);

    // void set_cookie(const std::string& cookie_name, const std::string& cookie_value);

    // void set_redirect(const std::string& redirect_url);

    // void set_security_headers();

    /**
     * @brief Set the Content-Type header.
     *
     * @param content_type The value to set for the Content-Type header.
     */
    void set_content_type(const std::string& content_type);

    // void set_content_disposition_attachment(const std::string& file_name);

    // void send_compressed() const;

    // void send_partial_content(const std::vector<std::pair<size_t, size_t>>& ranges) const;
};
