#include <iostream>
#include <cstddef>
#include <cstdint>
#include <limits>


static_assert
(
        std::numeric_limits<bool>::is_integer
    &&  std::numeric_limits<std::size_t>::is_integer
    &&  std::numeric_limits<std::int32_t>::is_integer
    &&  std::numeric_limits<std::int64_t>::is_integer
    &&  std::numeric_limits<decltype(42)>::is_integer
    && !std::numeric_limits<int*>::is_integer
    && !std::numeric_limits<float>::is_integer
    && !std::numeric_limits<double>::is_integer
    && !std::numeric_limits<long double>::is_integer
    && !std::numeric_limits<decltype([](){})>::is_integer // P0315R4
);

int main()
{
    std::cout << std::numeric_limits<bool>::is_integer << std::endl;
}