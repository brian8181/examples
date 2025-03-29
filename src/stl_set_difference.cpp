#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>


// template<class InputIt1, class InputIt2, class OutputIt>
// OutputIt set_difference(InputIt1 first1, InputIt1 last1,
//                         InputIt2 first2, InputIt2 last2, OutputIt d_first)
// {
//     while (first1 != last1)
//     {
//         if (first2 == last2)
//             return std::copy(first1, last1, d_first);
 
//         if (*first1 < *first2)
//             *d_first++ = *first1++;
//         else
//         {
//             if (! (*first2 < *first1))
//                 ++first1;
//             ++first2;
//         }
//     }
//     return d_first;
// }

// template<class InputIt1, class InputIt2, class OutputIt, class Compare>
// OutputIt set_difference(InputIt1 first1, InputIt1 last1,
//                         InputIt2 first2, InputIt2 last2, OutputIt d_first, Compare comp)
// {
//     while (first1 != last1)
//     {
//         if (first2 == last2)
//             return std::copy(first1, last1, d_first);
 
//         if (comp(*first1, *first2))
//             *d_first++ = *first1++;
//         else
//         {
//             if (!comp(*first2, *first1))
//                 ++first1;
//             ++first2;
//         }
//     }
//     return d_first;
// }
 
template<typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T> const& v)
{
    os << '{';
    for (auto n{v.size()}; auto const& e : v)
        os << e << (--n ? ", " : "");
    return os << '}';
}
 
struct Order // a struct with very interesting data
{
    int order_id{};
 
    friend std::ostream& operator<<(std::ostream& os, const Order& ord)
    {
        return os << ord.order_id;
    }
};
 
int main()
{
    const std::vector<int> v1{1, 2, 5, 5, 5, 9};
    const std::vector<int> v2{2, 5, 7};
    std::vector<int> diff;
 
    std::set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(),
                        std::inserter(diff, diff.begin()));
 
    std::cout << v1 << " ∖ " << v2 << " == " << diff << "\n\n";
 
    // we want to know which orders "cut" between old and new states:
    std::vector<Order> old_orders{{1}, {2}, {5}, {9}};
    std::vector<Order> new_orders{{2}, {5}, {7}};
    std::vector<Order> cut_orders;
 
    std::set_difference(old_orders.begin(), old_orders.end(),
                        new_orders.begin(), new_orders.end(),
                        std::back_inserter(cut_orders),
                        [](auto& a, auto& b) { return a.order_id < b.order_id; });
 
    std::cout << "old orders: " << old_orders << '\n'
              << "new orders: " << new_orders << '\n'
              << "cut orders: " << cut_orders << '\n';
}