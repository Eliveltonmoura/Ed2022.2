#include <iostream>
#ifndef NODE_H
#define NODE_H
using namespace std;

template <typename T>
struct Node
{
    T value;
    Node *next{nullptr};
    Node *prev{nullptr};

    Node(const T &val, Node *prv, Node *nxt)
    {
        value = val;
        next = nxt;
        prev = prv;
    }
    ~Node()
    {
        std::cout << "Node " << value << " liberada" << endl;
    }
};

#endif
