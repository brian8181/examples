#include <iostream>
#include <iomanip>
#include <random>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <chrono>
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
    long x;
    long y;
    int token = 0;
    unsigned long len = atoi(argv[1]);
    unsigned long rounds = atoi(argv[2]);
    long walk;
    long max_x = 0;
    long max_y = 0;
    long max_x_y = 0;
    vector<std::pair<int,int>> vwalk(len);
    std::stringstream ss;

    auto start = std::chrono::high_resolution_clock::now();
    for(int j = 0; j < rounds; ++j)
    {
        for(int i = 0; i < len; ++i)
        {
            int rv = distrib(gen);
            //walk += rv;

            switch(rv)
            {
                case right:
                    x += 1;

                    //if(token == right) cout << ">" << endl;
                    //token = right;
                break;
                case left:
                    x -= 1;
                    //if(token == left) cout << "<" << endl;
                    //token = left;
                break;
                case up:
                    y += 1;
                    //if(token == up) cout << "^" << endl;
                    //token = up;
                break;
                case down:
                    y -= 1;
                    //if(token == down) cout << "v" << endl;
                    //token = down;
                break;
            }

            max_x = abs(x) > abs(max_x) ? x : max_x;
            max_y = abs(y) > abs(max_y) ? y : max_y;
            max_x_y =  (abs(x) + abs(y)) > (abs(max_x) + abs(max_y)) ? (abs(x) + abs(y)) : (abs(max_x) + abs(max_y));

            vwalk.push_back(std::make_pair(x,y));
        }
        //auto max = std::max_element(vwalk.begin(), vwalk.end());
        //auto min = std::min_element(vwalk.begin(), vwalk.end());
        //std::cout << "max_x = " << *std::max_element(vwalk.begin(), vwalk.end()) << ", min = " << *min << endl;

        ss  << std::right << std::setw(8) << x << " " << std::right << std::setw(8) << y << " " << std::right << std::setw(8) << max_x << " " << std::right << std::setw(8) << max_y << " " << std::right << std::setw(8) << max_x_y << "\n";
        x = 0;
        y = 0;
        max_x = 0;
        max_y = 0;
        max_x_y = 0;
    }
    auto end = std::chrono::high_resolution_clock::now();

    cout << "[[\n" << ss.str() << "\t]]\n";

    auto mseconds = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    auto useconds = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Elapsed time: " << mseconds.count() << " milliseconds" << std::endl;
    float seconds = static_cast<double>(mseconds.count() / 1000);
    std::cout << len * rounds << " cycles, " <<  mseconds.count() << " milliseconds" << endl;
    std::cout <<  (long)((len * rounds) / mseconds.count() * 1000) / 1'000 << " KHz" << endl;

    return 0;
}
