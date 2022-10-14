#ifndef LIST_H
#define LIST_H
#include "Node.h"
#include <sstream>
#include <string>

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
        Node *aux = new Node(val, m_head->next);
        m_head->next = aux;
        m_size++;
    }

    void push_back(int val)
    {
        Node *aux = m_head;
        while (aux->next != nullptr)
        {
            aux = aux->next;
        }
        aux->next = new Node(val, nullptr);
        m_size++;
    }

    std::string toString()
    {
        std::stringstream ss;
        ss << "[";
        Node *atual = m_head;
        while (atual->next != nullptr)
        {
            ss << /// falta coisa
        }

        ss << "]";

        return ss.str();
    }

    void clear()
    {
        while (m_head->next != nullptr)
        {
            Node *temp = m_head->next;
            m_head->next = temp->next;
            delete temp;
        }
        m_size = 0;
    }
    ~ForwordList()
    {
        clear();
        delete m_head;
    }
};

#endif