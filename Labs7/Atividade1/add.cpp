#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

// int matchingStrings(vector<string> &vet1, vector<string> &vet2, int tam1, int tam2)
// {
//     int cont{};
//     for (int i = 0; i < tam1; i++)
//     {
//         for (int j = 1; j < tam2; j++)
//         {
//             if (vet1[i] == vet2[j])
//             {
//                 cont++;
//             }
//         }
//     }
//     return cont;
// }

int main()
{
    string str1;
    stringstream valor1;
    string str2;
    stringstream valor2;
    int tam1;
    int tam2;
    int cont;
    cin >> tam1;
    cin >> tam2;
    getline(cin, str1, str2);
    valor1 << str1;
    valor2 << str2;
    // cin.ignore();
    // getline(cin, str2);
    // valor2 << str2;

    vector<string> vet;

    while (valor1)
    {
        cout << "oi";
    }
}