/* **************************************
Name: Jon Welch
Assignment: 7
Purpose of the file: This source file contains the main function for testing the HashTable class.
It generates test data, inserts it into the hash table, and demonstrates various operations.

@note This file is associated with [main.h]
;*************************************** */

#include "main.h"

int main()
{
    //seed the rand function
    srand(time(NULL));

    /*
     * This code makes test data of 6 - 25 entries
     * Note this guarantees at least one non unique id and one bad id
     * Do not modify this code from here to the next comment telling
     * you to "START HERE"
     */
    const int testdatasize = BASE + (rand() % OFFSET + 1);
    int ids[testdatasize];
    string strs[testdatasize];
    
    char buffer[BUFFERSIZE];
    for (int i = 0; i < testdatasize; i++) {
        ids[i] = rand() % MAXID + 1;
        for (int j = 0; j < BUFFERSIZE - 1; j++) {
            buffer[j] = 'a' + i;
        }
        buffer[BUFFERSIZE - 1] = '\0';
        strs[i] = buffer;
    }
    ids[testdatasize-2] = ids[testdatasize-3];
    strs[testdatasize-2] = "known duplicate";
    ids[testdatasize-1] = - 1;
    strs[testdatasize-1] = "known bad";
    
    /*
     * Show test data
     */
    cout << "Showing Test Data (" << testdatasize << " entries)..." << endl;
    for (int i = 0; i < testdatasize; i++) {
        cout << ids[i] << " : " << strs[i] << endl;
    }
    cout << endl;

    /*
     * Now you have two parallel arrays with ids and strings for test data.
     * START HERE and create your hash table and use the test data to show
     * it works.
     */
    
    // Create your hash table object here
    HashTable ht;
    
    // Show it is empty by calling getCount and printTable
    cout << "Initial hash table state:" << endl;
    cout << "Entry count: " << ht.getCount() << endl;
    ht.printTable();
    cout << endl;

    // Try and put ALL the test data into the table and show what happens
    cout << "Inserting test data into hash table..." << endl;
    for (int i = 0; i < (testdatasize); i++)
    {
        if (ht.insertEntry(ids[i], &strs[i]))
        {
            cout << "Inserted: " << ids[i] << " : " << strs[i] << endl;
        }
        else
        {
            cout << "Failed to insert: " << ids[i] << " : " << strs[i] << endl;
        }
    }
    cout << endl;

    // Show the state of the hash table after insertion
    cout << "Hash table after insertion:" << endl;
    cout << "Entry count: " << ht.getCount() << endl;
    ht.printTable();
    cout << endl;

    // Demonstrate retrieval of data
    cout << "Retrieving data from hash table:" << endl;
    for (int i = 0; i < (testdatasize); i++)
    {
        string data = ht.getData(ids[i]);
        if (!data.empty())
        {
            cout << "Retrieved: ID " << ids[i] << " -> " << data << endl;
        }
        else
        {
            cout << "ID " << ids[i] << " not found in hash table." << endl;
        }
    }
    cout << endl;

    // Demonstrate removal of data
    cout << "Removing entries from hash table:" << endl;
    for (int i = 0; i < (testdatasize); i++)
    {
        if (ht.removeEntry(ids[i]))
        {
            cout << "Removed: ID " << ids[i] << endl;
        }
        else
        {
            cout << "Failed to remove: ID " << ids[i] << endl;
        }
    }
    cout << endl;

    // Show the state of the hash table after removal
    cout << "Hash table after removal:" << endl;
    cout << "Entry count: " << ht.getCount() << endl;
    ht.printTable();
    cout << endl;

    return 0;
}
