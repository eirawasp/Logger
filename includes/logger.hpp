#include <sstream>
#include <string>

enum kLogLevel
	{
		ERROR,
		WARNING,
		VERBOSE,
		INFO,
	};

class Logger {
	public: 

		static Logger& Instance(kLogLevel log_level, char * component_name) {
			static Logger log(log_level, component_name);
			return log;
		}

		void PrintLog (kLogLevel msg_level, std::string message, const char* caller);

	private:
		Logger (kLogLevel, char *);
		Logger(Logger const&) = delete;
		Logger& operator= (Logger const&) = delete;
		
		~Logger();

		char * component_name_;
		kLogLevel log_level_;
		std::stringstream log_buf_;

		std::string ConvertLvlToStr(kLogLevel level);
};
