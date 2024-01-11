#include "clog/clog.h"
#include "clog/sinks/rotating_file_sink.h"

void simpleOutput() {}

int main() {
    auto logger = clog::async_factory::create<clog::sinks::RotatingFileSinkNullMutex>(
        "logger", "log/tmp.log");
    logger->warn("{} {}", "hello", 123);
    logger->debug("{} {:2f}", "hello", 123.213);
    logger->info("{} {:4f}", "hello", 123.213123);
}