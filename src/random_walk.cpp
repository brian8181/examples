#include <iostream>
#include <iomanip>
#include <random>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{

    enum direction
    {
        right = 1,
        left = 2,
        up = 3,
        down = 4
    };
    // Initialize a random number generator
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(1, 4);

    // Generate random number in the range [min, max]

    int x;
    int y;

    int len = atoi(argv[1]);
    int walk;
    vector<std::pair<int,int>> vwalk(len);
    for(int i = 0; i < len; ++i)
    {
        int rv = distrib(gen);
        //walk += rv;

        switch(rv)
        {
            case right:
                x += 1;
            break;
            case left:
                x -= 1;
            break;
            case up:
                y += 1;
            break;
            case down:
                y -= 1;
            break;
        }


        vwalk.push_back(std::make_pair(x,y));


        //std::cout << walk << " ";
        //if( i%25 == 0 ) std::cout << endl;
    }
    std::cout << endl;

    // auto max = std::max_element(vwalk.begin(), vwalk.end());
    // auto min = std::min_element(vwalk.begin(), vwalk.end());
    auto beg = vwalk.begin();
    auto end = vwalk.end();
    //std::cout << "max_x = " << *std::max_element(beg, end) << ", min = " << *min << endl;
    std::cout << "x = " << x << ", y = " << y << endl;
    return 0;
}
