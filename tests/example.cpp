#include <vector>

#include "elog/elog.h"

void simpleLog() {
    // synchronize log, output to terminal
    // will use default logger
    elog::info("hello world. This use default logger");
    elog::debug("you can use format like {}, number:{:.2f}", "fmtlib", 12.2311);
    // set log level
    elog::setLogLevel(elog::LogLevel::INFO);
    elog::debug("I will not be shown");
    std::vector<int> nums{1, 2, 3, 4};
    elog::error("vector nums: [{}]", fmt::join(nums, ", "));

    // you can also set output pattern
    elog::setPattern("[%M-%D %h:%m:%s.%f] [%L] [thread: %t] %v");
    elog::info("change format");

    // you can also use macro to log
    ELOG_ERROR("use macro: {}", "hhh");
    ELOG_WARN("Also use default logger, so pattern and level had been set");
}

#include "elog/sinks/rotating_file_sink.h"
void rollFileLog() {
    // synchronize log, output to terminal
    auto logger = elog::sync_factory::create<elog::sinks::RotatingFileSinkNullMutex>("logger_name",
                                                                                     "log/tmp.log");
    logger->debug("output to file");
    logger->info("when file bigger than max_size, it will create a new log file");
    // you can also set it to default logger, then you can use elog::...
    elog::setDefaultLogger(std::move(logger));
    elog::setLogLevel(elog::LogLevel::INFO);
    elog::debug("I will not be shown");
    std::vector<int> nums{1, 2, 3, 4};
    elog::error("vector nums: [{}]", fmt::join(nums, ", "));

    // you can also set output pattern
    elog::setPattern("[%M-%D %h:%m:%s.%f] [%L] [thread: %t] %v");
    elog::info("change format");
}

void asyncLog() {
    // asynchronize logger, you must use sinks with Mutex
    auto logger = elog::async_factory::create<elog::sinks::RotatingFileSinkMutex>("logger_name",
                                                                                  "log/async.log");
    logger->debug("output to file");
    logger->info("when file bigger than max_size, it will create a new log file");
    // you can also set it to default logger, then you can use elog::...
    elog::setDefaultLogger(std::move(logger));
    elog::setLogLevel(elog::LogLevel::INFO);
    elog::debug("I will not be shown");
    std::vector<int> nums{1, 2, 3, 4};
    elog::error("vector nums: [{}]", fmt::join(nums, ", "));

    // you can also set output pattern
    elog::setPattern("[%M-%D %h:%m:%s.%f] [%L] [thread: %t] %v");
    elog::info("change format");
}

void multiOutput() {
    std::shared_ptr<elog::sinks::Sink> sinker1 =
        std::make_shared<elog::sinks::StdColorSinkNullMutex>();
    std::shared_ptr<elog::sinks::Sink> sinker2 =
        std::make_shared<elog::sinks::RotatingFileSinkNullMutex>("log/hh.log");
    // for forward
    auto sinker_list = {sinker1, sinker2};
    auto logger = elog::make_unique<elog::Logger>("logger_name", sinker_list);
    logger->debug("output to both file and console");
    logger->info("when file bigger than max_size, it will create a new log file");
    // you can also set it to default logger, then you can use elog::...
    elog::setDefaultLogger(std::move(logger));
    elog::setLogLevel(elog::LogLevel::INFO);
    elog::debug("I will not be shown");
    std::vector<int> nums{1, 2, 3, 4};
    elog::error("vector nums: [{}]", fmt::join(nums, ", "));

    // you can also set output pattern
    elog::setPattern("[%M-%D %h:%m:%s.%f] [%L] [thread: %t] %v");
    elog::info("change format");
}

int main() {
    simpleLog();
    // rollFileLog();
    // asyncLog();
    // multiOutput();
}