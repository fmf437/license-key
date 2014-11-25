#include "include/listkeys.hpp"

// põe uma lista de chaves com o tamanho de 60 caracteres - são estas as chaves válidas

namespace lk {
    ListKeys::ListKeys()
    {
        vec = new std::vector<std::string>;
    }

    ListKeys::~ListKeys()
    {
        delete vec;
    }

    void ListKeys::set_new_keys(std::string key)
    {
        // tem de ser verificado se key tem lenght de 60 caracteres
        /*
        if (key.length() == 60)
        {
            vec->push_back(key);
        }
        else
        {
            std::cerr << "Não tem 60 caracteres!!!" << std::endl;
        }
        */
        // mas por agora fica assim
        vec->push_back(key);
    }
}
