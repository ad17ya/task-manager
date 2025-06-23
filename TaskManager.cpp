#include <iostream>

#include "TaskManager.h"

TaskManager::TaskManager()
{
}

bool TaskManager::addTask(const std::string& sTaskName)
{
    HTask task(new Task(sTaskName));
    m_TaskMap[sTaskName] = task ;



    return true;
}

bool TaskManager::updateTask(const std::string& sTaskName)
{
    if (m_TaskMap.find(sTaskName) == m_TaskMap.end())
    {
        LOG_ERROR("No task with name " + sTaskName);
        return false;
    }

    return true;
}
