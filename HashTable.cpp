#include "HashTable.hpp"


namespace myStl {

    HashTable::HashTable() {
        _arr = new Node*[_cap];
        for (int i = 0; i < _cap; ++i) {
            _arr[i] = new Node;
        }
    };

    HashTable::~HashTable() {
        for (int i = 0; i < _cap; ++i) {
            delete _arr[i];
            _arr[i] = nullptr;  
        }
        delete[] _arr;
        _arr = nullptr;
    };

    size_t HashTable::getHash(const int& key) {
        return key % _cap;
    }

    void HashTable::insertElement(const int& key, const std::string& value) {
        int bucketIndex = getHash(key);

        if(_arr[bucketIndex]->_key == -1) {
            _arr[bucketIndex]->_key = key;
            _arr[bucketIndex]->_value = value;
            _arr[bucketIndex]->next = nullptr;
        }
        else {
            Node* tmp = _arr[bucketIndex];
            while (tmp != nullptr) {
                tmp = tmp -> next;
            }
            tmp = new Node;
            tmp->_key = key;
            tmp->_value = value;
            tmp->next = nullptr;
        }
    }

    void HashTable::deleteElement(const int& key) {
        int bucketIndex = getHash(key);
        if (_arr[bucketIndex]->_key == -1) {
            return;
        }
        else {
            Node* tmp = _arr[bucketIndex];
            while (tmp != nullptr) {
                    Node* prevTmp = tmp;
                    tmp = tmp -> next;
                    prevTmp -> _key = ZERO_KEY;
                    prevTmp -> _value = "";
                }
            }
            
        }
    

    std::string HashTable::searchElement(const int& key) {
        int bucketIndex = getHash(key);
        if (_arr[bucketIndex]->_key == -1) {
            return "None";
        }
        else {
            return _arr[bucketIndex]->_value;
        }    
    }

}