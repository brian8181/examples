#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char** argv)
{
    int severity = 1;
    unsigned error = 42;
    auto reason = "access denied";

    std::stringstream ss;
    ss << "severity=" << severity
        << ",error=" << error
        << ",reason=" << reason;

    //std::string text = ss.str();

    cout << ss.str() << endl;
}