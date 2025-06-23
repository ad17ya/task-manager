#include <string>
#include <unordered_map>

#include "Task.h"

class TaskManager
{
private:
    std::unordered_map<std::string, HTask> m_TaskMap;

public:
    TaskManager();
    ~TaskManager() {};

    bool addTask(const std::string& taskName);
    bool updateTask(const std::string& taskName);
    // bool removeTask(const std::string& taskName);
    // bool markProgress(const int ID);
    // bool markDone(const int ID);
};

using HTaskManager = std::shared_ptr<TaskManager>;