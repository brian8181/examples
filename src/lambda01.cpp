#include <iostream>
#include <utility>

using namespace std;

int main()
{
    // generic lambda, operator() is a template with two parameters
    auto glambda = [](auto a, auto&& b) { return a < b; };
    bool b = glambda(3, 3.14); // OK

    // generic lambda, operator() is a template with one parameter
    auto vglambda = [](auto printer)
    {
        return [=](auto&&... ts) // generic lambda, ts is a parameter pack
        {
            printer(std::forward<decltype(ts)>(ts)...);
            // nullary lambda (takes no parameters):
            return [=] { printer(ts...); };
        };
    };

    auto p = vglambda([](auto v1, auto v2, auto v3)
    {
        std::cout << v1 << v2 << v3;
    });

    auto q = p(1, 'a', 3.14); // outputs 1a3.14
    q();

    return 0;
}
