/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; fill-column: 100 -*- */

#include <istream>
#include <string>
#include <vector>
#include <tuple>
#include <utility>

std::string GetName(std::string line);
std::string GetValue(std::string line);
std::vector<std::string> GetLines(std::istream& in);
std::tuple<std::string, std::string> GetKeyValue(std::string line);
std::vector<std::pair<std::string, std::string>> GetKeyValues(std::vector<std::string> const& lines);

/* vim:set shiftwidth=4 softtabstop=4 expandtab cinoptions=b1,g0,N-s cinkeys+=0=break: */
