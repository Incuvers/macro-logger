# Macro Logger
[![ci](https://github.com/Incuvers/macro-logger/actions/workflows/ci.yaml/badge.svg)](https://github.com/Incuvers/macro-logger/actions/workflows/ci.yaml)

Modified: 2021-06

![img](/img/Incuvers-black.png)

## Navigation
 1. [About](#about)
 2. [Quickstart](#quickstart)
 3. [License](#license)

## About
Macro Logger is an arduino logging library with support for precompilation directives and `printf` formatting. This library is adapted from: [Logger](https://github.com/bakercp/Logger).

## Quickstart
Below is a snippet of the basic usage:
```cpp
#include "Logger.h"

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
```
Output:
```bash
[CRITICAL] loop:25 This is a critical logging message
[ERROR] loop:25 This is a error logging message
[WARNING] loop:25 This is a warning logging message
[INFO] loop:25 This is an info logging message: 5
[TRACE] loop:25 This is a trace logging message:  
```

[tests.ino](./tests/tests.ino) is available for 

## Licence
[MIT License](LICENSE)