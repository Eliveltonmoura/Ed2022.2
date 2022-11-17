#ifndef Node_H
#define NODE_H

template <typename T>

struct Node
{
    T value;
    Node *next;
    Node(const T &, Node *nxt)
    {
        value = val;
        next = nxt;
    }
};

#endif
