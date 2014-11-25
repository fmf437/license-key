#ifndef COMPAREKEYS_HPP
#define COMPAREKEYS_HPP

// compara as chaves válidas com a ajuda das classes HashKey e ListKeys

#include "hashkey.hpp"
#include "listkeys.hpp"

namespace lk {
    class CompareKeys: public HashKey, public ListKeys
    {
    public:
        CompareKeys();
        ~CompareKeys();
    };
}

#endif // COMPAREKEYS_HPP
