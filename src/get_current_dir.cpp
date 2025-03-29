#include <filesystem>
#include <iostream>

using namespace std;

int main()
{
    std::filesystem::path cwd = std::filesystem::current_path();
    cout << cwd << endl;
}