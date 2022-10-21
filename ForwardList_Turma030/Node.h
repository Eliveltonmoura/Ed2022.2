#ifndef NODE_H
#define NODE_H

using Item = int;

class Node {
    friend class ForwardList;
private:
    Item value;
    Node* next;
public:
    Node(int val, Node *nextPtr) {
        value = val;
        next = nextPtr;
    }
};

#endif