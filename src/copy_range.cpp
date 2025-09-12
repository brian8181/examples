#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using std::copy;
using std::cout;
using std::vector;

int main()
{
    std::vector<int> src {1,2,3,4,5,6,7,8,9,0};
    std::vector<int> tgt;
    int const n = 5;
    tgt.resize(n);
    copy(begin(src)+3, begin(src)+8, begin(tgt));
    for (int x : tgt) { cout << x << ' '; }  // 4 5 6 7 8
    cout << std::endl;
}
