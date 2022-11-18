#include <iostream>
#include <queue>

using namespace std;

int main()
{

    int tamanho{};
    int op{};
    int n{};

    queue<int> deposito, prateleira;

    cin >> tamanho;

    for (int i = 0; i < tamanho; i++)
    {
        cin >> op;

        if (op == 1)
        {

            cin >> n;
            deposito.push(n); // 1 2 3
        }
        else if (op == 2)
        {
            prateleira.pop();
        }
        else if (op == 3)
        {
            cout << prateleira.front() << endl;
        }
        if (prateleira.empty())
        {
            while (!deposito.empty())
            {
                prateleira.push(deposito.front());
                deposito.pop();
            }
        }
    }
}
