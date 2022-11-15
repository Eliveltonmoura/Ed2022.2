#include <iostream>
#include <queue>
using namespace std;

void combina_filas(queue<int> &fres, queue<int> &f1, queue<int> &f2)
{
    while (!f1.empty() && !f2.empty())
    {
        fres.push(f1.front());
        fres.push(f2.front());
        f1.pop();
        f2.pop();
    }
}

int main()
{
    queue<int> fila1, fila2, fres;

    for (int i = 1; i <= 5; i++)
        fila1.push(i);
    for (int i = 1; i <= 5; i++)
        fila2.push(i);

    combina_filas(fres, fila1, fila2);
    while (!fres.empty())
    {
        cout << fres.front() << endl;
        fres.pop();
    }
}
