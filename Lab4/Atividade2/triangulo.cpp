#include <iostream>
#include <string>
#include <vector>
using namespace std;

void tringulo(int vet[], int n)
{
    int aux[n];

    if (n == 0)
    {
        return;
    }

    else
    {

        int i;
        for (i = 0; i < n; i++)
        {
            aux[i] = vet[i] + vet[i + 1];
        }

        tringulo(aux, n - 1);
    }

    for (int j = 0; j < n; j++)
    {
        cout << vet[j] << ' ';
    }
    cout << endl;
}

int main()
{
    int n = 0;

    cin >> n;

    int vet[n];

    for (int i = 0; i < n; i++)
    {
        cin >> vet[i];
    }
    tringulo(vet, n);
}