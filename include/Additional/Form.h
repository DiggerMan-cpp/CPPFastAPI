#include <app.h>

class [[maybe_unused]] Form {
public:
    /**
     * @brief Add a form field with multiple values.
     *
     * @param field_name The name of the form field.
     * @param field_values The values associated with the field.
     */
    [[maybe_unused]]  static void add_multi_value_field(const std::string& field_name, const std::vector<std::string>& field_values);

    /**
     * @brief Get all values of a form field with multiple values by its name.
     *
     * @param field_name The name of the form field.
     * @return A vector containing all values of the specified field.
     */
    [[maybe_unused]]  static std::vector<std::string> get_multi_value_field([[maybe_unused]] const std::string& field_name) ;

    /**
     * @brief Remove all values of a form field with multiple values by its name.
     *
     * @param field_name The name of the form field.
     */
    [[maybe_unused]] static void remove_multi_value_field(const std::string& field_name);

    /**
     * @brief Get all form fields with multiple values as an associative container.
     *
     * @return An unordered map with field names as keys and associated values as vectors.
     */
    [[maybe_unused]] static std::unordered_map<std::string, std::vector<std::string>> get_all_multi_value_fields() ;

    /**
     * @brief Serialize all form fields with multiple values into a string for inclusion in the request body.
     *
     * @return A string representing the serialized form data.
     */
    [[maybe_unused]] [[nodiscard]] static std::string serialize_multi_value_fields() ;

    /**
     * @brief Add a file to the form.
     *
     * @param field_name The name of the form field representing the file.
     * @param file_path The path to the file to be added.
     */
    [[maybe_unused]] static void add_file(const std::string& field_name, const std::string& file_path);

    /**
     * @brief Get the file path associated with a form field by its name.
     *
     * @param field_name The name of the form field.
     * @return The path to the file associated with the specified field.
     */
    [[maybe_unused]] [[nodiscard]] static std::string get_file_path(const std::string& field_name) ;

    /**
     * @brief Check if a file exists for a given form field name.
     *
     * @param field_name The name of the form field.
     * @return True if a file is associated with the specified field, false otherwise.
     */
    [[maybe_unused]] [[nodiscard]] static bool has_file(const std::string& field_name) ;

    /**
     * @brief Remove the file associated with a form field by its name.
     *
     * @param field_name The name of the form field.
     */
    [[maybe_unused]]  static void remove_file(const std::string& field_name);

    /**
     * @brief Get all form fields with files as an associative container.
     *
     * @return An unordered map with field names as keys and file paths as values.
     */
    [[maybe_unused]] [[nodiscard]] static std::unordered_map<std::string, std::string> get_all_files() ;

    /**
     * @brief Serialize all form fields with files into a string for inclusion in the request body.
     *
     * @return A string representing the serialized form data with files.
     */
    [[maybe_unused]] [[nodiscard]] static std::string serialize_files() ;

    /**
     * @brief Parse form data with files from a query string.
     *
     * @param query_string The query string containing form data.
     * @return A Form instance with parsed data, including files.
     */
    [[maybe_unused]] static Form parse_with_files(const std::string& query_string);
};
