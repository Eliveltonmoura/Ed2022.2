/*
José Natan dos Santos - 476072
Antonio Elivelton Moura da Silva - 428426

*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "SparseMatrix.h"
#include "Node.h"

using namespace std;

SparseMatrix *readSparseMatrix(string filename){

    std::ifstream file(filename); // open file

    string line;
    int row, column;
    double value;
    int counter = 0;
    SparseMatrix *newMatrix;

    while(file.good()){
        // reads the first two values from file
        if(counter < 2){
            if(counter == 0){
                file >> row;
                counter++;
            }else if(counter == 1){
                file >> column;
                newMatrix = new SparseMatrix(row, column);
                counter++;
            }
        // reads the rest of file and treats its data
        }else{
            file >> line;
            row = stoi(line);
            file >> line;
            column = stoi(line);
            file >> line;
            value = stod(line);
            newMatrix->insert(row, column, value);
        }
    }

    file.close();
    return newMatrix;
    
}

SparseMatrix *sum(SparseMatrix *A, SparseMatrix *B){
    // checks if both matrix have the same size for rows and columns
    if (A->getRows() != B->getRows() || A->getColumns() != B->getColumns())
        throw std::runtime_error("Matrizes de tamanho diferente");

    SparseMatrix *C = new SparseMatrix(A->getRows(), A->getColumns());

    for (int i = 1; i <= A->getRows(); i++){
        for (int j = 1; j <= A->getColumns(); j++){
            if (A->validatePosition(i, j) && B->validatePosition(i, j)){
                C->insert(i, j, A->get(i, j) + B->get(i, j));
            }
            else if (A->validatePosition(i, j) && B->validatePosition(i, j) == false){
                C->insert(i, j, A->get(i, j));
            }
            else if (A->validatePosition(i, j) == false && B->validatePosition(i, j)){
                C->insert(i, j, B->get(i, j));
            }
        }
    }

    return C;
}

SparseMatrix *multiply(SparseMatrix *A, SparseMatrix *B){
    // checks if column and row size from A and B are different
    if (A->getColumns() != B->getRows())
        throw runtime_error("Tamanhos Inválidos");

    SparseMatrix *C = new SparseMatrix(A->getRows(), B->getColumns());

    for (int i = 1; i <= A->getRows(); i++){
        for (int j = 1; j <= B->getColumns(); j++){
            C->insert(i, j, 0);
            for (int k = 1; k <= A->getColumns(); k++){
                if (A->validatePosition(i, k) && B->validatePosition(k, j)){
                    C->insert(i, j, (C->get(i, j) + (A->get(i, k) * B->get(k, j))));
                }
            }
        }
    }
    return C;
}

int main(){
    
    vector<SparseMatrix*> sparsematrixList;

    while(true){
        string input, action;
        getline(cin, input);

        stringstream ss(input);
        ss >> action;

        cout << "👋:" << ss.str() << endl;
        // create
        if(action == "create"){
            int row, column;
            ss >> row; 
            ss >> column;
            SparseMatrix *sp = new SparseMatrix(row, column);
            sparsematrixList.push_back(sp);
        
        // print matrix X
        }else if(action == "print"){
            int id;
            ss >> id;
            sparsematrixList[id]->print();
        
        // print position i j from matrix X
        }else if(action == "get"){
            int id, row, column;
            ss >> id >> row >> column;
            cout << sparsematrixList[id]->get(row, column) << endl;
        
        // remove position i j from matrix X
        }else if(action == "remove"){
            int id, row, column;
            ss >> id >> row >> column;
            sparsematrixList[id]->remove(row, column);
        
        // insert a value on matrix X in position i j        
        }else if(action == "insert"){
            int id, row, column;
            double value;
            ss >> id >> row >> column >> value;
            sparsematrixList[id]->insert(row, column, value);
        
        // prints all matrix        
        }else if(action == "showAll"){
            for(unsigned i = 0; i<sparsematrixList.size(); i++){
                cout << "Matrix " << i << endl;
                sparsematrixList[i]->print();
                cout << endl;
            }
        
        // end
        }else if(action == "end"){
            for(unsigned i = 0; i<sparsematrixList.size(); i++){
                delete sparsematrixList[i];
            }
            sparsematrixList.clear();
            break;
        
        // soma
        }else if(action == "sum"){
            int id1, id2;
            ss >> id1 >> id2;
            SparseMatrix *sp = sum(sparsematrixList[id1], sparsematrixList[id2]);
            sparsematrixList.push_back(sp);
            sp->print();
        
        // multiply
        }else if(action == "multiply"){
            int id1, id2;
            ss >> id1 >> id2;
            SparseMatrix *sp = multiply(sparsematrixList[id1], sparsematrixList[id2]);
            sparsematrixList.push_back(sp);
            sp->print();
        
        // read a matrix from a file
        }else if(action == "read"){
            string filename;
            ss >> filename;
            SparseMatrix *sp = readSparseMatrix(filename);
            sparsematrixList.push_back(sp);
            sp->print();
        
        }else{
            cout << "comand '" << action << "' nonexistent!" << endl;
        }
    }

    return 0;
}