#include <algorithm>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <random>
#include <sstream>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) 
{
  enum direction { right = 1, left = 2, up = 3, down = 4 };
  // Initialize a random number generator
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<> distrib(1, 4);

  // Generate random number in the range [min, max]
  long x = 0;
  long y = 0;
  int token = 0;
  unsigned long len = atoi(argv[1]);
  unsigned long rounds = atoi(argv[2]);
  long walk;
  long max_x = 0;
  long max_y = 0;
  long max_x_y = 0;
  vector<std::pair<int, int>> vwalk;
  vwalk.push_back(std::make_pair(x, y));
  std::stringstream ss;

  auto start = std::chrono::high_resolution_clock::now();
  int j = 0;
  for (; j < rounds; ++j) 
  {
    std::cout << "Round = " << j << endl;
    for (int i = 0; i < len; ++i) 
    {
      vwalk.push_back(std::make_pair(x, y));
      if (argv[3] && (x > 5 || x < -5 || y > 5 || y < -5)) 
      {
        for (int n = 0; n < vwalk.size(); ++n) 
        {
          std::cout << n << "(" << vwalk[n].first << "," << vwalk[n].second
                    << "), ";
        }
        std::cout << std::endl << std::endl;
        vwalk.clear(); // BKP hu?? 
        i = len;
        break;
      }
      int rv = distrib(gen);
      // walk += rv;

      switch (rv) 
      {
      case right:
        x += 1;
        // if(token == right) cout << ">" << endl;
        // token = right;
        break;
      case left:
        x -= 1;
        // if(token == left) cout << "<" << endl;
        // token = left;
        break;
      case up:
        y += 1;
        // if(token == up) cout << "^" << endl;
        // token = up;
        break;
      case down:
        y -= 1;
        // if(token == down) cout << "v" << endl;
        // token = down;
        break;
      }

      max_x = abs(x) > abs(max_x) ? x : max_x;
      max_y = abs(y) > abs(max_y) ? y : max_y;
      max_x_y = (abs(x) + abs(y)) > (abs(max_x) + abs(max_y)) ? (abs(x) + abs(y)) : (abs(max_x) + abs(max_y));
    }
    // auto max = std::max_element(vwalk.begin(), vwalk.end());
    // auto min = std::min_element(vwalk.begin(), vwalk.end());
    // std::cout << "max_x = " << *std::max_element(vwalk.begin(), vwalk.end())
    // << ", min = " << *min << endl;

    int total_x = 0;
    int total_y = 0;

    for (int i = 0; i < vwalk.size(); ++i) 
    {
      total_x += vwalk[i].first;
      total_y += vwalk[i].second;
    }

    double avg_x = static_cast<double>(total_x) / len;
    double avg_y = static_cast<double>(total_y) / len;
    // cout << "Average x = " << avg_x << ", Average y = " << avg_y << endl;
    // cout << "Total steps = " << vwalk.size() << endl;

    ss << "x = " << std::setw(4) << std::right << x << std::left << "   |   "
       << std::left << "y = " << std::setw(4) << std::right << y << "   |   "
       << std::left << "max x = " << std::setw(4) << std::right << max_x
       << "   |   " << std::left << "max y = " << std::setw(4) << std::right
       << max_y << "   |   " << std::left << "max x+y = " << std::setw(4)
       << std::right << max_x_y << "   |   " << std::left
       << "average x = " << std::setw(4) << std::right << avg_x << "   |   "
       << std::left << "average y = " << std::setw(4) << std::right << avg_y
       << "\n";

    //    ss << "last x = " << std::setw(4) << std::right << last.first <<
    //    std::left << "   |   "
    //       << std::left << "last y = " << std::setw(4) << std::right <<
    //       last.second << "\n";

    x = 0;
    y = 0;
    max_x = 0;
    max_y = 0;
    max_x_y = 0;
    avg_x = 0;
    avg_y = 0;
    total_x = 0;
    total_y = 0;
  }

  auto end = std::chrono::high_resolution_clock::now();
  std::cout << "[[\n" << ss.str() << "\t]]\n";

  auto mseconds =
      std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
  auto useconds =
      std::chrono::duration_cast<std::chrono::microseconds>(end - start);
  std::cout << "Elapsed time: " << mseconds.count() << " milliseconds"
            << std::endl;
  float seconds = static_cast<double>(mseconds.count() / 1000);
  std::cout << len * rounds << " cycles, " << mseconds.count()
            << " milliseconds" << std::endl;
  std::cout << (long)((len * rounds) / mseconds.count() * 1000) / 1'000
            << " KHz" << std::endl;
  return 0;
}
