#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/property_tree/detail/file_parser_error.hpp>
#include <iostream>

namespace pt = boost :: property_tree;


int main()
{
    std :: string xml_str = "<?xml version = \"1.0\" encoding = \"utf-8\"?>\
    <tv>\
        <series>\
            <name>Breaking Bad</name>\
            <genre>crime</genre>\
            <year>2008-2013</year>\
            <creator>Vince Gilligan</creator>\
            <imdb>9.4</imdb>\
            <stream>Netflix</stream>\
        </series>\
        <series>\
            <name>Game Of Thrones</name>\
            <genre>Adventure</genre>\
            <year>2011-2019</year>\
            <creator>David Benioff & D.B. Weiss</creator>\
            <imdb>9.4</imdb>\
            <stream>Netflix</stream>\
       </series>\
    </tv>";

    // Create an empty property tree object
    pt :: ptree tv_tree;

    try {
        std :: stringstream ss; 
        ss << xml_str;
        read_xml(ss, tv_tree);
    } catch (pt :: xml_parser_error &e) {
        std :: cout << "Failed to parse the xml string." << e.what();
    } catch (...) {
        std :: cout << "Failed !!!";
    }

    // get_child is used to find the node in xml for iterating over its children.
    // Note : get_child throws if the path cannot be resolved. 
    for (auto& p : tv_tree.get_child("tv")) {
        std :: cout << "[" << p.first << "]" << std :: endl;
        for (auto& c : p.second) {
            std :: cout << "Tag : [" << c.first.data() << "], ";
            std :: cout << "Value : [" << c.second.data() << "]" << std :: endl;
        }   
    }
    return 0;
}