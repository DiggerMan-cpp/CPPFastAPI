#include <app.h>
class DependencyContainer {
public:

    template <typename T>
    void register_dependency();


    template <typename T>
    void register_dependency_instance(T* instance);


    template <typename T, typename... Args>
    void register_dependency_factory(std::function<T*(Args...)> factory);


    template <typename T>
    T* resolve_dependency();


    template <typename T>
    bool has_dependency() const;


    void clear_dependencies();
};
