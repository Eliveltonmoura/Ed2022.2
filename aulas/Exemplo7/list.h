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
    class iterator
    {
    private:
        Node<T> *ptr;

    public:
        iterator(Node<T> *pointer)
        {
            prt = pointer;
        }
        bool operator!=(const iterator &it)
        {
            return ptr != it.ptr;
        }
        T &operator*()
        {
            return ptr->value;
        }
        iterator &operator++()
        {
            ptr = ptr->next;
            return *this;
        }
    };

    iterator begin()
    {
        return iterator(m_head->next);
    }

    iterator end()
    {
        return iterator(m_head);
    }

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
        m_head->prev = aux;
        m_size++;
    }
    T &operator[](int index)
    {
        Node<T> *aux = m_head->next;
        for (int i = 0; i < index; i++)
        {
            aux = aux->next;
        }
        return aux->value;
    }
    const T &operator[](int index) const
    {
        Node<T> *aux = m_head->next;
        for (int i = 0; i < index; i++)
        {
            aux = aux->next;
        }
        return aux->value;
    }
    size() const
    {
        return m_size;
    }
    bool empty() const
    {
        return m_size == 0;
    }
    void pop_back()
    {
        if (!empty())
        {
            Node<T> *aux = m_head->prev;
            m_head->prev = aux->prev;
            aux->prev->next = m_head;
            delete aux;
            m_size--;
        }
    }

    void clear()
    {
        Node<T> *aux = m_head->prev;
        while (aux != m_head)
        {
            Node<T> *temp = aux;
            aux = temp->prev;
            delete temp;
        }
    }
    ~list()
    {
        clear();
        delete m_head;
    }
};

#endif
