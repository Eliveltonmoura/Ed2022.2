#ifndef LIST_H
#define LIST_H
#include "Node.h"

template <typename T>
class list
{
private:
    Node<T> *m_head{nullptr};
    int m_size{0};

public:
    list()
    {
        m_head = new Node<T>(0, nullptr, nullptr);
        m_head->next = m_head;
        m_head->prev = m_head;
    }

    void push_back(const T &val)
    {
        Node<T> *aux = new Node<T>(val, m_head->prev, m_head);
        aux->prev->next = aux;
        m_head - prev = aux;
        m_size++;
    }
};

#endif
