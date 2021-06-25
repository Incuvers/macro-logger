// -*- lsst-c++ -*-

#include "MacroLogger.h"

void setup() {
  Serial.begin(9600);
  Logger::set_level(Logger::Level::WARNING);
}

void loop() {
  Logger::critical("This is a critical logging message");
  Logger::error("This is a error logging message");
  Logger::warning("This is a warning logging message");
  Logger::info("This is an info logging message: %d", 5);
  Logger::trace("This is a trace logging message: %s", "");
  delay(500);
}
