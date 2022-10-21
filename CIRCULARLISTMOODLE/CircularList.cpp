#include <sstream>
#include <string>
#include "Node.h"
#include "CircularList.h"

// Insere val no final da lista e incrementa o valor de m_size
// Haverá dois casos: lista vazia e lista com elementos
void CircularList::push_back(const Item &val)
{
    if (m_head == nullptr)
    { // lista vazia
        m_head = new Node(val, nullptr);
        m_head->next = m_head;
    }
    else
    { // lista com pelo menos 1 elemento
        Node *aux = m_head;
        while (aux->next != m_head)
        {
            aux = aux->next;
        }
        aux->next = new Node(val, m_head);
    }
    m_size++;
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
    Node *aux = m_head;
    for (int i = 0; i < index; i++)
    {
        aux = aux->next;
    }
    return aux->value;
}

// Retira elemento do final da lista
// Se o elemento for retirado com sucesso, m_size é decrementado
void CircularList::pop_back()
{
    if (m_head == nullptr)
    { // lista vazia
        return;
    }
    if (m_head->next == m_head)
    { // lista com 1 elemento
        delete m_head;
        m_head = nullptr;
    }
    else
    { // 2 ou mais elementos
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

// Retorna lista como uma string
std::string CircularList::toString() const
{
}

void clear_recursivo(Node *nodeAtual, Node *cabeca)
{
    if (nodeAtual->next == cabeca)
    { // case base
        delete nodeAtual;
    }
    else
    {
        clear_recursivo(nodeAtual->next, cabeca);
        delete nodeAtual;
    }
}

void CircularList::clear()
{
    clear_recursivo(m_head, m_head);
    m_head = nullptr;
    m_size = 0;
}

CircularList::~CircularList()
{
    // FAZER
}

void CircularList::insert(int index, const Item &val)
{
    if (index < 0 || index > m_size)
    {
        throw std::range_error("indice invalido");
    }
    if (m_head == nullptr)
    {
        m_head = new Node(val, nullptr);
        m_head->next == m_head;
        m_size++;
    }
    else if (index == 0)
    {
        Node *novo = new Node(val, m_head);
        m_size++;
        Node *aux = m_head;
        while (aux->next != m_head)
        {
            /* code */
            aux = aux->next;
        }
        aux->next = novo;
        m_head = novo;
    }
    else
    {
        Node *aux = m_head;
        for (int cont = 0; cont < index - 1; cont++)
        {
            aux = aux->next;
        }
        Node *novo = new Node(val, aux->next);
        aux->next = novo;
        m_size++;
    }
}
