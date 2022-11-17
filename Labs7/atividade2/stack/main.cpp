#include <iostream>
#include <string>
#include <sstream>
#include "Stack"

using namespace std;
// string iverter paçavras(string str)
// {
// stack<cha>pilha;
// string resultado;
// for(int i= 0;. i<=(int)str.size();i++){
//     if(str[i]!=' ' && str[i]!= "\n"){
//         pilha.push();
//     }
// }

// }

int main()
{

    Stack<string> pilha;
    string line;
    cout << getline(cin, line);

    getline(cin, line);
    stringstream ss{line};
    string word;
    while (ss >> word)
    {
        pilha.push(word);
    }

    while (!pilha.empty())
    {
    }
    {
        cout << pilha.pop() << endl;
        pilha.pop();
    }
}