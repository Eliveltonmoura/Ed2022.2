#include <iostream>
using namespace std;

bool primo(int n)

{

    for (int i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            return false;
        }

        else
        {
            return true;
        }
    }
}

int main()
{

    int a{0}, b{0}, numprimo{0};
    cin >> a >> b;

    if (a < b)
    {
        for (int i = a; i <= b; i++)
        {
            numprimo = primo(i);

            if (numprimo == true)
            {
                cout << i << endl;
            }
        }
    }
    else
    {
        cout << "nao e valido" << endl;
    }
}
