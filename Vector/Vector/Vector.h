#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>

class Vector
{
private:
    int *m_list{nullptr}; // ponteiro para a lista
    int m_size{0};        // numero de elementos na lista
    int m_capacity{0};    // capacidade total da lista

public:
    // Construtor default: aloca uma lista com
    // capacidade inicial igual a 16 e size = 0
    Vector()
    {
        m_capacity = 16;
        m_list = new int[m_capacity];
    }

    // Copy constructor: cria uma nova lista com os
    // mesmos elementos da lista passada como argumento
    Vector(const Vector &vector) // O(n)
    {
        this->m_size = vector.m_size;
        this->m_capacity = vector.m_capacity;
        this->m_list = new int[this->m_capacity];
        for (int i = 0; i < m_size; i++)
        {
            this->m_list[i] = vector.m_list[i];
        }
        std::cout << "copiar" << std::endl;
    }

    // Destrutor: libera memoria alocada
    ~Vector()
    {
        delete[] m_list;
        std::cout << "lista liberada" << std::endl;
    }

    // Retorna a capacidade atual da lista
    int capacity() const // O(1){}
    {
        return m_capacity;
    }

    // Retorna o numero de elementos na lista
    int size() const // O(1)
    {
        return m_size;
    }

    // Retorna true se e somente se a lista estiver vazia
    bool empty() const // O(1)
    {
        return m_size == 0;
    }

    // Retorna uma referencia para o elemento na posicao k.
    // A funcao verifica automaticamente se n esta dentro dos
    // limites de elementos validos no vetor, lancando uma
    // excecao 'out_of_range' se nao estiver.
    int &at(int k) // O(1)
    {
        if (k < 0 || k >= m_size)
        {
            /// lança erro
            throw std::runtime_error("fail: indice invalido");
        }
        return m_list[k]
    }
    const int &at(int k) const // O(1)
    {
        if (k < 0 || k >= m_size)
        {
            /// lança erro
            throw std::runtime_error("fail: indice invalido");
        }
        return m_list[k]
    }

    // Retorna uma referencia para o elemento na posicao k.
    // Essas funcoes nao verificam se o indice eh valido.
    int &operator[](int index) // O(1)
    {
        return m_list[index];
    }
    const int &operator[](int index) const // O(1)
    {
        return m_list[index];
    }

    // Solicita que a capacidade do vetor seja >= n.
    // Se n for maior que a capacidade atual do vetor, a
    // funcao faz com que a lista aumente sua capacidade
    // realocando os elementos para o novo vetor. Em todos
    // os outros casos, a chamada da funcao nao causa uma
    // realocacao e a capacidade do vetor nao eh afetada.
    void reserve(int n) // O(n)
    {
        if (n > m_capacity)
        {
            m_capacity = n;
            int *aux = new int[m_capacity];
        }
        for (int i = 0; i < m_size; i++)
        {
            aux[i] = m_list[i];
        }
        delete[] m_list;
        m_list = aux;
    }

    // Recebe um inteiro como argumento e o adiciona
    // logo apos o ultimo elemento da lista.
    void push_back(const int &value) // tempo medio O(1)
    {
        if (m_size == m_capacity)
        {
            reserve(1.5 * m_capacity);
        }
        m_list[m_size] = value;
        m_size++;
    }

    // Remove o ultimo elemento da lista se a lista nao
    // estiver vazia. Caso contrario, faz nada
    void pop_back() // O(1)
    {
        if (!empty())
        {
            m_size--;
        }
    }

    // void insert(int index, int v) // insersão de memoria
    // {
    // }
};

#endif