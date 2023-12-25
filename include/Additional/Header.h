#include <app.h>



class Header {
public:

/**
     * @brief Set the value of a header.
     *
     * @param header_name The name of the header.
     * @param header_value The value to set for the header.
     */
    void set_value(std::basic_string<wchar_t> header_name, std::basic_string<wchar_t> header_value);

    /**
     * @brief Get the value of a header by its name.
     *
     * @param header_name The name of the header.
     * @return The value of the specified header.
     */
    [[nodiscard]] std::string get_value(const std::string& header_name) const;

    /**
     * @brief Check if a header exists by its name.
     *
     * @param header_name The name of the header.
     * @return True if the header exists, false otherwise.
     */
    [[maybe_unused]] bool has_header(const std::string& header_name) const;

    /**
     * @brief Remove a header by its name.
     *
     * @param header_name The name of the header to remove.
     */
    void remove_header(
            __gnu_cxx::__normal_iterator<std::basic_string<char, std::char_traits<char>, std::allocator<char>>::const_pointer, std::basic_string<char, std::char_traits<char>, std::allocator<char>>> header_name);

    /**
     * @brief Get all headers as an associative container.
     *
     * @return An unordered map with header names as keys and values as values.
     */
    [[maybe_unused]] [[nodiscard]] const std::basic_string<char> get_all_headers() const;

    /**
     * @brief Serialize all headers into a string for inclusion in the request body.
     *
     * @return A string representing the serialized headers.
     */
    [[nodiscard]] std::string serialize() const;

    /**
     * @brief Parse headers from a headers string.
     *
     * @param headers_string The string containing header data.
     * @return A Header instance with parsed header data.
     */
    [[maybe_unused]] static Header parse(const std::string& headers_string);


    std::string headers;
};
