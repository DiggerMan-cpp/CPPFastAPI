#include <app.h>

class Header {
public:
    /**
     * @brief Set the value of a header.
     *
     * @param header_name The name of the header.
     * @param header_value The value to set for the header.
     */
    void set_value(const std::string& header_name, const std::string& header_value);

    /**
     * @brief Get the value of a header by its name.
     *
     * @param header_name The name of the header.
     * @return The value of the specified header.
     */
    std::string get_value(const std::string& header_name) const;

    /**
     * @brief Check if a header exists by its name.
     *
     * @param header_name The name of the header.
     * @return True if the header exists, false otherwise.
     */
    bool has_header(const std::string& header_name) const;

    /**
     * @brief Remove a header by its name.
     *
     * @param header_name The name of the header to remove.
     */
    void remove_header(const std::string& header_name);

    /**
     * @brief Get all headers as an associative container.
     *
     * @return An unordered map with header names as keys and values as values.
     */
    std::unordered_map<std::string, std::string> get_all_headers() const;

    /**
     * @brief Serialize all headers into a string for inclusion in the request body.
     *
     * @return A string representing the serialized headers.
     */
    std::string serialize() const;

    /**
     * @brief Parse headers from a headers string.
     *
     * @param headers_string The string containing header data.
     * @return A Header instance with parsed header data.
     */
    static Header parse(const std::string& headers_string);
};
