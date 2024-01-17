#include <fstream>
#include <iostream>

struct mybuf : std::filebuf
{
    pos_type seekpos(pos_type sp, std::ios_base::openmode which)
    {
        std::cout << "Before seekpos(" << sp << "), size of the get area is "
                  << egptr() - eback() << " with "
                  << egptr() - gptr() << " read positions available.\n";

        pos_type rc = std::filebuf::seekpos(sp, which);

        std::cout << "seekpos() returns " << rc << ".\nAfter the call, "
                  << "size of the get area is "
                  << egptr() - eback() << " with "
                  << egptr() - gptr() << " read positions available.\n";
// uncomment if get area is emptied by seekpos()
//        std::filebuf::underflow();
//        std::cout << "after forced underflow(), size of the get area is "
//                  << egptr() - eback() << " with "
//                  << egptr() - gptr() << " read positions available.\n";

        return rc;
    }
};

int main()
{
    mybuf buf;
    buf.open("test.txt", std::ios_base::in);
    std::istream stream(&buf);
    stream.get(); // read one char to force underflow()
    stream.seekg(2);
}