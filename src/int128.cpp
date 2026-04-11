

class int128
{
public:
    int128() {};

    void add(int128 n)
    {
        int ci = 0;
        for(int i = 0; i < 4; ++i)
        {
            _n[i] += (n._n[i] + ci);
            if(_n[i] < (n._n[i] + ci))
                ci = _n[i] - (n._n[i] + ci);
        }
    }

private:
    unsigned char _n[4];

};


main()
{
    int128 n;
    return 0;
}
