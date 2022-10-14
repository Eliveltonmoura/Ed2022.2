#include <iostream>
using namespace std;
void printr
{
}

int main()
{
    int r = 3;

    // Creating the array of pointers
    // of size N
    int **p = new int *[r];
    int x = 1;

    // For multiplying
    for (int i = 0; i < r; i++)
    {
        p[i] = new int[r];

        for (int j = 0; j < r; j++, x++)
        {

            cin >> p[n][m];
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << p[i][j]
                 << " "; /* code */
        }
    }

    return 0;
}