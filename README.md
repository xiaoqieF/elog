A simple version of spdlog

support synchronize and asynchronize logger

support stdout and roll file output

### simple output

```c++
#include <vector>
#include "clog/clog.h"

// synchronize log, output to terminal
// which use default logger
clog::info("hello world. This use default logger");
clog::debug("you can use format like {}, number:{:.2f}", "fmtlib", 12.2311);
// set log level
clog::setLogLevel(clog::LogLevel::INFO);
clog::debug("I will not be shown");
// use fmtlib 
std::vector<int> nums{1, 2, 3, 4};
clog::error("vector nums: [{}]", fmt::join(nums, ", "));

// you can also set output pattern
clog::setPattern("[%M-%D %h:%m:%s.%f] [%L] [thread: %t] %v");
clog::info("change format");

// you can also use macro to log
CLOG_ERROR("use macro: {}", "hhh");
CLOG_WARN("Also use default logger, so pattern and level had been set");
```

### format

use `clog::setPattern` to set log format.
all support format flag list here:

`%n`: logger name.
`%l`: log level, such as `info`, `debug`.
`%L`: simplified log level, such as `I`, `D`.
`%Y`: year, such as `2001`.
`%M`: month, such as `03`.
`%D`: day, such as `29`.
`%h`: hour.
`%m`: minute.
`%s`: second.
`%e`: millisecond.
`%f`: microsecond.
`%t`: thread id.
`%v`: log content.
`%u`: source filename.
`%w`: function name.


```c++
// set format of default logger
clog::setPattern("[%M-%D %h:%m:%s.%f] [%L] [thread: %t] %v");
```