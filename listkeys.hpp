#ifndef LISTKEYS_HPP
#define LISTKEYS_HPP

// põe uma lista de chaves com o tamanho de 60 caracteres - são estas as chaves válidas

#include <iostream>
#include <vector>

namespace lk {
    class ListKeys
    {
    public:
        ListKeys();
        ~ListKeys();

        // you can set as many keys as you want
        void set_new_keys(std::string key);

    protected:
        std::vector<std::string> *vec;
    };
}

#endif // LISTKEYS_HPP
