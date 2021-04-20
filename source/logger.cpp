#include "logger.hpp"

#include <iostream>
#include <locale>
#include <boost/algorithm/string.hpp>

Logger::Logger(kLogLevel log_level, char * component_name): log_level_(log_level), component_name_(component_name) {
}

Logger::~Logger() {
	std::cout << log_buf_.str();
}

std::string Logger::ConvertLvlToStr(kLogLevel level) {
	switch(level) {
		case(INFO): 
			return ("INFO");		
		case(VERBOSE): 
			return("VERBOSE");
		case(WARNING): 
			return ("WARNING");
		case(ERROR): 
			return ("ERROR");
		default: 
			return("UNKNOWN_LEVEL");
	} 
}

void Logger::PrintLog (kLogLevel msg_level, std::string message, const char* caller = __builtin_FUNCTION()) {
	if (msg_level <= log_level_) {
		log_buf_ << component_name_ << " : " << caller << " : " << ConvertLvlToStr(msg_level) << " : " << message << std::endl;
	} 
}

int main (int argc, char *argv[]) {

	Logger& instance = Logger::Instance(VERBOSE, argv[0]);

	instance.PrintLog(INFO, "smth strange happens here!");
	instance.PrintLog(VERBOSE, "smth strange happens here!");
	instance.PrintLog(WARNING, "smth strange happens here!");
	instance.PrintLog(ERROR, "smth strange happens here!");
}