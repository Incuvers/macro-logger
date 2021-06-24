// -*- lsst-c++ -*-

#pragma once
#include "Arduino.h"

class Logger {
 public:
  enum Level {
    TRACE,
    INFO,
    WARNING,
    ERROR,
    CRITICAL
  };

  static Level get_level();
  static void set_level(Level level);

  static void _trace(const char* fmt, ...);
  static void _info(const char* fmt, ...);
  static void _warning(const char* fmt, ...);
  static void _error(const char* fmt, ...);
  static void _critical(const char* fmt, ...);

  static void log(Level level, const char* fmt, va_list argp);

  static Logger& get();  // return reference to Logger instance

 private:
  // const char*[]
  Logger();
  Logger(const Logger&);
  void printf(Level level, const char* fmt, va_list argp);
  Level _level;
};

#ifndef critical
#define critical(...) CRITICAL(__VA_ARGS__, "")
#define CRITICAL(fmt, ...) \
  Logger::_critical("%s:%i " fmt " %s", __func__, __LINE__, __VA_ARGS__)
#endif

#ifndef error
#define error(...) ERROR(__VA_ARGS__, "")
#define ERROR(fmt, ...) \
  Logger::_error("%s:%i " fmt " %s", __func__, __LINE__, __VA_ARGS__)
#endif

#ifndef warning
#define warning(...) WARNING(__VA_ARGS__, "")
#define WARNING(fmt, ...) \
  Logger::_warning("%s:%i " fmt " %s", __func__, __LINE__, __VA_ARGS__)
#endif

#ifndef info
#define info(...) INFO(__VA_ARGS__, "")
#define INFO(fmt, ...) \
  Logger::_info("%s:%i " fmt " %s", __func__, __LINE__, __VA_ARGS__)
#endif

#ifndef trace
#define trace(...) TRACE(__VA_ARGS__, "")
#define TRACE(fmt, ...) \
  Logger::_trace("%s:%i " fmt " %s", __func__, __LINE__, __VA_ARGS__)
#endif