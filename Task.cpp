#include "Task.h"
#include "TaskCommon.h"

Task::Task(const std::string& sTaskName) : 
    m_nID(time(nullptr)),
    m_sName(sTaskName),
    m_eStatus(enStatus::enInvalid)
{
}

int Task::getID() const
{
    return m_nID;
}

void Task::setName(const std::string& sName)
{
    m_sName = sName;
}

std::string Task::getName() const
{
    return m_sName;
}

void Task::setStatus(const enStatus eStatus)
{
    m_eStatus = eStatus;
}

enStatus Task::getStatus() const
{
    return m_eStatus;
}

std::ostream& operator<<(std::ostream& os, const Task& task)
{
    os  << "Task [ Name : " << task.getName() 
        << ", ID : " << task.getID()
        << ", Status: " << (task.getStatus()) << "]";

    return os;
}