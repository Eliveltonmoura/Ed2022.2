#include <iostream>
#include <iomanip>
using namespace std;

double fatorial(double num)
{
    double fatorial{1};
    for (int i = num; i >= 1; i--)
    {
        fatorial = fatorial * i;
    }
    return fatorial;
}

double euler(double n)
{
    double eule{1};

    for (int i = 1; i <= n; i++)
    {
        eule += 1 / fatorial(i);
    }
    return eule;
}

int main()
{
    double numeuler{0}, n{0};
    cin >> n;

    numeuler = euler(n);

    cout << setprecision(6)<<fixed<< numeuler << endl;
}