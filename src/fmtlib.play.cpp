#include <iostream>
#include <type_traits>
#include <fmt/format.h>

using namespace std;

int main()
{
    std::string s = fmt::format("The answer is {}.", 42);
    cout << s << endl;

    std::string s1 = fmt::format("The answer is {0}, the question is {1}", 42, 55);
    cout << s1 << endl;

    fmt::print("I'd rather be {1} than {0}.", "right", "happy");
    cout << endl;

}