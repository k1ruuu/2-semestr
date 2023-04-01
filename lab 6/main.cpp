#include <iostream>
#include <fstream>
#include "lab6.hpp"
using namespace std;





int main() {
	Logger::SetLogLevel(LogLevel::DEBUG);
	Logger::SetLogPath("logs.txt");
	Logger::PrintLog("Programm started", LogErrType::INFO);
	Logger::PrintLog("chto-to proishodit", LogErrType::DEBUG);
	Logger::PrintLog("ERORRRRRRRRRRRR", LogErrType::ERROR);
	Logger::PrintLog("Crashed...", LogErrType::FATALERROR);
}