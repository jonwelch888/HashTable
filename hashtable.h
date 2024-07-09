/**************************
* Name: Jon Welch
* Assignment: 7
* Purpose of the file: This header file declares the HashTable class,
* which uses separate chaining to handle collisions. It supports operations 
* such as inserting, deleting, and retrieving entries, as well as printing the table 
* and checking the number of entries.
* @note file is associated with [hashtable.cpp] & [linkedlist.h];
* ***************************/

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "linkedlist.h"
#define HASHTABLESIZE 15

class HashTable
{
    /*********************************************
    This class defines a hash table that uses separate chaining 
    for collision resolution. It allows adding, deleting, retrieving, 
    and printing entries, as well as checking the number of entries 
    in the table.

    @attrib table: an array of linked lists representing the hash table
    @attrib count: the number of entries in the hash table
    *********************************************/ 

    public:
    /**************************************
    Constructor and Destructor
    **************************************/
    HashTable(); 
    ~HashTable();  

    /**********************
     Getters/Accessors
    **********************/
    bool insertEntry(int id, std::string* data);  
    std::string getData(int id);  
    bool removeEntry(int id); 
    int getCount();  
    void printTable();  

    private:
    /********************************************
    Private methods:
    int hash(int id); Generates the hash for a given id
    LinkedList table[HASHTABLESIZE]; Array of linked lists
    **********************************************/
    int hash(int id); 

    LinkedList table[HASHTABLESIZE];  
    int count; 
};

#endif // HASHTABLE_H
