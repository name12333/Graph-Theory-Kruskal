#include "Logger.h"
#include <ctime>
#include <iomanip>
#include <sstream>

/**
 * Logger类的日志记录函数
 * 该函数用于记录带有时间戳的日志信息
 * @param msg 要记录的日志消息内容
 */
void Logger::log(const std::string& msg) {
    // 获取当前时间
    std::time_t now = std::time(nullptr);
    std::tm tm_now;
    localtime_r(&now, &tm_now);

    // 格式化时间字符串
    std::ostringstream timeStream;
    timeStream << std::put_time(&tm_now, "%Y-%m-%d %H:%M:%S");

    // 输出带时间戳的日志
    std::cout << "[" << timeStream.str() << "] [LOG] " << msg << std::endl;
}

void Logger::result(const std::string& msg) {
    // 获取当前时间
    std::time_t now = std::time(nullptr);
    std::tm tm_now;
    localtime_r(&now, &tm_now);

    // 格式化时间字符串
    std::ostringstream timeStream;
    timeStream << std::put_time(&tm_now, "%Y-%m-%d %H:%M:%S");

    // 输出带时间戳的结果
    std::cout << "[" << timeStream.str() << "] [RESULT] " << msg << std::endl;
}
