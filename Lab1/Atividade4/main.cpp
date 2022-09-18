#include <iostream>
#include <string>
#include <limits>
using namespace std;

int main()
{
    int qt = 0;
    int contP = 0;
    int contS = 0, i = 0;

    cin >> qt;

    float vp[qt];
    float cp[qt];
    char es[qt];

    for (i = 0; i < qt; i++)
    {
        cin >> vp[i];
    }
    for (i = 0; i < qt; i++)
    {
        cin >> cp[i];
    }
    cin.ignore();
    for (i = 0; i < qt; i++)
    {
        cin >> es[i];
    }

    for (i = 0; i < qt; i++)
    {

        if (vp[i] > cp[i] && es[i] == 'M')
        {
            contS++;
        }
        else if (vp[i] < cp[i] && es[i] == 'm')
        {
            contS++;
        }
        else
        {
            contP++;
        }
    }
    if (contP == contS)
    {
        cout << "empate" << endl;
    }
    else if (contP > contS)
    {
        cout << "primeiro" << endl;
    }
    else
    {
        cout << "segundo" << endl;
    }
}
