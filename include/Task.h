#pragma once

#include<string>
#include<memory>

#include "TaskCommon.h"

class Task
{
private:
    int m_nID;
    std::string m_sName;
    enStatus m_eStatus;

public:
    int getID() const;
    std::string getName() const;

    void setStatus(const enStatus eStatus);
    enStatus getStatus() const;

    Task(const std::string& sTaskName);
    ~Task() {};

    friend std::ostream& operator<<(std::ostream os, const Task& task);
};

using HTask = std::shared_ptr<Task>;