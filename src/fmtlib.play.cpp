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

    fmt::print("Don't {}\n", "panic");

    // more examples
    double n = 1.123456789;
    fmt::print("n equal -> {0:+f}\n", n);

    // fmt::print("n equal -> {1:.2f}\n", n);

    // fmt::print("n equal -> {2:.3f}\n", n);

    // fmt::print("n equal -> {3:.4f} as float\n", n);

    //fmt::print("n equal -> {4:x} in hex\n", n);

}