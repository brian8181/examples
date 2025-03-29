#include <boost/regex.hpp>
#include <iostream>

bool validate_card_format(const std::string& s)
{
   static const boost::regex e("(\\d{4}[- ]){3}\\d{4}");
   return regex_match(s, e);
}

// match any format with the regular expression:
const boost::regex e("\\A(\\d{3,4})[- ]?(\\d{4})[- ]?(\\d{4})[- ]?(\\d{4})\\z");
const std::string machine_format("\\1\\2\\3\\4");
const std::string human_format("\\1-\\2-\\3-\\4");

std::string machine_readable_card_number(const std::string s)
{
   return regex_replace(s, e, machine_format, boost::match_default | boost::format_sed);
}

std::string human_readable_card_number(const std::string s)
{
   return regex_replace(s, e, human_format, boost::match_default | boost::format_sed);
}

int main()
{
    std::string str = "1234-1234-1234-1234";
    bool ret = validate_card_format(str);
    std::cout << "Is valid: " << ret << std::endl;

    std::string s1 = machine_readable_card_number(str);
    std::cout << "Machine Readable Card Number: " << str << std::endl;

    std::string s2 = human_readable_card_number(str);
    std::cout << "Human Readable Card Number: " << str << std::endl;

    return 0;
}
