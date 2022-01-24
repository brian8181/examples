#include <filesystem>
#include <string>

using recursive_directory_iterator = std::filesystem::recursive_directory_iterator;

std::string myPath = "~/src";

for (const auto& dirEntry : recursive_directory_iterator(myPath))
{
     std::cout << dirEntry << std::endl;
}