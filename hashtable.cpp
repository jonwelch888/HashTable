/* **************************************
Name: Jon Welch
Assignment: 7
Purpose of the file: This source file contains the implementation of the HashTable class.
It uses separate chaining to handle collisions and supports operations 
such as inserting, deleting, and retrieving entries, as well as printing the table 
and checking the number of entries.

@note This file is associated with [hashtable.h];
*************************************** */

#include "hashtable.h"

HashTable::HashTable() : count(0)
{
    /* *************************************
    Constructor: Initializes the hash table with the count set to 0.
    ************************************* */
    // No dynamic allocation needed; LinkedList constructor will handle initialization
}

HashTable::~HashTable()
{
    /* *************************************
    Destructor: Cleans up allocated memory.
    ************************************* */
    // No dynamic deallocation needed; LinkedList destructor will handle cleanup
}

int HashTable::hash(int id)
{
    /* *************************************
    hash: Generates the hash for a given id using modulo operation.
    @param id The identifier to hash.
    @return The hash value.
    ************************************* */
    return id % (HASHTABLESIZE);
    // Returning the remainder, [(25%7)=(4)] => [(25/7)=(3)] => [(7*3)=(21)] => [(25-21)=(4)=(remainder)];
}

bool HashTable::insertEntry(int id, std::string* data)
{
    /* *************************************
    insertEntry: Inserts a new entry into the hash table.
    @param id The identifier for the entry.
    @param data A pointer to the string data.
    @return true if the insertion was successful, false otherwise.
    ************************************* */
    bool success = false;
    if (id > 0 && !data->empty())
    {
        int index = hash(id);
        if (table[index].addNode(id, data))
        {
            count++;
            success = true;
        }
    }
    return success;
}

std::string HashTable::getData(int id)
{
    /* *************************************
    getData: Retrieves the data associated with the given id.
    @param id The identifier for the entry.
    @return The data string if found, otherwise an empty string.
    ************************************* */
    std::string result;
    Data data;
    int index = hash(id);
    if (table[index].getNode(id, &data))
    {
        result = data.data;
    }
    else
    {
        result = "";
    }
    return result;
}

bool HashTable::removeEntry(int id)
{
    /* *************************************
    removeEntry: Removes the entry with the given id from the hash table.
    @param id The identifier for the entry.
    @return true if the removal was successful, false otherwise.
    ************************************* */
    bool success = false;
    int index = hash(id);
    std::cout << "Attempting to remove ID " << id << " from index " << index << std::endl;
    if (table[index].deleteNode(id)) {
        count--;
        success = true;
        std::cout << "Removed ID " << id << " from index " << index << std::endl;
    } else {
        std::cout << "Failed to remove ID " << id << " from index " << index << std::endl;
    }
    return success;
}

int HashTable::getCount()
{
    /* *************************************
    getCount: Returns the number of entries in the hash table.
    @return The number of entries.
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
