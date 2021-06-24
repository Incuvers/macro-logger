// -*- lsst-c++ -*-
#include "Logger.h"
#include <Arduino.h>

Logger::Logger() : _level(INFO) {
}

void Logger::set_level(Level level) {
  get()._level = level;
}

Logger::Level Logger::get_level() {
  return get()._level;
}

void Logger::_trace(const char* fmt, ...) {
  va_list args;
  // Serial.println(line);
  va_start(args, fmt);
  log(TRACE, fmt, args);
  va_end(args);
}

void Logger::_info(const char* fmt, ...) {
  va_list args;
  // Serial.println(line);
  va_start(args, fmt);
  log(INFO, fmt, args);
  va_end(args);
}

void Logger::_warning(const char* fmt, ...) {
  va_list args;
  // Serial.println(line);
  va_start(args, fmt);
  log(WARNING, fmt, args);
  va_end(args);
}

void Logger::_error(const char* fmt, ...) {
  va_list args;
  // Serial.println(line);
  va_start(args, fmt);
  log(ERROR, fmt, args);
  va_end(args);
}

void Logger::_critical(const char* fmt, ...) {
  va_list args;
  va_start(args, fmt);
  log(CRITICAL, fmt, args);
  va_end(args);
}

void Logger::log(Level level, const char* fmt, va_list argp) {
  if (get()._level <= level) {
    get().printf(level, fmt, argp);
  }
}

Logger& Logger::get() {
  static Logger logger;
  return logger;
}

void Logger::printf(Level level, const char* fmt, va_list argp) {
  char buffer[256];
  vsnprintf(buffer, sizeof(buffer), fmt, argp);
  String tag;
  switch (level) {
    case Logger::Level::TRACE:
      tag = "TRACE";
      break;
    case Logger::Level::INFO:
      tag = "INFO";
      break;
    case Logger::Level::WARNING:
      tag = "WARNING";
      break;
    case Logger::Level::ERROR:
      tag = "ERROR";
      break;
    case Logger::Level::CRITICAL:
      tag = "CRITICAL";
      break;
  }
  // print log level tag
  Serial.print(F("["));
  Serial.print(tag);
  Serial.print(F("] "));
  Serial.println(buffer);
}
