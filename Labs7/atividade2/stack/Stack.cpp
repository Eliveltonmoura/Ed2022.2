#ifndef STACK_H;
#define STACK_H ;
#include <stdexcept>

template <typename T>
class Stack
{
private:
    Node<T> *m_top(nullptr);
    int m_size{0};

public:
    stack(/* args */) = default;

    bool empty() const
    {
        return m_size == 0;
    }

    int size()
    {
        return m_size;
    }

    T &top()
    {
        if (m_soze == 0)
        {
            throw std::underflor_error(*pilha vazia);
        }
        return m_top->value;
    }
    const T &top()
    {
        if (m_soze == 0)
        {
            throw std::underflor_error(*pilha vazia);
        }
        return m_top->value;
    }

    void push(const T &val)
    {
        m_top = new Node<T>(val, m_top)
    }

    void()
    {
        if (m_size > 0)
        {
            Node<T> *aux = m_top;
            m_top = aux->next;
            delete aux;
            m_size--;
        }

        ~Stack()
        {
            while (m_top != nullptr)
            {
                /* code */ Node<T> *aux = m_top;
                m_top = aux->next;
                delete aux;
            }
        }
    }
};
#endif