#include <iostream>
using namespace std;

int main()
{
    int num{0}, nao{0};

    cin >> num;

    int vet[num];

    for (int i = 0; i < num; i++)
    {
        cin >> vet[i];
    }
    for (int j = 0; j <= (num - 1); j++)
    {
        if (vet[j] > vet[j + 1])
        {
            nao = 1;
        }
    }

    if (nao == 0)
    {
        cout << "ok" << endl;
    }

    else
    {
        cout << "precisa de ajuste" << endl;
    }
}