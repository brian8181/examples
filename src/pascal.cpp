#include <iostream>
#include <vector>


using namespace std;

int main(int argc, char* arg[])
{

    vector<vector<int>> v;
    vector<int> row;

    row.push_back(1);
    row.push_back(1);
    v.push_back(row);

    cout << v[0][0] << row[0] << row[1];

    // int n = 25;
    // for(int i = 0; i < n; ++i)
    // {
    //     cout << v[i][0];
    //     int len = v.size();
    //     for(int j = 0; j < len-1; ++j)
    //     {
    //         cout << v[i][j] + v[i][j+1] ;
    //     }
    //     cout << v[i][len-1];
    //     row.clear();
    //     v.push_back(row);
    // }

    
}