/* **************************************
Name: Jon Welch
Assignment: 7
Purpose of the file: This header file declares the HashTable class,
which uses separate chaining to handle collisions. It supports operations 
such as inserting, deleting, and retrieving entries, as well as printing the table 
and checking the number of entries.

@note file is associated with [hashtable.cpp];
*************************************** */

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "linkedlist.h"
#define HASHTABLESIZE 15

class HashTable
{
    public:
    /* *************************************
    Constructor and Destructor
    ************************************* */
    HashTable();  // Constructor to initialize the hash table
    ~HashTable();  // Destructor to clean up allocated memory

    /* *************************************
    Accessors:
    bool insertEntry(int id, string* data); Inserts a new entry into the hash table
    string getData(int id); Retrieves the data associated with the given id
    bool removeEntry(int id); Removes the entry with the given id from the hash table
    int getCount(); Returns the number of entries in the hash table
    void printTable(); Prints the contents of the hash table
    ************************************* */

    bool insertEntry(int id, std::string* data);  // Inserts an entry into the hash table
    std::string getData(int id);  // Retrieves the data for the given id
    bool removeEntry(int id);  // Removes the entry with the given id
    int getCount();  // Returns the number of entries in the hash table
    void printTable();  // Prints the hash table

    private:
    /* *******************************************
    Private methods:
    int hash(int id); Generates the hash for a given id
    ********************************************* */
    int hash(int id);  // Hash function

    LinkedList table[HASHTABLESIZE];  // Array of linked lists
    int count;  // Number of entries in the hash table
};

#endif // HASHTABLE_H
