# Hash table with closed adressing on C++

The interaface of hash table :
  * *int Hash(std::string key,int HashSize)* - return result of hash function;
  * *int NumberOfItemsInIndex(int index)* - number of items at *index* linked list;
  * *void PrintTable()* - prints table;
  * *void PrintItemsInIndex(int index)* - prints items from *index* linked list ;
  * *void RemoveItem(std::string name)* - remove item from the table;
  * *void reHash()* - change the size of hash table;
  * *int NumberOfAllElements()* - number of all items in hash table;
  * *void PrintKeys()* - outputs keys of hash table;
  * *void PrintValues()* - outputs values of hash table;
  * *void DisplayTable()* - outouts a whole table;
