/**************************
* Name: Jon Welch
* Assignment: 7
* Purpose of the file: This header file defines the Data and Node structures used in the HashTable class.
* The Data structure contains an id and a string, while the Node structure is used for the doubly linked list,
* containing a Data object and pointers to the next and previous nodes.
***************************/

#ifndef DATA_H
#define DATA_H

#include "string"
using std::string;

struct Data {
    int id;
    string data;
};

struct Node {
    Data data;
    Node *next;
    Node *prev;
};

#endif /* DATA_H */
