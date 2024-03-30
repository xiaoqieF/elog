#include <vector>

#include "clog/clog.h"

void simpleLog() {
    // synchronize log, output to terminal
    // will use default logger
    clog::info("hello world. This use default logger");
    clog::debug("you can use format like {}, number:{:.2f}", "fmtlib", 12.2311);
    // set log level
    clog::setLogLevel(clog::LogLevel::INFO);
    clog::debug("I will not be shown");
    std::vector<int> nums{1, 2, 3, 4};
    clog::error("vector nums: [{}]", fmt::join(nums, ", "));

    // you can also set output pattern
    clog::setPattern("[%M-%D %h:%m:%s.%f] [%L] [thread: %t] %v");
    clog::info("change format");

    // you can also use macro to log
    CLOG_ERROR("use macro: {}", "hhh");
    CLOG_WARN("Also use default logger, so pattern and level had been set");
}

#include "clog/sinks/rotating_file_sink.h"
void rollFileLog() {
    // synchronize log, output to terminal
    auto logger = clog::sync_factory::create<clog::sinks::RotatingFileSinkNullMutex>("logger_name",
                                                                                     "log/tmp.log");
    logger->debug("output to file");
    logger->info("when file bigger than max_size, it will create a new log file");
    // you can also set it to default logger, then you can use clog::...
    clog::setDefaultLogger(std::move(logger));
    clog::setLogLevel(clog::LogLevel::INFO);
    clog::debug("I will not be shown");
    std::vector<int> nums{1, 2, 3, 4};
    clog::error("vector nums: [{}]", fmt::join(nums, ", "));

    // you can also set output pattern
    clog::setPattern("[%M-%D %h:%m:%s.%f] [%L] [thread: %t] %v");
    clog::info("change format");
}

void asyncLog() {
    // asynchronize logger, you must use sinks with Mutex
    auto logger = clog::async_factory::create<clog::sinks::RotatingFileSinkMutex>("logger_name",
                                                                                  "log/async.log");
    logger->debug("output to file");
    logger->info("when file bigger than max_size, it will create a new log file");
    // you can also set it to default logger, then you can use clog::...
    clog::setDefaultLogger(std::move(logger));
    clog::setLogLevel(clog::LogLevel::INFO);
    clog::debug("I will not be shown");
    std::vector<int> nums{1, 2, 3, 4};
    clog::error("vector nums: [{}]", fmt::join(nums, ", "));

    // you can also set output pattern
    clog::setPattern("[%M-%D %h:%m:%s.%f] [%L] [thread: %t] %v");
    clog::info("change format");
}

void multiOutput() {
    std::shared_ptr<clog::sinks::Sink> sinker1 =
        std::make_shared<clog::sinks::StdColorSinkNullMutex>();
    std::shared_ptr<clog::sinks::Sink> sinker2 =
        std::make_shared<clog::sinks::RotatingFileSinkNullMutex>("log/hh.log");
    // for forward
    auto sinker_list = {sinker1, sinker2};
    auto logger = clog::make_unique<clog::Logger>("logger_name", sinker_list);
    logger->debug("output to both file and console");
    logger->info("when file bigger than max_size, it will create a new log file");
    // you can also set it to default logger, then you can use clog::...
    clog::setDefaultLogger(std::move(logger));
    clog::setLogLevel(clog::LogLevel::INFO);
    clog::debug("I will not be shown");
    std::vector<int> nums{1, 2, 3, 4};
    clog::error("vector nums: [{}]", fmt::join(nums, ", "));

    // you can also set output pattern
    clog::setPattern("[%M-%D %h:%m:%s.%f] [%L] [thread: %t] %v");
    clog::info("change format");
}

int main() {
    simpleLog();
    // rollFileLog();
    // asyncLog();
    // multiOutput();
}