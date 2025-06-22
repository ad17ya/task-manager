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
    void setID(const int nId);
    int getID() const;

    void setName(const std::string& sName);
    std::string getName() const;

    void setStatus(const enStatus eStatus);
    enStatus getStatus() const;

    Task();
    ~Task() {};
};

using HTask = std::shared_ptr<Task>;