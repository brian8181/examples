#include <iostream>
#include <string>
#include <string_view>
#include <stdexcept>
#include <charconv>

using namespace std;

/* Primary template, default implementation */
template <class T>
struct string_converter 
{
    T scan(std::string_view s) const 
    {
        T a;
        std::from_chars(s.begin(), s.end(), a);
        // error checking omitted
        return a;
    }
};

/* Specialization for bool */
template <>
struct string_converter<bool> 
{
    bool scan(std::string_view s) const 
    {
        if (s == "true") return true;
        if (s == "false") return false;
        throw std::runtime_error("bad bool: " + std::string(s));
    }
};

int main()
{
    string_converter<char> sc;
    string_view sv("Test");
    char s = sc.scan(sv);
    cout << s << endl;

    return 0;
}