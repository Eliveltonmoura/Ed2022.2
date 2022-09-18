#include <iostream>
using namespace std;

int soma(int n)
{
    if (n == 1)
    { // caso base ou caso de parada
        return 1;
    }

    else
    {
        return soma(n - 1) + n;
    }
}

int main()
{

    cout << soma(3) << endl;

    return 0;
}