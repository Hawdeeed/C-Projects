#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"
#include <iostream>
using namespace std;

class LinkedList
{
private:
    Node *head; // Pointer to the head node
public:
    // Constructor
    LinkedList() : head(nullptr) {}
    void setHead(Node *newHead) { head = newHead; }
    // Destructor to free memory
    ~LinkedList()
    {
        clear();
    }
    Node *getHead() const { return head; }
    // Add a city to the list
    void add(const City &city)
    {
        // Check for duplicates
        if (find(city.name, city.state_or_country))
        {
            cout << "Duplicate city detected: " << city.name << " in " << city.state_or_country << ". Not added.\n";
            return;
        }
        Node *newNode = new Node(city);
        newNode->next = head;
        head = newNode;
        cout << "City " << city.name << " (" << city.state_or_country << ") added successfully!\n";
    }
    void loaded(const City &city)
    {
        Node *newNode = new Node(city);
        newNode->next = head;
        head = newNode;
    }

    // Find a city in the list
    Node *find(const string &name, const string &state_or_country) const
    {
        Node *current = head;
        while (current)
        {
            if (current->data.name == name && current->data.state_or_country == state_or_country)
            {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    // Clear all nodes in the list
    void clear()
    {
        while (head)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
};

#endif // LINKEDLIST_H