#include <app.h>

class Form {
public:
    /**
     * @brief Add a form field with multiple values.
     *
     * @param field_name The name of the form field.
     * @param field_values The values associated with the field.
     */
    void add_multi_value_field(const std::string& field_name, const std::vector<std::string>& field_values);

    /**
     * @brief Get all values of a form field with multiple values by its name.
     *
     * @param field_name The name of the form field.
     * @return A vector containing all values of the specified field.
     */
    std::vector<std::string> get_multi_value_field(const std::string& field_name) const;

    /**
     * @brief Remove all values of a form field with multiple values by its name.
     *
     * @param field_name The name of the form field.
     */
    void remove_multi_value_field(const std::string& field_name);

    /**
     * @brief Get all form fields with multiple values as an associative container.
     *
     * @return An unordered map with field names as keys and associated values as vectors.
     */
    std::unordered_map<std::string, std::vector<std::string>> get_all_multi_value_fields() const;

    /**
     * @brief Serialize all form fields with multiple values into a string for inclusion in the request body.
     *
     * @return A string representing the serialized form data.
     */
    std::string serialize_multi_value_fields() const;

    /**
     * @brief Add a file to the form.
     *
     * @param field_name The name of the form field representing the file.
     * @param file_path The path to the file to be added.
     */
    void add_file(const std::string& field_name, const std::string& file_path);

    /**
     * @brief Get the file path associated with a form field by its name.
     *
     * @param field_name The name of the form field.
     * @return The path to the file associated with the specified field.
     */
    std::string get_file_path(const std::string& field_name) const;

    /**
     * @brief Check if a file exists for a given form field name.
     *
     * @param field_name The name of the form field.
     * @return True if a file is associated with the specified field, false otherwise.
     */
    bool has_file(const std::string& field_name) const;

    /**
     * @brief Remove the file associated with a form field by its name.
     *
     * @param field_name The name of the form field.
     */
    void remove_file(const std::string& field_name);

    /**
     * @brief Get all form fields with files as an associative container.
     *
     * @return An unordered map with field names as keys and file paths as values.
     */
    std::unordered_map<std::string, std::string> get_all_files() const;

    /**
     * @brief Serialize all form fields with files into a string for inclusion in the request body.
     *
     * @return A string representing the serialized form data with files.
     */
    std::string serialize_files() const;

    /**
     * @brief Parse form data with files from a query string.
     *
     * @param query_string The query string containing form data.
     * @return A Form instance with parsed data, including files.
     */
    static Form parse_with_files(const std::string& query_string);
};
