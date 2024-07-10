/* **************************************
* Name: Jon Welch
* Assignment: 7
* Purpose of the file: This source file contains the implementation of the HashTable class.
* It uses separate chaining to handle collisions and supports operations 
* such as inserting, deleting, and retrieving entries, as well as printing the table 
* and checking the number of entries.
*
* @note This file is associated with [hashtable.h];
*************************************** */

#include "hashtable.h"

HashTable::HashTable() : count(0)
{
    /* *************************************
    Constructor: Initializes the hash table with the count set to 0.
    ************************************* */
}

HashTable::~HashTable()
{
    /* *************************************
    Destructor: Cleans up allocated memory.
    ************************************* */
}

int HashTable::hash(int id)
{
    /* *************************************
    hash: Generates the hash for a given id using modulo operation.
    @param id : The identifier to hash.
    @return : The hash value.
    ************************************* */
    return id % HASHTABLESIZE;
}

bool HashTable::insertEntry(int id, std::string* data)
{
    /* *************************************
    insertEntry: Inserts a new entry into the hash table.
    @param id : The identifier for the entry.
    @param data : A pointer to the string data.
    @return : true if the insertion was successful, false otherwise.
    ************************************* */
    int index = hash(id);
    bool success = table[index].addNode(id, data);
    count += success ? 1 : 0;
    return success;
}

std::string HashTable::getData(int id)
{
    /* *************************************
    getData: Retrieves the data associated with the given id.
    @param id : The identifier for the entry.
    @return : The data string if found, otherwise an empty string.
    ************************************* */
    int index = hash(id);
    Data data;
    bool found = (index != -1) && table[index].getNode(id, &data); // Ran into segmentation error again, trying to troubleshoot
    return found ? data.data : "";
}

bool HashTable::removeEntry(int id)
{
    /* *************************************
    removeEntry: Removes the entry with the given id from the hash table.
    @param id : The identifier for the entry.
    @return : true if the removal was successful, false otherwise.
    ************************************* */
    int index = hash(id);
    bool success = table[index].deleteNode(id);
    count -= success ? 1 : 0;
    return success;
}

int HashTable::getCount()
{
    /* *************************************
    getCount: Returns the number of entries in the hash table.
    @return : The number of entries.
    ************************************* */
    return count;
}

void HashTable::printTable()
{
    /* *************************************
    printTable: Prints the contents of the hash table.
    ************************************* */
    for (int i = 0; i < (HASHTABLESIZE); i++)
    {
        std::cout << "Entry " << i << ": ";
        table[i].printList();
    }
}
