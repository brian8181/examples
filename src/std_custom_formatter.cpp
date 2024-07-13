#include <format>
#include <iostream>
#include <vector>

using namespace std;

template<typename T>
struct std::formatter<vector<T>>
{
  constexpr auto
    parse(format_parse_context& parse_ctx)  {
    auto iter = parse_ctx.begin();
    auto get_char = [&]() { return iter
      != parse_ctx.end() ? *iter : 0; };
    char c = get_char();
    if (c == 0 || c == '}')   // 1
    {
      m_val_fmt.parse(parse_ctx);   // 2
      return iter;
    }
    auto get_next_char = [&]() {   // 3
      ++iter;
      char vc = get_char();
      if (vc == 0)
      {
        throw format_error(
          "Invalid vector format specification");
      }
      return vc;
    };
    if (c == 'w')   // 4
    {
      m_lc = get_next_char();
      m_rc = get_next_char();
      ++iter;
    }
    if ((c = get_char()) == 's')   // 5
    {
       m_sep = get_next_char();
       ++iter;
    }
    if ((c = get_char()) == '/' || c == '}') // 6
    {
      if (c == '/')   // 7
      {
        ++iter;
      }
      parse_ctx.advance_to(iter);   // 8
      iter = m_val_fmt.parse(parse_ctx);   // 9
    }
    if ((c = get_char()) != 0 && c != '}')  // 10
    {
      throw format_error(
        "Invalid vector format specification");
    }
    return iter;
  }
  auto format(const vector<T>& vec,
    format_context& format_ctx) const
  {
    auto pos = format_ctx.out();    // 11
    bool need_sep = false;
    for (const auto& val : vec)
    {
      if (need_sep)   //  12
      {
        *pos++ = m_sep;
        if (m_sep != ' ')
        {
          *pos++ = ' ';
        }
      }
      if (m_lc != '\0')   //  13
      {
        *pos++ = m_lc;
      }
      format_ctx.advance_to(pos); //  14
      pos = m_val_fmt.format(val,
        format_ctx);   // 15
      if (m_rc != '\0')   //  16
      {
        *pos++ = m_rc;
      }
      need_sep = true;
    }
    return pos;
  }
private:
  char m_lc = '\0';
  char m_rc = '\0';
  char m_sep = ' ';
  formatter<T> m_val_fmt; // 17
};

int main()
{
  vector<int> vec{1, 2, 4, 8, 16, 32};
  cout << format("{}\n", vec);            // a
  cout << format("{:w[]}\n", vec);        // b
  cout << format("{:s,}\n", vec);         // c
  cout << format("{:w[]s,}\n", vec);      // d
  cout << format("{:w[]/3}\n", vec);      // e
  cout << format("{:s;/+0{}}\n", vec, 5); // f
  vector<vector<int>> vec2{ {1, 2, 3},
    {40, 50, 60}, {700, 800, 900} };
  cout << format("{}\n", vec2);           // g
  cout << format("{:w[]}\n", vec2);       // h
  cout << format("{:s,}\n", vec2);        // i
  cout << format("{:w[]s,}\n", vec2);     // j
  cout << format("{:w[]/s,}\n", vec2);    // k
  cout << format("{:s;/s,/03}\n", vec2);  // l
}