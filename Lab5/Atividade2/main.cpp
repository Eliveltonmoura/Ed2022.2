#include <iostream>

using namespace std;
void hanoi(int qte, char ini, char aux, char meio, char fim)
{
    if (qte == 0)
    {
        return;
    }
    if (qte == 1)
    {
        cout << "hanoi " << ini << " para " << fim << endl;
    }

    else
    {
        hanoi(qte - 1, ini, meio, fim, aux);

        cout << "hanoi " << ini << " para " << meio << " para " << fim << endl;
        hanoi(qte - 1, aux, ini, meio, fim);
    }
}

int main()
{
    int qte;
    cin >> qte;
    hanoi(qte, 'A', 'B', 'C', 'D');
    return 0;
}