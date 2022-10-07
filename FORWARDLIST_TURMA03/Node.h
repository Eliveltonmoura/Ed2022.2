#ifndef NODE_H
#define NODE_H

typedef int Item;

class Node
{
    friend class ForwordList;

private:
    Item value;
    Node *next;

public:
    Node(int val, Node *nextPtr)
    {
        value = val;
        next = nextPtr;
    }
};

#endif