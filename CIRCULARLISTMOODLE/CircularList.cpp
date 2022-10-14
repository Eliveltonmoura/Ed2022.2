#include <sstream>
#include <string>
#include "Node.h"
#include "CircularList.h"

void CircularList::push_back(const Item &val)
{
    if (empty())
    {
        m_head = new Node(val, m_head);
        m_head->next = m_head;
    }
    else
    {
        Node *aux = m_head;
        while (aux->next != m_head)
        {
            aux = aux->next;
        }
        aux->next = Node(val, m_head);
    }
    m_size++;
}

void CircularList::pop_back()
{
    if (empty())
    {
        return;
    }
    {
        /* code */
    }

    if (m_head->next == m_head)
    {
        delete m_head;
        m_head = nullptr;
    }
    else
    {
        Node *aux = m_head;
        while (aux->next->next != m_head)
        {
            aux = aux->next;
        }
        delete aux->next;
        aux->next = m_head;
    }
    m_size--;
}

std::string CircularList::toString() const
{
    // FAZER
}

Item &CircularList::operator[](int index)
{
    Node *aux = m_head;
    for (int i = 0; i < index; i++)
    {
        aux = aux->next;
    }
    return aux->value;
}

const Item &CircularList::operator[](int index) const
{
    // FAZER
}

void clear_recursiva(Node *nodeAtual, Node *cabeca)
{

    if (nodeAtual->next == cabeca)
    {
        delete nodeAtual;
    }
    else
    {
        clear_recursiva(nodeAtual->next, cabeca);
        delete nodeAtual;
    }
}

void CircularList::clear()
{

    clear_recursiva(m_head, m_head);
    m_head = nullptr;
    m_size = 0;
}

CircularList::~CircularList()
{
    // FAZER
}
