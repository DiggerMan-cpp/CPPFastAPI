#include <app.h>
#include <cstdint>

class WebSocket {
public:
    

    void set_message_handler(const std::function<void(const std::string&)>& handler);

    void set_connection_handler(const std::function<void()>& handler);

    void set_disconnection_handler(const std::function<void()>& handler);

    void send_message(const std::string& message);

    void close();

    std::string get_client_ip() const;

    std::uint16_t get_client_port() const;
};