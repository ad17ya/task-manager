#pragma once
#include <iostream>
#include <fstream>
#include <mutex>
#include <string>
#include <ctime>

enum class enLogLevel
{
    DEBUG, 
    INFO, 
    ERROR
};

class Logger
{
public:
    static Logger& getInstance();

    void setLevel(enLogLevel level);
    void setOutputFile(const std::string& filename);
    void log(enLogLevel level, const std::string& message, const char* file, int line);

private:
    Logger() = default;
    std::ofstream m_oLogFile;
    std::mutex m_mLogMutex;
    enLogLevel m_eLogLevel;

    std::string levelToString(enLogLevel level);
    std::string timestamp();
};