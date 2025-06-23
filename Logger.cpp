#include <sstream>

#include "Logger.h"

Logger& Logger::getInstance()
{
    static Logger instance;
    return instance;
}

void Logger::setLevel(enLogLevel level)
{
    m_eLogLevel = level;
}

void Logger::setOutputFile(const std::string& filename)
{
    std::lock_guard<std::mutex> lock(m_mLogMutex);
    if (m_oLogFile.is_open())  
        m_oLogFile.close();
    m_oLogFile.open(filename, std::ios::app);
}

std::string Logger::timestamp()
{
    std::time_t now = std::time(nullptr);
    char buff[32];
    std::strftime(buff, sizeof(buff), "%Y-%m-%d %H:%M:%S", std::localtime(&now));
    return std::string(buff);
}

std::unordered_map<enLogLevel, std::string> levelToStringMap
{
    {enLogLevel::DEBUG, "DEBUG"},
    {enLogLevel::INFO, "INFO"},
    {enLogLevel::ERROR, "ERROR"}
};

void Logger::log(enLogLevel level, const std::string& message, const char* file, int line)
{
    if (level < m_eLogLevel) return;

    std::lock_guard<std::mutex> lock(m_mLogMutex);
    std::ostream& out = m_oLogFile.is_open() ? m_oLogFile : std::cerr;
    out << "[" << timestamp() << "]"
        << "[" << levelToStringMap[level] << "]"
        << file << ":" << line << " - "
        << message << std::endl;
}

