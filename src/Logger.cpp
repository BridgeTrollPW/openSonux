#include "../include/Logger.hpp"
#include <iostream>
#include <sstream>
#include <stdio.h>

Logger::Logger(std::string _clazz) : clazz(_clazz) {}

void Logger::write(LOGLEVEL logLevel, const char *format, va_list argptr) {
  const char *loglevel = "INFO ";
  switch (logLevel) {
  case LOGLEVEL::WARN:
    loglevel = "WARN ";
    break;
  case LOGLEVEL::ERROR:
    loglevel = "ERROR ";
    break;
  case LOGLEVEL::TRACE:
    loglevel = "TRACE ";
    break;
  default:
    break;
  }
  std::string buffer(clazz);
  buffer.append("[");
  buffer.append(getDateTime(std::chrono::system_clock::now()));
  buffer.append("]");
  buffer.append(" ");
  buffer.append(loglevel);
  buffer.append(format);
  vprintf(buffer.c_str(), argptr);
}

void Logger::warn(const char *format, ...) {
  va_list argptr;
  va_start(argptr, format);
  write(LOGLEVEL::WARN, format, argptr);
  va_end(argptr);
}
void Logger::trace(const char *format, ...) {
  va_list argptr;
  va_start(argptr, format);
  write(LOGLEVEL::TRACE, format, argptr);
  va_end(argptr);
}
void Logger::error(const char *format, ...) {
  va_list argptr;
  va_start(argptr, format);
  write(LOGLEVEL::ERROR, format, argptr);
  va_end(argptr);
}
void Logger::info(const char *format, ...) {
  va_list argptr;
  va_start(argptr, format);
  write(LOGLEVEL::INFO, format, argptr);
  va_end(argptr);
}

std::string getDateTime(std::chrono::system_clock::time_point t) {
  char dateTimeBuffer[64];
  auto as_time_t = std::chrono::system_clock::to_time_t(t);
  struct tm tm;
  if (::gmtime_r(&as_time_t, &tm)) {
    if (std::strftime(dateTimeBuffer, sizeof(dateTimeBuffer), "%F", &tm)) {
      return std::string{dateTimeBuffer};
    }
  }
  throw std::runtime_error("Failed to get current date as string");
}