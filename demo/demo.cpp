#include "sha-1.h"
#include <iostream>

int main ( int argc, char ** argv )
{
    const unsigned char text[] =
        "The quick brown fox jumps over the lazy dog";
    unsigned char hash[20];
    sha1_compute(text, sizeof(text)-1, hash);
    char display[40];
    sha1_hexstring(hash, display);
    std::cout.write(display, 40) << std::endl;
}
