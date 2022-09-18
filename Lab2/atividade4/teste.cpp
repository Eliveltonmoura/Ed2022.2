#include <iostream> // std::wcout
#include <cwctype>  // towupper
using namespace std;
int main()
{

    string frase;
    char op;

    // cin.ignore();
    getline(cin, frase);
    // int n = strlen(nome);

    cin >> op;

    if (op == 'M')
    {

        for (size_t i = 0; i < size(frase); i++)
        {
            frase[i] = towupper(frase[i]);
            cout << frase[i];
        }
    }

    else if (op == 'm')
    {
        for (size_t i = 0; i < size(frase); i++)
        {
            frase[i] = tolower(frase[i]);
            cout << frase[i];
        }
    }
    else if (op == 'i')
    {
        for (size_t i = 0; i < size(frase); i++)
        { // inverter cases
            if (frase[i] >= 'a' && frase[i] <= 'z')
            {
                frase[i] -= 32;
            }
            else if (frase[i] >= 'A' && frase[i] <= 'Z')
            {
                frase[i] += 32;
            }
            cout << frase[i];
        }
    }
    if (op == 'p')
    {
        for (size_t i = 0; i < size(frase); i++)
        {
            if (i == 0 || frase[i - 1] == ' ')
            { // primeiras letras maiusculas
                if (frase[i + 1] == ' ' && frase[i] >= 'A' && frase[i] <= 'Z')
                {
                    frase[i] += 32;
                }
                else if (frase[i + 1] != ' ' && frase[i] >= 'a' && frase[i] <= 'z')
                {
                    frase[i] -= 32;
                }
            }
            cout << frase[i];
        }
    }
}