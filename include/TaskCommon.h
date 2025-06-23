#pragma once
#include "Logger.h"

enum enStatus
{
    enNew,
    enProgress,
    enDone,
    enInvalid
};

#define LOG(level, message) \
    Logger::getInstance().log(level, message, __FILE__, __LINE__)

#define LOG_DEBUG(msg)      LOG(enLogLevel::DEBUG, msg)
#define LOG_INFO(msg)      LOG(enLogLevel::INFO, msg)
#define LOG_ERROR(msg)      LOG(enLogLevel::ERROR, msg)