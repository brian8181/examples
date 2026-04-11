/**
 * @file    int256.hpp
 * @version 0.0.1
 * @date    Sun, 28 Sep 2025 01:13:35 +0000
 * @info    ...
 */
#include "int256.hpp"

int256::int256()
{
    _n[0] = 0;
    _n[1] = 0;
    _n[2] = 0;
    _n[3] = 0;
}

int256::int256( const int256& src )
{

}

int256::~int256()
{

}

void int256::add(int256 n)
{
    int ci = 0;
    for(int i = 0; i < 4; ++i)
    {
        _n[i] += (n._n[i] + ci);
        if(_n[i] < (n._n[i] + ci))
            ci = _n[i] - (n._n[i] + ci);
    }
}

void int256::to_string()
{

}

int main()
{
    int256 n;
    n.add(1);
    return 0;
}
