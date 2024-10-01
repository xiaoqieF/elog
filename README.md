A simple version of spdlog

Support synchronize and asynchronize logger

Support stdout and roll file output

### simple output

```c++
#include <vector>
#include "elog/elog.h"

// synchronize log, output to terminal
// which use default logger
elog::info("hello world. This use default logger");
elog::debug("you can use format like {}, number:{:.2f}", "fmtlib", 12.2311);
// set log level
elog::setLogLevel(elog::LogLevel::INFO);
elog::debug("I will not be shown");
// use fmtlib 
std::vector<int> nums{1, 2, 3, 4};
elog::error("vector nums: [{}]", fmt::join(nums, ", "));

// you can also set output pattern
elog::setPattern("[%M-%D %h:%m:%s.%f] [%L] [thread: %t] %v");
elog::info("change format");

// you can also use macro to log
ELOG_ERROR("use macro: {}", "hhh");
ELOG_WARN("Also use default logger, so pattern and level had been set");
```

Attention: **only macro log can output source info(source filename and line number)**.

### format

Use `elog::setPattern` to set log format. All support format flag list here:

* `%n`: logger name.
* `%l`: log level, such as `info`, `debug`.
* `%L`: simplified log level, such as `I`, `D`.
* `%Y`: year, such as `2001`.
* `%M`: month, such as `03`.
* `%D`: day, such as `29`.
* `%h`: hour.
* `%m`: minute.
* `%s`: second.
* `%e`: millisecond.
* `%f`: microsecond.
* `%t`: thread id.
* `%v`: log content.
* `%u`: source filename.
* `%w`: function name.


```c++
// set format of default logger
elog::setPattern("[%M-%D %h:%m:%s.%f] [%L] [thread: %t] %v");
```

See `tests/example.cpp` for more.