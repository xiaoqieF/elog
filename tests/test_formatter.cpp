#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "clog/common.h"
#include "clog/details/file_helper.h"
#include "clog/details/threadpool.h"
#include "clog/formatter.h"
#include "clog/logger.h"
#include "clog/sinks/console_mutex.h"
#include "clog/sinks/rotating_file_sink.h"
#include "clog/sinks/stdout_sink.h"

TEST_CASE("default formatter pattern") {
    using namespace clog;

    memory_buf_t dest;
    details::LogMsg msg("", LogLevel::INFO, "hwllo");
    auto formatter = make_unique<PatternFormatter>();
    formatter->format(msg, dest);
    REQUIRE(dest.size() == 39);
    formatter->setPattern("[%h:%m:%s.%f][%l] %v");
    dest.clear();
    formatter->format(msg, dest);
}
