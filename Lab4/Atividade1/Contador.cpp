#include <iostream>
#include <cstring>

using namespace std;

// Retorna o números de ocorrências do caractere 'c' na string 'str' (com 'n' caracteres).
// Algoritmo deve ser recursivo e sem comandos de repetição.
int contaCaracteres(string str, char c)
{
    if (str[0] == '\0')
    {
        return 0;
    }
    else if (str[0] == c)
    {
        return contaCaracteres(str.substr(1), c) + 1;
    }
    else
    {
        return contaCaracteres(str.substr(1), c);
    }
}

int main()
{
    string str, sem;
    char c;
    int n;

    getline(cin, str); // passei um dia para resover isso

    cin >> c;

    n = contaCaracteres(str, c);
    cout << n << endl;
}