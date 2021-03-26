#pragma once
#include <vector>
#include <string>
#include <sstream>
std::vector<std::string> SplitLine(std::string line, char delimiter)
{
    std::vector<std::string> result;
    std::stringstream string_stream(line);
    std::string substring;
    while (getline(string_stream, substring, delimiter))
        result.push_back(substring);
    return result;
}
