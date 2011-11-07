/*
 *  sha.cpp
 *
 *  Copyright (C) 1998, 2009
 *  Paul E. Jones <paulej@packetizer.com>
 *  All Rights Reserved
 *
 *****************************************************************************
 *  $Id: sha.c 12 2009-06-22 19:34:25Z paulej $
 *****************************************************************************
 *
 *  Description:
 *      This utility will display the message digest (fingerprint) for
 *      the specified file(s).
 *
 *  Portability Issues:
 *      None.
 */

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include "Digest.hpp"

namespace {

    void usage()
    {
        std::cout
            << "usage: sha [<file> ...]"
            << std::endl
            << std::endl;
    }

}

int main ( int argc, char ** argv )
try
{
    if ((argc > 1) && ((strcmp(argv[1],"-?")     == 0) ||
                       (strcmp(argv[1],"--help") == 0)))
    {
        usage();
        return (EXIT_FAILURE);
    }

    if ( argc < 2 )
    {
        sha1::Digest digest;
        digest.update(std::cin);
        std::cout
            << (std::string)digest.result()
            << std::endl;
    }
    for ( int i = 1; (i < argc); ++i )
    {
        std::ifstream stream(argv[i], std::ios::binary);
        if (!stream.is_open())
        {
            std::cerr
                << "Could not open '" << argv[i] << "' for reading."
                << std::endl;
            return (EXIT_FAILURE);
        }
        sha1::Digest digest;
        digest.update(stream);
        std::cout
            << (std::string)digest.result()
            << std::endl;
    }
}
catch ( const std::exception& error )
{
    std::cerr
        << "Uncaught exception: '" << error.what() << "'."
        << std::endl;
    return (EXIT_FAILURE);
}
catch ( ... )
{
    std::cerr
        << "Uncaught exception of unkown type."
        << std::endl;
    return (EXIT_FAILURE);
}
