#include <print>
#include <string_view>

namespace Debug {
inline void info(std::string_view str) { std::println("INFO: {}", str); }
inline void warn(std::string_view str) { std::println("WARN: {}", str); }
inline void error(std::string_view str) { std::println("ERROR: {}", str); }
} // namespace Debug
