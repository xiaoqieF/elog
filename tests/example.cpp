#include "clog/clog.h"
#include "clog/sinks/rotating_file_sink.h"

int main() {
    auto logger = clog::sync_factory::create<clog::sinks::RotatingFileSinkNullMutex>(
        "logger1", "log/master.log");
    for (int i = 0; i < 100000; ++i) {
        logger->info("hello world");
        logger->debug("the price is {}", 123);
        logger->error("float: {:.2f}", 12.33333);
        logger->setPattern("[%h:%m:%s.%f] [%L] %v");
        logger->info("hello world");
        logger->debug("the price is {}", 123);
        logger->error("float: {:.2f}", 12.33333);
    }
}