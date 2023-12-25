#include <app.h>

class BackgroundTasks {
public:
    /**
     * @brief Add a background task.
     *
     * @param task The function representing the background task.
     */
    void add_task(const std::function<void()>& task);

    /**
     * @brief Get all background tasks as a vector of functions.
     *
     * @return A vector containing all background tasks.
     */
    std::vector<std::function<void()>> get_all_tasks() const;

    /**
     * @brief Clear the list of background tasks.
     */
    void clear_tasks();

    /**
     * @brief Execute all background tasks.
     */
    void execute_all_tasks();
};
