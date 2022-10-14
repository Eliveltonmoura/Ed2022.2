// Arquivo de Implementacao do TAD Matriz
#include <iostream>
#include <iomanip>
#include "Matriz.h"
#include <string>
#include <stdlib.h>
using namespace std;

// Aloca espaco dinamicamente para matriz com m linhas e n colunas
Matriz::Matriz(int m, int n)
{
    lin = m;
    col = n;
    mat = new int *[n];

    for (int i = 0; i < n; i++)
    {
        mat[i] = new int[n];
    }
}

// Destrutor: Libera a memoria que foi alocada dinamicamente no construtor
Matriz::~Matriz()
{

    for (int i = 0; i < lin; i++)
    {
        delete[] mat[i];
    }

    cout << "matriz liberada" << endl;
}

// Retorna o numero de linhas da matriz
int Matriz::linhas()
{
    return lin;
}

// Retorna o numero de colunas da matriz
int Matriz::colunas()
{
    return col;
}

// Retorna o valor da celula [i][j] da matriz
int Matriz::getValor(int i, int j)
{
    return this->mat[i][j];
}

// Atribui valor a celula [i][j] da matriz
void Matriz::setValor(int valor, int i, int j)
{
    this->mat[i][j] = valor;
}

// Imprimir a matriz
void Matriz::print()
{
    for (int i = 0; i < lin; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            cout << setw(7) << mat[i][j];
        }
        cout << "\n";
    }
}

// Soma matrizes
Matriz *Matriz::soma(Matriz &B)
{
    if (this->lin == B.linhas() && this->col == B.colunas())
    {
        Matriz *C = new Matriz(lin, col);

        for (int i = 0; i < lin; i++)
        {
            for (int j = 0; j < col; j++)
            {
                C->setValor((B.getValor(i, j) + this->getValor(i, j)), i, j);
            }
        }
        return C;
    }
    else
        return nullptr;
}

// Multiplica matrizes
Matriz *Matriz::multiplica(Matriz &B)
{
    if (this->col == B.linhas())
    {
        Matriz *C = new Matriz(lin, B.colunas());

        for (int i = 0; i < lin; i++)
        {
            for (int k = 0; k < B.colunas(); k++)
            {
                C->setValor(0, i, k);
                for (int j = 0; j < col; j++)
                {
                    C->setValor((C->getValor(i, k) +
                                 (this->getValor(i, j) * B.getValor(j, k))),
                                i, k);
                }
            }
        }
        return C;
    }
    else
        return nullptr;
}