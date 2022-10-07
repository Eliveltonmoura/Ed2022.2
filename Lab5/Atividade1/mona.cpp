#include <iostream>
#include <string>

using namespace std;
int main()
{

    int n{};
    cin >> n;
    int vet[n];
    int aux{};
    int cont{};
    int i, j;
    for (i = 0; i < n; i++)
    {
        cin >> vet[i];
    }

    for (i = 0; i < n; i++)
    {
        if (vet[i] > vet[i + 1])
        {
            aux = vet[i];
            vet[i] = vet[i + 1];
            vet[i + 1] = aux;
            cont++;
            break;
        }
    }

    cout << cont << endl;
}