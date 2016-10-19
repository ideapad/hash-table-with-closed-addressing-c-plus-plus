#include <cstdlib>
#include <iostream>
#include <string>

#include "hash.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

hash::hash()
{
    tableSize = TABLE_SIZE;

    HashTable = new item*[tableSize];

    for(int i = 0;i < tableSize; i++)
    {
        HashTable[i] = new item;
        HashTable[i]->name = "empty";
        HashTable[i]->drink = "empty";
        HashTable[i]->next = NULL;
    }
}

hash::~hash()
{
   item* Ptr;
   for(int i=0;i<tableSize;i++)
   {
      while(HashTable[i] != NULL)
      {
         Ptr = HashTable[i];
         HashTable[i] = HashTable[i]->next;
         delete Ptr;
      }
   }
}

int hash::NumberOfItemsInIndex(int index)
{
    int count = 0;

    if(HashTable[index]->name == "empty")
    {
        return count;
    }else
    {
        count++;
        item* Ptr = HashTable[index];
        while(Ptr->next != NULL)
        {
            count++;
            Ptr = Ptr->next;
        }
    }
    return count;
}

void hash::PrintTable()
{
    int number;
    for(int i = 0; i < tableSize; i++)
    {
        number = NumberOfItemsInIndex(i);
        cout << "----------------------\n";
        cout << "index = " << i << endl;
        cout << HashTable[i]->name << endl;
        cout << HashTable[i]->drink << endl;
        cout << "Number of items = " << number << endl;
        cout << "----------------------\n";
    }

}

void hash::DisplayTable()
{
    for(int index = 0; index<tableSize;index++)
    {
        item* Ptr = HashTable[index];

        if(Ptr->name != "empty")
        {
            while(Ptr != NULL)
            {
                cout << Ptr->name << " - " << Ptr->drink << endl;
                Ptr = Ptr->next;
            }
        }
    }
}

void hash::PrintKeys()
{
    for(int index = 0; index<tableSize;index++)
    {
        item* Ptr = HashTable[index];

        if(Ptr->name != "empty")
        {
            while(Ptr != NULL)
            {
                cout << Ptr->name << endl;
                Ptr = Ptr->next;
            }
        }
    }

}

void hash::PrintValues()
{
    for(int index = 0; index<tableSize;index++)
    {
        item* Ptr = HashTable[index];

        if(Ptr->drink != "empty")
        {
            while(Ptr != NULL)
            {
                cout << Ptr->drink << endl;
                Ptr = Ptr->next;
            }
        }
    }

}

void hash::PrintItemsInIndex(int index)
{
    item* Ptr = HashTable[index];

    if(Ptr->name == "empty")
    {
        cout << "index = " << index << " is empty";
    }else
    {
        cout << "index " << index << " contains the following items\n";

        while(Ptr != NULL)
        {
            cout << "--------------------\n";
            cout << Ptr->name << endl;
            cout << Ptr->drink << endl;
            cout << "--------------------\n";
            Ptr = Ptr->next;

        }
    }
}

int hash::NumberOfAllElements()
{
    int count = 0;

    for(int i = 0;i<tableSize;i++)
    {
        if(HashTable[i]->name != "empty")
        {
            count++;
            item* Ptr = HashTable[i];
            while(Ptr->next != NULL)
            {
                count++;
                Ptr = Ptr->next;
            }
        }
    }
    return count;
}

int hash::Hash(string key, int HashSize)
{
    size_t hashsum,i;
    for ( hashsum = i = 0; i < key.length(); i++ )
    {
        hashsum = (hashsum * 31) ^ key[i];
     }
     return (hashsum & 0x7fffffff) % HashSize;

}

void hash::RemoveItem(string name)
{
    int index = Hash(name,tableSize);

    item* delPtr;
    item* P1;
    item* P2;

  //  Case 0 - bucket is empty
    if(HashTable[index]->name == "empty" && HashTable[index]->drink == "empty")
    {
        cout << name << " was not found in the Hash Table\n";
    }

  // Case 1 = only 1 item contained and that item has matching name
   else if(HashTable[index]->name == name && HashTable[index]->next == NULL)
    {
        HashTable[index]->name = "empty";
        HashTable[index]->drink = "empty";

        cout << name << " was removed from the Hash Table\n";
    }

  // Case 2 = match is located in the first item in the bucket but there are
  // more items in the bucket
    else if(HashTable[index]->name == name)
    {
        delPtr = HashTable[index];
        HashTable[index] = HashTable[index]->next;
        delete delPtr;

        cout << name << " was removed from the Hash Table\n";
    }

  // Case 3 - bucket contains items but first item is not match
    else
    {
        P1 = HashTable[index]->next;
        P2 = HashTable[index];

        while(P1 != NULL && P1->name != name)
        {
            P2 = P1;
            P1 = P1->next;
        }
        // Case 3.1 - no match
        if(P1 == NULL)
        {
            cout << name << " was not found in the Hash Table\n";
        }
        // Case 3.2 - match is found
        else
        {
            delPtr = P1;
            P1 = P1->next;
            P2->next = P1;

            delete delPtr;
            cout << name << " was removed from the Hash Table\n";
        }
    }
}

void hash::reHash()
{
    int newSize = 2*tableSize+1;
    item** ExtendHashTable = new item*[newSize];
    for (int i = 0;i <newSize;i++)
    {
        ExtendHashTable[i] = new item;
        ExtendHashTable[i]->name = "empty";
        ExtendHashTable[i]->drink = "empty";
        ExtendHashTable[i]->next = NULL;
    }
    for (int i = 0; i < tableSize;i++)
    {
        item *n = HashTable[i];
        while( n != NULL)
        {
            item *tmp = n;
            n=n->next;

            item*& bucket = ExtendHashTable[Hash(tmp->name,newSize)];
            tmp->next = bucket;
            bucket = tmp;
        }
    }

    tableSize = newSize;

    delete [] HashTable;

    HashTable = ExtendHashTable;
}

string hash::operator [](string name)
{
    int index = Hash(name,tableSize);
    bool foundName = false;
    string drink;

    item* Ptr = HashTable[index];

    while(Ptr != NULL)
    {
        if(Ptr->name == name)
        {
            foundName = true;
            drink = Ptr->drink;
        }
        Ptr = Ptr->next;
    }
    if(foundName == true)
    {
        return drink;
    }else
    {
        cout << "Information was not found!\n";
        return "Information was not found.";
    }
}

string hash::operator ()(string name,string drink)
{
    int index = Hash(name,tableSize);

    if(HashTable[index]->name == "empty")
    {
       HashTable[index]->name = name;
       HashTable[index]->drink = drink;
    }
    else
    {
        item* Ptr = HashTable[index];
        item* n = new item;
        n->name = name;
        n->drink = drink;
        n->next = NULL;
        while(Ptr->next != NULL)
        {
           Ptr = Ptr->next;
        }
        Ptr ->next = n;
    }



    if(NumberOfAllElements() == int(0.5*tableSize))
    {
        reHash();
        cout << "\nThe Hast table was expended\n";
    }
    cout << "The element was added!\n";
    return "The element was added !";
}
