/*
José Natan dos Santos - 476072
Antonio Elivelton Moura da Silva - 428426

*/

#ifndef NODE_H
#define NODE_H

class Node{
    friend class SparseMatrix;
    private:
        Node *right_pointer;
        Node *below_pointer;
        int row; 
        int column;
        double value;
    public:
        //constructor
        Node(int row_index, int column_index, const int &position_value, Node *right, Node *below){
            row = row_index;
            column = column_index;
            value = position_value;
            right_pointer = right;
            below_pointer = below;
        }

};

#endif