/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; fill-column: 100 -*- */

#include <istream>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

std::string GetName(std::string line)
{
    size_t endchar = line.find_first_of("=");

    if (endchar != std::string::npos)
        return line.substr(0, endchar);

    return std::string("");
}

std::string GetValue(std::string line)
{
    size_t endchar = line.find_first_of("=");

    if (endchar == std::string::npos)
        return std::string("");

    std::string value = line.substr(endchar + 1, line.length());

    if (value[0] == '"'
        && value[value.length() - 1] == '"') // account for the newline as the last character
        value = value.substr(1, value.length() - 2);

    return value;
}

std::vector<std::string> GetLines(std::istream& in)
{
    std::vector<std::string> lines;

    for (std::string line; std::getline(in, line);)
    {
        lines.push_back(line);
    }

    return lines;
}

std::tuple<std::string, std::string> GetKeyValue(std::string line)
{
    std::string key = GetName(line);
    std::string value = GetValue(line);

    return std::make_tuple(key, value);
}

std::vector<std::pair<std::string, std::string>> GetKeyValues(std::vector<std::string> const& lines)
{
    std::vector<std::pair<std::string, std::string>> keyvalues;

    for (std::string const& line : lines)
    {
        auto [key, value] = GetKeyValue(line);
        keyvalues.push_back(std::pair(key, value));
    }

    return keyvalues;
}

/* vim:set shiftwidth=4 softtabstop=4 expandtab cinoptions=b1,g0,N-s cinkeys+=0=break: */
