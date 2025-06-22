#include <string>
#include <unordered_map>

class TaskManager
{
private:


public:
    TaskManager(/* args */);
    ~TaskManager();

    bool addTask(const std::string& taskName);
    bool updateTask(const std::string& taskName);
    bool removeTask(const std::string& taskName);
    bool markProgress(const int ID);
    bool markDone(const int ID);
};

TaskManager::TaskManager(/* args */)
{
}

TaskManager::~TaskManager()
{
}
