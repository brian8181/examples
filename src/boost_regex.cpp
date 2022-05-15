#include <boost/lambda/lambda.hpp>
#include <boost/regex.hpp>
#include <iostream>
#include <iterator>
#include <algorithm>

bool validate_card_format(const std::string& s);

int main()
{
    using namespace boost::lambda;
    typedef std::istream_iterator<int> in;

    std::for_each(
       in(std::cin), in(), std::cout << (_1 * 3) << " " );

    std::cout << std::endl;


    bool ret = validate_card_format("1234-1234-1234-1234");

    std::cout << "Is valid: " << ret << std::endl;
}

bool validate_card_format(const std::string& s)
{
   static const boost::regex e("(\\d{4}[- ]){3}\\d{4}");
   return regex_match(s, e);
}
