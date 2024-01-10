#include <iostream>
#include <mutex>

#include "clog/async_logger.h"
#include "clog/async_logger_base.h"
#include "clog/common.h"
#include "clog/details/async_log_msg.h"
#include "clog/formatter.h"
#include "clog/logger.h"
#include "clog/sinks/rotating_file_sink.h"
#include "clog/sinks/stdout_sink.h"

int main() {
    using namespace clog;
    auto logger = std::make_shared<AsyncLogger>(
        "log_name", std::make_shared<sinks::RotatingFileSinkMutex>("./log/tmp.log"), 2);
    // Logger logger("log_name",
    // std::make_shared<sinks::RotatingFileSinkMutex>("./log/tmp.log",
    //                                                                          1024 * 1024 *
    //                                                                          300));
    logger->setFlushLevel(LogLevel::NUM_LEVELS);
    auto begin = std::chrono::steady_clock::now();
    for (int i = 0; i < 1000000; ++i) {
        logger->error("{} world", 2.821312312);

        logger->debug("hello {}", 123);
        logger->info("{} {} {}", 1.2, 222, "hello");
        // logger->debug("hello");
        logger->debug("hello {}", 123);
        logger->info("{} {} {}", 1.2, 222, "hello");
        // logger->debug("hellofashduifhuiwehfiuwahefuiawheuif");
        // logger->debug("hellojawfieojweoifjioawjefoeiwafjoiweajfoiawjefoi");
        logger->debug("hello {}", 123);
        logger->info("{} {} {}", 1.2, 222, "hello");
    }
    auto end = std::chrono::steady_clock::now();
    std::cout << "cost: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count()
              << " ms " << std::endl;

    // std::this_thread::sleep_for(std::chrono::seconds(2));
}