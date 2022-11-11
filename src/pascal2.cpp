#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
    long size = 10;
    vector< vector<unsigned long>> mat;
    mat.reserve(100);
    mat[0][0] = 1;
    for(int i = 1; i < size; ++i)
    {
        mat[i][0] = 1;
        cout << 1;
        for(int j = 1; j < size; ++j)
        {
            mat[i][j] = mat[i-1][j] + mat[i][j];
            cout << " " << mat[i][j];
        }
        mat[i][size-1] = 1; 
        cout << " " << 1 << endl;
    }
    mat[size-1][size-1] = 1;

	return 0;
}
