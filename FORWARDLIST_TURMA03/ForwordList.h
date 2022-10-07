#ifndef LIST_H
#define LIST_H
#include "Node.h"

class ForwordList
{
private:
    Node *m_head{nullptr}; // ponteiro para o inicio da lista
    int m_size { 0 }       // numero de elementos na lista atualmente

public:
    // construtor default: cria uma lista vazia
    ForwordList()
    {
        m_head = new Node(0, nullptr);
    }

    // insere val no inicio da lista
    void push_front(int val)
    {
        }
};

#endif