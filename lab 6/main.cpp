#include <iostream>
#include <fstream>
#include "lab6.hpp"
using namespace std;





int main() {
	Logger::SetLogLevel(LogLevel::DEBUG);
	Logger::SetLogPath("logs.txt");
	Logger::Info("Programm started");
	Logger::Debug("chto-to proishodit");
	Logger::Error("ERORRRRRRRRRRRR");
	Logger::FatalError("Crashed...");
}