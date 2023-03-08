#include <iostream>
#include <type_traits>
#include <fmt/format.h>

struct A {
  virtual ~A() {}
  virtual std::string name() const { return "A"; }
};

struct B : A {
  virtual std::string name() const { return "B"; }
};

template <typename T>
struct fmt::formatter<T, std::enable_if_t<std::is_base_of<A, T>::value, char>> :
    fmt::formatter<std::string> {
  template <typename FormatCtx>
  auto format(const A& a, FormatCtx& ctx) const {
    return fmt::formatter<std::string>::format(a.name(), ctx);
  }
};

int main() {
  B b;
  A& a = b;
  fmt::print("{}", a); // prints "B"
  std::cout << std::endl;
}