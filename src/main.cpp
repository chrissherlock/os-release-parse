/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; fill-column: 100 -*- */

#include <filesystem>
#include <iostream>
#include <string>

namespace fs = std::filesystem;

static std::string getArgument(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " FILENAME" << std::endl;
        std::exit(1);
    }

    fs::path f { argv[1] };
    if (fs::exists(f))
    {
        return argv[1];
    }
    else
    {
        std::cerr << "invalid filename" << std::endl;
        std::exit(1);
    }
}

int main(int argc, char** argv)
{
    std::string filename(getArgument(argc, argv)); 
}

/* vim:set shiftwidth=4 softtabstop=4 expandtab cinoptions=b1,g0,N-s cinkeys+=0=break: */
