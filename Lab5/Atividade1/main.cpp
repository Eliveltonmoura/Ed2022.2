#include <iostream>
using namespace std;
int main()
{
    bool cont = true;

    int vet[] = {8, 2, 3, 4};

    for (int i = 1; i < 4; i++)

    {

        if (vet[i - 1] > vet[i])
        {
            cont = false;
            break;
        }
    }

    if (cont != true)
    {
        cout << "Nao ordenado";
    }
    else
        cout << "ordenado";
}