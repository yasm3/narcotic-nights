#include "Logger.h"

Logger::Logger(const std::string &logFilePath, bool logConsole) : logConsole(logConsole)
{
    logFile.open(logFilePath, std::ios::app);
    if (!logFile.is_open()) {
        std::cerr << "Failed to open " << logFilePath << " file" << std::endl;
    }
}

Logger::~Logger()
{
    if (logFile.is_open()) logFile.close();
}

void Logger::log(LogLevel level, const std::string &message)
{
    std::time_t currentTime = std::time(nullptr);
    std::string timeStr = std::ctime(&currentTime);
    timeStr.pop_back();

    std::string logStr;
    logStr += "[";
    logStr += timeStr;
    logStr += "]";
    
    switch (level) {
    case LogLevel::INFO:
        logStr += "[INFO]";
        break;
    case LogLevel::WARNING:
        logStr += "[WARNING]";
        break;
    case LogLevel::ERROR:
        logStr += "[ERROR]";
        break;
    }

    logStr += " " + message;
    
    if (logFile.is_open()) logFile << logStr << std::endl;
    if (logConsole) std::cout << logStr << std::endl;
}
