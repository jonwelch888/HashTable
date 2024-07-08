# Assignment 7: Hash Tables [2436]

## Description
This assignment involves creating a Hash Table class that uses separate chaining for collision resolution. The hash table is implemented using an array of linked list objects, and it supports basic operations such as insertion, deletion, retrieval, and printing of entries.

## Files Included
- `data.h`: Defines the `Data` and `Node` structs.
- `linkedlist.h`: Declares the `LinkedList` class.
- `linkedlist.cpp`: Implements the `LinkedList` class.
- `hashtable.h`: Declares the `HashTable` class.
- `hashtable.cpp`: Implements the `HashTable` class.
- `main.h`: Includes necessary headers and defines constants used in `main.cpp`.
- `main.cpp`: Contains the main function for testing the `HashTable` class.

## Specifications / Requirements
- Implement a separate chaining hash table using an array of linked list objects.
- The hash table should have a size of 15, defined using `#define` in `hashtable.h`.
- Use modulo operation as the hash function.
- The hash table should support the following public methods:
  - `bool insertEntry(int id, std::string* data)`: Inserts a new entry into the hash table.
  - `std::string getData(int id)`: Retrieves the data associated with the given ID.
  - `bool removeEntry(int id)`: Removes the entry with the given ID from the hash table.
  - `int getCount()`: Returns the number of entries in the hash table.
  - `void printTable()`: Prints the contents of the hash table.
- Ensure the program handles invalid IDs and empty data appropriately.
- Include robust testing in `main.cpp` to demonstrate all functionalities of the hash table.



## Author 
Jon Welch
