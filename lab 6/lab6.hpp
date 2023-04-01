#pragma once
#include <iostream>
#include <fstream>
#include "lab6.hpp"
using namespace std;

enum class LogLevel {
	DEBUG,
	RELEASE
};

enum class LogErrType {
	INFO,
	DEBUG,
	ERROR,
	FATALERROR
};

class Logger {
private:

	static ofstream m_out;
	static LogLevel m_level;

public:

	static void SetLogLevel(LogLevel level) {
		m_level = level;
	}

	static void SetLogPath(const string& path) {
		m_out.open(path);
	}

	static char* GetCurrTime()
	{
		time_t t = time(nullptr);
		static char time_str[20];
		strftime(time_str, sizeof(time_str),
			"%d-%m-%Y %H:%M:%S", localtime(&t));
		return time_str;
	}

	static void PrintLog(const string& msg, LogErrType type) {

		if (type == LogErrType::INFO) {
			if (m_level == LogLevel::DEBUG) {
				cerr << "\033[1;32m" << "[Info]" << GetCurrTime() << " " << msg << endl;
			}
			m_out << "[Info]" << GetCurrTime() << " " << msg << endl;
			m_out.flush();
		}

		else if (type == LogErrType::DEBUG) {
			if (m_level == LogLevel::DEBUG)
				cerr << "\033[1;36m" << "[Debug]" << GetCurrTime() << " " << msg << endl;
			m_out << "[Debug]" << GetCurrTime() << " " << msg << endl;
			m_out.flush();
		}

		else if (type == LogErrType::ERROR) {
			if (m_level == LogLevel::DEBUG)
				cerr << "\033[1;31m" << "[Error]" << GetCurrTime() << " " << msg << endl;
			m_out << "[Error]" << GetCurrTime() << " " << msg << endl;
			m_out.flush();
		}

		else if (type == LogErrType::FATALERROR) {
			if (m_level == LogLevel::DEBUG)
				cerr << "\033[1;31m" << "[FatalError]" << GetCurrTime() << " " << msg << endl;
			m_out << "[FatalError]" << GetCurrTime() << " " << msg << endl;
			m_out.flush();
		}
	}
};