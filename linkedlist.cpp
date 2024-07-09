/***************************************
* Name: Jon Welch
* Assignment: 7
* Purpose of the file: This source file contains the implementation of the LinkedList class.
* It handles dynamic memory allocation and supports operations such as adding, deleting, 
* retrieving, printing, and checking nodes in a doubly linked list.

* @note This file is associated with linkedlist.h.
****************************************/


#include "linkedlist.h"

LinkedList::LinkedList() : head(nullptr)
{
    /**************************************
    Constructor: Initializes the linked list with the head pointer set to nullptr.
    ************************************* */
}

LinkedList::~LinkedList()
{
    /* *************************************
    Destructor: Cleans up all dynamically allocated memory by clearing the list.
    ************************************* */
    clearList();
}

bool LinkedList::addNode(int id, string* data)
{
    /* *************************************
    addNode: Adds a new node with the given id and data to the list in ascending order.
    @param id : The identifier for the Data.
    @param data : A pointer to the string data.
    ************************************* */
    bool success = false;

    if (id > 0 && !data->empty())
    {
        Node* current = head;
        Node* previous = nullptr;

        // Search for where the new node goes
        while (current && current->data.id < id)
        {
            previous = current;
            current = current->next;
        }

        // Check if id already exists
        if (!current || current->data.id != id)
        {
            // Now we know we need a new node
            Node* newNode = new Node;
            newNode->data.id = id;
            newNode->data.data = *data;
            newNode->next = nullptr;
            newNode->prev = nullptr;

            // Insert the new node
            if (!previous)
            { // Inserting at head
                addHead(newNode);
            } 
            else if (!current)
            { // Inserting at tail
                addTail(newNode);
            }
            else
            { // Inserting in the middle
                addMiddle(newNode, previous);
            }

            success = true;
        }
    }

    return success;
}


bool LinkedList::deleteNode(int id)
{
    /* *************************************
    deleteNode: Deletes the node with the given id from the list.
    @param id The identifier for the node to delete.
    ************************************* */
    bool success = false;
    Node* current = head;
    Node* toDelete = nullptr;

    while (current && !toDelete)
    {
        if (current->data.id == id)
        {
            toDelete = current;
        }
        else
        {
            current = current->next;
        }
    }

    if (toDelete)
    {
        
        deleteNode(toDelete);
        success = true;
    }
    return success;
}

bool LinkedList::getNode(int id, Data* data)
{
    /* *************************************
    getNode: Retrieves the node with the given id and stores its data.
    @param id The identifier for the node to retrieve.
    @param data A pointer to a Data object to store the retrieved data.
    ************************************* */
    bool found = false;
    Node* current = head;

    while (current && !found)
    {
        if (current->data.id == id)
        {
            data->id = current->data.id;
            data->data = current->data.data;
            found = true;
        }
        else
        {
            current = current->next;
        }
    }

    if (!found)
    {
        data->id = -1;
        data->data = "";
    }

    return found;
}


void LinkedList::printList(bool backward)
{
    /* *************************************
    printList: Prints the list forward or backward based on the parameter.
    @param backward A boolean indicating the direction to print the list.
    ************************************* */
    
    if (!head)
    {
        std::cout << "List is empty" << std::endl;
    }

    Node* current = head;
    if (!backward)
    {
        while (current)
        {
            std::cout << current->data.id << ": " << current->data.data << std::endl;
            current = current->next;
        }
    }
    else
    {
        while (current->next)
        {
            current = current->next;
        }
        while (current)
        {
            std::cout << current->data.id << ": " << current->data.data << std::endl;
            current = current->prev;
        }
    }
}


int LinkedList::getCount()
{
    /* *************************************
    getCount: Returns the number of nodes in the list.
    @return The count of nodes in the list.
    ************************************* */
    int count = 0;
    Node* current = head;
    while (current)
    {
        count++;
        current = current->next;
    }
    return count;
}


bool LinkedList::clearList()
{
    /* *************************************
    clearList: Clears the list and deallocates memory for all nodes.
    @return true if the list was cleared successfully, false otherwise.
    ************************************* */
    bool success = false;
    Node* current = head;
    while (current)
    {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
    success = true;
    return success;
}


bool LinkedList::exists(int id)
{
    /* *************************************
    exists: Checks if a node with the given id exists in the list.
    @param id The identifier to check for existence.
    ************************************* */
    bool found = false;
    Node* current = head;

    while (current && !found)
    {
        if (current->data.id == id)
        {
            found = true;
        }
        else
        {
            current = current->next;
        }
    }

    return found;
}


// Helper method implementations (if needed)
void LinkedList::addHead(Node* newNode)
{
    /* *************************************
    addHead: Adds a new node at the head of the list.
    @param newNode The new node to add.
    ************************************* */
    newNode->next = head;
    if (head)
    {
        head->prev = newNode;
    }
    head = newNode;
}

void LinkedList::addTail(Node* newNode)
{
    /* *************************************
    addTail: Adds a new node at the tail of the list.
    @param newNode The new node to add.
    ************************************* */
    Node* current = head;
    while (current->next)
    {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
}

void LinkedList::addMiddle(Node* newNode, Node* prevNode)
{
    /* *************************************
    addMiddle: Adds a new node in the middle of the list after the specified previous node.
    @param newNode The new node to add.
    @param prevNode The node after which to add the new node.
    ************************************* */
    
    newNode->next = prevNode->next;
    newNode->prev = prevNode;
    if (prevNode->next)
    {
        prevNode->next->prev = newNode;
    }
    prevNode->next = newNode;
}

void LinkedList::deleteNode(Node* node)
{
    /* *************************************
    deleteNode: Deletes the specified node from the list.
    @param node The node to delete.
    ************************************* */
    if (node->prev)
    {
        node->prev->next = node->next;
    }
    else
    {
        head = node->next;
    }
    if (node->next)
    {
        node->next->prev = node->prev;
    }
    delete node;
    
}



