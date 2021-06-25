// -*- lsst-c++ -*-
/**
 * @file Logger.cpp
 * @author Christian Sargusingh (christian@incuvers.com)
 * @brief Arduino logger with support for precompiler directives and standard C/C++ string formatting
 * @version 0.1
 * @date 2021-06
 * 
 * @copyright Copyright © 2021 Incuvers
 * 
 */
#include "Logger.h"
#include <Arduino.h>

/**
 * @brief Construct a new Logger:: Logger object
 * 
 */
Logger::Logger() : _level(INFO) {
}

/**
 * @brief Set the logging level for this instance
 * 
 * @param level logging level from enum def
 */
void Logger::set_level(Level level) {
  get()._level = level;
}

/**
 * @brief Get the logging level for this instance
 * 
 * @return Logger::Level active log level
 */
Logger::Level Logger::get_level() {
  return get()._level;
}

/**
 * @brief trace level logging
 * 
 * @param fmt string format schema
 * @param ... __VA_ARGS__
 */
void Logger::_trace(const char* fmt, ...) {
  va_list args;
  va_start(args, fmt);
  log(TRACE, fmt, args);
  va_end(args);
}

/**
 * @brief info level logging
 * 
 * @param fmt string format schema
 * @param ... __VA_ARGS__
 */
void Logger::_info(const char* fmt, ...) {
  va_list args;
  va_start(args, fmt);
  log(INFO, fmt, args);
  va_end(args);
}

/**
 * @brief warning level logging
 * 
 * @param fmt string format schema
 * @param ... __VA_ARGS__
 */
void Logger::_warning(const char* fmt, ...) {
  va_list args;
  va_start(args, fmt);
  log(WARNING, fmt, args);
  va_end(args);
}

/**
 * @brief error level logging
 * 
 * @param fmt string format schema
 * @param ... __VA_ARGS__
 */
void Logger::_error(const char* fmt, ...) {
  va_list args;
  va_start(args, fmt);
  log(ERROR, fmt, args);
  va_end(args);
}

/**
 * @brief critical level logging
 * 
 * @param fmt string format schema
 * @param ... __VA_ARGS__
 */
void Logger::_critical(const char* fmt, ...) {
  va_list args;
  va_start(args, fmt);
  log(CRITICAL, fmt, args);
  va_end(args);
}

/**
 * @brief Filter logs by log level
 * 
 * @param level inbound log level
 * @param fmt string format schema
 * @param argp arguments for string format schema
 */
void Logger::log(Level level, const char* fmt, va_list argp) {
  if (get()._level <= level) {
    get().out(level, fmt, argp);
  }
}

/**
 * @brief Get reference of logging instance
 * 
 * @return Logger& 
 */
Logger& Logger::get() {
  static Logger logger;
  return logger;
}

/**
 * @brief Logging stdout string format resolver
 * 
 * @param level log level
 * @param fmt string format schema
 * @param argp arguments for string format schema
 */
void Logger::out(Level level, const char* fmt, va_list argp) {
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
