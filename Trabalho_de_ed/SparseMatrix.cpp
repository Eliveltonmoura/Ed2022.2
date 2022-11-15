/*
José Natan dos Santos - 476072
Antonio Elivelton Moura da Silva - 428426

*/

#include <iostream>
#include "SparseMatrix.h"


SparseMatrix::SparseMatrix(int m, int n){
    // checks if the row and column values are valid.
    if(m < 0 || n < 0)
        throw std::length_error("Valor inserido para linha ou coluna está abaixo do permitido.");
    

    m_head = new Node(0, 0, 0, nullptr, nullptr);
    row_size = m;
    column_size = n;

    Node *aux = m_head;
    Node *novo;
    // creates sentinel row nodes.
    for(int i=1; i<=m; i++){
        novo = new Node(i, 0, 0, novo, novo);
        aux->below_pointer = novo;
        aux = novo;
        aux->right_pointer = aux;
    }

    aux->below_pointer = m_head;
    aux = m_head;

    // creates sentinel column nodes.    
    for(int i=1; i<=n; i++){
        novo = new Node(0, i, 0, novo, novo);
        aux->right_pointer = novo;
        aux = novo;
        aux->below_pointer = aux;
    }

    aux->right_pointer = m_head;    
}

int SparseMatrix::getRows(){
    return this->row_size;
}

int SparseMatrix::getColumns(){
    return this->column_size;
}

bool SparseMatrix::empty(){
    Node *aux_row = this->m_head->below_pointer;
   
    // for each row checks if the row is empty
    for(int i=1; i<=this->row_size; i++){
        if(aux_row->right_pointer != aux_row)
            return false;
        
        aux_row = aux_row->below_pointer;
    }
    
    return true;
}

void SparseMatrix::insert(int i, int j, double value){
        // checks if the i and j values are valid for the matrix
        if(i > this->row_size || j > this->column_size){
           std::cout << ("Valores de I ou J são inválidos.") << std::endl;
           return;
        }
        
        Node *aux_row = this->m_head->below_pointer;
        Node *aux_column = this->m_head->right_pointer;
        Node *newest;
        // reach sentinel row equal to I
        while(aux_row->row != i){
            aux_row = aux_row->below_pointer;
        }
        // reach sentinel column equal to J
        while(aux_column->column != j){
            aux_column = aux_column->right_pointer;
        }
        
        if(this->empty()){
            newest = new Node(i, j, value, aux_row, aux_column);
            aux_row->right_pointer = newest;
            aux_column->below_pointer = newest;
        }else{
            Node *auxr1 = aux_row;
            Node *auxc1 = aux_column;

            // reach node in the position before column J
            while(auxr1->right_pointer != aux_row && auxr1->right_pointer->column < j){
                auxr1 = auxr1->right_pointer;
            }
            
            // reach node in the position before row I
            while(auxc1->below_pointer != aux_column && auxc1->below_pointer->row < i){
                auxc1 = auxc1->below_pointer;
            }
        
            Node *tempr = auxr1;
            Node *tempc = auxc1;

            // checks if the positon i j already exists and/or save the next position from it
            if(auxr1->right_pointer->column == j){
                tempr = auxr1->right_pointer->right_pointer;
            }else{
                tempr = auxr1->right_pointer;
            }

            if(auxc1->below_pointer->row == i){
                tempc = auxc1->below_pointer->below_pointer;

            }else{
                tempc = auxc1->below_pointer;
            }
            
            // if the position i j already exists overwrite its value otherwise create a new node in i j
            if (auxr1->right_pointer->column == j && auxc1->below_pointer->row == i){
                auxr1->right_pointer->value = value;
            }else{
                newest = new Node(i, j, value, tempr, tempc);
                auxr1->right_pointer = newest;
                auxc1->below_pointer = newest;
            }
        }

}

bool SparseMatrix::validatePosition(int i, int j){

    Node *aux_row = this->m_head;

    while(aux_row->below_pointer->row != i){
        aux_row = aux_row->below_pointer;
    }
    aux_row = aux_row->below_pointer;

    // run through the matrix at row i and checks if a node with column j exists
    for(int i=1; i<=this->column_size; i++){
        if(aux_row->right_pointer->column == j)
            return true;
        aux_row = aux_row->right_pointer;
    }

    return false;
}

double SparseMatrix::get(int i, int j){
    if(this->empty() || this->row_size < i || this->column_size < j)
        throw std::underflow_error("Matriz Vazia.");

    if(!this->validatePosition(i, j))
        throw std::runtime_error("Posição Inválida.");

    Node *aux_row = this->m_head->below_pointer;

    // reach the row position before the row i
    while(aux_row->below_pointer->row != i){
        aux_row = aux_row->below_pointer;
    }
    aux_row = aux_row->below_pointer; // move to row i

    // reach the column position before the column j
    while(aux_row->right_pointer->column != j){
        aux_row = aux_row->right_pointer;
    }

    return aux_row->right_pointer->value;
}


void SparseMatrix::print(){
    Node *aux1 = this->m_head->below_pointer;
    Node *aux2 = this->m_head->below_pointer;

    for(int i=1; i<=this->row_size; i++){
        for(int j=1; j<=this->column_size; j++){
            // while running through the matrix checks if position exits and prints its value otherwise prints 0
            if(aux1->right_pointer->column == j){
                aux1 = aux1->right_pointer;
                std::cout << aux1->value << " ";
            }else std::cout << "0 ";
        }
        std::cout << std::endl;

        aux2 = aux2->below_pointer;
        aux1 = aux2;
    }
}

void SparseMatrix::remove(int i, int j){
    // checks if the matrix is empty
    if(this->empty()){
        std::cout << "ERRO: Matriz vazia" << std::endl;
        return;
    }else{
        // check if a node in the position i j exists
        if(!this->validatePosition(i, j)){
            std::cout << "ERRO: Posição inválida." << std::endl;
            return;
        }

        // reach row i
        Node *aux_row = this->m_head;
        while(aux_row->below_pointer->row <= i){
            aux_row = aux_row->below_pointer;
        }

        // reach node before the node from column j
        while(aux_row->right_pointer->column < j){
            aux_row = aux_row->right_pointer;
        }

        // delete node in position i j and rearranges matrix
        Node *temp = aux_row->right_pointer->right_pointer;
        delete aux_row->right_pointer;
        aux_row->right_pointer = temp;
    }
}

SparseMatrix::~SparseMatrix(){

    while(this->m_head->right_pointer != nullptr){
        Node *aux = this->m_head->right_pointer;
        this->m_head->right_pointer = aux->right_pointer;
        delete aux;
    }

    while(this->m_head->below_pointer != nullptr){
        Node *aux = this->m_head->below_pointer;
        this->m_head->below_pointer = aux->below_pointer;
        delete aux;
    }
    delete this->m_head;
}