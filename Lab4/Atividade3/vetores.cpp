#include <iostream>
#include <vector>
#include <sstream>

using namespace std;
void vetorNormal(vector<int> v, int n)
{

    if (n == 0)
    {
        cout << v[n];
    }
    else
    {
        vetorNormal(v, n - 1);
        cout << v[n];
    }
}

int vetorSoma(vector<int> v, int n) //  Recursão para  Soma elentos  do vector;
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        return v[n - 1] + vetorSoma(v, n - 1);
    }
}
int vetorMut(vector<int> v, int n) // recursão para multiplicar os elentos do vector
{

    if (n == 0)
    {
        return 1;
    }
    else
    {
        return v[n - 1] * vetorMut(v, n - 1);
    }
}

int main()
{
    string line;
    getline(cin, line);
    stringstream s(line);
    vector<int> vet;
    int n;
    while (s >> n)
    {
        vet.push_back(n);
    }
    int tam = vet.size();

    vetorNormal(vet, tam);          // retornar os elementos de um vertor
    int soma = vetorSoma(vet, tam); // recursão de soma
    int mult = vetorMut(vet, tam);  // recusão de multiplica

    cout << endl;
    cout << "sum: " << soma << endl;
    cout << "mult: " << mult << endl;
}