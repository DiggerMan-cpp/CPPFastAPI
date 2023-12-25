#include <app.h>
class PathParams {
public:

    void set_value(const std::string& param_name, const std::string& param_value);

    std::string get_value(const std::string& param_name) const;

    bool has_param(const std::string& param_name) const;

    void remove_param(const std::string& param_name);

    std::unordered_map<std::string, std::string> get_all_params() const;

    std::string serialize() const;

    static PathParams parse(const std::string& path_params_string);
};
