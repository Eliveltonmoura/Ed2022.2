#ifndef LIST_H
#define LIST_H
#include <sstream>
#include <string>
#include "Node.h"

class ForwardList {
private:
    Node* m_head { nullptr }; // ponteiro para o inicio da lista
    Item m_size {0}; // numero de elementos na lista atualmente

public:
    // construtor default: cria uma lista vazia, com 0 elementos
    // na lista vazia, m_head aponta para um node sentinela
    ForwardList() {
        m_head = new Node(0, nullptr);
    }
    // insere val no inicio da lista
    void push_front(Item val) {
        Node *aux = new Node(val, m_head->next);
        m_head->next = aux;
        m_size++;
    }
    // insere val no final da lista
    void push_back(Item val) {
        Node *aux = m_head;
        while(aux->next != nullptr) {
            aux = aux->next;
        }
        aux->next = new Node(val, nullptr);
        m_size++;
    }
    // retorna uma string no formato "[ a b c d ]"
    // ou retorna [ ] se a lista estiver vazia
    std::string toString() {
        std::stringstream ss;
        ss << "[ ";
        Node *atual = m_head;
        while(atual->next != nullptr) {
            ss << atual->next->value << " ";
            atual = atual->next;
        }
        ss << "]";
        return ss.str();
    }
    // deixa a lista vazia: com 0 elementos
    void clear() {
        while(m_head->next != nullptr) {
            Node* temp = m_head->next;
            m_head->next = temp->next;
            delete temp;
        }
        m_size = 0;
    }
    // Destrutor
    ~ForwardList() {
        clear();
        delete m_head;
    }
};

#endif