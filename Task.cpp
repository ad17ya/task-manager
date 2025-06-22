#include "Task.h"

Task::Task() : 
    m_nID(-1),
    m_sName(""),
    m_eStatus(enStatus::enInvalid)
{
}

void Task::setID(const int nId)
{
    m_nID = nId;
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