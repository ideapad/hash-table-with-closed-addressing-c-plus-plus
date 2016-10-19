#include <cstdlib>
#include <iostream>
#include <string>

#define TABLE_SIZE 29

#ifndef HASH
#define HASH

class hash{

    int tableSize;

 private:

    struct item
    {
       std::string name;
       std::string drink;
       item* next;
    };

    item** HashTable;


 public:

    hash();
    ~hash();
    int Hash(std::string key,int HashSize);
    int NumberOfItemsInIndex(int index);
    void PrintTable();
    void PrintItemsInIndex(int index);
    void RemoveItem(std::string name);
    void reHash();
    int NumberOfAllElements();
    void PrintKeys();
    void PrintValues();
    void DisplayTable();

    std::string operator[](std::string name);
    std::string operator()(std::string name,std::string drink);
};

#endif // HASH

