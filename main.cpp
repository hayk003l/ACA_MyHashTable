#include <iostream>
#include "HashTable.hpp"


int main() {
    myStl::HashTable obj;

    obj.insertElement(4, "Hayk");
    obj.insertElement(5, "Vaspur");
    std::cout <<  obj.searchElement(4) << std::endl;
    std::cout <<  obj.searchElement(5) << std::endl;
    obj.deleteElement(4);
    std::cout <<  obj.searchElement(4) << std::endl;
    return 0;
}