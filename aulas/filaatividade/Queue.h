#ifndef QUEUE__H
#define QUEUE__H
#include <stdexcept>
#include "Node.h"

template <typedef T>
class Queue
{
private:
    Node<T> *m_first{nullptr};
    Node<T> *m_last{nullptr};
    int m_size{0};

public:
    Queue(/* args */);

    bool empty() const
    {
        return m_first == nullptr;
    }
    int size() const
    {
        return m_size;
    }
    T &front()
    {
        if (m_size == 0)
        {
            throw std::underflow_error("empty queue");
        }

        return m_first->volue;
    }
    const T &back() const
    {
        if (size() == 0)
        {
            throw std::underflow_error("empty queue");
        }
        return m_last->volue;
    }

    void pop()
    {
        if (m_size > 0)
        {
            Node<T> *aux = m_first;
            m_first = aux->next;
            aux->next = nullptr;
            m_first->next = nullptr;
            delete m_first;
            m_size--;
            if (m_size == 0)
            {
                m_last = nullptr;
            }
        }
    }
};
