#pragma once
#include <sstream>

#include "Logger.h"

enum enStatus
{
    enNew,
    enProgress,
    enDone,
    enInvalid
};

#define LOG(level, streamExpr) \
    do {                                                        \
        std::stringstream ss__;                                 \
        ss__ << streamExpr;                                     \
        Logger::getInstance().log(level, ss__.str(), __FILE__, __LINE__); \
    } while (0)

#define LOG_DEBUG(msg)      LOG(enLogLevel::DEBUG, msg)
#define LOG_INFO(msg)      LOG(enLogLevel::INFO, msg)
#define LOG_ERROR(msg)      LOG(enLogLevel::ERROR, msg)