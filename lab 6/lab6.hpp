#pragma once
#include <iostream>
#include <fstream>
#include "lab6.hpp"
using namespace std;

enum class LogLevel {
	DEBUG,
	RELEASE
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

	static void Info(const string& msg) {

		time_t t = time(nullptr);
		static char time_str[20];
		strftime(time_str, sizeof(time_str),
			"%d-%m-%Y %H:%M:%S", localtime(&t));

		if (m_level == LogLevel::DEBUG)
			cerr << "\033[1;32m" << "[Info]" << time_str << " " << msg << endl;
		m_out << time_str << " " << msg << endl;
		m_out.flush();
	}

	static void Debug(const string& msg) {

		time_t t = time(nullptr);
		static char time_str[20];
		strftime(time_str, sizeof(time_str),
			"%d-%m-%Y %H:%M:%S", localtime(&t));

		if (m_level == LogLevel::DEBUG)
			cerr << "\033[1;36m" << "[Debug]" << time_str << " " << msg << endl;
		m_out << time_str << " " << msg << endl;
		m_out.flush();
	}

	static void Error(const string& msg) {

		time_t t = time(nullptr);
		static char time_str[20];
		strftime(time_str, sizeof(time_str),
			"%d-%m-%Y %H:%M:%S", localtime(&t));

		if (m_level == LogLevel::DEBUG)
			cerr << "\033[1;31m" << "[Error]" << time_str << " " << msg << endl;
		m_out << time_str << " " << msg << endl;
		m_out.flush();
	}

	static void FatalError(const string& msg) {

		time_t t = time(nullptr);
		static char time_str[20];
		strftime(time_str, sizeof(time_str),
			"%d-%m-%Y %H:%M:%S", localtime(&t));

		if (m_level == LogLevel::DEBUG)
			cerr << "\033[1;31m" << "[FatalError]" << time_str << " " << msg << endl;
		m_out << time_str << " " << msg << endl;
		m_out.flush();
	}
};