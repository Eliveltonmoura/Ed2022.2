#include <iostream>
#include <vector>
#include <sstream>

using namespace std;
void vetorNormal(vector<int> v, int n)
{

    if (n == 0)
    {
        cout << "vet : [ " << v[n];
    }
    else
    {
        vetorNormal(v, n - 1);
        cout << " " << v[n];
    }
}

void vetorInvt(vector<int> v, int n) // investe um vetor
{

    if (n == 0)
    {
        cout << " " << v[n];
    }
    else
    {
        cout << " " << v[n];
        vetorInvt(v, n - 1);
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

int vetorMin(vector<int> v, int n, int i)
{
    if (n == 0)
    {
        return v[i];
    }
    else
    {
        if (v[n] < v[i])
        {
            return vetorMin(v, n - 1, n);
        }
        else
        {
            return vetorMin(v, n - 1, i);
        }
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

    vetorNormal(vet, tam - 1); // retornar os elementos de um vertor
    cout << " ]" << endl;
    cout << "rvet: [";
    vetorInvt(vet, tam - 1); // investe um vetor
    cout << " ]";
    int soma = vetorSoma(vet, tam);      // recursão de soma
    int mult = vetorMut(vet, tam);       // recusão de multiplica
    int min = vetorMin(vet, tam - 1, 0); // menor elemento

    cout << endl;
    cout << "sum : " << soma << endl;
    cout << "mult: " << mult << endl;
    cout << "min : " << min << endl;

    cout << "inv : [";
    vetorInvt(vet, tam - 1);
    cout << " ]" << endl;
}