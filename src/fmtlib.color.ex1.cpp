// color.h:
#include <fmt/core.h>

enum class color {red, green, blue};

template <> struct fmt::formatter<color>: formatter<string_view> {
  // parse is inherited from formatter<string_view>.

  auto format(color c, format_context& ctx) const;
};

// color.cc:
//#include "color.h"
#include <fmt/format.h>

auto fmt::formatter<color>::format(color c, format_context& ctx) const {
  string_view name = "unknown";
  switch (c) {
  case color::red:   name = "red"; break;
  case color::green: name = "green"; break;
  case color::blue:  name = "blue"; break;
  }
  return formatter<string_view>::format(name, ctx);
}


#include <fmt/format.h>

struct point {
  double x, y;
};

template <>
struct fmt::formatter<point> : nested_formatter<double> {
  auto format(point p, format_context& ctx) const {
    return write_padded(ctx, [=](auto out) {
      return format_to(out, "({}, {})", nested(p.x), nested(p.y));
    });
  }
};

int main() {
  fmt::print("[{:>20.2f}]", point{1, 2});
}