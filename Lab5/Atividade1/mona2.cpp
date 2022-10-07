#include <iostream>

using namespace std;

int main()
{

    int n, cont = 0;
    cin >> n;

    int vet[] = {1, 2, 1, 3, 5, 3, 2, 1};

    // for (int i = 0; i < n; i++)
    // {
    //     cin >> vet[i];
    // }

    for (int i = 0; i < n; i++)

    {

        for (int j = i + 1; j < n; j++)
        {
            cout << vet[i] << " " << vet[j] << endl;
            if (vet[i] == vet[j])
            {
                // vet[i] = '#';
                cont++;
                break;
            }
        }
    }

    cout << cont << endl;

    return 0;
}