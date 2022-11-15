/*
José Natan dos Santos - 476072
Antonio Elivelton Moura da Silva - 428426

*/

#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H
#include "Node.h"

class SparseMatrix{
    private:
        Node *m_head;
        int row_size;
        int column_size;

    public:
    // SparseMatrix constructor
    SparseMatrix(int m, int n);
    
    // returns the number of rows from the matrix.
    int getRows();

    // returns the number of columns from the matrix.
    int getColumns();
    
    // return true if matrix is empty or false if is not.
    bool empty();

    // create a new node in the matrix in i j with the value passed
    // if a node in the i j position already exists then overwrite the
    // existing value for the new one.
    void insert(int i, int j, double value);

    // return the value in the i j position.
    double get(int i, int j);

    // returns true if the position already exists or false if not.
    bool validatePosition(int i, int j);

    // prints the matrix.
    void print();

    // remove the value in the i j positon.
    void remove(int i, int j);

    // destructor.
    ~SparseMatrix();

};


#endif