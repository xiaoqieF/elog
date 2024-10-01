#include <chrono>
#include <random>
#include <thread>
#include <vector>

#include "elog/elog.h"
#include "elog/logger_factory.h"
#include "elog/sinks/rotating_file_sink.h"
#include "elog/sinks/std_color_sink.h"

void initElog() {
    auto logger = elog::async_factory::create<elog::sinks::RotatingFileSinkMutex>("logger_name",
                                                                                  "log/test.log");
    // auto logger = elog::sync_factory::create<elog::sinks::StdColorSinkMutex>("stdlog");
    logger->setLevel(elog::LogLevel::TRACE);
    elog::setDefaultLogger(std::move(logger));
}

void thread1(const std::string& thread_name) {
    std::mt19937 mt;
    std::uniform_int_distribution<> dist(0, 5);

    const size_t LOG_NUM = 1000000;
    for (int i = 0; i < LOG_NUM; ++i) {
        elog::info("log from {}, content: {}", thread_name, i);
        std::this_thread::sleep_for(std::chrono::microseconds(dist(mt)));
    }
}

int main() {
    initElog();
    const size_t THREAD_NUM = 10;
    std::vector<std::thread> threads;
    for (int i = 0; i < THREAD_NUM; ++i) {
        threads.emplace_back(thread1, fmt::format("thread[{}]", i));
    }
    for (auto& t : threads) {
        t.join();
    }
    return 0;
}