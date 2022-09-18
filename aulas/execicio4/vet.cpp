#include <iostream>
using namespace std;

int maximo(int n, int v[]) // recebe um vertor com n elementos
                           // e retorno o maior entre eles
{
    if (n == 1)
    {
        return v[n - 1];
    }
    else
    {
        int maior = maximo(n - 1, v);
        return (maior > v[n - 1]) ? maior : v[n - 1];
    }
}
int main()
{
    int vet[5] = {-1, 0, 9, 52
    
    
    , 5};
    cout << maximo(5, vet) << endl;
    return 0;
}