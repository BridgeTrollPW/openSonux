#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <chrono>
#include <cstdarg>
#include <string>

enum class LOGLEVEL { WARN, ERROR, INFO, TRACE };

class Logger {
private:
  std::string clazz;
  void write(LOGLEVEL logLevel, const char *format, va_list argptr);
  std::string getDateTime(std::chrono::system_clock::time_point t);

public:
  explicit Logger(std::string clazz);
  void warn(const char *format, ...);
  void trace(const char *format, ...);
  void info(const char *format, ...);
  void error(const char *format, ...);
};

#endif /* LOGGER_HPP */
