#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n{};
    int a{};
    int b{};
    queue<int> times, ganhou;

    for (int i = 1; i <= 15; i++)
    {
        times.push(i);
    }

    for (int j = 0; j < times.size() - 1; j++)
    {
        cin >> a >> b;

        if (a > b)
        {
            ganhou.push(times.front());
            times.
        }

        else if (a < b)
        {
        }
    }
}