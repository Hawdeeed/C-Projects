#ifndef UTILITY_H
#define UTILITY_H
#include <algorithm>
#include <string>
// Helper function to trim leading and trailing spaces
inline std::string trim(const std::string &str)
{
    const auto begin = str.find_first_not_of(" \t");
    if (begin == std::string::npos)
        return ""; // No non-whitespace characters
    const auto end = str.find_last_not_of(" \t");
    return str.substr(begin, end - begin + 1);
}

#endif // UTILITY_H