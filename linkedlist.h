/* **************************************
Name: Jon Welch
Assignment: 7
Purpose of the file: This header file declares the LinkedList class,
which implements a doubly linked list of Data objects. 
It supports operations such as adding, deleting, and retrieving nodes, 
as well as printing the list and checking for the existence of a node.

@note file is associated with linkedlist.cpp.
*************************************** */



#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>
#include "data.h"
#include <iostream>
using std::string;

// Define the debug flag
constexpr bool DEBUG = true; // Set to false to disable debug prints

class LinkedList
{
    /*********************************************
    This class defines a doubly linked list that handles dynamic memory allocation for Data objects.
    It allows adding, deleting, retrieving, printing, and checking nodes in the list.

    @attrib head: pointer to the first node in the linked list
    *********************************************/


    private:
    Node* head;

    // Helper methods (if needed)
    void addHead(Node* newNode);
    void addTail(Node* newNode);
    void addMiddle(Node* newNode, Node* prevNode);
    void deleteNode(Node* node);

    public:
    /* *************************************
    Constructor and Destructor
    ************************************* */
    LinkedList();
    ~LinkedList();

    /* *************************************
    Accessors:
    bool getNode(int id, Data* data); Retrieves the node with the given id
    void printList(bool backward = false); Prints the list forward or backward
    int getCount(); Returns the count of nodes in the list
    bool exists(int id); Checks if a node with the given id exists
    ************************************* */
    bool getNode(int id, Data* data);
    void printList(bool backward = false);
    int getCount();
    bool exists(int id);
    
    /* *******************************************
    Mutators:
    bool addNode(int id, string* data); Adds a new node with the given id and data
    bool deleteNode(int id); Deletes the node with the given id
    bool clearList(); Clears the list and deallocates memory
    ********************************************* */

    bool addNode(int id, string* data);
    bool deleteNode(int id);
    bool clearList();


};

#endif // LINKEDLIST_H
