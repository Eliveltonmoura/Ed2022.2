#include <iostream>
using namespace std;

int main()
{

    int i, j, mat[3][3], cont = 0;

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            cin >> mat[i][j];

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 2; j++)
        {
            if (mat[j][i] < mat[j + 1][i])
            {
                cont++;
            }
        }
    }

    cout << cont << endl;
}