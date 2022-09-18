#include <iostream>
#include <vector>
using namespace std;

void tringulo(int n)
{
    if (n == 0)
    {
        return;
    }
    else
    {
        return tringulo(n - 1);
    }
}

int main()
{
    vector<int> vet;

    vet.push_back(10);
    vet.push_back(15);
    vet.push_back(15);

    int n = size(vet);
    int soma1{};
    int soma2{};

    for (int i = 0; i < n; i++)
    {
        soma1 = vet[0] + vet[1];
        soma2 = vet[1] + vet[2];

        cout << " " << vet[i];
    }
    cout << " " << endl;
    cout << soma1 << endl;
    cout << soma2;
}