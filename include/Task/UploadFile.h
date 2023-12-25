#include <app.h>
class UploadFile {
public:

    std::string get_filename() const;

    std::string read_content() const;

    void save_to(const std::string& destination_path) const;

    std::size_t get_size() const;

    std::string get_mime_type() const;

    std::unordered_map<std::string, std::string> get_additional_params() const;
};
