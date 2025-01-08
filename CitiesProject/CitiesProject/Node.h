#ifndef NODE_H
#define NODE_H
#include "City.h"

class Node
{
public:
    City data;  // The city object
    Node *next; // Pointer to the next node
    // Constructor
    Node(const City &city) : data(city), next(nullptr) {}
};

#endif // NODE_H