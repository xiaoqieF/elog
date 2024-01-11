#pragma once

#include "clog/async_logger.h"
#include "clog/logger.h"
#include "clog/sinks/std_color_sink.h"

namespace clog {
inline Logger &defaultLogger() {
    static Logger default_logger("", std::make_shared<sinks::StdColorSinkNullMutex>());
    return default_logger;
}

inline void setLogLevel(LogLevel level) { defaultLogger().setLevel(level); }

inline void setPattern(const std::string &pattern) { defaultLogger().setPattern(pattern); }

template <typename... Args>
void trace(format_string_t<Args...> fmt, Args &&...args) {
    defaultLogger().trace(fmt, std::forward<Args>(args)...);
}

template <typename... Args>
void debug(format_string_t<Args...> fmt, Args &&...args) {
    defaultLogger().debug(fmt, std::forward<Args>(args)...);
}

template <typename... Args>
void info(format_string_t<Args...> fmt, Args &&...args) {
    defaultLogger().info(fmt, std::forward<Args>(args)...);
}

template <typename... Args>
void warn(format_string_t<Args...> fmt, Args &&...args) {
    defaultLogger().warn(fmt, std::forward<Args>(args)...);
}

template <typename... Args>
void error(format_string_t<Args...> fmt, Args &&...args) {
    defaultLogger().error(fmt, std::forward<Args>(args)...);
}

template <typename T>
void trace(const T &msg) {
    defaultLogger().trace(msg);
}

template <typename T>
void debug(const T &msg) {
    defaultLogger().debug(msg);
}

template <typename T>
void info(const T &msg) {
    defaultLogger().info(msg);
}

template <typename T>
void warn(const T &msg) {
    defaultLogger().warn(msg);
}

template <typename T>
void error(const T &msg) {
    defaultLogger().error(msg);
}

namespace sync_factory {
template <typename Sink, typename... SinkArgs>
std::unique_ptr<Logger> create(std::string logger_name, SinkArgs &&...args) {
    auto sinker = std::make_shared<Sink>(std::forward<SinkArgs>(args)...);
    return make_unique<Logger>(std::move(logger_name), sinker);
}
}; // namespace sync_factory

namespace async_factory {
template <typename Sink, typename... SinkArgs>
std::unique_ptr<Logger> create(std::string logger_name, SinkArgs &&...args) {
    auto sinker = std::make_shared<Sink>(std::forward<SinkArgs>(args)...);
    return make_unique<AsyncLogger>(std::move(logger_name), sinker);
}
} // namespace async_factory

} // namespace clog
