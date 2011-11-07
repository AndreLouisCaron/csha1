#ifndef _sha1_Digest_hpp__
#define _sha1_Digest_hpp__

/*!
 * @file Digest.hpp
 * @author Andre Caron (andre.l.caron@gmail.com)
 * @brief C++ wrapper for SHA-1 digest accumulator.
 */

#include "sha-1.h"
#include <cstddef>
#include <cstring>
#include <istream>
#include <stdexcept>

namespace sha1 {

    class Hash
    {
    private:
        unsigned char myData[20];

    public:
        Hash ()
        {
            std::memset(myData, 0, sizeof(myData));
        }

    public:
        std::size_t size () const
        {
            return (sizeof(myData));
        }

        unsigned char * data ()
        {
            return (myData);
        }

        const unsigned char * data () const
        {
            return (myData);
        }

    public:
        operator std::string () const
        {
            char data[40];
            ::sha1_hexstring(myData, data);
            return (std::string(data, sizeof(data)));
        }
    };

    class Digest
    {
    private:
        ::sha1_digest myBackend;

    public:
        Digest ()
        {
            ::sha1_clear(&myBackend);
        }

    public:
        void update ( const void * data, std::size_t size )
        {
            ::sha1_update(
                &myBackend, static_cast<const unsigned char*>(data), size);
        }

        void update ( const std::string& message )
        {
            update(message.data(), message.size());
        }

        void update ( std::istream& stream )
        {
            char data[1024];
            do {
                stream.read(data, sizeof(data));
                update(data, stream.gcount());
            }
            while ( stream );
        }

        Hash result ()
        {
            Hash hash;
            if (!::sha1_result(&myBackend, hash.data())) {
                throw (std::logic_error("SHA-1"));
            }
            return (hash);
        }
    };

}

#endif /* _sha1_Digest_hpp__ */
