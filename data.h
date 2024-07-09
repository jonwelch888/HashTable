/**************************
* Name: Jon Welch
* Assignment: 7
* Purpose of the file: This header file defines the Data and Node structures used in the HashTable class.
* The Data structure contains an id and a string, while the Node structure is used for the doubly linked list,
* containing a Data object and pointers to the next and previous nodes.
***************************/

#ifndef DATA_H
#define DATA_H

#include <string>
using std::string;

struct Data
{
    /*********************************************
    This structure defines a Data object that holds an integer ID 
    and a string data.

    @attrib id : the identifier for the data
    @attrib data : the string data
    *********************************************/
    int id;
    string data;
};

struct Node
{
    /*********************************************
    This structure defines a Node used in the doubly linked list.
    Each node contains a Data object and pointers to the next 
    and previous nodes in the list.

    @attrib data : the Data object stored in the node
    @attrib next : pointer to the next node in the list
    @attrib prev : pointer to the previous node in the list
    *********************************************/
    Data data;
    Node *next;
    Node *prev;
};

#endif /* DATA_H */
