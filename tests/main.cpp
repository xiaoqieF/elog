#include <iostream>
#include <mutex>

#include "clog/async_logger.h"
#include "clog/async_logger_base.h"
#include "clog/clog.h"
#include "clog/common.h"
#include "clog/details/async_log_msg.h"
#include "clog/formatter.h"
#include "clog/logger.h"
#include "clog/sinks/rotating_file_sink.h"
#include "clog/sinks/std_color_sink.h"
#include "clog/sinks/stdout_sink.h"

int main() {
    // using namespace clog;
    // AsyncLogger logger("log_name",
    //                    std::make_shared<sinks::RotatingFileSinkMutex>("log/master.log"));
    // logger.setFlushLevel(LogLevel::NUM_LEVELS);
    // auto begin = std::chrono::steady_clock::now();
    // for (int i = 0; i < 100000; ++i) {
    //     logger.error("{} world", 2.821312312);

    //     logger.debug("hello {}", 123);
    //     logger.info("{} {} {}", 1.2, 222, "hello");
    //     logger.trace("hello");
    //     logger.warn("hello {}", 123);
    //     logger.info("{} {} {}", 1.2, 222, "hello");
    //     // logger->debug("hellofashduifhuiwehfiuwahefuiawheuif");
    //     // logger->debug("hellojawfieojweoifjioawjefoeiwafjoiweajfoiawjefoi");
    //     logger.debug("hello {}", 123);
    //     logger.info("{} {} {}", 1.2, 222, "hello");
    // }
    // auto end = std::chrono::steady_clock::now();
    // std::cout << "cost: "
    //           << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count()
    //           << " ms " << std::endl;

    CLOG_DEBUG("{} world", 2.821312312);

    CLOG_DEBUG("hello {}", 123);
    clog::info("{} {} {}", 1.2, 222, "hello");
    clog::trace("hello");
    // clog::setLogLevel(LogLevel::INFO);
    clog::warn("hello {}", 123);
    clog::setPattern("[%L] %v");
    clog::info("{} {} {}", 1.2, 222, "hello");
    clog::trace("hello");
    clog::trace("hello");
    clog::trace("hello");

    // std::this_thread::sleep_for(std::chrono::seconds(2));
}