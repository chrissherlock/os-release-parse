/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; fill-column: 100 -*- */

#include <string>

std::string GetName(std::string line)
{
    size_t endchar = line.find_first_of("=");
    if (endchar != std::string::npos)
        return line.substr(0, endchar);

    return std::string("");
}

/* vim:set shiftwidth=4 softtabstop=4 expandtab cinoptions=b1,g0,N-s cinkeys+=0=break: */
