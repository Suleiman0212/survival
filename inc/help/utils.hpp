#include "help/debug.hpp"
#include <cstdlib>
#include <string_view>

namespace Utils {
inline void panic(std::string_view str) {
  Debug::error(str);
  exit(-1);
}
inline void quit() { exit(-1); }
} // namespace Utils
