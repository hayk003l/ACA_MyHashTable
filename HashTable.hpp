#ifndef __HASHTABLE__
#define __HASHTABLE__
#include <string>
#include <iostream>

namespace myStl {

    #define ZERO_KEY -1;

    struct Node {
        int _key = ZERO_KEY;
        std::string _value;
        Node* next = nullptr;
    };

    class HashTable {
    private:
        int _cap = 10;
        int _size = 0;
        Node** _arr = nullptr;
    public:
        HashTable();
        ~HashTable();

    private:
        size_t getHash(const int& key);
    public:
        void insertElement(const int& key, const std::string& value);
        void deleteElement(const int& key);
        std::string searchElement(const int& key);
    };

}
#endif // __HASHTABLE__

