#ifndef _LOGGER_H
#define _LOGGER_H

#include <string>
#include <iostream>
#include <fstream>

enum class LogLevel {
	INFO,
	WARNING,
	ERROR
};

class Logger {
	public:
		Logger(const std::string &logFilePath, bool logConsole);
		~Logger();
		void log(LogLevel level, const std::string &message);
	private:
		bool logConsole = false;
		std::ofstream logFile;
};

#endif