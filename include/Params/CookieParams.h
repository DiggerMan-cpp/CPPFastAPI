#include <app.h>
class CookieParams : App {
public:

    void set_value(const std::string& cookie_name, const std::string& cookie_value);

    std::string get_value(const std::string& cookie_name) const;

    bool has_cookie(const std::string& cookie_name) const;

    void remove_cookie(const std::string& cookie_name);

    std::unordered_map<std::string, std::string> get_all_cookies() const;

    std::string serialize() const;

    static CookieParams parse(const std::string& cookies_string);
};
