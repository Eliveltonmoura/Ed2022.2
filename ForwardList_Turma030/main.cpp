#include <iostream>
#include "ForwardList.h"
using namespace std;

int main() {
    ForwardList lst; // cria lista vazia

    cout << lst.toString() << endl; // imprime lista

    for(int i = 1; i <= 15; i++)
        lst.push_back(i);

    cout << lst.toString() << endl; // imprime lista
}